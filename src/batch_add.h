#pragma once
#include "types.h"

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

#define GET_LATEST_LSP front
#define PUSH_LATEST_LSP push_front

#define LSP_NEW_PATH(S, PS, PE, E) ((S == PS ? 0 : (S)->lsp[PS].GET_LATEST_LSP().dist) + 1 + (PE == E ? 0 : (PE)->lsp[E].GET_LATEST_LSP().dist))
#define LSP_IS_NEED_TO_UPDATE(N, L) ((N)->second.GET_LATEST_LSP().dist > (L))


void addEdge(Node* src, Node* dest, vid_t curr_ver);
