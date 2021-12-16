local current_dir = _SCRIPT_DIR

function IncludeIVP_hk_math()
	local refcount = IncludePackage("ivp_hk_math")

	local _project = project()

	sysincludedirs(current_dir .. "/../")
	links({"hk_math"})

	if refcount == 1 then
		dofile(current_dir .. "/premake5_create_project.lua")
	end

	project(_project.name)
end
