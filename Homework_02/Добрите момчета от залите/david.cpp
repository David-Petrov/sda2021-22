#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class GoodBoyAtTheGym
{
private:
    size_t id;
    double di, ti;
    static size_t counter;

public:
    GoodBoyAtTheGym(double di, double ti)  : id(counter++), di(di), ti(ti) {}

    size_t getId() const
    {
        return id;
    }

    long double getWeightForTime() const
    {
        return di*di/ti;
    }
    
    bool moreEfficientThan(const GoodBoyAtTheGym& other) const
    {
        return getWeightForTime() > other.getWeightForTime() 
            || (getWeightForTime() == other.getWeightForTime() && di > other.di);
    }
    
    bool operator<(const GoodBoyAtTheGym& other) const 
    {
        return moreEfficientThan(other);
    }
};

size_t GoodBoyAtTheGym::counter = 1;

int main()
{
    size_t n;
    cin >> n;
    
    vector<GoodBoyAtTheGym> boys;
    boys.reserve(n);
    
    double di, ti;
    for(size_t i = 0; i < n; i++)
    {
        cin >> di >> ti;
        boys.push_back(GoodBoyAtTheGym(di, ti));
    }

    sort(boys.begin(), boys.end());

    for(const GoodBoyAtTheGym& boy : boys)
    {
        cout << boy.getId() << ' ';
    }
        
    return 0;
}