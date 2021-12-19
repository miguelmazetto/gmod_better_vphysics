local testserver = _SCRIPT_DIR .. "/../testserver"
local sdklibs = _SCRIPT_DIR .. "/../sourcesdk-minimal/lib/public"

project("vphysics")
	_project = project()
	_project.serverside = true
	kind("SharedLib")
	language("C++")
	warnings("Default")
	location("../projects/" .. os.target() .. "/" .. _ACTION)
	
	--libdirs({
	--	"../ivp/projects/" .. os.target() .. "/" .. _ACTION
	--})

	filter({"system:linux","platforms:x86"})
		libdirs({sdklibs.."/linux32"})

	filter({"system:linux","platforms:x86_64"})
		libdirs({sdklibs.."/linux64"})

	--filter("platforms:x86")
	--	libdirs({sdklibs})

	--filter("platforms:x86_64")
	--	libdirs({sdklibs.."/x64"})

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
		"vphysics_saverestore.cpp",
		"*.h"
	})
	vpaths({["Source files/*"] = {"*.cpp","../sourcesdk-minimal/public/filesystem_helpers.cpp"}})
	vpaths({["Header files/*"] = "*.h"})

	filter("system:windows")
		debuggertype("NativeOnly")

	filter({"platforms:x86","system:windows"})
		defines({"COMPILER_MSVC32","WIN32"})

	filter({"platforms:x86_64","system:windows"})
		defines({"COMPILER_MSVC64","WIN32","WIN64"})

	filter("system:linux")
		defines({"_LIB", "LINUX"})
		buildoptions { "-fpic", "-fno-semantic-interposition" }
		links({"pthread","dl"})

	filter({"platforms:x86_64","system:linux"})
		buildoptions { "-march=native" }

	--Debug
	if os.isdir(testserver) then
		filter({"platforms:x86","system:windows"})
			postbuildcommands({"{COPY} %{cfg.targetdir}/vphysics.dll "..testserver.."/bin"})
			debugcommand(testserver.."/srcds.exe")

		filter({"platforms:x86_64","system:windows"})
			postbuildcommands({"{COPY} %{cfg.targetdir}/vphysics.dll "..testserver.."/bin/win64"})
			debugcommand(testserver.."/srcds_win64.exe")

		filter({"platforms:x86","system:linux"})
			postbuildcommands({"{COPY} %{cfg.targetdir}/vphysics.so "..testserver.."/bin/linux32"})
	end

	filter({})
	debugargs({"-nomaster","-debug","-console","-dev","+gamemode sandbox","+map gm_flatgrass"})

	--although this will not matter in windows, the order of these is important for linux
	IncludeSDKInterfaces()
	IncludeSDKTier0()
	IncludeSDKTier1()
	IncludeSDKMathlib()
	IncludeIVPCompactBuilder()
	IncludeIVP_havana_constraints()
	IncludeIVPPhysics()
	IncludeIVP_hk_math()
	IncludeIVP_hk_base()
--
	--filter({"system:windows","platforms:x86"})

	--	debugcommand('cp -f --reply=yes D:/UserFiles/repos/gmod_better_vphysics/projects/windows/vs2019/x86/Debug/vphysics.dll C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/bin && C:/Program Files (x86)/Steam/steamapps/common/GarrysMod/bin/gmod.exe')