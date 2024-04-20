#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>


template <template <typename ...> typename Container, typename T>
void print_container(std::ostream& os, const Container<T>& cont) {
    bool is_first = true;
    for(const T& elem : cont) {
        if (is_first) {
            os << elem;
            is_first = false;
            continue;
        }
        os << ", " << elem;
    }
    os << std::endl;
}

int main() {
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(std::cout, test_set); // four one three two. помните почему такой порядок? :)

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(std::cout, test_list); // one, two, three, four

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(std::cout,test_vector); // one, two, three, four
    return 0;
}
