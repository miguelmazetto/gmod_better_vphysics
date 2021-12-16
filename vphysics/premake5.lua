project("vphysics")
	_project = project()
	_project.serverside = true
	configurations({"ReleaseWithSymbols", "Release", "Debug"})
	kind("SharedLib")
	language("C++")
	warnings("Default")
	location("../projects/" .. os.target() .. "/" .. _ACTION)
	targetdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
	debugdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
	objdir("!%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}/intermediate/%{prj.name}")
	libdirs({
		"../sourcesdk-minimal/lib/public",
		"../ivp/projects/" .. os.target() .. "/" .. _ACTION
	})
	sysincludedirs({
		"../sourcesdk-minimal/public",
		"../ivp/ivp_intern",
		"../ivp/ivp_collision",
		"../ivp/ivp_physics",
		"../ivp/ivp_surface_manager",
		"../ivp/ivp_utility",
		"../ivp/ivp_controller",
		"../ivp/ivp_compact_builder",
		"../ivp/havana/havok",
		"../ivp/havana"
	})
	files({
		"convert.cpp",
		"../sourcesdk-minimal/public/filesystem_helpers.cpp",
		"ledgewriter.cpp",
		"main.cpp",
		"physics_airboat.cpp",
		"physics_collide.cpp",
		"physics_constraint.cpp",
		"physics_controller_raycast_vehicle.cpp",
		"physics_environment.cpp",
		"physics_fluid.cpp",
		"physics_friction.cpp",
		"physics_material.cpp",
		"physics_motioncontroller.cpp",
		"physics_object.cpp",
		"physics_shadow.cpp",
		"physics_spring.cpp",
		"physics_vehicle.cpp",
		"physics_virtualmesh.cpp",
		"trace.cpp",
		"vcollide_parse.cpp",
		"vphysics_saverestore.cpp",
	})
	vpaths({["Source files/*"] = "*.cpp"})
	
	filter("system:linux")
		defines({"_LIB", "LINUX"})
		buildoptions { "-fpic", "-fno-semantic-interposition" }

	IncludeIVP_hk_base()
	IncludeIVP_hk_math()
	IncludeIVP_havana_constraints()
	IncludeIVPCompactBuilder()
	IncludeIVPPhysics()
	IncludeSDKTier0()
	IncludeSDKTier1()
	IncludeSDKTier2()
	IncludeSDKMathlib()
	--IncludeSDKvstdlib()