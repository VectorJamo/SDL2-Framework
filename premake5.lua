workspace "SDL3-Framework"
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

project "SDL3-Framework"
	location "SDL3-Framework"
	
	kind "ConsoleApp"
	language "C++"
	
	files {
		"SDL3-Framework/src/**.h",
		"SDL3-Framework/src/**.cpp",
	}
	
	includedirs {
		"Dependencies/SDL3/include"
	}
	
	libdirs {
		"Dependencies/SDL3/lib/x86"
	}
	
	links {
		"SDL3", "SDL3_image"
	}
	
	targetdir "bin/%{prj.name}/%{cfg.buildcfg}-%{cfg.platform}/"