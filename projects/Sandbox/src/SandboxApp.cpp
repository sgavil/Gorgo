#include <Gorgo.h>


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

	SandboxApp* app = new SandboxApp();
	app->Run();
	delete app;

	return 0;
}