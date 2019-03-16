#include "config.h"

#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/Platform/Sdl2Application.h>

#include <dummy.h>
#include <TexturedShader.h>

#include <iostream>

using namespace Magnum;

struct Vertex { 
	Vector2 position;
	Vector2 textureCoordinates;
};

const TriangleVertex data[]{
	{{-0.5f, -0.5f}, {0.0f, 0.0f}}, /* Left vertex position and texture coordinate */
	{{ 0.5f, -0.5f}, {1.0f, 0.0f}}, /* Right vertex position and texture coordinate */
	{{ 0.0f,  0.5f}, {0.5f, 1.0f}}  /* Top vertex position and texture coordinate */
};


class MyApplication: public Platform::Application {
	public:
		explicit MyApplication(const Arguments& arguments);
#ifndef CORRADE_TARGET_ANDROID
		void keyPressEvent(KeyEvent &event) override;
		void keyReleaseEvent(KeyEvent &event) override;
#endif

	private:
		void drawEvent() override;
	private:
		int m_window_width = 960;
		int m_window_height = 720;
	private:
		GL::Buffer _buffer;
		GL::Mesh _mesh;
		TexturedShader _shader;
		GL::Texture2D _texture;
};

#include <dlfcn.h>
#include <assert.h>

typedef bool(*FUNC_B)(void);

MyApplication::MyApplication(const Arguments& arguments): Platform::Application{arguments} {
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
	// Clear color and depth buffers
	GL::defaultFramebuffer.clear(GL::FramebufferClear::Color | GL::FramebufferClear::Depth);
	swapBuffers();
}

#ifndef CORRADE_TARGET_ANDROID
void MyApplication::keyPressEvent(KeyEvent &event) {
	if(event.key() == KeyEvent::Key::Esc) {
		exit();
	} else return;
	event.setAccepted();
	redraw();
}

void MyApplication::keyReleaseEvent(KeyEvent &event) {
	if(event.key() == KeyEvent::Key::Esc) {
		exit();
	} else return;
	event.setAccepted();
	redraw();
}
#endif

MAGNUM_APPLICATION_MAIN(MyApplication)
