#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

enum Day { MORNING, DAY, EVENING };
enum TypeOFStop { ENDL, NONENDL };

class BusStop
{
private:
	Day day_time;
	TypeOFStop bus_stop_type;
	const int time_period = 360;
	double average_sum;
	int average_count;

	int* passengers_time;
	int passenger_morning_time;
	int passenger_event_time;
	int passenger_day_time;
	int passenger_count;
	int passenger_time_count;

	int* buses_time;
	int bus_morning_time;
	int bus_event_time;
	int bus_day_time;
	int seats_count;
	int free_seats;
	int bus_time_count;

public:
	BusStop() = delete;

	BusStop(TypeOFStop bus_stop_type, int passenger_morning_time, int passenger_day_time, int passenger_event_time, int bus_morning_time, int bus_day_time, int bus_event_time, int seats_count)
	{
		this->bus_stop_type = bus_stop_type;
		this->passenger_day_time = passenger_day_time;
		this->passenger_event_time = passenger_event_time;
		this->passenger_morning_time = passenger_morning_time;
		this->bus_day_time = bus_day_time;
		this->bus_event_time = bus_event_time;
		this->bus_morning_time = bus_morning_time;
		this->seats_count = seats_count;
	}

	bool isBusFull()const
	{
		return free_seats == 0;
	}

	void clearPassengerTime()
	{
		delete[] passengers_time;
	}

	void clearBusesTime()
	{
		delete[] buses_time;
	}

	int getAverageFreeSeats()
	{
		int sum = 0;

		for (int i = 1; i <= seats_count; i++)
		{
			sum += i;
		}

		return sum / seats_count;
	}

	void getAllTimeOfPassengersInBusStopInPeriod(Day day_time)
	{
		int time = 0;

		switch (day_time)
		{
		case MORNING: time = passenger_morning_time;
			break;
		case DAY: time = passenger_day_time;
			break;
		case EVENING: time = passenger_event_time;
			break;
		}

		passenger_time_count = time_period / time;

		if (passengers_time != nullptr) clearPassengerTime();

		passengers_time = new int[passenger_time_count];

		for (int i = 0; i < passenger_time_count; i++)
		{
			passengers_time[i] = time;
		}
	}

	void getAllTimeOfBusesRideInPeriod(Day day_time)
	{
		int time = 0;

		switch (day_time)
		{
		case MORNING: time = bus_morning_time;
			break;
		case DAY: time = bus_day_time;
			break;
		case EVENING: time = bus_event_time;
			break;
		}

		bus_time_count = time_period / time;

		if (buses_time != nullptr) clearBusesTime();

		buses_time = new int[bus_time_count];

		for (int i = 0; i < bus_time_count; i++)
		{
			buses_time[i] = time;
		}
	}

	double getAverageTimeOfPassengerInBusStopInPeriod(Day day_time)
	{
		getAllTimeOfPassengersInBusStopInPeriod(day_time);
		getAllTimeOfBusesRideInPeriod(day_time);

		average_sum = 0.0;
		average_count = 0;

		int time_pas = 0;
		int time_bus = 0;

		switch (day_time)
		{
		case MORNING:
			time_pas = passenger_morning_time;
			time_bus = bus_morning_time;
			break;
		case DAY:
			time_pas = passenger_morning_time;
			time_bus = bus_day_time;
			break;
		case EVENING:
			time_pas = passenger_event_time;
			time_bus = bus_event_time;
			break;
		}

		srand(time(NULL));

		for (int i = 1; i <= time_period; i++)
		{
			if (i % time_pas == 0)
			{
				passenger_count++;
				average_count++;
				average_sum += time_pas;
			}
			if (i % time_bus == 0)
			{
				switch (bus_stop_type)
				{
				case ENDL: free_seats = seats_count;
					break;
				case NONENDL: free_seats = rand() % seats_count;
					break;
				}

				if (passenger_count <= free_seats)
				{
					passenger_count = 0;
				}
				else
				{
					passenger_count = passenger_count - free_seats;
					average_sum += (time_pas * passenger_count);
				}
			}
		}

		return (double)(average_sum / average_count);
	}

	double getAverageTimeOfPassengerInBusStopAllDay()
	{
		return (getAverageTimeOfPassengerInBusStopInPeriod(DAY) + getAverageTimeOfPassengerInBusStopInPeriod(MORNING) + getAverageTimeOfPassengerInBusStopInPeriod(EVENING)) / 3;
	}

	double getAverageTimeBetweenBusesInTime(int pas_count, Day day_time)
	{
		double average_time = 0;

		switch (bus_stop_type)
		{
		case ENDL: free_seats = seats_count;
			break;
		case NONENDL: free_seats = getAverageFreeSeats();
			break;
		}

		double time = 0;

		switch (day_time)
		{
		case MORNING: time = getAverageTimeOfPassengerInBusStopInPeriod(MORNING);
			break;
		case DAY: time = getAverageTimeOfPassengerInBusStopInPeriod(DAY);
			break;
		case EVENING: time = getAverageTimeOfPassengerInBusStopInPeriod(EVENING);
			break;
		}

		for (int i = 0; i < pas_count; i++)
		{
			average_time += time;
		}

		return (average_time + time) / 2;
	}

	double getAverageTimeBetweenBusesInDay(int pas_count)
	{
		double average_time = 0;

		switch (bus_stop_type)
		{
		case ENDL: free_seats = seats_count;
			break;
		case NONENDL: free_seats = getAverageFreeSeats();
			break;
		}

		double time = getAverageTimeOfPassengerInBusStopAllDay();

		for (int i = 0; i < pas_count; i++)
		{
			average_time += time;
		}

		return (average_time + time) / 2;
	}

	~BusStop()
	{
		if (passengers_time != nullptr)
			delete[] passengers_time;

		if (buses_time != nullptr)
			delete[] buses_time;
	}

};


void main()
{
	BusStop b(NONENDL, 1, 5, 2, 10, 20, 15, 30);

	cout << "Average time in the motning: " << b.getAverageTimeOfPassengerInBusStopInPeriod(MORNING) << endl;

	cout << "Average time in the afternoon: " << b.getAverageTimeOfPassengerInBusStopInPeriod(DAY) << endl;

	cout << "Average time in the evening: " << b.getAverageTimeOfPassengerInBusStopInPeriod(EVENING) << endl;

	cout << "Average time in all day: " << b.getAverageTimeOfPassengerInBusStopAllDay() << endl;

	cout << "Average time between buses in the morning: " << b.getAverageTimeBetweenBusesInTime(5, MORNING) << endl;

	cout << "Average time between buses in the afternoon: " << b.getAverageTimeBetweenBusesInTime(5, DAY) << endl;

	cout << "Average time between buses in the evening: " << b.getAverageTimeBetweenBusesInTime(5, EVENING) << endl;

	cout << "Average time between buses in the all day: " << b.getAverageTimeBetweenBusesInDay(5) << endl;
}

