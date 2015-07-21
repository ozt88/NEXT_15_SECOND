using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    public static class Kata
    {
        public static int Factorial(int n)
        {
            if( n < 0 || n > 12)
                throw new ArgumentOutOfRangeException("n", "n < 0 || n > 12");

            int result = 1;
            for (int i = 1; i < n; ++i)
            {
                result *= i;
            }

            return result;
        }

        public static string HighAndLow(string numbers)
        {
            string[] tokens = numbers.Split(' ');
            int high = -0x7FFFFF;
            int highIndex = -1;
            int low = 0x7FFFFF;
            int lowIndex = -1;
            for (int idx = 0; idx < tokens.Length; idx++)
            {
                int value = Convert.ToInt32(tokens[idx]);
                if (value > high)
                {
                    high = value;
                    highIndex = idx;
                }
                if (value < low)
                {
                    low = value;
                    lowIndex = idx;
                }
            }
            return tokens[highIndex] + " " + tokens[lowIndex];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Kata.HighAndLow("1 2 -3 -10 111 55512 -243123 111 94 -234"));
        }
    }
}
