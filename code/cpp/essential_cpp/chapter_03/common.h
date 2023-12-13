
#ifndef __ESSENTIAL_CPP_CHAPTER_03_H__
#define __ESSENTIAL_CPP_CHAPTER_03_H__

#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

namespace chapter_03
{

const int s_int_size = 12;
const int s_string_size = 4;

extern int     s_ia[s_int_size];
extern std::string  s_sa[s_string_size];

extern std::vector<int>     s_ivec;
extern std::vector<std::string>  s_svec;

extern const int* FindVec(const std::vector<int> &vec, int val);

template <typename T>
const T* FindVer1(const std::vector<T> &vec, T &val)
{
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == val)
            return &vec[i];

    return 0;
}

template <typename T>
const T* FindVer2(const T *array, int size, const T &val)
{
    if (!array || size < 1)
        return 0;

    for (int ix = 0; ix < size; ix++)
        if (array[ix] == val)
            return &array[ix];

    return 0;
}

template <typename T>
const T* FindVer3(const T *array, int size, const T &val)
{
    if (!array || size < 1)
        return 0;

    for (int ix = 0; ix < size; ix++, ++array)
        if (*array == val)
            return array;

    return 0;
}

template <typename T>
const T* FindVer4(const T *first, const T *last, T &val)
{
    if (!first || !last)
        return 0;

    for (;first != last; ++first)
        if (*first == val)
            return first;

    return 0;
}

template <typename T>
inline const T* Begin(const std::vector<T> &vec)
{
    return vec.empty() ? 0 : &vec[0];
}

template <typename T>
inline const T* End(const std::vector<T> &vec)
{
    return vec.empty() ? 0 : &vec[vec.size()];
}

template <typename T, typename Y>
T FindVer5(T first, T last, const Y &val)
{
    for (; first != last; ++first)
        if (val == *first)
            return first;

    return last;
}

extern void ch_3_6();

extern std::vector<int> FilterVer1(const std::vector<int> &vec, int filter_val, bool (*pred)(int, int));
extern std::vector<int> FilterVer2(const std::vector<int> &vec, int val, const std::less<int> &lt);

template <typename It, typename Ot, typename ElemType,typename Comp>
Ot FilterVer3( It first, It last, Ot at, const ElemType &val, Comp pred )
{
    while ((first = find_if(first, last, bind2nd(pred, val))) != last)
    //while (( first = find_if( first, last, not1(bind2nd( pred, val )))) != last )
    {
        std::cout << "found val: " << *first << std::endl;
        *at++ = *first++;
    }

    return at;
}

extern std::vector<int> SubVec(const std::vector<int> &vec, int val);

extern void ch_3_9();
extern void ch_3_10();

extern void InitExclusionSet(std::set<std::string> &exs);
extern void ProcessFile(std::map<std::string, int> &word_map,
                        const std::set<std::string> &exclude_set,
                        std::ifstream &ifile);
extern void DisplayWordCount(const std::map<std::string, int> &word_map,
                            std::ostream &out = std::cout);
extern void UserQuery(const std::map<std::string, int> &word_map);
extern void hw_3_1();

class StrSizeComp
{
public:
    bool operator()(const std::string &s1, const std::string &s2)
    {
        return s1.size() < s2.size();
    }
};
extern void hw_3_2();

typedef std::vector<std::string> vstring;
typedef std::string::size_type ssize_type;
typedef std::map<std::string, vstring> svec_map;

extern void InitFamilyMap(std::ifstream &in, std::map<std::string, vstring> &family);
extern void DisplayMap(const std::map<std::string, vstring> &familes, std::ostream &out);
extern void QueryMap(const std::string &family, svec_map familes);
extern void hw_3_3();

class EvenElem
{
public:
    bool operator()(const std::string &s)
    {
        return s.size() % 2 ? false : true;
    }
};
extern void hw_3_4();

}

#endif // __ESSENTIAL_CPP_CHAPTER_03_H__