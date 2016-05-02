#include "Timer.h"
#include <Windows.h>


Timer::Timer()
{
	m_timerCallback = 0;
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	m_frequency = static_cast<double>(frequency.QuadPart);
}


Timer::~Timer()
{
}

void Timer::Start()
{
	m_lastTimeStamp = QueryCurrentTime();
	m_startTime = m_lastTimeStamp;
	m_frameCount = 0;
}

double Timer::Tick()
{
	double currentTime = QueryCurrentTime();
	double deltaTime = (currentTime - m_lastTimeStamp) / 1000000.0;
	m_lastTimeStamp = currentTime;
	m_frameCount++;
	if (m_timerCallback != NULL && (((currentTime - m_startTime) * 1000000) / m_frequency) >= m_timePeriod)
	{
		m_timerCallback(m_frameCount);
		m_startTime = currentTime;
		m_frameCount = 0;
	}
	return deltaTime;
}

int Timer::GetFrameCount()
{
	int result = m_frameCount;
	m_frameCount = 0;
	return result;
}

void Timer::SetTimer(double timePeriod, void(*timerCallback)(int))
{

	m_timePeriod = timePeriod * 1000000.0;
	m_timerCallback = timerCallback;
}

double Timer::QueryCurrentTime()
{
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	return static_cast<double>(time.QuadPart);
}

