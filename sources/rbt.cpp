#include "rbt.h"
using namespace std;

int main()
{
	RBT<int> tree;
	tree.insert(16);
	tree.insert(5);
	tree.insert(2);
	tree.insert(6);
	tree.insert(19);
	tree.insert(7);
	tree.insert(3);
	tree.insert(8);
	tree.display(tree.root_(), 0);

	cin.get();
	return 0;
}
