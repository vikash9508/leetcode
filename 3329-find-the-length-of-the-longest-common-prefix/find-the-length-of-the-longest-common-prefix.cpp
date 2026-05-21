class TrieNode {
public:
    TrieNode* child[10];

    TrieNode() {
        for(int i=0;i<10;i++)
            child[i]=NULL;
    }
};

class Solution {
public:
    void insert(TrieNode* root,string s){
        TrieNode* node=root;

        for(char ch:s){
            int idx=ch-'0';

            if(node->child[idx]==NULL)
                node->child[idx]=new TrieNode();

            node=node->child[idx];
        }
    }

    int search(TrieNode* root,string s){
        TrieNode* node=root;
        int len=0;

        for(char ch:s){
            int idx=ch-'0';

            if(node->child[idx]==NULL)
                break;

            len++;
            node=node->child[idx];
        }

        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        TrieNode* root=new TrieNode();

        for(int x:arr1){
            insert(root,to_string(x));
        }

        int ans=0;

        for(int x:arr2){
            ans=max(ans,search(root,to_string(x)));
        }

        return ans;
    }
};