#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Clock_ {
private:
	int second;
	int minute;
	int hour;
public:
	//конструктор с параметрами по умолчанию
	Clock_(int h = 0, int m = 0, int s = 0) {
		setHour(h);
		setMinute(m);
		setSecond(s);
	}
	//сеттеры
	void setSecond(int s) {
		if (s >= 0 && s < 60) {
			second = s;
		}
		else {
			second = 0;
		}
	}
	void setMinute(int m) {
		if (m >= 0 && m < 60) {
			minute = m;
		}
		else {
			minute = 0;
		}
	}
	void setHour(int h) {
		if (h >= 0 && h < 24) {
			hour = h;
		}
		else {
			hour = 0;
		}
	}
	void setClock(int h, int m, int s) {
		setSecond(s);
		setMinute(m);
		setHour(h);
	}
	//геттеры
	int getSecond() { return second; }
	int getMinute() { return minute; }
	int getHour() { return hour; }
	void printClock() const {
		if (hour < 10)
			cout << "0";
		cout << hour << ":";
		if (minute < 10)
			cout << "0";
		cout << minute << ":";
		if (second < 10)
			cout << "0";
		cout << second;
	}
	void addSecond() {
		second++;
		if (second == 60) {
			second = 0;
			minute++;
			if (minute == 60) {
				minute = 0;
				hour++;
				if (hour == 24) {
					hour = 0;
				}
			}
		}
	}
	int getTotalSec() const {
		return this->hour * 3600 + this->minute * 60 + this->second;
	}
	Clock_& operator+=(const Clock_& obj) {
		int resSec = (this->getTotalSec() + obj.getTotalSec()) % 86400;
		this->hour = resSec / 3600;
		this->minute = (resSec - this->hour * 3600) / 60;
		this->second = resSec - this->hour * 3600 - this->minute * 60;
		return *this;
	}
	Clock_& operator-=(const Clock_& obj) {
		int resSec = (this->getTotalSec() - obj.getTotalSec()) % 86400;
		this->hour = resSec / 3600;
		this->minute = (resSec - this->hour * 3600) / 60;
		this->second = resSec - this->hour * 3600 - this->minute * 60;
		return *this;
	}
};
Clock_ operator+(const Clock_& a, const Clock_& b) {
	int resSec = (a.getTotalSec() + b.getTotalSec()) % 86400;
	int h = resSec / 3600;
	int m = (resSec - h * 3600) / 60;
	int s = resSec - h * 3600 - m * 60;
	return Clock_(h, m, s);
}

Clock_ operator-(const Clock_& a, const Clock_& b) {
	int resSec = (a.getTotalSec() - b.getTotalSec()) % 86400;
	int h = resSec / 3600;
	int m = (resSec - h * 3600) / 60;
	int s = resSec - h * 3600 - m * 60;
	return Clock_(h, m, s);
}

bool operator==(const Clock_& a, const Clock_& b) {
	return a.getTotalSec() == b.getTotalSec();
}

bool operator!=(const Clock_& a, const Clock_& b) {
	return !(a == b);
}

bool operator<=(const Clock_& a, const Clock_& b) {
	return a.getTotalSec() <= b.getTotalSec();
}

bool operator<(const Clock_& a, const Clock_& b) {
	return a.getTotalSec() < b.getTotalSec();
}

bool operator>=(const Clock_& a, const Clock_& b) {
	return a.getTotalSec() >= b.getTotalSec();
}

bool operator>(const Clock_& a, const Clock_& b) {
	return a.getTotalSec() > b.getTotalSec();
}

ostream& operator<<(ostream& out, const Clock_& obj) {
	obj.printClock();
	return out;
}

istream& operator>>(istream& in, Clock_& obj) {
	int h, m, s;
	cout << "\nEnter h, m, s" << endl;
	in >> h >> m >> s;
	obj.setClock(h, m, s);
	return in;
}

void main() {
	Clock_ a(15, 01, 15);
	Clock_ b(10, 02, 15);
	a += b;
	//a != b ? cout << "Yes" : cout << "No";
	cout << a;
	/*while (1)
	{
		system("cls");
		a.printClock();
		a.addSecond();
		Sleep(1000);
	}*/
}