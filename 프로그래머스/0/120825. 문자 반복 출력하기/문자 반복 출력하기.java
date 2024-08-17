class Solution {
    public String solution(String my_string, int n) {
        StringBuilder answer = new StringBuilder();
        
        for (char c: my_string.toCharArray()) {
            answer.append((c + "").repeat(n));
        }
        
        return answer.toString();
    }
}