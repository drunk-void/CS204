#include <bits/stdc++.h>
using namespace std;

class treeNode {
    public:
        string data;
        vector<treeNode*> point;
};

treeNode* createNode() {
    treeNode* temp=new treeNode();
}

void addData(string data, treeNode* root) {
    root->data=data;
}

treeNode* addChild(treeNode* root) {
    root->point.push_back(NULL);
    return root->point[root->point.size()-1];
}

int main() {
    int k=1;
    string name;
    treeNode* root=new treeNode();
    treeNode* temp;
    int count=0;
    while(k!=0) {
        cin>>k;
        for(int i=0;i<k;i++) {
            temp=new treeNode();
            cin>>name;
            temp->data=name;
            root->point.push_back(temp);
        }
    }
}