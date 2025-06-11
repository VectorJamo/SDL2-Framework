workspace "SDL2-Framework"
	configurations {
	"Debug", "Release"
	}
	platforms {
		"Win32", "Win64"
	}

	filter {"platforms:Win32"}
		system "Windows"
		architecture "x86"

	filter {"platforms:Win64"}
		system "Windows"
		architecture "x86_64"

project "SDL2-Framework"
	location "SDL2-Framework"
	
	kind "ConsoleApp"
	language "C++"
	
	files {
		"SDL2-Framework/src/**.h",
		"SDL2-Framework/src/**.cpp",
	}
	
	includedirs {
		"Dependencies/SDL2/include"
	}
	
	libdirs {
		"Dependencies/SDL2/lib/x86"
	}
	
	links {
		"SDL2", "SDL2main", "SDL2_image", "SDL2_ttf", "SDL2_mixer"
	}
	
	targetdir "bin/%{prj.name}/%{cfg.buildcfg}-%{cfg.platform}/"