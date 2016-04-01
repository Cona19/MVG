#include <map>
#include <set>
#include <list>

typedef unsigned int vid_t;
typedef unsigned int nid_t;

typedef std::list<LSPNode> LSPList;

struct Node{
    Cluster *cluster;
    std::set<Node*> inEdges;
    std::set<Node*> outEdges;
    std::map<Node*, LSPList> lsp;
};

struct LSPNode{
    unsigned int dist;//if we can't reach there, set 0. otherwise, set shortest path distance.
    vid_t ver;
};

struct Cluster{
    std::list<Bridge> inBridges;
    std::list<Bridge> outBridges;
    bool isUpdating;
    unsigned int size;
};

struct Bridge{
    Node *src;
    Node *dest;
    std::list<ValidNode> validList;
}

struct ValidNode{
    bool isValid;
    vid_t ver;
}
