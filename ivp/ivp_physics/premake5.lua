local current_dir = _SCRIPT_DIR

function IncludeIVPPhysics()
	local refcount = IncludePackage("ivp_physics")

	local _project = project()

	--sysincludedirs(current_dir .. "/../public/mathlib")
	links("ivp_physics")

	if refcount == 1 then
		dofile(current_dir .. "/premake5_create_project.lua")
		project(_project.name)
	end
end