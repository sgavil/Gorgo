-- premake5.lua
workspace "Gorgo"
   configurations { "Debug", "Release" }
   architecture "x64"

outputdir = "%{prj.name}/%{cfg.buildcfg}/"

project "Gorgo"
   location "projects/%{prj.name}"
   kind "SharedLib"
   language "C++"

   targetdir ("bin/" .. outputdir)
   objdir ("bin-inter/" .. outputdir)

   pchheader "grgpch.h"
   pchsource "projects/%{prj.name}/src/grgpch.cpp"

   files
   {
      "projects/%{prj.name}/src/**.h",
      "projects/%{prj.name}/src/**.cpp"
   }

   includedirs
   {
      "projects/%{prj.name}/src",
      "dependencies/vendor/spdlog/include/"
   }

   filter "system:windows"
      staticruntime "On"
      systemversion "latest"

      defines
      {
         "GRG_PLATFORM_WINDOWS",
         "GRG_BUILD_DLL"
      }

      postbuildcommands
      {
         ("{COPY} ../../bin/" .. outputdir .. " ../../bin/Sandbox/%{cfg.buildcfg}")
      }
   
   filter "configurations:Debug"
      defines "GRG_DEBUG"
      symbols "On"
   
   filter "configurations:Release"
      defines "GRG_RELEASE"
      optimize "On"

project "Sandbox"
location "projects/%{prj.name}"
   kind "ConsoleApp"
   language "C++"

   targetdir ("bin/" .. outputdir)
   objdir ("bin-inter/" .. outputdir)
   files
   {
      "projects/%{prj.name}/src/**.h",
      "projects/%{prj.name}/src/**.cpp"
   }

   includedirs 
   {
      "dependencies/vendor/spdlog/include/",
      "projects/Gorgo/src"
   }
   links 
   {
      "Gorgo"
   }

   filter "system:windows"
      staticruntime "On"
      systemversion "latest"

      defines "GRG_PLATFORM_WINDOWS"
   
   filter "configurations:Debug"
      defines "GRG_DEBUG"
      symbols "On"
   
   filter "configurations:Release"
      defines "GRG_RELEASE"
      optimize "On"


