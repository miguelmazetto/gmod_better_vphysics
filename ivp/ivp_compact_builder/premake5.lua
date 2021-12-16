local current_dir = _SCRIPT_DIR

function IncludeIVPCompactBuilder()
	local refcount = IncludePackage("ivp_compact_builder")

	local _project = project()

	--sysincludedirs(current_dir .. "/../public/mathlib")
	links("ivp_compact_builder")

	if refcount == 1 then
		dofile(current_dir .. "/premake5_create_project.lua")
		project(_project.name)
	end
end