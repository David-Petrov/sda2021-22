#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

typedef unsigned int IndexType;
typedef unsigned long long InputType;
typedef std::function<void(InputType&)> InputFuntionType;

const InputFuntionType inputFunction = [](InputType& elem) -> void {
    std::cin >> elem;
};

int main() {
    IndexType n, k;
    InputType result = 0;

    std::cin >> n >> k;

    std::map<InputType, IndexType> left, right;

    InputType* data = new InputType[n];

    // Input all data
    std::for_each(data, data + n, inputFunction);

    // Fill right torba
    std::for_each(data, data + n,
                  [&right](const InputType& elem) -> void { ++right[elem]; });

    // Start transferring elements from right to left torba
    std::for_each(data, data + n,
                  [&result, &left, &right, k](const InputType& elem) -> void {
                      // Remove current element from right torba (currently
                      // processing it)
                      --right[elem];

                      // If current element could be the `y` in (x, y, z),
                      // (y = x*k, i.e. y is divisible by k) -> Look for `x` and `z`
                      if (!(elem % k)) {
                          // If either the left or right torba doesn't contain
                          // the required number (y/k && y*k) then their count
                          // would be zero -> No triplets here,
                          // Otherwise -> The amount of y/k numbers in the left
                          // torba times the amount of y*k numbers in the right
                          // torba would give the number of (y/k, y, y*k)
                          // triplets for the given `y`
                          result += left[elem / k] * right[elem * k];
                      }

                      // Readd current element to left torba (finished
                      // processing it)
                      ++left[elem];
                  });

    // Print final result
    printf("%lld\n", result);

    delete[] data;

    return 0;
}
