struct Node{
    vector<Node*> links{26,nullptr};
    bool flag = false;
    Node* get(char c){
        return links[c-'a'];
    }
    void put(char c, Node* node){
        links[c-'a']=node;
    }
    bool contains(char c){
        return links[c-'a']!=nullptr;
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (int i=0 ;i<word.size(); i++){
            if (!node->contains(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return helper(0,word, root);
    }

    bool helper(int start, string word, Node* node){
        if (start==word.size()) return node->isEnd();
        if (word[start]!='.' && node->contains(word[start])){
            return helper(start+1, word, node->get(word[start]));
        }
        if (word[start]!='.') return false;
        for (char ch='a'; ch<='z'; ch++){
            if (node->contains(ch)){
                word[start]=ch;
                if (helper(start+1,word,node->get(ch))) return true;
                word[start]='.';
            }
        }
        return false;
    }
};
