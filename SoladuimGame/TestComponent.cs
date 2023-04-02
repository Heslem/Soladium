using SoladuimAPI;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SoladuimGame
{
    public class TestComponent
    {
        public void Start()
        {
            Console.WriteLine("Start");
        }

        public void Update()
        {
            
            if (SKeyboard.IsKeyPressed(SKeyboard.Keys.G))
            {
                Console.WriteLine("Working");
            }
        }
    }
}
