#include<bits/stdc++.h>
using namespace std;

class trinode
{
public:
	trinode* left;
	trinode* right;
};

int maxi = INT_MIN;

void insert(trinode* head, int n)
{
	trinode* curr = head;
	for (int i = 31; i >= 0; i--)
	{
		int b = (n >> i) & 1;
		if (b == 0)
		{
			if (!curr->left)
			{
				curr->left = new trinode();
			}
			curr = curr->left;
		}
		else
		{
			if (!curr->right)
			{
				curr->right = new trinode();
			}
			curr = curr->right;
		}
	}
}

int max_xor(int value,  trinode* head)
{

	//int maxi = INT_MIN;
	if (maxi < value)
		maxi = value;


	//int value = a[i];
	int curr_xor = 0;
	trinode* curr = head;
	for (int j = 31; j >= 0; j--)
	{
		int b = (value >> j) & 1;
		if (b == 0)
		{
			if (curr->right)
			{
				curr_xor += pow(2, j);
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}
		}
		else
		{
			if (curr->left)
			{
				curr_xor += pow(2, j);
				curr = curr->left;
			}
			else
			{
				curr = curr->right;
			}
		}
	}

	//cout << curr_xor << " ";
	//cout << endl;
	if (curr_xor > maxi)
	{
		maxi = curr_xor;
	}

	return maxi;
}

int main()
{

	//int arr[6] = {8, 1, 2, 15, 10, 5};
	trinode* head = new trinode();
	int n;
	cin >> n;
	int* a = new int[n];
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		//insert(head, a[i]);
	}
	//int maxi* =INT_MIN;
	int final;
	for (int i = 0; i < n; i++)
	{
		ans = ans ^ a[i];
		insert(head, ans);
		final = max(maxi, max_xor(ans,  head) );
	}
	cout << final;

	//cout << max_xor(a, n, head);
}
