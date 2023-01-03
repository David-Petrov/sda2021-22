#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

typedef int IndexType;
typedef int InputType;
typedef std::stack<IndexType> IndexStack;
typedef std::function<void(InputType&)> InputFuntionType;
typedef std::function<void(IndexType&)> OutputFuntionType;
typedef std::function<void(const IndexType&)> IndexOperation;
typedef std::function<void(IndexStack&, IndexOperation)> StackDischarger;
typedef std::map<const InputType, IndexStack> MapType;
typedef std::map<const InputType, IndexStack>::iterator IteratorType;
typedef std::pair<const InputType, IndexStack> PairType;
typedef std::function<bool(const InputType&, const PairType&)> ComparatorType;

const InputFuntionType inputFunction = [](InputType& elem) -> void {
    std::cin >> elem;
};

const OutputFuntionType outputFunction = [](IndexType& elem) -> void {
    printf("%d ", elem);
};

IteratorType get_value_at_key_in_map(const InputType& value, MapType& map) {
    return map.emplace(value, std::stack<InputType> {}).first;
}

void empty_stack(IndexStack& stack, IndexOperation operation) {
    while (!stack.empty()) {
        operation(stack.top());
        stack.pop();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    IndexType n, k;
    std::cin >> n >> k;

    std::vector<InputType> input(n);
    std::for_each(input.begin(), input.end(), inputFunction);


    std::vector<InputType> results(n, -1);
    MapType entries;

    IteratorType runner, upper_bound;
    for (InputType currentIndex = n - 1; currentIndex >= 0; --currentIndex) {
        runner = ::get_value_at_key_in_map(input[currentIndex], entries);
        runner->second.push(currentIndex);

        upper_bound = entries.upper_bound(input[currentIndex] + k);

        ++runner;
        while (runner != upper_bound) {
            ::empty_stack(
                runner->second,
                [&results, currentIndex](const IndexType& index) -> void {
                    results[index] = currentIndex;
                });

            runner = entries.erase(runner);
        }
    }

    std::for_each(results.begin(), results.end(), outputFunction);

    return 0;
}
