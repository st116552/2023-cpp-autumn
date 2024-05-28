#include<iostream>

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int data, Node* left = 0, Node* right = 0) :
		data(data), left(left), right(right) {}
    Node(const Node& node) : data(0), left(0), right(0)
    {
        this->data = node.data;
        this->left = node.left;
        this->right = node.right;
    }
    Node(Node&& node) noexcept
    {
        this->data = node.data;
        this->left = node.left;
        this->right = node.right;
        node.data = 0;
        node.left = 0;
        node.right = 0;
    }
    Node& operator=(Node& src)
    {
        if (this != &src)
        {
            this->data = src.data;
            this->left = src.left;
            this->right = src.right;
        }
        return *this;
    }
    friend bool operator==(Node n1, Node n2)
    {
        return (n1.data == n2.data);
    }
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data;
		return stream;
	}
};

class BTree
{
public:
	BTree() : root(0) {}
    BTree(const BTree& src) : root(0)
    {
        dispose(root);
        this->root = copy(src.root);

    }
    Node* copy (Node* src)
    {
        if (src == 0)
        {
            return 0;
        }
        Node* ans = new Node(src->data);
        ans->left = copy(src->left);
        ans->right = copy(src->right);
        return ans;
    }
    BTree(BTree&& src) noexcept
    {
        dispose(root);
        this->root = copy(src.root);
        dispose(src.root);
    }
    BTree& operator=(BTree& src)
    {
        if (this != &src)
        {
            dispose(root);
            this->root = copy(src.root);
        }
        return *this;
    }
    bool sameTree(BTree bt)
    {
        return sameSubTree(this->root, bt.root);
    }
    bool sameSubTree(Node* n1, Node* n2)
    {
        if ((n1 == 0) && (n2 == 0))
        {
            return true;
        }
        if ((n1 == 0) || (n2 == 0))
        {
            return false;
        }
        if (n1->data == n2->data)
        {
            return (sameSubTree(n1->left, n2->left) && sameSubTree(n1->right,n2->right));
        }
        return false;
    }
    friend bool operator==(BTree bt1, BTree bt2)
    {
        return bt2.sameTree(bt1);
    }
   
	~BTree()
	{
		dispose(root);
	}
	void Add(int data)
	{
		add(root, data);
	}
	void Remove(int data)
	{
		Node* node = extractNode(searchNode(root, data));
		if (node != 0)
		{
			delete node;
		}
	}
	friend std::ostream& operator<<(std::ostream& stream, BTree& tree)
	{
		stream << "__________TREE START___________" << std::endl;
		tree.printLineTree(stream, tree.root);
		stream << std::endl;
		stream << "_______________________________" << std::endl;
		tree.printVerticalTree(stream, tree.root);
		stream << "__________TREE  END ___________" << std::endl;
		return stream;
	}
private:
	Node* root;
	void dispose(Node*& node)
	{
		if (node != 0) //if(node)
		{
			dispose(node->left);
			dispose(node->right);
			delete node;
		}
	}
	void add(Node*& node, int data)
	{
		if (node == 0)
		{
			node = new Node(data);
		}
		else if (node->data > data)
		{
			add(node->left, data);
		}
		else if (node->data < data)
		{
			add(node->right, data);
		}
	}
	void printVerticalTree(std::ostream& stream, Node*& node, int depth = 0)
	{
		if (node == 0)
		{
			return;
		}
		printVerticalTree(stream, node->left, depth + 1);
		for (int i = 0; i < depth; ++i)
		{
			stream << "\t";
		}
		stream << node << std::endl;
		printVerticalTree(stream, node->right, depth + 1);
	}
	void printLineTree(std::ostream& stream, Node*& node)
	{
		if (node == 0)
		{
			return;
		}
		printLineTree(stream, node->left);
		stream << node << " ";
		printLineTree(stream, node->right);
	}
	Node*& searchNode(Node*& node, int data)
	{
		if (node == 0 || node->data == data)
		{
			return node;
		}
		if (node->data > data)
		{
			return searchNode(node->left, data);
		}
		else
		{
			return searchNode(node->right, data);
		}
	}
	Node* extractNode(Node*& node)
	{
		if (node == 0)
		{
			return node;
		}
		if (node->left == 0 && node->right == 0)
		{
			Node* temp = node;
			node = 0;
			return temp;
		}
		if (node->left == 0)
		{
			Node* temp = node;
			node = node->right;
			temp->right = temp->left = 0;
			return temp;
		}
		if (node->right == 0)
		{
			Node* temp = node;
			node = node->left;
			temp->right = temp->left = 0;
			return temp;
		}
		Node* leftMostRight = 0;
		if (node->right->left == 0)
		{
			leftMostRight = extractNode(node->right);
		}
		else
		{
			leftMostRight = node->right;
			while(leftMostRight->left->left != 0)
			{
				leftMostRight = leftMostRight->left;
			}
			leftMostRight = extractNode(leftMostRight->left);
		}
		Node* res = node;
		leftMostRight->left = node->left;
		leftMostRight->right = node->right;
		node = leftMostRight;
		return res;
	}
};

int main(int argc, char* argv[])
{
	BTree tree;
	tree.Add(6);
	tree.Add(1);
	tree.Add(10);
	tree.Add(7);
	tree.Add(5);
	tree.Add(3);
	tree.Add(8);
	tree.Add(9);
	std::cout << tree << std::endl;
    BTree tree2 = BTree(tree);
	std::cout << tree2 << std::endl;
    BTree tree3 = tree;
	std::cout << tree3 << std::endl;
	std::cout << (tree == tree2) << std::endl;
	std::cout << (tree == tree3) << std::endl;

    tree2.Add(17);
    tree3.Remove(9);
	std::cout << (tree == tree2) << std::endl;
	std::cout << (tree == tree3) << std::endl;
	

	return 0;
}