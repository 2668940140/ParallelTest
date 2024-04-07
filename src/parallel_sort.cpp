#include "parallel_sort.h"
#include "merge_sort.h"
#include "parallel_config.h"


#include <thread>
#include <utility>
#include <vector>
#include <algorithm>
#include <list>
#include <cassert>

void parallel_sort(int *begin, int *end, Sort_func sort_func)
{
    long long size = end - begin;
    long long chunk_size = std::max((size + MAX_THREADS - 1) / MAX_THREADS, MIN_BATCH_SIZE);

    std::list<int *> cut_points;
    int *p = begin;
    while (p < end)
    {
        cut_points.push_back(p);
        p += chunk_size;
    }
    cut_points.push_back(end);

    std::vector<std::thread> threads;
    for (auto begin_p = cut_points.begin(); begin_p != cut_points.end(); ++begin_p)
    {
        auto end_p = std::next(begin_p);
        threads.push_back(std::thread(sort_func, *begin_p, *end_p));
    }

    for (auto & thread : threads)
    {
        thread.join();
    }
    threads.clear();
    
    while (cut_points.size() > 2)
    {
        auto p = std::next(cut_points.begin());
        if (cut_points.size() > 4)
        {
            while (p != cut_points.end() && std::next(p) != cut_points.end())
            {
                threads.push_back(std::thread(std::inplace_merge<int *>, *std::prev(p), *p, *std::next(p)));
                auto tmp = p;
                p = std::next(p, 2);
                cut_points.erase(tmp);
            }
            for (auto & thread : threads)
            {
                thread.join();
            }
            threads.clear();
        }
        else
        {
            if (cut_points.size() == 3)
            {
                std::inplace_merge(*cut_points.begin(), *std::next(cut_points.begin()), *cut_points.rbegin());
            }
            else if (cut_points.size() == 4)
            {
                std::inplace_merge(*cut_points.begin(), *std::next(cut_points.begin()), *std::next(cut_points.begin(), 2));
                std::inplace_merge(*cut_points.begin(), *std::next(cut_points.begin(), 2), *cut_points.rbegin());
            }
            break;
        }
    }
}