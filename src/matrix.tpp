/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:02:50 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 00:05:16 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_TPP
# define MATRIX_TPP

# include <iostream>
# include <cstring>

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
void Matrix<K>::set_element(K element, int row, int column)
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
void Matrix<K>::reshape(int rows, int columns)
{
    if (rows * columns != shape[0] * shape[1])
        throw std::invalid_argument(
            "The new shape does not have the same number of elements.");
    shape[0] = rows;
    shape[1] = columns;
}

#endif
