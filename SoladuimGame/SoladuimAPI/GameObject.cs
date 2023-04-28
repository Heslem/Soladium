using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace SoladuimAPI
{
    public class GameObject
    {
        public IntPtr _intPtr;

        public GameObject(IntPtr intPtr)
        {
            _intPtr = intPtr;
        }

        public void Move(in float x, in float y)
        {
            s_move(x, y, _intPtr);
        }

        public void Destroy()
        {
            s_destroy(_intPtr);
        }


        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static void s_move(float x, float y, IntPtr ptr);


        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static void s_destroy(IntPtr ptr);
    }
}
