//
//  container.h
//

#pragma once

#ifndef __ML__CONTAINER_H__
#define __ML__CONTAINER_H__

#include <iterator>

namespace ml {
	
	template< typename T >
	struct container {
		
		typedef T value_type;
		typedef T & reference;
		typedef T const & const_reference;
		
		struct iterator : public std::iterator<std::bidirectional_iterator_tag, value_type>{
			
			iterator() : m_data(NULL) {}
			iterator(iterator const &it) : m_data(it.m_data) {}
			
			iterator operator++(int) {iterator it = *this; ++m_data; return it;}
			iterator &operator++() { ++m_data; return *this; }
			iterator operator--(int) {iterator it = *this; --m_data; return it;}
			iterator &operator--() { --m_data; return *this; }
			
			value_type * operator->() {return m_data;}
			value_type & operator*() {return *m_data;}
			
			bool operator != (iterator const &it) const { return m_data != it.m_data; }
			bool operator == (iterator const &it) const { return m_data == it.m_data; }
			
		protected:
			friend class container;
			iterator(value_type *data) : m_data(data) {}
			value_type *m_data;
		};

		
		struct const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type>{
			
			const_iterator() : m_data(NULL) {}
			const_iterator(const_iterator const &it) : m_data(it.m_data) {}
			
			const_iterator operator++(int) {const_iterator it = *this; ++m_data; return it;}
			const_iterator &operator++() { ++m_data; return *this; }
			const_iterator operator--(int) {const_iterator it = *this; --m_data; return it;}
			const_iterator &operator--() { --m_data; return *this; }
			
			value_type const * operator->() const {return m_data;}
			value_type const & operator*() const {return *m_data;}
			
			bool operator != (const_iterator const &it) const { return m_data != it.m_data; }
			
		protected:
			friend class container;
			const_iterator(value_type *data) : m_data(data) {}
			value_type *m_data;
		};

		container(T *start, size_t size) : m_first(start), m_last(start+size) {}
		container(T *start, T *end) : m_first(start), m_last(end) {}
		
		iterator begin() { return iterator(m_first); }
		iterator end() { return iterator(m_last); }

		const_iterator begin() const { return const_iterator(m_first); }
		const_iterator end() const { return const_iterator(m_last); }

		const_iterator rbegin() const { return const_iterator(m_last-1); }
		const_iterator rend() const { return const_iterator(m_first-1); }

		reference front() const { return *m_first; }
		reference back() const { return *(m_last-1); }
		
		reference operator[](size_t index) const { return *(m_first + index); }
		
		bool empty() const { return m_first == m_last; }
		size_t size() const { return m_last - m_first; }
		
		value_type *m_first;
		value_type *m_last;
	};
	
} // namespace ml

#endif // __ML__CONTAINER_H__
