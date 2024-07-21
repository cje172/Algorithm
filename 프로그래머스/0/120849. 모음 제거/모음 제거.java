class Solution {
    public String solution(String my_string) {
        String answer = my_string;
        String[] alphabet = {"a","e","i","o","u"};
        
        for (String s: alphabet)
            answer = answer.replaceAll(s, "");
        
        return answer;
    }
}