class Solution {
    public String intToRoman(int num) {
        if (num > 3999 || num < 1) {
            return "Error: enter a number between 1 and 3999";
        }
        int[] chart = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String romanNumerals = new String();

        while (num > 0) {
            for (int k : chart) {
                if (num >= k) {
                    romanNumerals += romanFactors(k);
                    num -= k;
                    break;
                }
            }
        }
        return romanNumerals;
    }

    private static String romanFactors (int f) {
        return switch (f) {
            case 1000 -> "M";
            case 900 -> "CM";
            case 500 -> "D";
            case 400 -> "CD";
            case 100 -> "C";
            case 90 -> "XC";
            case 50 -> "L";
            case 40 -> "XL";
            case 10 -> "X";
            case 9 -> "IX";
            case 5 -> "V";
            case 4 -> "IV";
            case 1 -> "I";
            default -> "";
        };
    }
}