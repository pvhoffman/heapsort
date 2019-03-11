#include <config.h>
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <functional>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/heapsort.h"

SCENARIO( "vectors can be sorted", "[vector]" ) 
{
    GIVEN( "A vector of 10000000 random integers" ) 
    {
        using namespace std;
        random_device rnd_device;
        // Specify the engine and distribution.
        mt19937 mersenne_engine {rnd_device()};  // Generates random integers
        uniform_int_distribution<int> dist {-10000000, 10000000};

        auto gen = [&dist, &mersenne_engine]()
        {
            return dist(mersenne_engine);
        };

        vector<int> vec(10000000);
        generate(begin(vec), end(vec), gen);

        WHEN("heapsort is applied")
        {
            ch4::heapsort hs;

            auto cs = hs.sort(vec);
            THEN("the container should be sorted")
            REQUIRE(is_sorted(begin(cs), end(cs)));
        }
    }
}


