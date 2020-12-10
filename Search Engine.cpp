# C_N_Tries
#include<bits/stdc++.h>
using namespace std;

class trinode
{
public:
	trinode** children;
	int w;
	trinode()
	{
		children = new trinode*[26];
		for (int i = 0; i < 26; i++)
		{
			children[i] = NULL;
		}
		w = 0;
	}
};

void insert(string s, int w, trinode* root)
{
	if (s.empty())
	{
		return;
	}
	trinode* child;
	int index = s[0] - 'a';
	if (root->children[index])
	{
		child = root->children[index];
	}
	else
	{
		child = new trinode();
		root->children[index] = child;
	}
	if (root->w < w)
	{
		root->w = w;
	}
	insert(s.substr(1), w, child);
}

int searchbest(string s, trinode* root)
{
	trinode* curr = root;
	int bestw = -1;
	for (int i = 0; i < s.length(); i++)
	{
		int index = s[i] - 'a';
		trinode* child = curr->children[index];
		if (child)
		{
			curr = child;
			bestw = child->w;
		}
		else
		{
			return -1;
		}
	}
	return bestw;
}

int main()
{

	int n, q;
	cin >> n >> q;
	trinode* root = new trinode();
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int w;
		cin >> w;

		insert(s, w, root);
	}

	for (int i = 0; i < q; i++)
	{
		string pre;
		cin >> pre;
		cout << searchbest(pre, root) << endl;
	}

	return 0;
}
