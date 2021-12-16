local current_dir = _SCRIPT_DIR

function IncludeIVP_havana_constraints()
	local refcount = IncludePackage("ivp_havana_constraints")

	local _project = project()

	sysincludedirs(current_dir .. "/../")
	links({"havana_constraints"})

	if refcount == 1 then
		dofile(current_dir .. "/premake5_create_project.lua")
	end

	project(_project.name)
end
