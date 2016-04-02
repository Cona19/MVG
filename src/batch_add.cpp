#include "batch_add.h"
#include <queue>

/*
S - Start Node
E - End Node
N - lsp iterator
PS - Passing Start Node
PE - Passing End Node
L - LSP_NEW_PATH value
*/

#define LSP_FIND(S, E) ((S)->lsp.find(E))
#define LSP_IS_EXIST(N, S) ((N) != (S)->lsp.end())

//this defines are based on that later version is added at front.
#define GET_LATEST_LSP front
#define PUSH_LATEST_LSP push_front
#define LSP_PATH_DIST(S, E) ((S) == (E) ? 0 : (S)->lsp[E].GET_LATEST_LSP().dist)
#define LSP_IS_NEED_TO_UPDATE(N, L) ((N)->second.GET_LATEST_LSP().dist > (L))


bool compareAndUpdateLSP(Node* src, Node* dest, LSPNode *new_node){
    map<Node* , LSPList>::iterator lspIt = LSP_FIND(src, dest);

    if (LSP_IS_EXIST(lspIt, src)){
        if (!LSP_IS_NEED_TO_UPDATE(lspIt, new_node->dist)){
            //branch
            return false;
        }
        if (lspIt->second.back().ver == new_node->ver)
            lspIt->second.back().dist = new_node->dist;
        else
            lspIt->second.PUSH_LATEST_LSP(*new_node);
    }
    else{
        src->lsp[dest].PUSH_LATEST_LSP(*new_node);
    }
    return true;
}

void addEdge(Node* src, Node* dest, vid_t curr_ver){
    queue<Node*> nodeQueue;
    set<Node*> foundCheck;
    Node* curr_node;
    LSPNode new_node = {0, curr_ver};
    unsigned int distToSrc = 0;

    nodeQueue.push(src);
    foundCheck.insert(src);

    while(!nodeQueue.empty()){
        curr_node = nodeQueue.front();
        nodeQueue.pop();

        distToSrc = LSP_PATH_DIST(curr_node, src);
        new_node.dist = distToSrc + 1;
        if (compareAndUpdateLSP(curr_node, dest, &new_node)){
            for (map<Node*, LSPList>::iterator it = dest->lsp.begin(); it != dest->lsp.end(); it++){
                new_node.dist = distToSrc + 1 + it->second.GET_LATEST_LSP().dist;
                compareAndUpdateLSP(curr_node, it->first, &new_node);
            }

            for (set<Node*>::iterator it = curr_node->inEdges.begin(); it != curr_node->inEdges.end(); it++){
                if (foundCheck.find(*it) == foundCheck.end()){
                    nodeQueue.push(*it);
                    foundCheck.insert(*it);
                }
            }
        }
    }
}
