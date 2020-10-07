#pragma once


#ifdef GRG_PLATFORM_WINDOWS
	#ifdef GRG_BUILD_DLL
		#define GRG_API __declspec(dllexport)
	#else 
		#define GRG_API __declspec(dllimport)
	#endif

#else
	#error Gorgo only supports Windows 
#endif