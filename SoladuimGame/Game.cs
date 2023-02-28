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
            Console.WriteLine("C# working.");

            var t = SProfiler.GetTest();
            Console.WriteLine(t.a);
            Console.WriteLine(t.b);
        }
    }
}
