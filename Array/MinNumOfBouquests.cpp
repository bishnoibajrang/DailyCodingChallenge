class Solution {
public:
    // Function to find the minimum number of days required to make m bouquets with k flowers each.
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Optimize input/output operations for competitive programming.
        ios::sync_with_stdio(0);
        cin.tie(0);

        // Find the maximum bloom day in the array.
        long long max = *max_element(bloomDay.begin(), bloomDay.end());

        // Initialize the low end of the search range to 0.
        long long low = 0;

        // Variable to store the answer.
        int answer = -1;

        // Perform binary search.
        while (low <= max) {
            // Calculate the middle day of the current range.
            long long day = low + (max - low) / 2;

            // Variables to track the number of bouquets and consecutive flowers.
            int noOfBouquete = 0;
            int count = 0;

            // Iterate through each bloom day.
            for (int i = 0; i < bloomDay.size(); i++) {
                // Check if the current flower can bloom within the middle day.
                if (bloomDay[i] <= day) {
                    count++;
                } else {
                    count = 0; // Reset count if the flower cannot bloom within the middle day.
                }

                // If enough consecutive flowers are found to make a bouquet.
                if (count >= k) {
                    noOfBouquete++;
                    count = 0; // Reset count after making a bouquet.
                }
            }

            // Check if the required number of bouquets can be made within the middle day.
            if (noOfBouquete >= m) {
                answer = day; // Update answer with the current middle day.
                max = day - 1; // Search in the lower half.
            } else {
                low = day + 1; // Search in the upper half if not enough bouquets are made.
            }
        }

        // Return the answer (minimum days required or -1 if not possible).
        return answer;
    }
};

