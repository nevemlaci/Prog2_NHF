// Time.hpp

#ifndef __Time_H__
#define __Time_H__

#ifndef CPORTA //time is only relevant in a graphical environment
#include <chrono>

namespace stdchr = std::chrono;

namespace SGL2 {
	using delta_time_ratio = std::nano;
	using delta_time_duration = stdchr::duration<int64_t, delta_time_ratio>;
	
class Time_t {
	friend class Game_t;
	friend Time_t& Time();
public:

	double DeltaTime() const { return m_DeltaTime; }

	const double ratio = static_cast<double>(delta_time_ratio::den);
private:
	Time_t();
#undef delete //sorry memtrace but you are annoying and you define an operator as a macro
	Time_t(const Time_t&) = delete;
	Time_t& operator=(const Time_t&) = delete;

	double m_DeltaTime;
	stdchr::steady_clock::time_point m_FrameStart;
	void FrameStart();

};
	Time_t& Time();
}
#endif
#endif


