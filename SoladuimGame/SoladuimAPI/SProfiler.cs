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
        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct ProfilerTask
        {
            public int time;
        }


        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void Start(string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void End(ref ProfilerTask task);





        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct TestStruct
        {
            public int a;
            public int b;
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern ref TestStruct GetTest();
    }
}
