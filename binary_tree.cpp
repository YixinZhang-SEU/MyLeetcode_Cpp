#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    // // 前中后序遍历：递归法
    // void traversal(TreeNode *cur, vector<int>& vec) {
    //     if (cur == NULL) {
    //         return;
    //     }
    //     vec.push_back(cur->val);
    //     traversal(cur->left, vec);
    //     traversal(cur->right, vec);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res = {};
    //     traversal(root, res);
    //     return res;
    // }

    // // 前序遍历：迭代法
    // vector<int> preorderTraversal(TreeNode* root) {
    //     stack<TreeNode*> st;
    //     vector<int> res = {};
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     st.push(root);
    //     TreeNode* temp;
    //     while (!st.empty()) {
    //         temp = st.top();
    //         res.push_back(temp->val);
    //         st.pop();
    //         // 注意：空结点不入栈，所以需要有if判定
    //         if (temp->right) {
    //             st.push(temp->right);
    //         }
    //         if (temp->left) {
    //             st.push(temp->left);
    //         } 
    //     }
    //     return res;
    // }

    // // 后序遍历：迭代法。与前序遍历对应。
    // vector<int> postorderTraversal(TreeNode* root) {
    //     stack<TreeNode*> st;
    //     vector<int> res = {};
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     st.push(root);
    //     TreeNode* temp;
    //     while (!st.empty()) {
    //         temp = st.top();
    //         res.push_back(temp->val);
    //         st.pop();
    //         // 注意：空结点不入栈，所以需要有if判定.
    //         // 左先压入栈，出栈变成右→左
    //         if (temp->left) {
    //             st.push(temp->left);
    //         }
    //         if (temp->right) {
    //             st.push(temp->right);
    //         } 
    //     }
    //     // 现在是中→右→左，反转一下就变为左→右→中，后序遍历
    //     reverse(res.begin(), res.end());
    //     return res;
    // }

    // // 中序遍历：迭代法 （理解）
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res = {};
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     stack<TreeNode*> st;
    //     TreeNode* cur = root;
    //     while (cur != nullptr || !st.empty()) {
    //         if (cur != nullptr) {    // 说明上一个访问的结点有左or右孩子，先将自己压栈，继续查看是否自己也有左孩子
    //             st.push(cur);
    //             cur = cur->left;
    //         } else {                // 说明上一个访问的结点一定没有左孩子了（这次深搜到头），那么先栈顶弹出，再查看栈顶结点有没有右孩子
    //             cur = st.top();
    //             res.push_back(cur->val);
    //             st.pop();
    //             cur = cur->right;
    //         }
    //     }
    //     return res;
    // }

    // // 前中后序遍历：标记迭代法
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res = {};
    //     stack<TreeNode*> st;
    //     TreeNode* node;
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     st.push(root);
    //     while (!st.empty()) {
    //         node = st.top();
    //         if (node != nullptr) {
    //             st.pop();
    //             // 右（因为是入栈）
    //             if (node->right) {
    //                 st.push(node->right);
    //             }
    //             // 中，并标记
    //             st.push(node);
    //             st.push(nullptr);
    //             // 左
    //             if (node->left) {
    //                 st.push(node->left);
    //             }
    //         } else {
    //             st.pop();
    //             node = st.top();
    //             res.push_back(node->val);
    //             st.pop();
    //         }
    //     }
    //     return res;
    // }

    // // 102. 二叉树的层序遍历  ||  107. 二叉树的层序遍历 II（大数组翻转一下就行了）
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     vector<vector<int> > res = {};
    //     vector<int> vec = {};
    //     TreeNode* cur;
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     q.push(root);
    //     q.push(nullptr);
    //     while (!q.empty()) {
    //         cur = q.front();
    //         if (cur == nullptr) {
    //             q.pop();
    //             vec = {};
    //         } else {
    //             q.pop();
    //             vec.push_back(cur->val);
    //             if (cur->left) {
    //                 q.push(cur->left);
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //             }
    //             if (q.front() == nullptr) {
    //                 q.push(nullptr);
    //                 res.push_back(vec);
    //             }
    //         }
    //     }
    //     return res;
    // }

    // // 199. 二叉树的右视图
    // vector<int> rightSideView(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     vector<int> res = {};
    //     TreeNode* cur;
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     q.push(root);
    //     q.push(nullptr);
    //     while (!q.empty()) {
    //         cur = q.front();
    //         q.pop();
    //         if (cur != nullptr) {
    //             if (cur->left) {
    //                 q.push(cur->left);
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //             }
    //             if (q.front() == nullptr) {
    //                 q.push(nullptr);
    //                 res.push_back(cur->val);
    //             }
    //         }
    //     }
    //     return res;
    // }

    // // 637. 二叉树的层平均值
    // vector<double> averageOfLevels(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     vector<double> res = {};
    //     double sum = 0;
    //     int count = 0;
    //     TreeNode* cur;
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     q.push(root);
    //     q.push(nullptr);
    //     sum += root->val;
    //     count = 1;
    //     while (!q.empty()) {
    //         cur = q.front();
    //         q.pop();
    //         if (cur != nullptr) {
    //             sum += cur->val;
    //             count++;
    //             if (cur->left) {
    //                 q.push(cur->left);
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //             }
    //             if (q.front() == nullptr) {
    //                 q.push(nullptr);
    //                 res.push_back(sum/(double)count);
    //                 count = 0;
    //                 sum = 0;
    //             }
    //         }
    //     }
    //     return res;
    // }
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int> > res = {};
        vector<int> vec = {};
        if (root == nullptr) {
            return res;
        }
        q.push(root);
        q.push(nullptr);
        Node* cur;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur == nullptr) {
                vec = {};
            } else {
                vec.push_back(cur->val);
                if (cur->children.size()) {    // 如果有孩子的话
                    for (Node* tmp : cur->children) {
                        q.push(tmp);
                    }
                }
                if (q.front() == nullptr) {
                    q.push(nullptr);
                    res.push_back(vec);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
}