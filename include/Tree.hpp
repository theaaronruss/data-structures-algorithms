#ifndef TREE_H
#define TREE_H

#include "LinkedList.hpp"

template <typename T>
class Tree
{
private:
    T value;
    LinkedList<Tree> children;

public:
    /**
     * @brief Create new tree with no children.
     */
    Tree(T value) : value(value) {}

    /**
     * @brief Get the value of the tree node.
     *
     * @return The tree node's value.
     */
    T getValue()
    {
        return value;
    }

    /**
     * @brief Set the value of the tree node.
     *
     * @param value The value to set.
     */
    void setValue(T value)
    {
        this.value = value;
    }

    /**
     * @brief Add a child to the tree node. Children are added from left to right.
     *
     * @param The child to add to the tree.
     */
    void addChild(Tree child)
    {
        children.pushBack(child);
    }

    /**
     * @brief Remove n-th child from the tree.
     *
     * @param index The index of the child to remove.
     * @return The removed child.
     * @throws std::out_of_range If index is out of bounds.
     */
    Tree removeChild(int index)
    {
        return children.remove(index);
    }

    /**
     * @brief Get the n-th child of the tree.
     *
     * @param index The index of the child.
     * @return The retrieved child.
     * @throws std::out_of_range If index is out of bounds.
     */
    Tree getChild(int index)
    {
        return children.get(index);
    }

    /**
     * @brief Get the number of children.
     *
     * @return The number of children.
     */
    int
    getNumChildren()
    {
        return children.getSize();
    }
};

#endif
