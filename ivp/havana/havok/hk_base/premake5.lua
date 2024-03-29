local current_dir = _SCRIPT_DIR

function IncludeIVP_hk_base()
	local refcount = IncludePackage("ivp_hk_base")

	local _project = project()

	includedirs(current_dir .. "/../")
	links({"hk_base"})

	if refcount == 1 then
		dofile(current_dir .. "/premake5_create_project.lua")
	end

	project(_project.name)
end
