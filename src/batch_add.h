#include "types.h"

/*
S - Start Node
E - End Node
N - lsp iterator
P - Passing Node
L - LSP_NEW_PATH value
*/
#define LSP_FIND(S, E) ((S)->lsp.find(E))
#define LSP_IS_EXIST(N, S) ((N) != (S)->lsp.end())
#define LSP_NEW_PATH(S, P, E) ((S)->lsp[P].back().dist + (P)->lsp[E].back().dist)
#define LSP_IS_NEED_TO_UPDATE(N, L) ((N)->second.back().dist > (L))


bool updateLSP(Node* src, Node* dest, Node* updatedNode, vid_t curr_ver);

void addEdge(Node* src, Node* dest, vid_t curr_ver);
