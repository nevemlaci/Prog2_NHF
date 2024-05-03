#include "Time.hpp"

namespace SGL2 {

	Time_t& Time() {
		static Time_t instance;
		return instance;
	}

	Time_t::Time_t() : m_DeltaTime(0.0) {

	}

	void Time_t::FrameStart() {
		auto diff = stdchr::duration_cast<delta_time_duration>(stdchr::high_resolution_clock::now() - this->m_FrameStart);
		m_DeltaTime = std::chrono::duration<double, std::nano>(diff).count();
		this->m_FrameStart = stdchr::high_resolution_clock::now();
	}

	
}
