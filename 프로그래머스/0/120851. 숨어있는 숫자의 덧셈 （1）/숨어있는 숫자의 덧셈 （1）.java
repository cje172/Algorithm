class Solution {
    public int solution(String my_string) {
        int answer = 0;
        my_string = my_string.replaceAll("[a-zA-Z]", "");
        String[] str = my_string.split("");
        for (String s: str)
            answer += Integer.parseInt(s);
        
        return answer;
    }
}