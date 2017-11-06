#include <iostream>
#include <bits/stdc++.h>


using namespace std;

struct Node
{
	int id;
	int freq;
	Node *left, *right;

	Node(int id, int freq)
	{
		left = NULL;
		right = NULL;
		this->id = id;
		this->freq = freq;
	}
};

struct compare
{
	bool operator()(Node* left, Node* right)
	{
		return (left->freq > right->freq);
	}
};

void print(struct Node* root, string str)
{
	if(!root)
	{
		return;
	}
	if(root->id != -1)
	{
		cout << str << endl;
	}
	
	print(root->left, str + "0");
	print(root->right, str + "1");
}

void Huffman(int N,int input[],int ID[])
{
	struct Node *left, *right, *internal;

	priority_queue<Node*, vector<Node*>, compare> lists;
	for(int i = 0; i < N; i++)
	{
		lists.push(new Node(ID[i], input[i]));
	}
	
	while(lists.size() != 1)
	{
		left = lists.top();
		lists.pop();
		
		right = lists.top();
		lists.pop();
		
		internal = new Node(-1, left->freq + right->freq);
		internal->left = left;
		internal->right = right;
		lists.push(internal);
	}
	
	print(lists.top(), "");
}




int main(int argc, char **argv)
{
	int N;
	cin >> N;
	int input[N];
	int ID[N];
	for(int i = 0; i < N; i++)
	{
		cin >> input[i];
		ID[i] = i+1;
	}
	Huffman(N, input, ID);
}



