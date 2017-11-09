#include <iostream>
#include <bits/stdc++.h>


using namespace std;

struct Node
{
	int id;
	int freq;
	bool internal;
	Node *left, *right;

	Node(int id, int freq, bool internal)
	{
		left = NULL;
		right = NULL;
		this->id = id;
		this->freq = freq;
		this->internal = internal;
	}
};

struct compare : public std::binary_function<Node*, Node*, bool>
{
	bool operator()(const Node* left, const Node* right) const
	{
		return (left->freq >= right->freq);
		//return (left->id > right->id);
	}
};

void print(struct Node* root, string str, int id, int fq)
{
	if(!root)
	{
		return;
	}
	else if(root->id == id && root->freq == fq && root->internal == 0)
	{
		cout << str << endl;
	}
	else
	{
		print(root->left, str + "0", id, fq);
		print(root->right, str + "1", id, fq);
	}
	return;
}

void Huffman(int N,int input[],int ID[])
{
	Node *left, *right, *internal, *t;
	int smallID;
	priority_queue<Node*, vector<Node*>, compare> lists;
	priority_queue<Node*, vector<Node*>, compare> temp;

	for(int i = 0; i < N; i++)
	{
		lists.push(new Node(ID[i], input[i], 0));
	}
	temp = lists;
	while(!temp.empty())
	{
		t = temp.top();
		//cout << "id: " << t->id << " freq: " << t->freq << endl;
		temp.pop();
	}
	//cout << endl;
	while(1 == 1)
	{
		left = lists.top();
		lists.pop();
		right = lists.top();
		lists.pop();

		if(left->freq == right->freq)
		{
//			cout << "match!!" << endl;
			if(left->id < right->id)
			{
				//cout << "left smaller" << endl;
				internal = new Node(left->id, left->freq + right->freq, 1);
				internal->left = left;
				internal->right = right;
				lists.push(internal);
			}
			else if(right->id < left->id)
			{
				//cout << "right smaller" << endl;
				internal = new Node(right->id, left->freq + right->freq, 1);
				internal->left = right;
				internal->right = left;
				lists.push(internal);
			}
		}
		/*else if(left->freq < right->freq)
		{
			internal = new Node(left->id, left->freq + right->freq, 1);
			internal->left = left;
			internal->right = right;
			lists.push(internal);
		}
		else if(right->freq < left->freq)
		{
			internal = new Node(right->id, left->freq + right->freq, 1);
			internal->left = right;
			internal->right = left;
			lists.push(internal);
		}*/
		else
		{
			//cout << "here!!" << endl;
			internal = new Node(left->id, left->freq + right->freq, 1);
			internal->left = left;
			internal->right = right;
			lists.push(internal);
		}
		temp = lists;
		while(!temp.empty())
		{
			t = temp.top();
			//cout << "id: " << t->id << " freq: " << t->freq << endl;
			temp.pop();
		}
		//cout << endl;
		if(lists.size() == 1)
		{
			break;
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
	return 0;
}



