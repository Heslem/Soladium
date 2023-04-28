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
        private GameObject _gameObject;

        public void Start(ref GameObject gameObject)
        {
            _gameObject = gameObject; 
            Console.WriteLine("Start");
        }

        public void Update()
        {
            float _speed = 0.001f;
            if (SKeyboard.IsKeyPressed(SKeyboard.Keys.A))
                _gameObject.Move(-_speed, 0);
            if (SKeyboard.IsKeyPressed(SKeyboard.Keys.D))
                _gameObject.Move(_speed, 0);
            if (SKeyboard.IsKeyPressed(SKeyboard.Keys.W))
                _gameObject.Move(0, _speed);
            if (SKeyboard.IsKeyPressed(SKeyboard.Keys.S))
                _gameObject.Move(0, -_speed);

        }
    }
}
