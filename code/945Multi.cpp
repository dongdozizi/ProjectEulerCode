#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

using ll = long long;
ll N = 10000000;
ll cantMask = 0;

mutex mtx;
ll globalAns = 0;
ll globalTmp = 0;

void dfs(ll x, ll curY, int cnt, ll curResult, ll curMask, bool canAdd, ll& localAns, ll& localTmp) {
    localTmp++;
    if (curResult & curMask) return;
    if (cnt >= 24) return;
    if (curY > x) return;
    if (canAdd && (!(curResult & cantMask)) && x >= curY) {
        localAns++;
    }
    dfs(x, curY | (1ll << cnt), cnt + 1, curResult ^ (x << cnt), curMask | (1ll << ((cnt / 2) * 2)), true, localAns, localTmp);
    dfs(x, curY, cnt + 1, curResult, curMask | (1ll << ((cnt / 2) * 2)), false, localAns, localTmp);
}

void process_range(ll start, ll end) {
    ll localAns = 0, localTmp = 0;
    for (ll i = start; i < end; i++) {
        dfs(i, 0, 0, 0, 0, true, localAns, localTmp);
        if (i % 1000000 == 0) {
            lock_guard<mutex> lock(mtx);
            cout << "[Thread] i = " << i << " localAns = " << localAns << " localTmp = " << localTmp << endl;
        }
    }
    lock_guard<mutex> lock(mtx);
    globalAns += localAns;
    globalTmp += localTmp;
}

int main() {
    for (int i = 0; i < 30; i++) {
        cantMask |= (1ll << (i * 2));
    }

    int numThreads = thread::hardware_concurrency(); // usually 8 on Apple M1
    vector<thread> threads;
    ll chunkSize = N / numThreads + 1;

    for (int i = 0; i < numThreads; i++) {
        ll start = i * chunkSize;
        ll end = min(N + 1, (i + 1) * chunkSize);
        threads.emplace_back(process_range, start, end);
    }

    for (auto& t : threads) t.join();

    cout << "Final ans = " << globalAns << ", total calls = " << globalTmp << endl;
    return 0;
}
