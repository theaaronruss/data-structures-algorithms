#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
    T *data;
    const int size;

public:
    /**
     * @brief Initializes array with x elements.
     *
     * @param size The size of the array.
     */
    Array(int size) : size(size)
    {
        data = new T[size]{};
    }

    /**
     * @brief Release memory allocated for the array data.
     */
    ~Array()
    {
        delete[] data;
    }

    /**
     * @brief Get the element stored at a particular index.
     */
    T get(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Invalid index");
        }
        return data[index];
    }

    /**
     * @brief Set the element at a particular index to a given value.
     */
    void set(int index, T value)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Invalid index");
        }
        data[index] = value;
    }

    /**
     * @brief Get the size of the array.
     */
    int getSize() const
    {
        return size;
    }

    /**
     * @brief Print the contents of the array.
     */
    void print() const
    {
        std::cout << "[ ";
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << "]\n";
    }
};

#endif
