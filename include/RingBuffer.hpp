#ifndef RING_BUFFER_H
#define RING_BUFFER_H

template <typename T>
class RingBuffer
{
private:
public:
    /**
     * @brief Create a ring buffer of a given capacity with an initial size of 0.
     */
    RingBuffer(int capacity);

    /**
     * @brief Clean up the ring buffer.
     */
    ~RingBuffer();

    /**
     * @brief Add an item to the ring buffer.
     *
     * @param value The item to add.
     * @throws std::out_of_range If ring buffer is full.
     */
    void add(T value) {}

    /**
     * @brief Remove and return an item from the ring buffer.
     *
     * @return The removed item.
     * @throws std::out_of_range If the ring buffer is empty.
     */
    T remove() {}

    /**
     * @brief Retrieve the next item to be removed without removing it.
     *
     * @return The next item to be removed.
     */
    T peek() const {}

    /**
     * @brief Check if the ring buffer is currently empty.
     *
     * @return True if the ring buffer is empty, otherwise false.
     */
    bool isEmpty() const {}

    /**
     * @brief Check if the ring buffer is currently full.
     *
     * @return True if the ring buffer is full, otherwise false.
     */
    bool isFull() const {}

    /**
     * @brief Get the current size of the ring buffer.
     *
     * @return The current size.
     */
    int getSize() const {}

    /**
     * @brief Get the capacity of the ring buffer.
     *
     * @return The capacity.
     */
    int getCapacity() const {}
};

#endif
