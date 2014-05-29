class Solution {
public:

    int findTheKthElement(int A[], int start_of_a, int end_of_a, 
                          int B[], int start_of_b, int end_of_b,
                        int k){
        if(start_of_a > end_of_a) return B[start_of_b + k - 1];
        else if(start_of_b > end_of_b) return A[start_of_a + k - 1];
        else{
            int middle_of_a = (start_of_a + end_of_a) / 2;
            int middle_of_b = (start_of_b + end_of_b) / 2;
            int length_of_first_half_of_a = middle_of_a - start_of_a + 1;
            int length_of_first_half_of_b = middle_of_b - start_of_b + 1;
            int length_of_first_half = length_of_first_half_of_a + length_of_first_half_of_b;
            if(k < length_of_first_half){
                if(A[middle_of_a] > B[middle_of_b]){ 
                    // k is either in B or the first half of A
                    return findTheKthElement(A, start_of_a, middle_of_a - 1, B, start_of_b, end_of_b, k);
                }
                else{ 
                    // k is either in A or the first half of B
                    return findTheKthElement(A, start_of_a, end_of_a, B, start_of_b, middle_of_b - 1, k);
                }
            }else{
                if(A[middle_of_a] > B[middle_of_b]){
                    // k is either in A or the last half of B
                    return findTheKthElement(A, start_of_a, end_of_a, B, middle_of_b + 1, end_of_b, k - length_of_first_half_of_b);
                }
                else
                {
                    // k is either in B or the last half of A
                    return findTheKthElement(A, middle_of_a + 1, end_of_a, B, start_of_b, end_of_b, k - length_of_first_half_of_a);
                }
            }
            
        }
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        bool odd = (m + n) & 1;
        unsigned mid = odd ? (m + n) / 2 + 1 : (m + n) / 2;
        int mid_value = findTheKthElement(A, 0, m - 1, B, 0, n - 1, mid);
        if(odd == true) return mid_value;
        else{
            int mid_value_2 = findTheKthElement(A, 0, m - 1, B, 0, n - 1, mid + 1);
            return double((mid_value + mid_value_2)) / 2;
        }
    }
};
