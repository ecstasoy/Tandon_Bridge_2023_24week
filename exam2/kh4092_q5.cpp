int findOddIntegersAndSum(int S[], int length, int &sumOdds) {
    if (length < 1) return 0;

    int sum = findOddIntegersAndSum(S, length - 1, sumOdds);

    if (S[length - 1] % 2 == 0) {
        return sum + 0;
    } else {
        sumOdds += S[length - 1];
        return sum + 1;
    }
}