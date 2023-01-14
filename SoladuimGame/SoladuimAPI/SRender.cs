using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;

namespace SoladuimAPI
{
    public static class SRender
    {
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void Vertex2f(float x, float y);
    }
}
