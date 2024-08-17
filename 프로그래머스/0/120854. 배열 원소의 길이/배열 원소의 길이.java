import java.util.Arrays;

class Solution {
    public int[] solution(String[] strlist) {
        int[] answer = Arrays.stream(strlist).mapToInt(String::length).toArray();
        return answer;
    }
}