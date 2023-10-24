// DAA Assn 02
// Write a program to implement Huffman Encoding using a greedy strategy.

#include <bits/stdc++.h>
using namespace std;


class MinHeapNode{
    public:
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq){
        left = nullptr;
        right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};


class compare{
    public:
    bool operator()(MinHeapNode *l, MinHeapNode *r){
        if(l->freq == r->freq) {
            return (l->data > r->data);
        }
        return (l->freq > r->freq);
    }
};


void printCode(MinHeapNode *root, string str, unordered_map<char,string> &mp){
    if(!root) return;
    if(root->data != '#'){
        // cout<<root->data<<": "<<str<<endl;
        mp[root->data] = str;
    }
    printCode(root->left, str+"0", mp);
    printCode(root->right, str+"1", mp);
}


void HuffManCoding(vector<char> &data, vector<int> &freq, unordered_map<char,string> &mp){
    MinHeapNode *left, *right, *top;
    
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for(int i=0; i<data.size(); i++){
        MinHeapNode *temp = new MinHeapNode(data[i], freq[i]);
        minHeap.push(temp);
    }

    while(minHeap.size()!=1){
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('#', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCode(minHeap.top(), "", mp);
}


int main() {
    int n;
    cout<<"Enter number of unique characters: ";
    cin>>n;
    vector<char> data(n);
    vector<int> freq(n);
    unordered_map<char,string> res;
    
    cout<<"Enter characters array: ";
    for(int i=0; i<n; i++){
        cin>>data[i];
    }
    cout<<"Enter frequencies array: ";
    for(int i=0; i<n; i++){
        cin>>freq[i];
    }

    HuffManCoding(data, freq, res);

    for(char i : data){
        cout<<i<<": "<<res[i]<<endl;
    }

    return 0;
}



/* OUTPUT
Enter number of unique characters: 7
Enter characters array: a b c d e f g
Enter frequencies array: 15 9 6 10 2 3 1
a: 11
b: 00
c: 101
d: 01
e: 10001
f: 1001
g: 10000
*/