#include <iostream>
#include <unordered_map>

template <typename K, typename V>
void add_remove_key(std::unordered_map<K, V> &map,
              const K &key,
              const bool &increment) {
    if (increment) {
        ++map.find(key)->second;
    } else {
        --map.find(key)->second;
    }
}

int main() {
    int n;
    std::cin >> n;

    int *keys = new int[n];

    std::unordered_map<int, int> map;

    for (int i = 0; i < n; i++) {
        std::cin >> keys[i];
    }

    int tempDoor;
    int brokenDoors = 0;
    for (int i = 0; i < n; i++) {
        // Read door
        std::cin >> tempDoor;
        // Fill with zeroes if missing
        map.emplace(tempDoor, 0);
        map.emplace(keys[i], 0);
        // Actually put appropriate key
        ::add_remove_key(map, keys[i], true);

        // If there is at least 1 key for this door -> remove key/no breaking
        if (map.at(tempDoor) > 0) {
            ::add_remove_key(map, tempDoor, false);
        } else {
            // Otherwise -> no key, break
            ++brokenDoors;
        }
    }

    std::cout << brokenDoors << std::endl;

    delete[] keys;

    return 0;
}
