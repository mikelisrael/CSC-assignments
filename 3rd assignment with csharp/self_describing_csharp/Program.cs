using System;

namespace SelfDescribing
{
    // read self.in file in the same directory
    public class Program
    {
        public static void Main(string[] args)
        {
            // if self.in file is not found, display error
            if (!System.IO.File.Exists("self.in"))
            {
                Console.WriteLine("self.in file not found");
                return;
            }

            string[] lines = System.IO.File.ReadAllLines(@"self.in");

            // read first line of lines
            int T = int.Parse(lines[0]);

            // loop through each line for T
            for (int i = 1; i <= T; i++)
            {
                //  read line i and check if self describing
                if (SelfDescribing(lines[i]) == 1)
                {
                    // print line is self describing
                    Console.WriteLine($"{lines[i]} - self describing");
                }
                else
                {
                    Console.WriteLine($"{lines[i]} - not self describing");
                }
            }
        }

        public static int SelfDescribing(string line)
        {
            int[] digits = new int[line.Length];
            for (int i = 0; i < line.Length; i++)
            {
                digits[i] = int.Parse(line[i].ToString());
            }

            for (int i = 0; i < digits.Length; i++)
            {
                int count = 0;
                for (int j = 0; j < digits.Length; j++)
                {
                    if (digits[j] == i)
                    {
                        count++;
                    }
                }

                if (count != digits[i])
                {
                    return 0;
                }
            }

            return 1;
        }
    }
}
