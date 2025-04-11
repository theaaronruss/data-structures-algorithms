#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayList
{
private:
    int capacity;
    int size;
    T *data;
    void expand()
    {
        int oldCapacity = capacity;
        capacity = capacity * 1.5 + 1;
        T *newData = new T[capacity]{};
        for (int i = 0; i < oldCapacity; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    /**
     * @brief Create an array list with an initial capacity of 10 and size of 0.
     */
    ArrayList() : ArrayList(10) {}

    /**
     * @brief Create an array list with a specified capacity and initial size of 0.
     *
     * @param capacity The initial capacity.
     */
    ArrayList(int capacity) : capacity(capacity), size(0), data(new T[capacity]{})
    {
        if (capacity < 1)
        {
            throw std::out_of_range("Invalid initial capacity");
        }
    }

    /**
     * @brief Add an element to the end of the list. Resize the list if necessary.
     *
     * @param value The value to add.
     */
    void add(T value)
    {
        if (size >= capacity)
        {
            expand();
        }
        data[size] = value;
        size++;
    }

    /**
     * @brief Insert an element at a given index. Resize the list if necessary.
     *
     * @param index The index to insert item at.
     * @param value The value to insert.
     */
    void insert(int index, T value)
    {
        if (size >= capacity)
        {
            expand();
        }
        for (int i = size; i > index; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    /**
     * @brief Remove an item from the list at a given index.
     *
     * @param index The index of the item to remove.
     * @return The removed item.
     */
    T remove(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Invalid index");
        }
        T value = data[index];
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
        return value;
    }

    /**
     * @brief Get the item at the given index.
     *
     * @param index The index of the item to retrieve.
     * @return The retrieved item.
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
     * @brief Set the value at a given index.
     *
     * @param index Index of the item to set.
     * @param value The value to assign at the given index.
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
     * @brief Get the current capacity.
     *
     * @return The current capacity.
     */
    int getCapacity() const
    {
        return capacity;
    }

    /**
     * @brief Get the current size.
     *
     * @return The current size.
     */
    int getSize() const
    {
        return size;
    }

    /**
     * @brief Print the contents of the list.
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
