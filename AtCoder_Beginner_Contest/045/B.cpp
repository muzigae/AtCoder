#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<queue<int> > C(3);
    for (int i = 0; i < 3; i++) {
        string deck; cin >> deck;
        for (auto card : deck) C[i].push(card - 'a');
    }

    int player = 0;
    while (1) {
        if (C[player].empty()) return !(cout << char(player + 'A'));
        int next_player = C[player].front();
        C[player].pop(); player = next_player;
    }
}
