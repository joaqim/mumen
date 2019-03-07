#include "config.h"

#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/Platform/Sdl2Application.h>

#include <dummy.h>

#include <iostream>

using namespace Magnum;

class MyApplication: public Platform::Application {
    public:
        explicit MyApplication(const Arguments& arguments);

    private:
        void drawEvent() override;
};

#include <dlfcn.h>
#include <assert.h>

typedef bool(*FUNC_B)(void);

MyApplication::MyApplication(const Arguments& arguments): Platform::Application{arguments} {
	/* TODO: Add your initialization code here */
	std::cout << "Version: " << PROJECT_NAME_LOWER << "\n";

	//void *lib = dlopen("libmy_application_dummy_plugin.so", RTLD_LAZY);
	void *lib = dlopen("plugins/libmy_application_dummy_plugin.so", RTLD_LAZY);
	if(lib == nullptr) { 
		std::cerr << dlerror() << "\n";
		return;
       	}


	auto f = (FUNC_B)dlsym(lib, "init");
	assert(f());

	dlclose(lib);
}

void MyApplication::drawEvent() {
	GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);

	/* TODO: Add your drawing code here */

	swapBuffers();
}

#if 0
void MyApplication::keyPressEvent(KeyEvent &event) {
	if(event.key() == KeyEvent::Key::Escape) {
		exit();
	} else return;
	event.setAccepted();
	redraw();
}

void MyApplication::keyReleaseEvent(KeyEvent &event) {
	if(event.key() == KeyEvent::Key::Escape) {
		exit();
	} else return;
	event.setAccepted();
	redraw();
}
#endif

MAGNUM_APPLICATION_MAIN(MyApplication)
