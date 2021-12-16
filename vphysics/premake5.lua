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
	
	--libdirs({
	--	"../ivp/projects/" .. os.target() .. "/" .. _ACTION
	--})

	filter("platforms:x86")
		libdirs({"../sourcesdk-minimal/lib/public"})

	filter("platforms:x86_64")
		libdirs({"../sourcesdk-minimal/lib/public/x64"})

	filter({})

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
		"../ivp/havana/havok/hk_physics",
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
		"vphysics_saverestore.cpp"
	})
	vpaths({["Source files/*"] = "*.cpp"})
	
	filter({"platforms:x86","system:windows"})
		defines({"COMPILER_MSVC32","WIN32"})

	filter({"platforms:x86_64","system:windows"})
		defines({"COMPILER_MSVC64","WIN32","WIN64"})

	filter("system:linux")
		defines({"_LIB", "LINUX"})
		buildoptions { "-fpic", "-fno-semantic-interposition" }

	filter({})

	IncludeIVP_hk_base()
	IncludeIVP_hk_math()
	IncludeIVPPhysics()
	IncludeIVP_havana_constraints()
	IncludeIVPCompactBuilder()
	IncludeSDKInterfaces()
	IncludeSDKTier0()
	IncludeSDKTier1()
	--IncludeSDKTier2()
	IncludeSDKMathlib()
	--IncludeSDKvstdlib()

	filter("system:windows")
		debuggertype("NativeOnly")

	filter({"system:windows","platforms:x86"})
		debugcommand('cp -f --reply=yes D:/UserFiles/repos/gmod_better_vphysics/projects/windows/vs2019/x86/Debug/vphysics.dll C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/bin && C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/bin/gmod.exe')