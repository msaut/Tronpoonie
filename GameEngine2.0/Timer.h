#pragma once
class Timer
{
public:
	Timer();
	~Timer();
	void Start();
	double Tick();
	int GetFrameCount();
	void SetTimer(double timePeriod, void(*timerCallback)(int));
private:
	double QueryCurrentTime();

	double m_startTime;
	double m_lastTimeStamp;
	int m_frameCount;
	double m_timePeriod;
	double m_frequency;
	void (*m_timerCallback)(int);
};

