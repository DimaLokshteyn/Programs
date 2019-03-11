using System;

namespace HAL
{
    public class Char
    {
        public char symbol;
        public int sum;
        public int cou;
        public String code;

        public Char(char symbol, int sum, int cou)
        {
            this.symbol = symbol;
            this.sum = sum;
            this.code = "";
            this.cou = cou;
        }

        public static bool operator >(Char a, Char b)
        {
            if (a.sum > b.sum)
                return true;
            return false;
        }

        public static bool operator <(Char a, Char b)
        {
            if (a.sum < b.sum)
                return true;
            return false;
        }

        public void AddCode(String code)
        {
            this.code += code;
        }

        public void AddCount(int cou)
        {
            this.cou += 1;
        }
    }
}
