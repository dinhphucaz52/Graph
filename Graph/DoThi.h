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
    void docMTK(std::string path);
    void inDSC();
    void inDSK();
    bool voHuong();
    int tongBac();
    int bac(int vertex);
    int tongBanBacRa();
    int tongBanBacVao();
    int banBacRa(int vertex);
    int banBacVao(int vertex);
    bool dayDu();
    bool vong();
    bool haiPhia();
    void dfs(int vertex);
    void bfs(int vertex);
    int soThanhPhanLienThong();
    void lietKeThanhPhanLienThong();
    bool coChuTrinhDon();
};