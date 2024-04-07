#ifndef PARALLEL_SORT_H
#define PARALLEL_SORT_H
typedef void (*Sort_func)(int *begin, int *end);

void parallel_sort(int *begin, int *end, Sort_func sort_func);
#endif