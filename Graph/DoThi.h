#include <vector>
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
using namespace std;
class DoThi
{
private:
    int V;
    int E;
    bool isVoHuong;
    std::vector<int> _banBacRa;
    std::vector<int> _banBacVao;
    std::vector<int>* adj;
    bool checkVoHuong(const std::vector < std::vector<bool>>& a);
    bool checkChuTrinh(int u, int parent);
    std::vector<bool> vst = vector<bool>(2);
public:
    DoThi(int V);
    void DocMTK(std::string path);
    void InDSC();
    void INDSK();
    bool VoHuong();
    int TongBac();
    int Bac(int vertex);
    int TongBanBacRa();
    int TongBanBacVao();
    int BanBacRa(int vertex);
    int BanBacVao(int vertex);
    bool DayDu();
    bool Vong();
    bool HaiPhia();
    void DFS(int vertex);
    void BFS(int vertex);
    int SoThanhPhanLienThong();
    void LietKeThanhPhanLienThong();
    bool CoChuTrinhDon();
};