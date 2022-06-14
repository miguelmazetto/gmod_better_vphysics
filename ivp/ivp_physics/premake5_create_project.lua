group("IVP")
	project("ivp_physics")
		kind("StaticLib")
		warnings("Default")
		location("../projects/" .. os.target() .. "/" .. _ACTION)
		targetdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
		debugdir("%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}")
		objdir("!%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}/intermediate/%{prj.name}")
		sysincludedirs({
			"../havana/havok",
			".",
			"../ivp_utility",
			"../ivp_compact_builder",
			"../ivp_collision",
			"../ivp_controller",
			"../ivp_surface_manager",
			"../ivp_intern"
		})
		files({
--IVP_PHYSICS_SRC_DIR
			--"../ivp_collision/ivp_3d_solver.cxx",
			--"../ivp_collision/ivp_clustering_longrange.cxx",
			--"../ivp_collision/ivp_clustering_lrange_hash.cxx",
			--"../ivp_collision/ivp_clustering_visual_hash.cxx",
			--"../ivp_collision/ivp_clustering_visualizer.cxx",
			--"../ivp_collision/ivp_coll_del_root_mindist.cxx",
			--"../ivp_collision/ivp_collision_filter.cxx",
			--"../ivp_collision/ivp_compact_ledge.cxx",
			--"../ivp_collision/ivp_compact_ledge_solver.cxx",
			--"../ivp_collision/ivp_i_collision_vhash.cxx",
			--"../ivp_collision/ivp_mindist.cxx",
			--"../ivp_collision/ivp_mindist_debug.cxx",
			--"../ivp_collision/ivp_mindist_event.cxx",
			--"../ivp_collision/ivp_mindist_mcases.cxx",
			--"../ivp_collision/ivp_mindist_minimize.cxx",
			--"../ivp_collision/ivp_mindist_recursive.cxx",
			--"../ivp_collision/ivp_oo_watcher.cxx",
			--"../ivp_collision/ivp_range_manager.cxx",
			--"../ivp_collision/ivp_ray_solver.cxx",
			--"../ivp_collision/ivp_sphere_solver.cxx",
			"../ivp_collision/*.cxx",
			"../ivp_collision/*.hxx",
--IVP_INTERN_SRC_DIR
			--"../ivp_intern/ivp_ball.cxx",
			--"../ivp_intern/ivp_calc_next_psi_solver.cxx",
			--"../ivp_intern/ivp_controller_phantom.cxx",
			--"../ivp_intern/ivp_core.cxx",
			--"../ivp_intern/ivp_environment.cxx",
			--"../ivp_intern/ivp_friction.cxx",
			--"../ivp_intern/ivp_friction_gaps.cxx",
			--"../ivp_intern/ivp_great_matrix.cxx",
			--"../ivp_intern/ivp_hull_manager.cxx",
			--"../ivp_intern/ivp_i_friction_hash.cxx",
			--"../ivp_intern/ivp_impact.cxx",
			--"../ivp_intern/ivp_i_object_vhash.cxx",
			--"../ivp_intern/ivp_merge_core.cxx",
			--"../ivp_intern/ivp_mindist_friction.cxx",
			--"../ivp_intern/ivp_object_attach.cxx",
			--"../ivp_intern/ivp_object.cxx",
			--"../ivp_intern/ivp_physic.cxx",
			--"../ivp_intern/ivp_physic_private.cxx",
			--"../ivp_intern/ivp_polygon.cxx",
			--"../ivp_intern/ivp_sim_unit.cxx",
			--"../ivp_intern/ivp_solver_core_reaction.cxx",
			--"../ivp_intern/ivp_time.cxx",
			"../ivp_intern/*.cxx",
			"../ivp_intern/*.hxx",
--IVP_UTILITY_SRC_DIR
			--"../ivp_utility/ivu_active_value.cxx",
			--"../ivp_utility/ivu_bigvector.cxx",
			--"../ivp_utility/ivu_geometry.cxx",
			--"../ivp_utility/ivu_hash.cxx",
			--"../ivp_utility/ivu_linear.cxx",
			--"../ivp_utility/ivu_mapping.cxx",
			--"../ivp_utility/ivu_memory.cxx",
			--"../ivp_utility/ivu_min_hash.cxx",
			--"../ivp_utility/ivu_min_list.cxx",
			--"../ivp_utility/ivu_os_dep.cxx",
			--"../ivp_utility/ivu_quat.cxx",
			--"../ivp_utility/ivu_string.cxx",
			--"../ivp_utility/ivu_types.cxx",
			--"../ivp_utility/ivu_vector.cxx",
			--"../ivp_utility/ivu_vhash.cxx",
			"../ivp_utility/*.cxx",
			"../ivp_utility/*.hxx",
--IVP_PHYSICS_COL_SRC_DIR
			--"../ivp_physics/ivp_anomaly_manager.cxx",
			--"../ivp_physics/ivp_betterdebugmanager.cxx",
			--"../ivp_physics/ivp_betterstatisticsmanager.cxx",
			--"../ivp_physics/ivp_cache_object.cxx",
			--"../ivp_physics/ivp_liquid_surface_descript.cxx",
			--"../ivp_physics/ivp_material.cxx",
			--"../ivp_physics/ivp_performancecounter.cxx",
			--"../ivp_physics/ivp_stat_manager_cback_con.cxx",
			--"../ivp_physics/ivp_surface_manager.cxx",
			--"../ivp_physics/ivp_templates.cxx",
			"../ivp_physics/*.cxx",
			"../ivp_physics/*.hxx",
--IVP_SURFACE_MANAGER_SRC_DIR
			--"../ivp_surface_manager/ivp_compact_surface.cxx",
			--"../ivp_surface_manager/ivp_gridbuild_array.cxx",
			--"../ivp_surface_manager/ivp_surman_grid.cxx",
			--"../ivp_surface_manager/ivp_surman_polygon.cxx",
			"../ivp_surface_manager/*.cxx",
			"../ivp_surface_manager/*.hxx",
--IVP_CONTRO--LLER_SRC_DIR
			--"../ivp_controller/ivp_actuator.cxx",
			--"../ivp_controller/ivp_actuator_spring.cxx",
			--"../ivp_controller/ivp_buoyancy_solver.cxx",
			--"../ivp_controller/ivp_car_system.cxx",
			--"../ivp_controller/ivp_constraint_car.cxx",
			--"../ivp_controller/ivp_constraint.cxx",
			--"../ivp_controller/ivp_constraint_fixed_keyed.cxx",
			--"../ivp_controller/ivp_constraint_local.cxx",
			--"../ivp_controller/ivp_controller_buoyancy.cxx",
			--"../ivp_controller/ivp_controller_floating.cxx",
			--"../ivp_controller/ivp_controller_motion.cxx",
			--"../ivp_controller/ivp_controller_raycast_car.cxx",
			--"../ivp_controller/ivp_controller_stiff_spring.cxx",
			--"../ivp_controller/ivp_controller_world_frict.cxx",
			--"../ivp_controller/ivp_forcefield.cxx",
			--"../ivp_controller/ivp_multidimensional_interp.cxx",
			--"../ivp_controller/ivp_template_constraint.cxx"
			"../ivp_controller/*.cxx",
			"../ivp_controller/*.hxx"
		})
		vpaths({["Source files/ivp_utility/*"] = {"../ivp_utility/*.cxx"},
				["Source files/ivp_compact_builder/*"] = {"../ivp_compact_builder/*.cxx"},
				["Source files/ivp_collision/*"] = {"../ivp_collision/*.cxx"},
				["Source files/ivp_controller/*"] = {"../ivp_controller/*.cxx"},
				["Source files/ivp_surface_manager/*"] = {"../ivp_surface_manager/*.cxx"},
				["Source files/ivp_intern/*"] = {"../ivp_intern/*.cxx"},
				["Source files/ivp_physics/*"] = "*.cxx",
				
				["Header files/ivp_utility/*"] = {"../ivp_utility/*.hxx"},
				["Header files/ivp_compact_builder/*"] = {"../ivp_compact_builder/*.hxx"},
				["Header files/ivp_collision/*"] = {"../ivp_collision/*.hxx"},
				["Header files/ivp_controller/*"] = {"../ivp_controller/*.hxx"},
				["Header files/ivp_surface_manager/*"] = {"../ivp_surface_manager/*.hxx"},
				["Header files/ivp_intern/*"] = {"../ivp_intern/*.hxx"},
				["Header files/ivp_physics/*"] = "*.hxx"})

		--vpaths({["Source files/*"] = {"*.cxx","../ivp_utility","../ivp_compact_builder","../ivp_collision","../ivp_controller","../ivp_surface_manager","../ivp_intern"}})

		filter {
				"files:../ivp_collision/ivp_i_collision_vhash.cxx",
				"files:../ivp_collision/ivp_mindist.cxx",
				"files:../ivp_collision/ivp_mindist_event.cxx",
				"files:../ivp_collision/ivp_mindist_mcases.cxx",
				"files:../ivp_collision/ivp_mindist_minimize.cxx",
				"files:../ivp_collision/ivp_mindist_recursive.cxx",
				"files:../ivp_utility/ivu_geometry.cxx",
				"files:../ivp_utility/ivu_linear.cxx",
				"files:../ivp_physics/ivp_cache_object.cxx"
			}
			optimize "Off"

		filter("system:linux")
			defines({"_LIB", "LINUX"})
			buildoptions { "-fpic", "-fno-semantic-interposition" }