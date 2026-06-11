struct Node{
    vector<Node*> links{26,nullptr};
    bool f=false;
    Node* getRef(char c){
        return links[c-'a'];
    }
    bool contains(char c){
        return links[c-'a']!=nullptr;
    }
    void set(char c, Node* temp){
        links[c-'a']=temp;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void setEnd(){
        f=true;
    }
    bool isEnd(){
        return f;
    }
};

class PrefixTree {
private:
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for (int i=0; i<word.size(); i++){
            if (!node->contains(word[i])){
                node->set(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for (int i=0; i<word.size(); i++){
            if (!node->contains(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
       Node* node=root;
        for (int i=0; i<prefix.size(); i++){
            if (!node->contains(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return true;  
    }
};
