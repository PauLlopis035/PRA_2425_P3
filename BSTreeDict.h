#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>

class BSTreeDict: public Dict<V>{
	private:
		BSTree<TableEntry<V>>* tree;
	public:
		BSTreeDict(){new BSTreeDict.tree(void);}
		friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
		out << print_inorden(out,bs) << std::endl;
		return out;
		}
		V operator[](std::string key){
			search(std::string key);
		}
};

#endif
