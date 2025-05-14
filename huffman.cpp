#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//first keep the node with ch ,freq and left right
struct Node{
  char ch;
  int freq;
  Node* left,*right;
  Node(char c,int f){
      ch = c;
      freq = f;
      left = nullptr;
      right = nullptr;
  }
};
//build a operator compare
struct Compare{
  bool operator()(Node*a,Node* b){
      return a->freq>b->freq;
  }  
};

//to generateCodes recursively take root and if it is leaf then just add current else appennd 0 for left and 1 for right
void generateCodes(Node* root,string currentCode,unordered_map<char,string> &codes){
    if (!root)return;
    if (!root->left && !root->right){
        codes[root->ch]=currentCode;
        return;
    }
    generateCodes(root->left,currentCode + '0',codes);
    generateCodes(root->right,currentCode + '1',codes);
}

int main()
{
    string pattern;
    cin>>pattern;
    //count freq for  pattern
    unordered_map<char,int> freq;
    for (char c:pattern){
        freq[c]++;
    }
    priority_queue<Node *,vector<Node*>,Compare>minHeap;
    for (auto pair:freq){
        minHeap.push(new Node(pair.first,pair.second));
    }
    //till there is more than one in minHeap just keep combining
    while (minHeap.size()>1){
        Node* left = minHeap.top();minHeap.pop();
        Node* right = minHeap.top();minHeap.pop();
        Node * combine = new Node('\0',left->freq+right->freq);
        combine->left = left;
        combine->right = right;
        minHeap.push(combine);
        
    }
    //generate Codes and then print it
    Node* root = minHeap.top();
    unordered_map<char,string> codes;
    generateCodes(root,"",codes);
    
    // Print Huffman codes
    cout << "\nHuffman Codes:\n";
    for (auto pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
