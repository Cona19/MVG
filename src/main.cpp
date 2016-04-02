#include <stdio.h>

#include "batch_add.h"
#ifdef LSP_TEST
#include "lsp_test.h"
#endif

std::map<nid_t, Node> nodes;

vid_t global_ver = 1;

int main(int argc, char *argv[]){
    FILE *in=fopen("input.txt","r");
    nid_t a = 0, b = 0;

    if (in == NULL) return 0;

    while(fscanf(in, "%u", &a) == 1){
        if (a == 0){
            global_ver++;
            continue;
        }
        fscanf(in, "%u", &b);
        Node *A = &nodes[a];
        Node *B = &nodes[b];
#ifdef LSP_TEST
        A->nid = a;
        B->nid = b;
#endif
        A->outEdges.insert(B);
        B->inEdges.insert(A);
        addEdge(A, B, global_ver);
    }

#ifdef LSP_TEST
    lspTest();
#endif

    fclose(in);
    return 0;
}
