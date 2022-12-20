using System;

namespace AdamProgramming
{
    class Program
    {
        static string file = "adam.in";
        
        static void Main(string[] args)
        {
            // if file is not found, display error
            if (!System.IO.File.Exists(file))
            {
                Console.WriteLine($"{file} file not found");
                return;
            }
          
            string[] lines = System.IO.File.ReadAllLines(file);

            // read first line of lines
            int T = int.Parse(lines[0]);

            for(int i=1; i<=T; i++)
            {
                GetSteps(lines[i]);
            }

            static void GetSteps(string line)
            {
                int numOfSteps = 0;
                Console.Write($"{line} - ");

                // for char in lines[i]
                for(int j=0; line[j] != 'D'; j++)
                {
                        // increment numOfSteps
                        numOfSteps++;
                }

                Console.WriteLine(numOfSteps);
            }
        }
    }
}