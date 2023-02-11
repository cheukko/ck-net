
#ifndef __ESSENTIAL_CPP_CHAPTER_02_H__
#define __ESSENTIAL_CPP_CHAPTER_02_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

#include "../util/num_sequence.h"

namespace chapter_02
{

/* 2.1 */
extern bool FibonElem(int pos, int &elem);
extern bool PrintFibon(int pos);
extern void ch_2_1();
extern void hw_2_1();

/* 2.3 */
extern void Swap(int &val1, int &val2, std::ostream &ofile = std::cout);
extern void Swap(int &val1, int &val2, std::ostream *ofile = 0);
extern void BubbleSort(std::vector<int> &vec, std::ostream &ofile = std::cout);
extern void BubbleSort(std::vector<int> *vec, std::ostream *ofile = 0);
extern void Display(const std::vector<int> &vec, std::ostream &out = std::cout);
extern void Display(const std::vector<int> *vec, std::ostream *out = 0);
extern void ch_2_3();

/* 2.4 */
extern const std::vector<int>* FibonSeq1(int size);
extern void ch_2_4();

/* 2.5 */
inline bool IsSizeOk1(int size)
{
    const int max_elems = 1024;

    if (size <= 0 || size > max_elems)
    {
        std::cerr << "oops: invalid size: " << size
                  << "cannot handle request!\n";
        return false;
    }

    return true;
}
extern const std::vector<int>* FibonSeq2(int size);
extern bool FibonElem2(int pos, int &elem);

/* 2.6 */
extern void DisplayMsg(const std::string &msg);
extern void DisplayMsg(const std::string &msg, int size);

inline bool IsSizeOk(int size)
{
    const int           max_elems = 1024;
    const std::string   msg("requested size is not supported.");

    if (size <= 0 || size > max_elems)
    {
//        std::cerr << "invalid position: " << size
//                  << "cannot handle request!\n";
        DisplayMsg(msg);
        return false;
    }

    return true;
}

extern void ch_2_8();

template <typename T>
inline T Max(T t1, T t2) { return t1 > t2 ? t1 : t2; }

template <typename T>
inline T Max(const std::vector<T> &vec)
{
    return *std::max_element(vec.begin(), vec.end());
}

template <typename T>
inline T Max(const T *arr, int size)
{
    return *std::max_element(arr, arr + size);
}

extern void hw_2_6();

}

#endif //__ESSENTIAL_CPP_CHAPTER_02_H__
