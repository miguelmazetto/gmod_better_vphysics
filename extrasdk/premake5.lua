local current_dir = _SCRIPT_DIR

function IncludeSDKInterfaces()
	local refcount = IncludePackage("sourcesdk_interfaces")

	local _project = project()

	links({"interfaces"})

	if refcount == 1 then
		dofile(current_dir .. "/interfaces.lua")
	end

	project(_project.name)
end
