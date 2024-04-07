#include "log.h"
void Debug::Clock::begin()
{
    this->record = clk.now();
}

double Debug::Clock::end()
{
    return std::chrono::duration<double>(clk.now() - this->record).count();
}