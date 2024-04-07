#include "log.h"
#include "data_gen.h"
#include "merge_sort.h"
#include "parallel_sort.h"
#include "parallel_config.h"
using namespace Debug;
void check()
{   
    for (int i = 0; i < N - 1; i++)
    {
        if (data[i] > data[i + 1])
        {
            cout << "Error: data[" << i << "] = " << data[i] << " > data[" << i + 1 << "] = " << data[i + 1] << endl;
            return;
        }
    }
    cout << "Check passed" << endl;
}

int main()
{
    generate_data();

    cout << "Single-thread merge_sort begins" << endl;
    Debug::Clock clk; clk.begin();
    merge_sort(data, data + N);
    cout << "Single-thread merge_sort completed in " << clk.end() << " seconds" << endl;
    check();

    generate_data();

    cout << "Multi-thread Merge_sort begins with " << MAX_THREADS << " threads" << endl;
    clk.begin();
    parallel_sort(data, data + N, merge_sort);
    cout << "Merge sort completed in " << clk.end() << " seconds" << endl;
    check();

    return 0;
}
