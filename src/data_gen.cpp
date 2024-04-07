#include "data_gen.h"
#include "log.h"


#include <random>

int data[N];

class Data_Gen{
    std::minstd_rand gen = std::minstd_rand(SEED);
    std::uniform_int_distribution<int> dist = std::uniform_int_distribution<int>(MIN_INT, MAX_INT);

public:
    int next()
    {
        return dist(gen);
    }
} data_gen;

void generate_data()
{
    using namespace Debug;
    cout << "Data generation started.\nN = " << N << '\n'
    << "Seed = " << SEED << '\n'
    << "Size = " << double(N * sizeof(int)) / 1024 / 1024 / 1024 << " GB" << endl;

    Clock clk; clk.begin();
    for (int i = 0; i < N; i++) {
        data[i] = data_gen.next();
    }
    cout << "Data generated in " << clk.end() << " seconds" << endl;
}