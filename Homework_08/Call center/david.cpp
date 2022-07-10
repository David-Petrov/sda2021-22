#include <cmath>
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

struct Operator { int index = 0, timeBusy = 0, calls = 0; };
struct Call { int opIndex, callTime, duration; };

struct OperatorBusier {
    bool operator()(const Operator& first, const Operator& second) const {
        return first.timeBusy > second.timeBusy;
    }
};

struct OperatorSmallerIndex {
    bool operator()(const Operator& first, const Operator& second) const {
        return first.index < second.index;
    }
};

set<Operator, OperatorSmallerIndex> freeOperators;
priority_queue<Operator, vector<Operator>, OperatorBusier> busyOperators;
set<int> mostCalled;
int mostCalls = 0;

void callOperator(const Call& call) {

    //check what operators are not busy anymore
    while (!busyOperators.empty() && busyOperators.top().timeBusy <= call.callTime) {
        freeOperators.emplace(busyOperators.top());
        busyOperators.pop();
    }

    //no operators, no service
    if (freeOperators.empty()) {
        return;
    }

    //first try to find the first free one with a bigger index
    auto it = freeOperators.lower_bound({ call.opIndex });

    //if there are none, start from the beginning
    if (it == freeOperators.end()) {
        it = freeOperators.begin();
    }

    //return the first free operator's index and mark him as busy
    Operator op = *it;
    freeOperators.erase(it);

    //register the call on the operator
    op.timeBusy = call.callTime + call.duration;
    ++op.calls;

    //and mark him as busy
    busyOperators.push(op);

    //maintain our set of most called
    int diff = op.calls - mostCalls;
    if (diff >= 0) {
        if (diff > 0) {
            mostCalled.clear();
            ++mostCalls;
        }
        
        mostCalled.emplace(op.index);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    //all operators are initially free
    for (int i = 0; i < k; ++i) {
        freeOperators.insert(Operator{i});
    }

    //execute all the calls
    Call call;
    for (int i = 0; i < n; ++i) {
        call.opIndex = i % k;
        cin >> call.callTime >> call.duration;
        callOperator(call);
    }

    //print the most called operators
    for (const auto& i : mostCalled) {
        cout << i << ' ';
    }

    return 0;
}
