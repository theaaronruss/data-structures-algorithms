#include "../include/LinearSearch.hpp"

template <typename T>
bool linearSearch(Array<T> arr, T target)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        if (arr.get(i) == target)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
bool linearSearch(ArrayList<T> arr, T target)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        if (arr.get(i) == target)
        {
            return true;
        }
    }
    return false;
}
