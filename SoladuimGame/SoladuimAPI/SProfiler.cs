using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SoladuimAPI
{
    public static class SProfiler
    {
        [StructLayout(LayoutKind.Sequential)]
        public struct ProfilerTask
        {
            public string name;
            public ulong time;
        }


        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void Start(string name);
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static ProfilerTask End();
    }
}
