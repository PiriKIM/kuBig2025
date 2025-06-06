#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct TreeNode
{
    int value;
    vector<shared_ptr<TreeNode>> children;
    TreeNode(int val) : value(val) { }
};

void printTree(const shared_ptr<TreeNode>& node, int depth = 0)
{
    if (!node)
        return;
    cout << string(depth * 2, ' ') << node->value << endl;
    for (const auto &child : node->children)
    {
        printTree(child, depth + 1);
    }
}

int main()
{
    auto root = make_shared<TreeNode>(1);
    root->children.push_back(make_shared<TreeNode>(2));
    root->children.push_back(make_shared<TreeNode>(3));
    root->children.push_back(make_shared<TreeNode>(4));
    root->children[0]->children.push_back(make_shared<TreeNode>(5));
    root->children[0]->children.push_back(make_shared<TreeNode>(6));
    root->children[1]->children.push_back(make_shared<TreeNode>(7));
    root->children[1]->children.push_back(make_shared<TreeNode>(8));
    root->children[1]->children.push_back(make_shared<TreeNode>(9));
    root->children[2]->children.push_back(make_shared<TreeNode>(0));

    printTree(root);

    return 0;
}