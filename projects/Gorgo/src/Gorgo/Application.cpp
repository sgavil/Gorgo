
#include "grgpch.h"

#include "Application.h"
#include "Events/MouseEvent.h"
#include "Log.h"


namespace Gorgo {

	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		MouseMovedEvent e(1280, 720);
		GRG_TRACE(e);

		while (true);
	}
}
