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
    g->DocMTK("input.txt");
    //g->InDSC();
    if (g->VoHuong())
    {
        int tongBac = g->TongBac();
        int bacDinh1 = g->Bac(1);
    }
    else
    {
        int tongBanBacRa = g->TongBanBacRa();
        int tongBanBacVao = g->TongBanBacVao();
    }
    //if (g->DayDu())
        //cout << "Do thi day du";
    //if (g->Vong())
        //cout << "Do thi vong";
    //if (g->HaiPhia())
        //cout << "Do thi hai phia";
    //g->DFS(1);
    //g->BFS(1);
    //int tplt = g->SoThanhPhanLienThong();
    //cout << tplt;
    //g->LietKeThanhPhanLienThong();
    if (g->CoChuTrinhDon())
        cout << "Do thi co chu trinh don";


    return 0;
}
