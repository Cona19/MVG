#pragma once
#include <map>
#include <set>
#include <list>

#include "config.h"

using namespace std;

typedef unsigned int vid_t;
typedef unsigned int nid_t;

struct Node;
struct LSPNode;
struct Cluster;
struct Bridge;
struct ValidNode;

typedef list<LSPNode> LSPList;

struct Node{
    Cluster *cluster;
    set<Node*> inEdges;
    set<Node*> outEdges;
    map<Node*, LSPList> lsp;
#ifdef LSP_TEST
    nid_t nid;
#endif
};

struct LSPNode{
    unsigned int dist;//if we can't reach there, set 0. otherwise, set shortest path distance.
    vid_t ver;
};

struct Cluster{
    list<Bridge> inBridges;
    list<Bridge> outBridges;
    bool isUpdating;
    unsigned int size;
};

struct Bridge{
    Node *src;
    Node *dest;
    list<ValidNode> validList;
};

struct ValidNode{
    bool isValid;
    vid_t ver;
};
