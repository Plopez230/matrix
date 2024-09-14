/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:00:47 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 16:14:30 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

# include <iostream>
# include <cstring>

template <typename K>
Vector<K>::Vector(): Matrix<K>()
{
    this->shape[0] = 0;
    this->shape[1] = 0;
    this->elements = NULL;
}

template <typename K>
Vector<K>::Vector(K *elements, int rows): Matrix<K>()
{
    this->shape[0] = rows;
    this->shape[1] = 1;
    this->elements = new K[rows];
    std::memcpy(this->elements, elements, rows * sizeof(K));
}

template <typename K>
Vector<K>::Vector(const Vector &o): Matrix<K>()
{
    this->shape[0] = o.shape[0];
    this->shape[1] = 1;
    this->elements = new K[this->shape[0] * this->shape[1]];
    std::memcpy(this->elements, o.elements,
        this->shape[0] * this->shape[1] * sizeof(K));
}

template <typename K>
Vector<K> &Vector<K>::operator=(const Vector &o)
{
    this->shape[0] = o.shape[0];
    this->shape[1] = 1;
    if (this->elements)
        delete[] this->elements;
    this->elements = new K[this->shape[0] * this->shape[1]];
    std::memcpy(this->elements, o.elements,
        this->shape[0] * this->shape[1] * sizeof(K));
    return *this;
}

template <typename K>
Vector<K>::~Vector()
{
}

template <typename K>
K Vector<K>::get_element(int row) const
{
    if (row >= 0 && row < this->shape[0])
        return this->elements[row * this->shape[1]];
    else
        throw std::out_of_range("Index out of range.");
}

template <typename K>
void Vector<K>::set_element(const K &element, int row)
{
    if (row >= 0 && row < this->shape[0])
        this->elements[row * this->shape[1]] = element;
    else
        throw std::out_of_range("Index out of range.");
}

#endif
