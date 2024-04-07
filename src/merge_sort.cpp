#include <algorithm>

void __merge_sort(int *begin, int *end, int * buffer)
{
    if (end - begin <= 1) return;

    int *mid = begin + (end - begin) / 2;
    
    __merge_sort(begin, mid, buffer);
    __merge_sort(mid, end, buffer + (mid - begin));

    std::merge(begin, mid, mid, end, buffer);
    std::copy(buffer, buffer + (end - begin), begin);
}

void merge_sort(int *begin, int *end)
{
    if (end - begin <= 1) return;
    int *buffer = new int[end - begin];
    int *mid = begin + (end - begin) / 2;
    
    __merge_sort(begin, mid, buffer);
    __merge_sort(mid, end, buffer + (mid - begin));

    std::merge(begin, mid, mid, end, buffer);
    std::copy(buffer, buffer + (end - begin), begin);

    delete[] buffer;
}