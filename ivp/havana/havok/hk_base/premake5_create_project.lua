group("IVP")
	project("hk_base")
		kind("StaticLib")
		warnings("Default")
		location("../../../projects/" .. os.target() .. "/" .. _ACTION)
		targetdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
		debugdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
		objdir("!%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}/intermediate/%{prj.name}")
		sysincludedirs({
			".."
		})
		files({
			"array/array.cpp",
			"hash/hash.cpp",
			"id_server/id_server.cpp",
			"memory/memory.cpp",
			"memory/memory_util.cpp",
			"stopwatch/stopwatch.cpp",
			"string/string.cpp",
			"base_types.cpp",
			"console.cpp"
		})
		vpaths({["Source files/*"] = "*.cpp"})

		filter("system:linux")
			defines({"_LIB", "LINUX"})
			buildoptions { "-fpic", "-fno-semantic-interposition" }
