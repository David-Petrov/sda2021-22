#include <algorithm>
#include <cstdio>
#include <iostream>

struct DateTime {
    static unsigned int ID;
    unsigned int id;
    short year, month, day, hour, minute, second;

    DateTime() : id(ID++) {
        scanf("%hd:%hd:%hd %hd.%hd.%hd",
        &this->hour, &this->minute, &this->second,
        &this->day, &this->month, &this->year);
    }
};
unsigned int DateTime::ID = 1;

int main() {
    size_t n;
    std::cin >> n;

    DateTime *datetimes = new DateTime[n];

    std::sort(datetimes, datetimes + n, [](DateTime &dt1, DateTime &dt2){
        if (dt1.year < dt2.year) {
            return true;
        } else if (dt1.year > dt2.year) {
            return false;
        }

        if (dt1.month < dt2.month) {
            return true;
        } else if (dt1.month > dt2.month) {
            return false;
        }

        if (dt1.day < dt2.day) {
            return true;
        } else if (dt1.day > dt2.day) {
            return false;
        }

        if (dt1.hour < dt2.hour) {
            return true;
        } else if (dt1.hour > dt2.hour) {
            return false;
        }

        if (dt1.minute < dt2.minute) {
            return true;
        } else if (dt1.minute > dt2.minute) {
            return false;
        }

        if (dt1.second < dt2.second) {
            return true;
        } else if (dt1.second > dt2.second) {
            return false;
        }

        return dt1.id < dt2.id;
    });

    std::for_each(datetimes, datetimes + n, [](DateTime &dt){
        std::cout << dt.id << '\n';
    });

    delete[] datetimes;

    return 0;
}
