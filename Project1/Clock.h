// this is intended to keep track of all game time
// notes:
// 12 months = 1 year
// 4 weeks = 1 month
// 7 days = 1 week
// 24 hours = 1 day
// 60 minutes = 1 hour
// 60 seconds = 1 minute
// these numbers are exact, unlike earth
// so 336 days a year (may change? 30 days a month would be 360, but 30 !/ 7 ...)
// week starts on a monday

#include <iostream>
#include <string>

using namespace std;

class Clock {
public:
	Clock();
	Clock(int sec, int min, int hour);
	void IncrementTimeSec();
	void IncrementTimeSec(int secs = 1);
	void OutputTime();
	
private:
	string MonthName();
	string DayName();

	int m_Seconds;
	int m_Minutes;
	int m_Hours;
	int m_Days;
	int m_Month;
	int m_Year;
	int m_WeekDay;
	int m_Week;
};

Clock::Clock(){
	m_Seconds = 0;
	m_Minutes = 0;
	m_Hours = 8;
	m_Days = 1;
	m_Month = 1;
	m_Year = 2020;
	m_WeekDay = 1;
	m_Week = 1;
}

Clock::Clock(int sec, int min, int hour){

}

void Clock::IncrementTimeSec(){
	m_Seconds += 1;
	while (m_Seconds >= 60){
		m_Seconds -= 60;
		m_Minutes += 1;
	}
	while (m_Minutes >= 60){
		m_Minutes -= 60;
		m_Hours += 1;
	}
	while (m_Hours >= 24){
		m_Hours -= 24;
		m_Days += 1;
		m_WeekDay += 1;
	}
	while (m_WeekDay >= 8){
		m_WeekDay -= 7;
		m_Week += 1;
	}
	while (m_Days >= 31){
		m_Week = 1;
		m_Days -= 30;
		m_Month += 1;
	}
	while (m_Month >= 13){
		m_Month -= 12;
		m_Year += 1;
	}
}

void Clock::IncrementTimeSec(int secs){
	m_Seconds += secs;
	while (m_Seconds >= 60){
		m_Seconds -= 60;
		m_Minutes += 1;
	}
	while (m_Minutes >= 60){
		m_Minutes -= 60;
		m_Hours += 1;
	}
	while (m_Hours >= 24){
		m_Hours -= 24;
		m_Days += 1;
		m_WeekDay += 1;
	}
	while (m_WeekDay >= 8){
		m_WeekDay -= 7;
		m_Week += 1;
	}
	while (m_Days >= 31){
		m_Week = 1;
		m_Days -= 30;
		m_Month += 1;
	}
	while (m_Month >= 13){
		m_Month -= 12;
		m_Year += 1;
	}
}

string Clock::MonthName(){
	if (m_Month == 1){
		return "January";
	}
	else if (m_Month == 2){
		return "February";
	}
	else if (m_Month == 3){
		return "March";
	}
	else if (m_Month == 4){
		return "April";
	}
	else if (m_Month == 5){
		return "May";
	}
	else if (m_Month == 6){
		return "June";
	}
	else if (m_Month == 7){
		return "July";
	}
	else if (m_Month == 8){
		return "August";
	}
	else if (m_Month == 9){
		return "September";
	}
	else if (m_Month == 10){
		return "October";
	}
	else if (m_Month == 11){
		return "November";
	}
	else if (m_Month == 12){
		return "December";
	}
	else{
		return "invalid";
	}
}

string Clock::DayName() {
	if (m_WeekDay == 1){
		return "Monday";
	}
	else if (m_WeekDay == 2){
		return "Tuesday";
	}
	else if (m_WeekDay == 3){
		return "Wednesday";
	}
	else if (m_WeekDay == 4){
		return "Thursday";
	}
	else if (m_WeekDay == 5){
		return "Friday";
	}
	else if (m_WeekDay == 6){
		return "Saturday";
	}
	else if (m_WeekDay == 7){
		return "Sunday";
	}
	else{
		return "invalid";
	}
}

void Clock::OutputTime() {
	cout << "The time is " << m_Hours << ":" << m_Minutes << ":" << m_Seconds << endl;
	cout << "The date is " << MonthName() << " " << m_Days << ", " << m_Year << endl;
	cout << "It's " << DayName() << " of the " << m_Week << " week" << endl;
}