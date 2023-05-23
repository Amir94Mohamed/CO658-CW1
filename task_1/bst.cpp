#include<iostream>
#include<string>
#include"TreeNode.cpp"
using namespace std;
int glb=0;
string enc="";
char main_temp;
bool big=false;
class BST
{
	TreeNode* root;

	void insertion(TreeNode*& root,  char sent )
	{
		glb=glb+1;
		if (root == NULL)
		{
			
			if(glb>1)
			{
								// Create a new TreeNode with the given character and encoded string
				TreeNode* temp = new TreeNode(sent,enc);
				enc="";
				enc=enc+main_temp;
				root = temp;
			}
			else
			{
//				cout<<"\nbig "<<big<<endl;
				if(big==1)
				{
										// Create a new TreeNode with the given character and '1' as the encoded string					
					TreeNode* temp = new TreeNode(sent,"1");
					main_temp = '1';
					enc="";
					enc=enc+main_temp;
				    root = temp;
				}
				else
				{
										// Create a new TreeNode with the given character and '0' as the encoded string
					TreeNode* temp = new TreeNode(sent,"0");
					main_temp = '0';
					enc="";
					enc=enc+main_temp;
				    root = temp;
				}	
			}	
		}
		else if (root->sentence > sent)
		{
						// As moving towards right of any node just concatinating 0 in encoding
			enc=enc+"0";
			(insertion(root->left,  sent));
		}

		else if (root->sentence < sent)
		{
			            // As moving towards left of any node just concatinating 1 in encoding
			enc=enc+"1";
			(insertion(root->right,  sent ));
		}
		else if (root->sentence == sent)
		{
			enc="";
			enc=enc+main_temp;
			
		}

	}
	
	void display(TreeNode* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		cout <<"> "<<temp->sentence<<" "<<temp->encode << endl;
		display(temp->left);
		display(temp->right);

	}

public:

	BST()
	{
		root = NULL;
	}

	BST(TreeNode* ptr)
	{
		root = ptr;
	}
	void setRoot(TreeNode* ptr)
	{
		root = ptr;
	}
	TreeNode* getRoot()
	{
		return root;
	}
	void insert( char sen )
	{
		insertion(root, sen );
	}

	void displayInOrder()
	{
		display(root);
	}

};


