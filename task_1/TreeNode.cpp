# include <iostream>
using namespace std;
class TreeNode
{
public:


	char sentence;
	string encode;
	TreeNode* left;
	TreeNode* right;

	TreeNode()
	{
	
		sentence = '\0';
		left = NULL;
		right = NULL;

	}

	TreeNode(char sent,string enc )
	{
		encode=enc;
		sentence = sent;
		left = NULL;
		right = NULL;

	}

};


