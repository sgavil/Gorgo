#include "Core.h"

namespace Gorgo 
{
	class GRG_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();	

	};

	//To be defined in CLIENT
	Application* CreateApplication();
}
