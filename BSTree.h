#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T>
class BSTree {
	private:
		int nelem;
		BSNode<T>* root;

		BSNode<T>* search(BSNode<T>* n, T e)const{
			if(n==nullptr){
				throw std::runtime_error("Elemento no encontrado");
			}
			if(e==n->elem){return n;}
			if(e<n->elem){return search(n->left,e)}
			else{return search(n->right,e)}
		}

		BSNode<T>* insert(BSNode<T>* n, T e){
			if(n==null){return new Node(e);}
			else if(n->elem){
				return new DuplicatedElementException();
			}
			else if(n->elem < e){n->right = insert(n->right,e);}
			else{n->left = insert(n->left,e);}
			return n;
		}
		void print_inorder(std::ostream &out, BSNode<T>* n)const{
			if(n!=nullptr){
				print_inorder(out,n->left);
				out << n->elem << " ";
				print_inorder(out,n->right);
			}
		}
		BSNode<T>* remove(BSNode<T>* n, T e){
			if(n==nullptr){throw std::runtime_error();}
			else if(n->elem < e){n->right = remove(n->rigth,e);}
			else if(n->elem > e){n->left = remove(n->left,e);}
			else{
				if((n->left != nullptr) && (n->right != nullptr)){
					n->elem = max(n->left);
					n->left = remove_max(n->left);
				}
				else{
					n=if(n->left !=nullptr){n->left;}
					else{n->right;}
				}
			}
			return n;
		}
		T max(BSNode<T>* n)const{
			if(n==nullptr){throw runtime_error();}
			else if(n->right != nullptr){return max(n->right);}
			else{return n->elem;}
		}
		BSNode<T>* remove_max(BSNode<T>* n){
			if(m->right==nullptr){return n->left;}
			else{
				n->right = remove_max(n->right);
				return n;
			}
		}
		void delete_cascade(BSNode<T>* n){
			if(n->left==nullptr){delete n;}
			if(n->right==nullptr){delete n;}
			if(n->left!=nullptr){delete_cascade(n->left);}
			if(n->left!=nullptr){delete_cascade(n->right);}
		}
	public:
		BSTree(){
			nelem=0;
			root=nullptr;
		}
		int size() const{
			return nelem;
		}
		T search(T e)const{
			return search(root,e)->elem;
		}
		T operator[](T e)const{
			return search (e);
		}
		
		void insert(T e){
			root=insert(root,e);
		}
		friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
		out << while(root!=nullptr){print_inorder(out,bst);} << std::endl;
		return out;
		}
		void remove(T e){
			root=remove(root,e);
		}
		~BSTree(){
			while(root!=nullptr){
				delete_cascade(root);
			}
		}
};


#endif
