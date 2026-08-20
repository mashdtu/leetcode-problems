import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> answer = new ArrayList<>(); 
        for (int i = 1; i <= n; i++) {
            answer.add(i % 15 == 0 ? "FizzBuzz"
            : i % 5 == 0 ? "Buzz"
            : i % 3 == 0 ? "Fizz"
            : String.valueOf(i));
        }
        return answer;
    }
}