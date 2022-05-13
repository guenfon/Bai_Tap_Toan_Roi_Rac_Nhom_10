/*
    //Thuật toán bao gồm các bước sau:
        Khởi tạo tập S là cây khung hiện tại, ban đầu S chưa có đỉnh nào.
        Khởi tạo mảng D trong đó Di là khoảng cách ngắn nhất từ đỉnh i đến 1 đỉnh đã được kết nạp vào tập S, 
    ban đầu D[i] = +∞
        Lặp lại các thao tác sau n lần(n là số cạnh của đồ thị)
            Tìm đỉnh u không thuộc S có Du nhỏ nhất, thêm u vào tập S.
            Xét tất cả các đỉnh v kề u, cập nhật Dv=min(Dv,wu,v) với wu,v là trọng số cạnh u−v. 
        Nếu Dv được cập nhật theo wu,v thì đánh dấu tracev=u.
            Thêm cạnh u−trace[u] vào tập cạnh thuộc cây khung nhỏ nhất.
    //Đánh giá độ phức tạp thuật toán:
        Ta duyệt tổng cộng n lần, mỗi lần lấy 1 đỉnh ra khỏi heap mất O(logn) và cập nhật trọng số của tất cả các
    đỉnh kề với đỉnh đó, tổng số lần cập nhật là m lần, mỗi lần cập nhật ta mất độ phức tạp O(logn).
        Như vậy, độ phức tạp của thuật toán Prim là O((m+n)logn) với n là số đỉnh và m là số cạnh của đồ thị.
    //Ví dụ
    4 4
    1 2 1
    2 3 2
    3 4 3
    4 1 4
*/

#include <bits/stdc++.h>

using namespace std;
// Khai báo đồ thị
int n, m;
vector<pair<int, int>> g[100];
int D[100]; // lưu khoảng cách toàn bộ đỉnh

int Prim(int s) // thuật toán bắt đầu chạy từ đỉnh nguồn s
{
    int total_cost = 0;
    // Sử dụng priorty_queue để lưu khoảng cách của các dỉnh tăng dần
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Khởi tạo khoảng cách các đỉnh là vô cùng lớn
    for (int i = 1; i <= n; i++)
        D[i] = INT_MAX;
    D[s] = 0;
    pq.push(make_pair(0, s)); // thêm đỉnh s vào priority queue
    while (!pq.empty())
    {
        // lấy đỉnh có khoảng cách nhỏ nhất 
        auto top = pq.top();
        int curD = top.first; int u = top.second;
        pq.pop();
        if (curD != D[u])
            continue;
        //kết nạp u và cây khung
        total_cost += D[u]; D[u] -= INT_MAX;
        // cập nhập khoảng cách cho các đỉnh kề u
        for (auto& e : g[u])
        {
            int v = e.first;
            int w = e.second;
            if (D[v] > w)
            {
                D[v] = w;
                pq.push(make_pair(w, v));
            }
        }
    }
    return total_cost;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    cout << Prim(1);
    return 0;
}