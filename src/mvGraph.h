#include "types.h"
#include <vector>


/*
S - Start Node
E - End Node
N - lsp iterator
P - Passing Node
*/
#define LSP_FIND(S, E) ((S)->lsp.find(E))
#define LSP_IS_EXIST(N, S) ((N) != (S)->lsp.end())
#define LSP_NEW_PATH(S, P, E) ((S)->lsp[P].back().dist + (P)->lsp[E].back().dist)
#define LSP_IS_NEED_TO_UPDATE(N, S, P, E) ((N)->second.back().dist > LSP_NEW_PATH(S, P, E))


std::map<nid_t, Node> nodes;

bool updateLSP(Node* src, Node* dest, Node* updatedNode, vid_t curr_ver){
    std::queue<Node*> nodeQueue;
    std::set<Node*> foundCheck;
    Node* curr_node;

    std::map<nid_t, LSPList>::iterator lspIt;

    lspIt = LSP_FIND(updatedNode, dest);
    //if this node don't have to use this new edge, return false;
    if (LSP_IS_EXIST(lspIt, updatedNode) && !LSP_IS_NEED_TO_UPDATE(lspIt, updatedNode, src, dest)){
        return false;//update is not used
    }

    nodeQueue.push(dest);
    foundCheck.insert(dest);

    while(!nodeQueue.empty()){
        curr_node = nodeQueue.front();
        nodeQueue.pop();

        //if this node don't have to use this new edge, branch it;
        lspIt = LSP_FIND(updatedNode, curr_node);
        if (LSP_IS_EXIST(lspIt, updatedNode)){
            if (!LSP_IS_NEED_TO_UPDATE(lspIt, updatedNode, src, curr_node)){
                //branch
                continue; 
            }
            lstIt->second.push_back({LSP_NEW_PATH(updatedNode, src, curr_node), curr_ver})
        }
        else{
            updatedNode->lsp[curr_node].push_back({LSP_NEW_PATH(updatedNode, src, curr_node), curr_ver});
        }

        for (std::set<Node*>::iterator it = curr_node->outEdges.begin(); it != curr_node->outEdges.end(); it++){
            if (foundCheck.find(*it) == foundCheck.end()){
                nodeQueue.push(*it);
            }
        }
    }
}

/*
1. src에 도달가능한 node들을 src부터 역으로 bfs탐색한다.
2. 발견한 node n1에 대해서 dest시작으로 bfs탐색을 한번 더 수행한다.
    1) 여기서 발견된 노드 n2에 대해서 경로가 갱신가능한지를 확인한다.
        (1) 갱신가능하다면 n2에 연결된 다음 노드들을 탐색하여 큐에 추가한다.
        (2) 갱신이 불가능하다면 더이상 찾지 않고 n2에 대한 탐색을 종료한다.
    2) 만약 dest노드부터 갱신이 불가능하다면 n1의 이전 노드들을 탐색하지 않고 종료한다.

*/
void addEdge(Node* src, Node* dest, vid_t curr_ver){
    std::queue<Node*> nodeQueue;
    std::set<Node*> foundCheck;
    Node* curr_node;

    nodeQueue.push(src);
    foundCheck.insert(src);

    while(!nodeQueue.empty()){
        curr_node = nodeQueue.front();
        nodeQueue.pop();

        if (!updateLSP(src, dest, curr_node, curr_ver)) continue;

        for (std::set<Node*>::iterator it = node->inEdges.begin(); it != node->inEdges.end(); it++){
            if (foundCheck.find(*it) == foundCheck.end()){
                nodeQueue.push(*it);
            }
        }
    }
}
