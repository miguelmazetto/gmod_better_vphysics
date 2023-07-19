if _ACTION == 'clean' then
	os.rmdir('projects')
	os.rmdir('ivp/projects')

	if os.ishost("windows") then
		os.remove('*.sln')
		os.remove('*.vcxproj')
	end

	return
end

if not externalincludedirs then
	externalincludedirs = includedirs
end

include("sourcesdk-minimal")
include("extrasdk")
include("ivp/havana/havok/hk_base")
include("ivp/havana/havok/hk_math")
include("ivp/havana/havok/hk_physics/constraint")
include("ivp/ivp_compact_builder")
include("ivp/ivp_physics")

function HasIncludedPackage(name)
	local _project = project()
	_project.packages = _project.packages or {}
	return _project.packages[name] == true
end

function IncludePackage(name)
	assert(not HasIncludedPackage(name), "a package with the name '" .. name .. "' already exists!")

	local _project = project()
	local _workspace = _project.workspace

	_project.packages[name] = true

	if _workspace.packages == nil then
		_workspace.packages = {}
	end

	local refcount = (_workspace.packages[name] or 0) + 1
	_workspace.packages[name] = refcount
	return refcount
end

-- Compile blaze include files
--if not os.isdir(_MAIN_SCRIPT_DIR .. "/blaze/include") then
--	local blazedir = _MAIN_SCRIPT_DIR.."/blaze"
--	local fblazedir = '"'..blazedir..'"'
--	local builddir = '"'..blazedir..'/build"'
--
--	os.execute('cmake -B '..builddir..' -S '..fblazedir..' -DUSE_LAPACK=OFF')
--	os.execute("cmake --install "..builddir.." --prefix "..fblazedir)
--end

if not os.isdir(_MAIN_SCRIPT_DIR .. "/eigen/include") then
	local eigendir = _MAIN_SCRIPT_DIR.."/eigen"
	local feigendir = '"'..eigendir..'"'
	local builddir = '"'..eigendir..'/build"'
	os.execute('cmake -B '..builddir..' -S '..eigendir..' -DCMAKE_INSTALL_PREFIX:PATH='..feigendir)
	os.execute("cmake --build "..builddir.." --target install")
end

workspace("gmod_better_vphysics")
	language("C++")
	warnings("Extra")

	flags({
		"MultiProcessorCompile", 
		"ShadowedVariables",
		"UndefinedIdentifiers",
		"EnableSSE2",
		"FloatFast",
		--"LinkTimeOptimization"
	})

	characterset("MBCS")
	intrinsics("On")
	inlining("Auto")
	rtti("On")
	vectorextensions("SSE2")
	targetprefix("")
	--toolset "clang"

	configurations({"Debug", "ReleaseWithSymbols", "Release"})
	targetdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
	debugdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
	objdir("!%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}/intermediate/%{prj.name}")
	includedirs({ "sourcesdk-minimal/public", "eigen/include/eigen3", "libs" })

	platforms({"x86_64", "x86"})
	defines({"VPROF_TELEMETRY_H"})

	filter("platforms:x86")
		architecture("x86")
		libdirs({"sourcesdk-minimal/lib/public"})
		defines({"_X86_", "_M_IX86"})

	filter("platforms:x86_64")
		architecture("x86_64")
		libdirs({"sourcesdk-minimal/lib/public/x64"})
		defines({"_AMD64_","PLATFORM_64BITS"})

	filter({"platforms:x86","system:windows"})
		defines({"COMPILER_MSVC32","WIN32"})

	filter({"platforms:x86_64","system:windows"})
		defines({"COMPILER_MSVC64","WIN64"})

	filter("configurations:ReleaseWithSymbols")
		optimize("Speed")
		symbols("Full")
		defines("NDEBUG")
		runtime("Release")

	filter("configurations:Release")
		flags("LinkTimeOptimization")
		optimize("Speed")
		symbols("Off")
		defines("NDEBUG")
		runtime("Release")

	filter("configurations:Debug")
		optimize("Off")
		symbols("On")
		defines({"DEBUG", "_DEBUG"})
		runtime("Debug")

	filter("system:windows")
		cdialect("C11")
		cppdialect("C++17")
		staticruntime("On")
		defaultplatform("x86")
		defines({
			"_CRT_NONSTDC_NO_WARNINGS",
			"_CRT_SECURE_NO_WARNINGS",
			"STRICT",
			"COMPILER_MSVC"
		})

	filter("system:linux")
		cdialect("GNU11")
		cppdialect("GNU++17")
		staticruntime("Off")
		defaultplatform("x86")
		linkoptions("-Wl,--no-undefined")
		defines({ "LINUX", "_LINUX", "COMPILER_GCC", "POSIX" })
		--undefines({"COMPILER_MSVC32"})
		--links({"dl"})

	filter("files:**.cpp or **.cxx or **.cc")
		strictaliasing("Level3")

	filter({"kind:StaticLib","system:linux"})
		buildoptions { "-fpic", "-fno-semantic-interposition" }
		
	filter({})

	include("vphysics")
	
workspace("gmod_better_vphysics")

	startproject("vphysics")