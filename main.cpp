#include <iostream>
#include <vector>

#include "vector.hpp"


int main() {
    pic::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "Test 1: Adding elements to the vector using push_back.\n";
    for (auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << std::endl;
    }

    pic::vector<int> vec2 = vec;
    vec2.push_back(5);
    vec2.push_back(6);
    vec2.push_back(7);

    std::cout << "\nTest 2: Copying the vector and adding new elements.\n";
    for (auto it = vec2.begin(); it != vec2.end(); it++) {
        std::cout << *it << std::endl;
    }

    pic::vector<int> vec3;
    vec3 = vec2;
    std::cout << "\nTest 3: Assigning one vector to another and printing elements in reverse order.\n";
    for (auto it = vec3.begin(); it != vec3.end(); it++) {
        std::cout << *it << std::endl;
    }

    pic::vector<int> vec4 = std::move(vec3);
    vec4.pop_back();
    vec4.pop_back();
    std::cout << "\nTest 4: Moving a vector and removing two elements from the moved vector.\n";
    for (auto it = vec4.begin(); it != vec4.end(); it++) {
        std::cout << *it << std::endl;
    }

    pic::vector<int> vec5;
    vec5 = std::move(vec4);

    std::cout << "\nTest 5: Moving another vector and resizing it to 10.\n";
    vec5.resize(10);
    for (auto it = vec5.begin(); it != vec5.end(); it++) {
        std::cout << *it << std::endl;
    }

    std::cout << "\nTest 6: Resizing the vector to size 5.\n";
    vec5.resize(5);
    for (auto it = vec5.begin(); it != vec5.end(); it++) {
        std::cout << *it << std::endl;
    }

    std::cout << "\nTest 7: Resizing the vector to size 12 and filling new elements with 12.\n";
    vec5.resize(12, 12);
    for (auto it = vec5.begin(); it != vec5.end(); it++) {
        std::cout << *it << std::endl;
    }

    std::cout << "\nTest 8: Checking size and capacity of the vector.\n";
    std::cout << vec5.size() << std::endl;
    std::cout << vec5.capacity() << std::endl;

    std::cout << "\nTest 9: Accessing an element at a specific index.\n";
    std::cout << vec5.at(4) << std::endl;
    for (int i = 0; i < vec5.size(); i++) {
        std::cout << vec5[i] << std::endl;
    }

    std::cout << "\nTest 10: Checking if the vector is empty.\n";
    std::cout << (vec5.empty() ? "Yes" : "No") << std::endl;

    std::cout << "\nTest 11: Accessing the front and back elements of the vector.\n";
    std::cout << vec5.front() << std::endl;
    std::cout << vec5.back() << std::endl;

    pic::vector<int> vec6;
    vec6.assign(10, 14);

    std::cout << "\nTest 12: Assigning a vector with 10 elements, each equal to 14.\n";
    for (auto it = vec6.begin(); it != vec6.end(); it++) {
        std::cout << *it << std::endl;
    }

    pic::vector<int> vec7 = {1, 2, 3, 4, 5};
    std::cout << "\nTest 13: Initializing vector with initializer list and printing elements in reverse order.\n";
    for (auto it = vec7.begin(); it != vec7.end(); it++) {
        std::cout << *it << std::endl;
    }

    vec7.reserve(10);
    std::cout << "\nTest 14: Reserving capacity for the vector and checking the capacity.\n";
    std::cout << vec7.capacity() << std::endl;

    vec7.shrink_to_fit();
    std::cout << "\nTest 15: Shrinking the vector to fit its current size and checking the capacity.\n";
    std::cout << vec7.capacity() << std::endl;

    pic::vector<int> vec8 = {1, 2, 3, 4, 5};
    pic::vector<int> vec9 = {-1, -2, -3, -4, -5};
    vec8.swap(vec9);
    std::cout << "\nTest 16: Swapping two vectors and printing their elements.\n";
    std::cout << "Vec8 (after swap):\n";
    for (auto it = vec8.begin(); it != vec8.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << "Vec9 (after swap):\n";
    for (auto it = vec9.begin(); it != vec9.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    pic::vector<int> vec10 = {1,2,3,4,5,6};
    vec10.insert(vec10.begin(), 2);
    for(auto x : vec10) {
        std::cout << x << std::endl;
    }
    std::cout << std::endl;
    vec10.insert(vec10.begin(), {1,2,3,4,5});
    for(auto x : vec10) {
        std::cout << x << std::endl;
    }

    std::cout << std::endl;

    vec10.erase(vec10.begin() + 1);
    for(auto x : vec10) {
        std::cout << x << std::endl;
    }

    std::cout << std::endl;

    vec10.erase(vec10.begin(), vec10.begin() + 1);
    for(auto x : vec10) {
        std::cout << x << std::endl;
    }

    return 0;
}
