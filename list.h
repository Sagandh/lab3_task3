#include "struct.h"

bool operator==(Data d1, Data d2);
Node* first(Data d);
Node* find(Node* pbeg, Data d);
void add(Node **pend, Data d);
bool remove(Node** pbeg, Node** pend, Data d);
void print_all(Node* pbeg);
Node* improve_search(Node* pbeg, Data d);