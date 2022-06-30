#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cmath>

namespace ft
{
	template <typename T>
	class Vector {
		public:
			Vector(){
				m_Data = nullptr;
				m_Size = 0;
				m_Capacity = 0;
				//allocate memory for vector buffer
				reAlloc(2);
			}
			void pushBack(const T& value){
				//if buffer is full, reallocate memory
				if(m_Size == m_Capacity){
					reAlloc(m_Capacity * 2);
				}
				//add value to end of buffer
				m_Data[m_Size++] = value;
			}
			size_t getSize() const{
				return m_Size;
			}
			size_t getCapacity() const{
				return m_Capacity;
			}
			T& operator[](size_t index){
				return m_Data[index];
			}
			const T& operator[](size_t index) const{
				return m_Data[index];
			}
		private:
			void reAlloc(size_t newCapacity){
				//allocate new block of memory
				T *newBuffer = new T[newCapacity];
				if (newCapacity < m_Size)
					m_Size = newCapacity;
				//copy old data to new block
				for(size_t i = 0; i < m_Size; i++){
					newBuffer[i] = std::move(m_Data[i]);
				}
				//delete old block
				delete[] m_Data;
				//assign new block to buffer
				m_Data = newBuffer;
				//assign new capacity to m_Capacity
				m_Capacity = newCapacity;
			}
		private:
			T *m_Data;
			size_t m_Size;
			size_t m_Capacity;
	};
}

#endif