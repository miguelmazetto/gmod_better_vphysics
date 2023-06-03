group("SourceSDK")
	project("interfaces")
		kind("StaticLib")
		location("../projects/" .. os.target() .. "/" .. _ACTION)

		files({"interfaces.cpp"})
		vpaths({["Source files/*"] = "*.cpp"})

		filter("system:linux")
			defines({"_LIB", "LINUX"})
			undefines({"COMPILER_MSVC32"})
			buildoptions { "-fpic", "-fno-semantic-interposition" }