#include <iostream>
#include <deque>
#include <map>
using namespace std;

int main()
{
    int N;
    long long D;

    cin >> N >> D;

    int a[N];

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int left = 0;

    int bestLength = 0;
    int bestStart = 1;

    // Stores how many times each number appears
    map<int, int> freq;

    // Stores indexes for minimum and maximum
    deque<int> minDeque;
    deque<int> maxDeque;

    for (int right = 0; right < N; right++)
    {
        // Add current element
        freq[a[right]]++;

        // Maintain minimum deque
        while (!minDeque.empty() &&
               a[minDeque.back()] > a[right])
        {
            minDeque.pop_back();
        }

        minDeque.push_back(right);

        // Maintain maximum deque
        while (!maxDeque.empty() &&
               a[maxDeque.back()] < a[right])
        {
            maxDeque.pop_back();
        }

        maxDeque.push_back(right);

        // Keep removing from left while window is invalid
        while (freq[a[right]] > 1 ||
               a[maxDeque.front()] - a[minDeque.front()] > D)
        {
            // Remove a[left]
            freq[a[left]]--;

            // Remove left index from minimum deque
            if (!minDeque.empty() && minDeque.front() == left)
            {
                minDeque.pop_front();
            }

            // Remove left index from maximum deque
            if (!maxDeque.empty() && maxDeque.front() == left)
            {
                maxDeque.pop_front();
            }

            left++;
        }

        // Current window is valid
        int length = right - left + 1;

        if (length > bestLength)
        {
            bestLength = length;
            bestStart = left + 1;
        }
    }

    cout << bestLength << " " << bestStart << endl;

    return 0;
}

/*
Time Complexity

O(N log N)

map insertion/removal: O(log N)
deque operations: O(1)
Each element is added and removed from the window at most once.
Space Complexity

O(N)

Array: O(N)
Frequency map: O(N)
Two deques: O(N)

So:

TC = O(N log N)
SC = O(N)
*/