#include <bits/stdc++.h>
using namespace std;

int main() {
    // Makes input/output faster
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // N = number of elements in the array
    // K = required XOR value
    int N;
    long long K;
    cin >> N >> K;

    /*
        freq stores:

        prefix XOR -> number of times it has appeared

        Example:
        If prefix XOR 5 has appeared 2 times,

        freq[5] = 2
    */
    unordered_map<long long, long long> freq;

    /*
        We start with prefix XOR = 0.

        This represents the "empty prefix" before the array starts.

        It is important because it allows us to count subarrays
        that start from index 0.

        Example:
        If the first few elements have XOR = K,

        current prefixXor = K

        needed = K ^ K = 0

        So freq[0] must already be 1.
    */
    freq[0] = 1;

    // XOR of all elements from the beginning up to the current position
    long long prefixXor = 0;

    // Total number of subarrays whose XOR is exactly K
    long long answer = 0;

    // Process every element of the array
    for (int i = 0; i < N; i++) {

        // Read the current element
        long long x;
        cin >> x;

        /*
            Update the prefix XOR.

            Example:
            If prefixXor = 3 and x = 4:

            prefixXor = 3 ^ 4
                       = 7
        */
        prefixXor ^= x;

        /*
            We want a subarray whose XOR is K.

            We know:

            previousPrefixXor ^ currentPrefixXor = K

            Therefore:

            previousPrefixXor = currentPrefixXor ^ K

            So 'needed' tells us which previous prefix XOR
            we need to find in the hashmap.
        */
        long long needed = prefixXor ^ K;

        /*
            If 'needed' has appeared before, then every occurrence
            of 'needed' represents one subarray whose XOR is K.

            freq[needed] gives the number of such previous prefixes.

            So we add that count to our answer.
        */
        answer += freq[needed];

        /*
            Now store the current prefix XOR.

            We do this AFTER checking needed because the current
            prefix should only be used as a "previous prefix"
            for future elements.
        */
        freq[prefixXor]++;
    }

    // Print the total number of subarrays having XOR equal to K
    cout << answer << '\n';

    return 0;
}