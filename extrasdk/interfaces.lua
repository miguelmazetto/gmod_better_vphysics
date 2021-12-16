group("SourceSDK")
	project("interfaces")
		kind("StaticLib")
		warnings("Default")
		location("../projects/" .. os.target() .. "/" .. _ACTION)
		targetdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
		debugdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
		objdir("!%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}/intermediate/%{prj.name}")
		sysincludedirs({"../sourcesdk-minimal/public"})

		files({"../sourcesdk-minimal/interfaces/interfaces.cpp"})

		vpaths({["Source files/*"] = "*.cpp"})

		filter("system:linux")
			defines({"_LIB", "LINUX"})
			buildoptions { "-fpic", "-fno-semantic-interposition" }