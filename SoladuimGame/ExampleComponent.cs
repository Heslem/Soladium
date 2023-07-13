using SoladuimAPI;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SoladuimGame
{
    public class ExampleComponent : SComponent
    {
        // Component have problems, but it will fixed in future...
        // WARN: You must initialize your variables in Begin()

        private float _speed;

        public override void Begin(ref GameObject gameObject)
        {
            base.Begin(ref gameObject);
            _speed = 0.02f;
        }

        public override void Update()
        {
            if (SKeyboard.IsKeyPressed(SKeyboard.Keys.A))
                GameObject.Move(-_speed, 0);
            if (SKeyboard.IsKeyPressed(SKeyboard.Keys.D))
                GameObject.Move(_speed, 0);
            if (SKeyboard.IsKeyPressed(SKeyboard.Keys.W))
                GameObject.Move(0, _speed);
            if (SKeyboard.IsKeyPressed(SKeyboard.Keys.S))
                GameObject.Move(0, -_speed);
        }

        public override void End()
        {
            Console.WriteLine("Game object end");
        }
    }
}
