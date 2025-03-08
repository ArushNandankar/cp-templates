#include <bits/stdc++.h>

using namespace std;

const int Ns = 1000000;
vector<int> SIEVE(Ns + 1); // O(nloglogn)
void sieve() // 
{
    SIEVE[1] = 1;
    for (int i = 2; i <= Ns; i++)
    {
        if (SIEVE[i] == 0)
        {
            SIEVE[i] = i;
            for (int j = 2 * i; j <= Ns; j += i)
            {
                SIEVE[j] = i;
            }
        }
    }
}

// const int Ns = 1000000;
// vector<vector<int>> SIEVE(Ns + 1); // O(nloglogn)
// void sieve() // 
// {
//     SIEVE[1].emplace_back(1);
//     for (int i = 2; i <= Ns; i++)
//     {
//         if (SIEVE[i].size() == 0)
//         {
//             SIEVE[i].emplace_back(i);
//             for (int j = 2 * i; j <= Ns; j += i)
//             {
//                 SIEVE[j].emplace_back(i);
//             }
//         }
//     }
// }

int main()
{
    auto start_time = chrono::high_resolution_clock::now();
    sieve();
    // for (int i = 2; i <= 100; i++)
    // {
    //     cout << i << " -> ";
    //     for (auto &x : SIEVE[i])
    //         cout << x << " ";
    //     cout << "\n";
    // }
    auto end_time = chrono::high_resolution_clock::now();
    auto elapsed_time = chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    cerr << "Elapsed time: " << elapsed_time.count() / 1000 << " ms\n";
}