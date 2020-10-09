#include <Gorgo.h>

#include <iostream>

class SandboxApp : public Gorgo::Application {
public:
	SandboxApp() {

	}
	~SandboxApp() {

	}
};

Gorgo::Application* Gorgo::CreateApplication() {
	return new SandboxApp();
}
