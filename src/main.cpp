#include "batch_add.h"

std::map<nid_t, Node> nodes;

vid_t global_ver = 1;

int main(int argc, char *argv[]){
    FILE *in=fopen("input.txt","w");

    while(1){
        int a, b;
        fscanf(in, "%d", &a);
        if (a == -1){
            global_ver++;
            continue;
        }
        fscanf(in, "%d", &b);
        Node A = nodes[a];
        Node B = nodes[b];
        A.outEdges.insert(B);
        B.inEdges.insert(A);
        addEdge(A, B, global_ver);
    }
    fclose(in);
    return 0;
}
