class hk_PSI_Info: protected IVP_Event_Sim {
public:
	hk_PSI_Info(const IVP_Event_Sim &sim) : IVP_Event_Sim(sim) {}

	IVP_DOUBLE get_inv_delta_time(){
		return i_delta_time;
	}

	IVP_DOUBLE get_delta_time(){
		return delta_time;
	}

};
