/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** SparseArray.hpp
*/

#ifndef SPARSE_ARRAY_HPP_
    #define SPARSE_ARRAY_HPP_

    #include <iostream>

    #include <optional>
    #include <vector>
    #include <algorithm>

namespace ECS {

template<class Component>
class SparseArray {
    public :
        using value_type = std::optional<Component>;
        using reference_type = value_type &;
        using const_reference_type = value_type const &;
        using container_t = std::vector<value_type>;

        using size_type = typename container_t::size_type;
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;
    
    public:
        SparseArray() = default;
        SparseArray(size_t size) : _data(size) {}
        SparseArray(const SparseArray& spa) = default;
        SparseArray(SparseArray&& spa) noexcept = default;
        ~SparseArray() = default;

        SparseArray& operator=(const SparseArray& spa) = default;
        SparseArray& operator=(SparseArray&& spa) noexcept = default;

        reference_type operator[](size_t idx) {
            return _data[idx];
        }
        const_reference_type operator[](size_t idx) const {
            return _data[idx];
        }

        iterator begin() {
            return _data.begin();
        }
        const_iterator begin() const {
            return _data.begin();
        }
        const_iterator cbegin() const {
            return _data.cbegin();
        }
        iterator end() {
            return _data.end();
        }
        const_iterator end() const {
            return _data.end();
        }
        const_iterator cend() const {
            return _data.cend();
        }
        size_type size() const {
            return _data.size();
        }

        reference_type insert_at(size_type pos, const Component& cmpt) {
            if (pos >= _data.size()) {
                _data.resize(pos + 1);
            }
            _data[pos].emplace(cmpt);
            return _data[pos];
        }
        reference_type insert_at(size_type pos, Component&& cmpt) {
            if (pos >= _data.size()) {
                _data.resize(pos + 1);
            }
            _data[pos].emplace(std::move(cmpt));
            return _data[pos];
        }

        void erase(size_type pos) {
            _data[pos].reset();
        }

        size_type get_index(const value_type& idx) const {
            auto i = std::find(_data.begin(), _data.end(), idx);

            if (i == _data.end())
                return _data.size();
            return std::distance(_data.begin(), i);
        }
    
    private:
        container_t _data;
};

} // namespace ECS

#endif
