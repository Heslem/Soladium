using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace SoladuimAPI
{
    public class GameObject
    {
        private IntPtr _intPtr;

        public GameObject(IntPtr intPtr)
        {
            _intPtr = intPtr;

        }

        public void Move(float x, float y)
        {
            s_move(_intPtr, x, y);
        }



        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static void s_move(IntPtr ptr, float x, float y);
    }
}
