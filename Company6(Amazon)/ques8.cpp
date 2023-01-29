int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    return max(left.empty() ? 0 : *max_element(begin(left), end(left)),
        n - (right.empty() ? n : *min_element(begin(right), end(right))));
}