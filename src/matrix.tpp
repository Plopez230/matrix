/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:02:50 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 15:57:52 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_TPP
# define MATRIX_TPP

# include <iostream>
# include <cstring>

template <typename K>
Matrix<K>::Matrix()
{
    shape[0] = 0;
    shape[1] = 0;
    this->elements = NULL;
}

template <typename K>
Matrix<K>::Matrix(K *elements, int rows, int columns)
{
    shape[0] = rows;
    shape[1] = columns;
    this->elements = new K[rows * columns];
    std::memcpy(this->elements, elements, rows * columns * sizeof(K));
}

template <typename K>
Matrix<K>::Matrix(const Matrix &o)
{
    shape[0] = o.shape[0];
    shape[1] = o.shape[1];
    this->elements = new K[shape[0] * shape[1]];
    std::memcpy(this->elements, o.elements, shape[0] * shape[1] * sizeof(K));
}

template <typename K>
Matrix<K> &Matrix<K>::operator=(const Matrix &o)
{
    shape[0] = o.shape[0];
    shape[1] = o.shape[1];
    if (this->elements)
        delete[] this->elements;
    this->elements = new K[shape[0] * shape[1]];
    std::memcpy(this->elements, o.elements, shape[0] * shape[1] * sizeof(K));
    return *this;
}

template <typename K>
Matrix<K>::~Matrix()
{
    delete[] elements;
}

template <typename K>
const K Matrix<K>::get_element(int row, int column) const
{
    if (row >= 0 && row < shape[0] && column >= 0 && column < shape[1])
        return elements[row * shape[1] + column];
    else
        throw std::out_of_range("Index out of range.");
}

template <typename K>
void Matrix<K>::set_element(const K &element, int row, int column)
{
    if (row >= 0 && row < shape[0] && column >= 0 && column < shape[1])
        elements[row * shape[1] + column] = element;
    else
        throw std::out_of_range("Index out of range.");
}

template <typename K>
const int* Matrix<K>::get_shape() const
{
    return shape;
}

template <typename K>
int Matrix<K>::is_square() const
{
    return shape[0] == shape[1];
}

template <typename K>
int Matrix<K>::is_vector() const
{
    return shape[0] > 0 && shape[1] == 0;
}

template <typename K>
void Matrix<K>::print() const
{
    for (int i = 0; i < shape[0]; i++)
    {
        for (int j = 0; j < shape[1]; j++)
        {
            std::cout << elements[i * shape[1] + j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename K>
Matrix<K> Matrix<K>::reshape(int rows, int columns)
{
    if (rows * columns != shape[0] * shape[1])
        throw std::invalid_argument(
            "The new shape does not have the same number of elements.");
    Matrix<K> result(elements, rows, columns);
    
    return result;
}

template <typename K>
Vector<K> Matrix<K>::reshape(int rows)
{
    if (rows != shape[0] * shape[1])
        throw std::invalid_argument(
            "The new shape does not have the same number of elements.");
    Vector<K> result(elements, rows);
    
    return result;
}

template <typename K>
bool Matrix<K>::operator==(const Matrix<K>& m) const
{
    const int *m_shape = m.get_shape();
    const int *this_shape = this->get_shape();

    if (m_shape[0] != this_shape[0] || m_shape[1] != this_shape[1])
    {
        return false;
    }

    for (int i = 0; i < m_shape[0]; ++i)
    {
        for (int j = 0; j < m_shape[1]; ++j)
        {
            if (m.get_element(i, j) != this->get_element(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

#endif
