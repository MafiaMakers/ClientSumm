#ifndef SUPER_LIST
#define SUPER_LIST
#include "LogsHandler.h"
#include <QList>
namespace SuperFunctions {
	template <class T>
	struct SuperListElement {
		T value;
		SuperListElement<T>* next;
		SuperListElement<T>* previous;
	};

	template <class T>
	class PointerVal {
	public:
		PointerVal(T* val) {
			ptr = val;
		}

		PointerVal(){}

		operator T(){
			return *ptr;
		}

		T operator = (T value) {
			*ptr = value;
			return *ptr;
		}

		T operator ++ () {
			*ptr++;
			return *ptr;
		}

		T operator += (T value) {
			*ptr += value;
			return *ptr;
		}

		T operator -= (T value) {
			*ptr -= value;
			return *ptr;
		}

		T operator *= (T value) {
			*ptr *= value;
			return *ptr;
		}

		T operator /= (T value) {
			*ptr /= value;
			return *ptr;
		}

		T operator -- () {
			*ptr--;
			return *ptr;
		}

		bool operator == (T value) {
			return *ptr == value;
		}

		bool operator >= (T value) {
			return *ptr >= value;
		}

		bool operator <= (T value) {
			return *ptr <= value;
		}

		bool operator != (T value) {
			return *ptr != value;
		}
	private:
		T* ptr;
	};

	template <class T>
	class SuperList
	{
	public:
		SuperList() {
			size = 0;
			first = 0;
			last = 0;
		}

		void append(T val) {
			if (size != 0) {
				if (size == 1) {
					SuperListElement<T>* ne = new SuperListElement<T>();
					ne->previous = last;
					ne->next = 0;
					ne->value = val;
					first->next = ne;
					last = ne;
					size++;
				}
				else {
					SuperListElement<T>* ne = new SuperListElement<T>();
					ne->previous = last;
					ne->next = 0;
					ne->value = val;
					last->next = ne;
					last = ne;
					size++;
				}
				
			}
			else {
				SuperListElement<T>* ne = new SuperListElement<T>();
				ne->previous = 0;
				ne->next = 0;
				ne->value = val;
				first = ne;
				last = ne;
				size++;
			}
		}

		T get(int index) {
			SuperListElement<T>* ne = 0;
			call(_get(index), &ne);
			return ne->value;
		}

		void set(T value, int index) {
			SuperListElement<T>* ne = 0;
			call(_get(index), &ne);
            ne->value = value;
		}

		void pop(int index) {
			SuperListElement<T>* current = 0;
			call(_get(index), &current);
			if (current->previous != 0) {
				if (current->next != 0) {
					current->next->previous = current->previous;
					current->previous->next = current->next;
					delete current;
				}
				else {
					current->previous->next = 0;
					last = current->previous;
					delete current;
				}
			}
			else {
				if (current->next != 0) {
					current->next->previous = 0;
					first = current->next;
					delete current;
				}
				else {
					delete current;
					first = 0;
					last = 0;
				}
			}
			size--;
		}

		void insert(T value, int index) {
			if (index == size) {
				append(value);
				return;
			}
			switch (index) {
			case 0: {
				SuperListElement<T>* cur = new SuperListElement<T>();
				cur->value = value;
				cur->next = first;
				cur->previous = 0;
				first->previous = cur;
				first = cur;
				size++;
				break;
			}
			default: {
				SuperListElement<T>* prev = 0;
				call(_get(index-1), &prev);
				SuperListElement<T>* cur = new SuperListElement<T>();
				cur->next = prev->next;
				cur->previous = prev;
				cur->value = value;
				prev->next->previous = cur;
				prev->next = cur;
				size++;
			}
			}
		}

		int length() {
			return size;
		}

        QList<T> toQtList(){
            QList<T> res = QList<T>();
            SuperListElement<T>* cur = first;
            for(int i = 0; i < size; i++){
                res.append(cur->value);
                cur = cur->next;
            }
            return res;
        }

        int indexOf(T obj){
            SuperListElement<T>* cur = first;
            for(int i = 0; i < size; i++){
                if(cur->value == obj){
                    return i;
                }
                cur = cur->next;
            }
            std::cout << "error! Not such object in collection!" << std::endl;
            raise_logs();
        }

        bool contains(T obj){
            SuperListElement<T>* cur = first;
            for(int i = 0; i < size; i++){
                if(cur->value == obj){
                    return true;
                }
                cur = cur->next;
            }
            return false;
        }

		PointerVal<T> operator [] (int index) {
			SuperListElement<T>* cur = 0;
			call(_get(index), &cur);
			return PointerVal<T>(&(cur->value));
		}

		SuperList<T> operator << (T value) {
			call_void(append(value));
			return *this;
		}

		PointerVal<T> getLast() {
			if (last != 0) {
				return PointerVal<T>(&(last->value));
			}
			else {
				std::cout << "Empty list error. Trying to get last element in null list" << std::endl;
				raise_logs();
				throw - 1;
				return PointerVal<T>();
			}
		}
	private:
		int size = 0;

		SuperListElement<T>* first = 0;
		SuperListElement<T>* last = 0;

		SuperListElement<T>* _get(int index) {
			if (index >= 0 && index < size) {
				SuperListElement<T>* ne = first;
				for (int i = 0; i < index; i++)
				{
					ne = ne->next;
				}
				return ne;
			}
			else {
				std::cout << "List index out of range!" << std::endl << "Size is " << size << " but " << index << " is given" << std::endl;
				raise_logs();
				throw - 1;
				return 0;
			}
		}
	};
}

#endif
