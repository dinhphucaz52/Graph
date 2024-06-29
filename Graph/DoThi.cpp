#include "Dothi.h"

bool DoThi::checkVoHuong(const std::vector<std::vector<bool>>& a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
            if (a[i][j] != a[j][i])
                return false;
    }
    return true;
}

bool DoThi::checkChuTrinh(int u, int parent)
{
    vst[u] = true;
    for (int v : adj[u])
    {
        if (!vst[v])
            if (checkChuTrinh(v, u))
                return true;
        else if (v != parent)
            return true;
    }
    return false;
}

DoThi::DoThi(int V)
{
    this->V = V;
    this->E = 0;
    this->isVoHuong = false;
    this->_banBacRa.resize(V);
    this->_banBacVao.resize(V);
    this->vst.resize(V);
    this->adj = new std::vector<int>[V];
}

void DoThi::docMTK(std::string path)
{

    ifstream ifs(path);
    bool w;
    std::vector<std::vector<bool>> a = std::vector<std::vector<bool>>(this->V, std::vector<bool>(this->V));
    for (int u = 0; u < this->V; u++)
        for (int v = 0; v < this->V; v++)
        {
            ifs >> w;
            a[u][v] = w;
            if (w)
            {
                this->_banBacRa[u]++;
                this->_banBacVao[v]++;
                this->E++;
                this->adj[u].push_back(v);
            }
        }
    isVoHuong = checkVoHuong(a);
}

void DoThi::inDSC()
{
    for (int u = 0; u < this->V; u++) {
        cout << u << " : ";
        for (auto v : this->adj[u])
            cout << v << " ";
        cout << "\n";
    }
}

void DoThi::inDSK()
{
    for (int u = 0; u < this->V; u++) {
        for (auto v : this->adj[u])
            cout << u << " " << v << "\n";
    }
}

bool DoThi::voHuong()
{
    return isVoHuong;
}

int DoThi::tongBac()
{
    return this->E * 2;
}

int DoThi::bac(int vertex)
{
    return (int)this->adj[vertex].size();
}

int DoThi::tongBanBacRa()
{
    return this->E;
}

int DoThi::tongBanBacVao()
{
    return this->E;
}

int DoThi::banBacRa(int vertex)
{
    return this->_banBacRa[vertex];
}

int DoThi::banBacVao(int vertex)
{
    return this->_banBacVao[vertex];
}

bool DoThi::dayDu()
{
    return V * (V - 1) / 2 == E;
}

bool DoThi::vong()
{
    if (V * 2 != E || this->soThanhPhanLienThong() != 1)
        return false;
    return true;
}

bool DoThi::haiPhia()
{
    // 0 -> White
    // 1 -> Black
    vector<int> isWhite(this->V, -1);
    queue<int> q;
    q.push(0);
    isWhite[0] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (isWhite[v] == -1)
            {
                isWhite[v] = (!isWhite[u]);
            }
            else if (isWhite[v] == isWhite[u])
                return false;
        }
    }
    return true;
}

void DoThi::dfs(int vertex)
{
    std::stack<int> s;
    std::vector<bool> vst(this->V);
    s.push(vertex);
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        if (vst[u])
            continue;
        cout << u << " ";
        for (auto v : adj[u])
            s.push(v);
        vst[u] = true;
    }
    cout << endl;
}

void DoThi::bfs(int vertex)
{
    std::queue<int> q;
    std::vector<bool> vst(this->V);
    q.push(vertex);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (vst[u])
            continue;
        for (auto v : adj[u])
            q.push(v);
        vst[u] = true;
    }
}

int DoThi::soThanhPhanLienThong()
{
    int cnt = 0;
    std::vector<bool> vst(this->V);
    for (int u = 0; u < this->V; u++)
    {
        if (!vst[u])
        {
            cnt++;
            std::queue<int> q;
            q.push(u);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                if (vst[u])
                    continue;
                for (auto v : adj[u])
                    q.push(v);
                vst[u] = true;
            }
        }
    }
    return cnt;
}

void DoThi::lietKeThanhPhanLienThong()
{
    std::vector<std::vector<int>> res;
    std::vector<bool> vst(this->V);
    for (int u = 0; u < this->V; u++)
    {
        if (!vst[u])
        {
            std::vector<int> tmp;
            std::queue<int> q;
            q.push(u);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                if (vst[u])
                    continue;
                tmp.push_back(u);
                for (auto v : adj[u])
                    q.push(v);
                vst[u] = true;
            }
            res.push_back(tmp);
        }
    }
    for (auto x : res)
    {
        for (auto u : x)
            std::cout << u << " ";
        std::cout << "\n";
    }
}

bool DoThi::coChuTrinhDon()
{
    for (int u = 0; u < this->V; u++)
        this->vst[u] = false;
    return this->checkChuTrinh(0, -1);
}