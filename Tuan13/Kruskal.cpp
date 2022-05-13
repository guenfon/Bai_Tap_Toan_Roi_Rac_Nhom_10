/*
    Giả sử ta cần tìm cây khung nhỏ nhất của đồ thị G. Thuật toán bao gồm các bước sau:
        Khởi tạo rừng F (tập hợp các cây), trong đó mỗi đỉnh của G tạo thành một cây riêng biệt.
        Khởi tạo tập S chứa tất cả các cạnh của G.
        Chừng nào S còn khác rỗng và F gồm hơn một cây
            Xóa cạnh nhỏ nhất trong S
            Nếu cạnh đó nối hai cây khác nhau trong F, thì thêm nó vào F và hợp hai cây kề với nó làm một
            Nếu không thì loại bỏ cạnh đó.
    Đánh giá độ phức tạp thuật toán: Gọi n là số đỉnh, m là số cạnh của đồ thị
        Thuật toán gồm 2 phần:
            Sắp xếp mảng m cạnh theo trọng số tăng dần mất độ phức tạp O(mlogm).
            Ta duyệt m cạnh, mỗi cạnh dùng Disjoint Set mất độ phức tạp O(logn), vậy tổng cộng mất độ phức tạp O(mlogn).
        ⇒ độ phức tạp của thuật toán Kruskal là O(mlogm+mlogn)
    Ví dụ
    4 4
    1 2 1
    2 3 2
    3 4 3
    4 1 4
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int u, v, w;
};

struct Kruskal
{
    // Khai báo mảng par
    vector <int> par;
    // Khởi tạo mảng par
    void init(int n)
    {
        par.resize(n + 5, 0);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }
    // Tìm gốc của đỉnh u
    int find(int u)
    {
        if (par[u] == u)
            return u;
        return par[u] = find(par[u]);
    }
    // Gộp cạnh u, v
    bool join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        par[u] = v;
        return true;
    }
};

Kruskal kruskal;
// n, m lần lượt là số đỉnh và số cạnh của đồ thị
// total_weight là tổng trọng số của cây khung nhỏ nhất
int n, m, total_weight = 0;
// edge là mảng các cạnh của đồ thị
vector <edge> edges;

int main()
{
    //fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    kruskal.init(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    // Sắp xếp mảng edges theo trọng số tăng dần
    sort(edges.begin(), edges.end(), [](edge a, edge b) {return a.w < b.w;});
    // Duyệt mảng edges
    for (int i = 0; i < m; i++)
    {
        edge e = edges[i];
        // Nếu hợp nhất được u v ta thêm trọng số cạnh vào total_weight
        if (kruskal.join(e.u, e.v))
            total_weight += e.w;
    }
    cout << total_weight << '\n';
    return 0;
}