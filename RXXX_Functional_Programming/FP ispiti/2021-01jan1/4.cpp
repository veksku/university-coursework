#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include <range/v3/view.hpp>
#include <range/v3/action.hpp>
#include <range/v3/algorithm.hpp>
// #include <range/v3/to_container.hpp>

#include <cassert>

using namespace ranges::v3;
namespace views = ranges::v3::view;
namespace actions = ranges::v3::action;


int main(int argc, char **argv)
{
    auto letters = 
            istream_range<char>(std::cin)
        |   to_vector
        ;
    
    auto list = 
            letters
        |   view::group_by(std::equal_to<>())
        |   view::transform([](auto group){
                    return std::to_string((distance(std::begin(group), std::end(group)))) +
                        *std::begin(group);
                    })   
        |   to_vector
        ;

    auto combined = std::accumulate(begin(list), end(list), 
            std::string(), std::plus<>());

    std::cout << combined << std::endl;
}