#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <chrono>

namespace Debug{
    using std::cout;
    using std::endl;

    struct Clock{
    private:
        static std::chrono::high_resolution_clock clk;
        std::chrono::time_point<std::chrono::high_resolution_clock> record;
    public:
        void begin();
        
        // Returns the time elapsed in seconds
        double end();
    };
};

#endif

