#include "config.h"
#include <iostream>
#include <dlfcn.h>

#include <catch.hpp>

typedef bool(*FUNC_B)(void);
typedef void(*FUNC)(void);

struct library {
	library() = default;
	void *pLibrary = nullptr;
	bool isInitialized = false;

	FUNC_B init;
	FUNC deinit;
	FUNC run;
};

template<typename T>
T load(const char* filename) {
	T lib;
	lib.pLibrary = dlopen(filename, RTLD_LAZY);
	if (lib.pLibrary == nullptr) {
		std::cerr << "Error loading plugin: " << errno << "\n";
	}
	return lib;
};

template <typename T>
void unload(T lib) {
	dlclose(lib.pLibrary);
	lib.pLibrary = nullptr;
	lib.isInitialized = false;
}

TEST_CASE("Loading plugin") {
	auto lib = load<library>("plugins/lib" PROJECT_NAME_LOWER "_dummy_plugin.so");
	lib.init = (FUNC_B)dlsym(lib.pLibrary, "init");
	lib.deinit = (FUNC)dlsym(lib.pLibrary, "deinit");
	lib.run = (FUNC)dlsym(lib.pLibrary, "run");

	REQUIRE(lib.init);

	lib.run();
	lib.deinit();
	unload(lib);

	REQUIRE(lib.pLibrary == nullptr);
}
