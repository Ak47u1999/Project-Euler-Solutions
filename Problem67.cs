using System;
using System.IO;
using System.Diagnostics;

namespace Project_Euler
{
    class Problem67
    {
        public static class global
        {
            public static Int64[,] triangle = new Int64[500, 500];
            public static Int64[,] dp = new Int64[500, 500];
        }

        public static Int64 max_x(Int64 a, Int64 b,Int64 c)
        {
            if(a>=b && a>=c)
             return a;
            if(b>=a && b>=c)
             return b;
            if(c>=a && c>=b)
             return c;

            return 0;
        }

        public static void filehandling()
        {


            FileStream fs = new FileStream("C:\\Users\\arpit\\Documents\\Project Euler\\p067_triangle.txt", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(fs);
            sr.BaseStream.Seek(0, SeekOrigin.Begin);

            string str = sr.ReadLine();
            for (Int64 row = 0; str != null; row++)
            {

                string[] tmp = str.Split(' ');

                for (Int64 i = 0; i < tmp.Length; i++)
                    global.triangle[row, i] = Convert.ToInt64(tmp[i]);

                // Console.Write(tmp.Length+" ");

                // for(Int64 i=0;i<triangle[row,i] !=false;i++)
                //  Console.Write(triangle[row,i]+" ");
                str = sr.ReadLine();
            }

            sr.Close();
            fs.Close();
        }

        public static Int64 dp_x(Int64 r, Int64 c)
        {
            if (r < 500 && c < 500 && r >= 0 && c >= 0 && global.triangle[r,c] != -100)
            {
                if (global.dp[r, c] == -100)
                    global.dp[r, c] = global.triangle[r, c] + max_x(dp_x(r + 1, c),dp_x(r + 1, c + 1),-100);

                return global.dp[r, c];
            }

            return 0;
        }

        static void Main(string[] args)
        {
            var watch = new System.Diagnostics.Stopwatch();

            watch.Start();

            for(Int64 i=0;i<500;i++)
            {
                for(Int64 j=0;j<500;j++)
                {
                    global.dp[i,j]=-100;
                    global.triangle[i,j]=-100;
                }
            }

            filehandling();

            // for(Int64 i=0;i<500;i++,Console.WriteLine())
            //     for(Int64 j=0;j<500;j++)
            //         Console.Write(global.triangle[i,j]+" ");

            Console.WriteLine(dp_x(0, 0));

            watch.Stop();
            Console.WriteLine($"Execution Time: {watch.ElapsedMilliseconds} ms");
        }
    }
}
