#pragma once

#ifdef  GRG_PLATFORM_WINDOWS

extern Gorgo::Application* Gorgo::CreateApplication();

int main(int argc, char** argv) {

	Gorgo::Log::Init();
	GRG_CORE_INFO("Gorgo initialized...");

	auto app = Gorgo::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif //  GRG_PLATFORM_WINDOWS