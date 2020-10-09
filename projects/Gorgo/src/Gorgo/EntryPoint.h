#pragma once

#ifdef  GRG_PLATFORM_WINDOWS

extern Gorgo::Application* Gorgo::CreateApplication();

int main(int argc, char** argv) {

	printf("Gorgo started");
	auto app = Gorgo::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif //  GRG_PLATFORM_WINDOWS