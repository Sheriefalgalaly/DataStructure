#include <iostream>
#include <cassert>
using namespace std;

struct Node {
	int data {};
	Node* next {};
	Node(int data) : data(data) {}
};

class LinkedList {
private:
	Node *head { };
	Node *tail { };
public:

	void print() {
		// DON'T change head itself.
		// 		You will lose it
		Node* temp_head = head;
		while(temp_head != nullptr) {
			cout<<temp_head->data<<" ";
			temp_head = temp_head->next;
		}
		cout<<"\n";
	}

	void insert_end(int value) {
		Node* item = new Node(value);

		if (!head)
			head = tail = item;
		else {
			tail->next = item;
			tail = item;
		}
	}
    Node* get_nth(int n){
   int cntr=0;
   for (Node* cur = head ;cur ;cur = cur->next)
    if (++cntr == n)
     return cur;

  return nullptr;
	// This code has memory leak, as we did not free memory
    }
    int Search (int n){
        int cntr=0;
       for (Node* cur = head ;cur ;cur = cur->next,cntr++)
        if (cur -> data == n)
          return cntr;
       return -1 ;


    }


    int Improved_Search(int i){
        int cntr=0;
       for (Node *cur = head , *prev = nullptr ;cur ; prev =cur,cur = cur->next,cntr++){
        if (cur->data==i){
          if (!prev)
            return 0;
          swap(cur -> data,prev->data );
          return cntr -1;
            }
       }
return -1;
    }
};

int main() {

	LinkedList list;

	list.insert_end(6);
	list.insert_end(10);
	list.insert_end(8);
	list.insert_end(15);
    list.insert_end(150);
	list.print();
	/********************************/
    int i =list.get_nth(4)->data;
    cout<<i<<" ";
    int i1 =list.Search(15);
    cout<<i1;
   int i2= list.Improved_Search(150);
    cout<<"\n"<<i2<<"\n";
   	list.print();             //6 10 15 8  150
	return 0;
}


