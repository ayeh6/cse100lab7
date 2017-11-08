#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int id;
	int freq;
	int prio;
	Node *left, *right;

	Node(int id, int freq, int prio)
	{
		left = NULL;
		right = NULL;
		this->id = id;
		this->freq = freq;
		this->prio = prio;
	}
};

struct compare
{
	bool operator()(Node* left, Node* right)
	{
		return (left->freq > right->freq);
	}
};

void print(struct Node* root, string str, int id, int fq)
{
	if(root == NULL)
	{
		return;
	}
	if(root->id == id && root->freq == fq)
	{
		cout << str << endl;
	}

	print(root->left, str + "0", id, fq);
	print(root->right, str + "1", id, fq);
}

void Huffman(int N,int input[],int ID[])
{
	struct Node *left, *right, *internal, *temp;

	priority_queue<Node*, vector<Node*>, compare> lists;

	for(int i = 0; i < N; i++)
	{
		lists.push(new Node(ID[i], input[i], 0));
	}

	while(lists.size() != 1)
	{
		left = lists.top();
		lists.pop();

		right = lists.top();
		lists.pop();

		internal = new Node(-1, left->freq + right->freq, 1);
		if(left->id == -1 || right->id == -1)
		{
			if(left->id == -1)
			{
				internal->left = left;
				internal->right = right;
				lists.push(internal);
			}
			else
			{
				internal->right = left;
				internal->left = right;
				lists.push(internal);
			}
		}
		else
		{
			internal->left = left;
			internal->right = right;
			lists.push(internal);
		}
	}
	for(int i = 0; i < N; i++)
	{
		print(lists.top(), "" , ID[i], input[i]);
	}
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



