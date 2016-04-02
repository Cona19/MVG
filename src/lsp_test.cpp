#include "lsp_test.h"
#include <stdio.h>

#ifdef LSP_TEST
FILE *fp = stdout;

void lspTest(){
    for (map<nid_t, Node>::iterator it = nodes.begin(); it != nodes.end(); it++){
        fprintf(fp, "%u Node\n", it->first);
        Node *curr_node = &(it->second);
        fprintf(fp, "inEdges : ");
        for (set<Node*>::iterator it2 = curr_node->inEdges.begin(); it2 != curr_node->inEdges.end(); it2++){
            fprintf(fp, "%u ", (*it2)->nid);
        }
        fprintf(fp, "\nOutEdges : ");
        for (set<Node*>::iterator it2 = curr_node->outEdges.begin(); it2 != curr_node->outEdges.end(); it2++){
            fprintf(fp, "%u ", (*it2)->nid);
        }
        fprintf(fp, "\nlsp\n");
        for (map<Node*, LSPList>::iterator it2 = curr_node->lsp.begin(); it2 != curr_node->lsp.end(); it2++){
            fprintf(fp, "  %u : ", it2->first->nid);
            for (LSPList::iterator it3 = it2->second.begin(); it3 != it2->second.end(); it3++){
                fprintf(fp, "    {d:%u,v:%u}\n", it3->dist, it3->ver);
            }
            fprintf(fp, "\n");
        }
    }
}
#endif
