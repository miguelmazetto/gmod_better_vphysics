group("IVP")
	project("hk_math")
		kind("StaticLib")
		warnings("Default")
		location("../../../projects/" .. os.target() .. "/" .. _ACTION)
		targetdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
		debugdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
		objdir("!%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}/intermediate/%{prj.name}")
		includedirs({
			".."
		})
		files({
			"gauss_elimination/gauss_elimination.cpp",
			"incr_lu/incr_lu.cpp",
			"lcp/lcp_solver.cpp",
			"quaternion/quaternion.cpp",
			"quaternion/quaternion_util.cpp",
			"vector3/vector3.cpp",
			"vector3/vector3_util.cpp",
			"dense_vector.cpp",
			"densematrix.cpp",
			"densematrix_util.cpp",
			"eulerangles.cpp",
			"math.cpp",
			"matrix3.cpp",
			"odesolve.cpp",
			"plane.cpp",
			"rotation.cpp",
			"spatial_matrix.cpp",
			"spatial_vector.cpp",
			"transform.cpp",
			"vecmath.cpp",
			"vector4.cpp"
		})
		vpaths({["Source files/*"] = "*.cpp"})

		filter("system:linux")
			defines({"_LIB", "LINUX"})
			buildoptions { "-fpic", "-fno-semantic-interposition" }