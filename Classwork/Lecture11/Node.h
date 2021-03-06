#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	namespace dn
	{
		/******************************************************
		* Doubly Linked Node:
		* It generates a linked list that can move forwards 
		* and backwards.
		* Doubly Linked Node Members:
		* T data
		* Node<T>* next
		* Node<T>* prev
		* Additional Note: 
		* A doubly linked node can be reduced to a singly 
		* linked node by always making prev equal NULL
		*******************************************************/
		template <class T>
		class Node
		{
		private:
			T data;
			Node<T>* next;
			Node<T>* prev;

			Node(const Node<T>& obj);
			Node& operator=(const Node<T>& rhs);
		public:
			Node() : data(T()), prev(NULL), next(NULL) {}

			Node(const T& data) : data(data), prev(NULL), next(NULL) {}

			Node(const T& data,Node<T>* prev,Node<T>* next) : data(data), prev(prev), next(next) {}

			~Node() {}
		
			T& GetData() {return data;}

			const T& GetData() const {return data;}

			Node<T>* GetPrev() {return prev;}

			const Node<T>* GetPrev() const {return prev;}

			Node<T>* GetNext() {return next;}

			const Node<T>* GetNext() const {return next;}

			void SetData(const T& value) {data = value;}

			void SetPrev(Node<T>* link) {prev = link;}

			void SetNext(Node<T>* link) {next = link;}

			std::string ToString() const
			{
				std::stringstream out;
				out << data;
				return out.str();
			}

			friend std::ostream& operator<<(std::ostream& out,const Node<T>& obj)
			{
				out << obj.ToString();
				return out;
			}
		};

		template<typename T>
		void Clear(Node<T>*& root)
		{
			Node<T> *tmp;

			while(root != NULL)
			{
				tmp = root;
				root->SetPrev(NULL);
				root = root->GetNext();
				delete tmp;
				tmp = NULL;
			}
		}

		template<typename T>
		Node<T>* Copy(Node<T>* root)
		{
			if(root == NULL)
			{
				return NULL;
			}
			
			Node<T> *head = new Node<T>(root->GetData());
			Node<T> *tmp2 = head;
			Node<T> *tmp1 = root;

			while(tmp1->GetNext() != NULL)
			{
				tmp1 = tmp1->GetNext();
				tmp2->SetNext(new Node<T>(tmp1->GetData()));
				tmp2->GetNext()->SetPrev(tmp2);
				tmp2 = tmp2->GetNext();
			}
			return head;
		}
	}
}
		
#endif
