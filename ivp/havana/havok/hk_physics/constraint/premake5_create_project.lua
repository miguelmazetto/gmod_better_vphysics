group("IVP")
	project("havana_constraints")
		kind("StaticLib")
		warnings("Default")
		location("../../../../projects/" .. os.target() .. "/" .. _ACTION)
		targetdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
		debugdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
		objdir("!%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}/intermediate/%{prj.name}")
		sysincludedirs({
			"../..",
			"../../../..",
			"../../../../ivp_physics",
			"../../../../ivp_utility",
			"../../../../ivp_controller"
		})
		files({
			"constraint.cpp",
			"ball_socket/ball_socket_constraint.cpp",
			"limited_ball_socket/limited_ball_socket_constraint.cpp",
			"ragdoll/ragdoll_constraint.cpp",
			"ragdoll/ragdoll_constraint_bp_builder.cpp",
			"hinge/hinge_constraint.cpp",
			"hinge/hinge_bp_builder.cpp",
			"breakable_constraint/breakable_constraint.cpp",
			"fixed/fixed_constraint.cpp",
			"prismatic/prismatic_constraint.cpp",
			"pulley/pulley_constraint.cpp",
			"stiff_spring/stiff_spring_constraint.cpp",
			"local_constraint_system/local_constraint_system.cpp",
			"../core/rigid_body_core.cpp",
			"../effector/rigid_body_binary_effector.cpp"
		})
		vpaths({["Source files/*"] = "**.cpp"})

		filter { "files:ragdoll/ragdoll_constraint_bp_builder.cpp" }
			optimize "Size"

		filter("system:linux")
			defines({"_LIB", "LINUX"})
			buildoptions { "-fpic", "-fno-semantic-interposition" }