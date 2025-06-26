/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** SparseArray.hpp
*/

#ifndef SPARSE_ARRAY_HPP_
    #define SPARSE_ARRAY_HPP_

template<typename Component>
class SparseArray {
    public :
        using value_type = ???; // optional component type
        using reference_type = value_type &;
        using const_reference_type = value_type const &;
        using container_t = std::vector<value_type>; // optionally add your allocator
        
        template here .
        using size_type = typename container_t::size_type;
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;
    
    public:
        SparseArray(); // You can add more constructors .
        SparseArray(SparseArray const &); // copy constructor
        SparseArray(SparseArray &&) noexcept; // move constructor
        ~SparseArray();
        SparseArray& operator=(SparseArray const &); // copy assignment operator
        SparseArray& operator=(SparseArray &&) noexcept; // move assignment operator
        reference_type operator[](size_t idx);
        const_reference_type operator[](size_t idx) const;
        iterator begin();
        const_iterator begin() const;
        const_iterator cbegin() const;
        iterator end();
        const_iterator end() const;
        const_iterator cend() const;
        size_type size() const;
        reference_type insert_at(size_type pos, Component const &);
        reference_type insert_at(size_type pos, Component &&);

        template<class ...Params>
        reference_type emplace_at(size_type pos, Params &&...); // optional
        void erase(size_type pos);
        size_type get_index(value_type const &) const;
    
    private:
        container_t _data;
};

#endif
