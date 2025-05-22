#include <iostream>
#include <vector>
#include <functional>

template<typename T>
std::vector<T> Filter(const std::vector<T>& vec, std::function<bool(const T&)> comp) {
    std::vector<T> res;

    for (size_t i = 0; i < vec.size(); ++i) {
        if (comp(vec[i])) {
            res.push_back(vec[i]);
        }
    }

    return res;
}

template<typename T>
std::vector<T> FilterNonZero(const std::vector<T>& vec) {
    return Filter<T>(vec, [](T x) { return x != 0; });
}

int main() {
    std::vector<int> data = { 0, 1, 4, 5 ,0, 9, 2332 };

    data = FilterNonZero(data);

    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }

    std::cout << "\n";

    return 0;
}
