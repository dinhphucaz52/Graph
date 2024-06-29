#include "DoThi.h"
//#include "Prim.h"
#include "Kruskal.h"

vector<Edge> graph = {
    {0, 1, 5},
    {0, 2, 6},
    {1, 2, 1},
    {1, 3, 3},
    {2, 3, 2},
    {1, 4, 1},
    {4, 3, 7},
    {4, 5, 2}
};

int main() {




    //Prim *tmp = new Prim(6, graph);
    Kruskal* tmp = new Kruskal(6, graph);

    auto mst = tmp->getMST();

    for (auto x : mst)
    {
        cout << x.u << " " << x.v << " " << x.w << endl;
    }
    return 0;

    DoThi *g = new DoThi(4);
    g->docMTK("input.txt");
    g->inDSC();
    if (g->voHuong())
    {
        int tongBac = g->tongBac();
        int bacDinh1 = g->bac(1);
    }
    else
    {
        int tongBanBacRa = g->tongBanBacRa();
        int tongBanBacVao = g->tongBanBacVao();
    }
    if (g->dayDu())
        cout << "Do thi day du";
    if (g->vong())
        cout << "Do thi vong";
    if (g->haiPhia())
        cout << "Do thi hai phia";
    g->dfs(1);
    g->bfs(1);
    int tplt = g->soThanhPhanLienThong();
    cout << tplt;
    g->lietKeThanhPhanLienThong();
    if (g->coChuTrinhDon())
        cout << "Do thi co chu trinh don";

    return 0;
}
