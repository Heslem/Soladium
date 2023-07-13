using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace SoladuimAPI
{
    public unsafe class GameObject
    {
        // Maybe this pointer need to delete. I don't know.

        public void* _ptr;
        public int TestValue = 0;

        private GameObject(ref void* ptr)
        {
            _ptr = ptr;
        }

        public void Move(float x, float y)
        {
            s_move(ref x, ref y, ref _ptr);
        }

        public void Destroy()
        {
            s_destroy(ref _ptr);
        }


        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static void s_move(ref float x, ref float y, ref void* ptr);


        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static void s_destroy(ref void* ptr);


        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static void* s_getComponent(ref void* ptr, string name);
    }
}
