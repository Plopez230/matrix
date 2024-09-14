/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:51:29 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 16:37:31 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <vector>

template<typename K>
class Vector;

template <typename K>
class Matrix
{
protected:

    K   *elements;
    int shape[2];

public:

    // matrix.tpp
    Matrix();
    Matrix(K *elements, int rows, int columns);
    Matrix(const Matrix &o);
    Matrix &operator=(const Matrix &o);
    ~Matrix();
    const K     get_element(int row, int column) const;
    void        set_element(const K &element, int row, int column);
    const int   *get_shape() const;
    int         is_square() const;
    int         is_vector() const;
    void        print() const;
    Matrix<K>   reshape(int rows, int columns);
    Vector<K>   reshape(int rows);
    bool        operator==(const Matrix &m) const;

    // ex00.tpp
    void        add(const Matrix<K> &m);
    void        subtract(const Matrix<K> &m);
    void        scale(K scalar);
};

template <typename K>
class Vector: public Matrix<K>
{
public:

    // vector.tpp
    Vector();
    Vector(K *elements, int rows);
    Vector(const Vector &o);
    Vector &operator=(const Vector &o);
    ~Vector();
    K           get_element(int row) const;
    void        set_element(const K &element, int row);

    // ex03.tpp
    K           dot(const Vector<K> &v);
};

// ex01.tpp
template<typename K>
Matrix<K> linear_combination(const std::vector<Matrix<K> > &matrices,
    const std::vector<K> &scalars);

// ex02.tpp
template<typename K>
Matrix<K> lerp(const Matrix<K> &u, const Matrix<K> &v, K t);

# include "matrix.tpp"
# include "vector.tpp"
# include "ex00.tpp"
# include "ex01.tpp"
# include "ex02.tpp"
# include "ex03.tpp"

#endif
