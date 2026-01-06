#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../../P1/ListLinked.h"

template <typename V>
class HashTable: public Dict<V>{
	private:
		int n;
		int max;
		ListLinked<TableEntry<V>>* table;

		int h(std::string key){
			int sum=0;
			for(char c:key)
				sum+=int(c);
			return sum%max;
		}
	public:
		HashTable(int size) : n(0), max(size) {
			table = new ListLinked<TableEntry<V>>[max];
		}
		~HashTable(){
			delete[] table;
		}
		int capacity(){
			return max;
		}
		friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
			out << th.V << std::endl;
			return out;
		}
		V operator[](std::string key){
			if(key==true){
				return table.seard(key);
			}
			else{
				throw std::runtime_error;
			}	
		}
};

#endif
