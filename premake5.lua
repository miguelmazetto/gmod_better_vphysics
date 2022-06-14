include("sourcesdk-minimal")
include("extrasdk")
include("ivp/havana/havok/hk_base")
include("ivp/havana/havok/hk_math")
include("ivp/havana/havok/hk_physics/constraint")
include("ivp/ivp_compact_builder")
include("ivp/ivp_physics")
--include("vstdlib")

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


workspace("gmod_better_vphysics")
	language("C++")
	warnings("Extra")
	flags({"MultiProcessorCompile", "ShadowedVariables", "UndefinedIdentifiers"})
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
	sysincludedirs({"sourcesdk-minimal/public"})

	platforms({"x86_64", "x86"})

	filter("platforms:x86")
		architecture("x86")
		libdirs({"sourcesdk-minimal/lib/public"})
		defines({"_X86_"})

	filter("platforms:x86_64")
		architecture("x86_64")
		libdirs({"sourcesdk-minimal/lib/public/x64"})
		defines({"_AMD64_","PLATFORM_64BITS"})

	filter({"platforms:x86","system:windows"})
		defines({"COMPILER_MSVC32","WIN32"})

	filter({"platforms:x86_64","system:windows"})
		defines({"COMPILER_MSVC64","WIN64"})

	filter("configurations:ReleaseWithSymbols")
		optimize("Debug")
		symbols("On")
		defines("NDEBUG")
		runtime("Release")

	filter("configurations:Release")
		flags("LinkTimeOptimization")
		optimize("Full")
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
		cppdialect("C++14")
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