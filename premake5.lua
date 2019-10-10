workspace "CosoEngine"
   architecture "x64"
   
   configurations 
   { 
   "Debug", 
   "Release", 
   "Dist" 
   }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CosoEngine"
   location "CosoEngine"
   kind "SharedLib"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files 
   {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
   }

   includedirs 
   {
	  "%{prj.name}/src"
	  "%{prj.name}/vendor/spdlog/include"
   }

   filter "system:windows"
      cppdialect "C++17"
	  staticruntime "On"
	  systemversion "latest"

      defines { 
		"COSO_PLATFORM_WINDOWS",
		"COSO_BUILD_DLL" 
	  }
      
	  postbuildcommands 
	  {
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	  }
	
   filter "system:Debug"
      defines "COSO_DEBUG"
	  symbols "On"

   filter "system:Release"
      defines "COSO_RELEASE"
	  optimize "On"

   filter "system:Dist"
      defines "COSO_DIST"
	  symbols "On"


project "Sandbox"
   location "Sandbox"
   kind "ConsoleApp"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files 
   {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
   }

   includedirs 
   {
	  "CosoEngine/vendor/spdlog/include",
	  "CosoEngine/src"
   }

   links 
   {
	  "CosoEngine"
   }

   filter "system:windows"
      cppdialect "C++17"
	  staticruntime "On"
	  systemversion "latest"

      defines { 
		"COSO_PLATFORM_WINDOWS",
	  }
      
   filter "system:Debug"
      defines "COSO_DEBUG"
	  symbols "On"

   filter "system:Release"
      defines "COSO_RELEASE"
	  optimize "On"

   filter "system:Dist"
      defines "COSO_DIST"
	  symbols "On"

