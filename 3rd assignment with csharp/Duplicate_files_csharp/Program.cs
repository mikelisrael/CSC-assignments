using System;

namespace DuplicateFiles
{
    class Program
    {
        static string file = "files.in";

        static void Main(string[] args)
        {
            // if file is not found, display error
            if (!System.IO.File.Exists(file))
            {
                Console.WriteLine($"{file} file not found");
                return;
            }

            string[] lines = System.IO.File.ReadAllLines(file);
            int lowestValue = 0;
            int[] sortedIDs;

            // read first line of lines
            int T = int.Parse(lines[0]);

            for (int i = 1; i <= T; i++)
            {
                if (int.TryParse(lines[i], out int group))
                {
                    //  console group
                    for (int j = 0; j < group; j++)
                    {
                        string line = lines[i + j + 1];

                        // seperate letter and number for line
                        string[] split = line.Split(' ');
                        string currName = split[0];
                        int currID = int.Parse(split[1]);
                        // create an empty array to store sortedIDs
                        sortedIDs = new int[group];

                        for (int m = 0; m < group; m++)
                        {
                            string line2 = lines[i + m + 1];
                            string[] split2 = line2.Split(' ');
                            string currName2 = split2[0];
                            int currID2 = int.Parse(split2[1]);

                            if (currName == currName2 && currID == currID2)
                            {
                                break;
                            }
                            else if (currName == currName2)
                            {
                                if (currID > currID2)
                                {
                                    lowestValue = currID2;
                                }
                                else
                                {
                                    lowestValue = currID;
                                }
                            }
                            else
                            {
                                sortedIDs[m] = currID2;
                                sortedIDs[m + 1] = currID;
                                Array.Sort(sortedIDs);
                                for (int n = 0; n < sortedIDs.Length; n++)
                                {
                                    Console.Write(sortedIDs[n] + " ");
                                }
                            }
                        }
                    }
                    Console.WriteLine();
                }
                else
                {
                    T = T + 1;
                }
            }

            Console.WriteLine(lowestValue);
        }
    }
}
