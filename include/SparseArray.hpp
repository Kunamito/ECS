/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** SparseArray.hpp
*/

#ifndef SPARSE_ARRAY_HPP_
    #define SPARSE_ARRAY_HPP_

    #include <optional>
    #include <vector>

template<typename Component>
class SparseArray {
    public :
        using value_type = std::optional<Component>;
        using reference_type = value_type &;
        using const_reference_type = value_type const &;
        using container_t = std::vector<value_type>;
        
        // template here .
        using size_type = typename container_t::size_type;
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;
    
    public:
        SparseArray() = default;
        SparseArray(size_t size) : _data(size) {}
        SparseArray(SparseArray const & spa) {
            _data = spa._data.copy();
        }
        SparseArray(SparseArray&& spa) noexcept {
            _data = spa._data.move();
        }
        ~SparseArray() {

        }

        SparseArray& operator=(SparseArray const & spa) {
            return spa._data.copy();
        }
        SparseArray& operator=(SparseArray && spa) noexcept {
            return spa._data.move();
        }
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
        reference_type insert_at(size_type pos, Component const & cmpt) {
            return _data.insert_at(pos, cmpt);
        }
        reference_type insert_at(size_type pos, Component && cmpt) {
            return _data.insert_at(pos, cmpt);
        }

        // template<class ...Params>
        // reference_type emplace_at(size_type pos, Params &&...) {

        // } // optional
        void erase(size_type pos) {
            _data.erase(pos);
        }
        size_type get_index(value_type const & idx) const {
            return _data.get_index(idx);
        }
    
    private:
        container_t _data;
};

#endif
