#include <Gorgo.h>

#include <iostream>

class SandboxApp : public Gorgo::Application {
public:
	SandboxApp() {

	}

	void Run() override {
		while (1);
	}
private:

};


int main() {

	/*SandboxApp* app = new SandboxApp();
	app->Run();
	delete app;*/
	Gorgo::Vector v1(3.0f, 5.0f, 5.0f);
	std::cout << v1;

	return 0;
}