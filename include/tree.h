// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>
struct Node {
    bool isRoot = false;
    char value;
    std::vector<Node*> children;
};
class Tree {
 private:
    Node* root;
    std::vector<std::vector<char>> permutations;
    void insert(Node* root, const std::vector<char>& vec) {
        char c;
        for (int i = 0; i < vec.size(); i++) {
            Node* child = new Node;
            child->value = c;
            root->children.push_back(child);
            std::vector<char> remainingChars(vec);
            remainingChars.erase(std::find(remainingChars.begin(), remainingChars.begin() + i, c));
            insert(child, remainingChars);
        }
    }
    void findPerms(Node* root, std::vector<char> vec) {
        if (!root->isRoot)
            vec.push_back(root->value);
        if (root->children.empty()) {
            permutations.push_back(vec);
        } else {
            for (Node* child : root->children) {
                findPerms(child, vec);
            }
        }
    }

 public:
    explicit Tree(const std::vector<char>& vec) {
        root = new Node;
        root->isRoot = true;
        insert(root, vec);
        std::vector<char> actual;
        findPerms(root, actual);
    }
    std::vector<std::vector<char>> getPermutations() const {
        return permutations;
    }
};
#endif  // INCLUDE_TREE_H_
