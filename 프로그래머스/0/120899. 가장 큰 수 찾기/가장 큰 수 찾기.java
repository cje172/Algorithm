class Solution {
    public int[] solution(int[] array) {
        int maxValue = array[0];
        int idx = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] > maxValue) {
                maxValue = array[i];
                idx = i;
            }
        }
        
        int[] answer = {maxValue, idx};
        return answer;
    }
}