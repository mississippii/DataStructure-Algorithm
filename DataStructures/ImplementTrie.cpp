#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

struct TrieNode{
    bool flag;
    TrieNode* ara[26];
    TrieNode(){
        flag = false;
        for(int i=0; i<26;i++)ara[i]=NULL;
    }
};

void InsertIntoTrie(TrieNode *root,string &str){
    for(auto x : str){
        int id  = x-'a';
        if(!root->ara[id]){
            root->ara[id]= new TrieNode();
        }
        root = root->ara[id];
    }
    root->flag = true;
    return;
}

bool FindingString(TrieNode *root,string &str){
    for(auto x : str){
        int id = x-'a';
        if(!root->ara[id])return false;
        root=root->ara[id];
    }
    return root->flag;
}

int DeleteFromTrie(TrieNode* root){
    for(int i=0;i<26;i++)
        if(root->ara[i])
            DeleteFromTrie(root->ara[i]);

    delete root;
}

int main() {

        string arrayOfString[]={"hello","apple","cherry","mango","banana","apply"};
        TrieNode *root=new TrieNode();
        for(auto str :arrayOfString){
            InsertIntoTrie(root,str);
        }
        string str[]={"apply","cherry","jackpot"};
        for(auto x : str){
            if(FindingString(root,x))cout<<x<<"  is Present in Prefix Tree or Trie"<<endl;
            else cout<<x<<"  is not Present in Prefix Tree or Trie"<<endl;
        }
        DeleteFromTrie(root);

    return 0;
}

