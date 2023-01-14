using SoladuimAPI;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SoladuimGame
{
    public class Game
    {
        public static void Run()
        {
            SProfiler.Start("YEAH");
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(i);
            }
            //Soladuim.Print();
            //var task = SProfiler.End();
            //Console.WriteLine(task.time);

            //FIX CLOSE
            //SEngine.Close();
        }
    }
}
