using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace SoladuimAPI
{
    internal static class SMouse
    {

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static float GetX();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static float GetY();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static float GetDeltaX();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static float GetDeltaY();
    }
}
