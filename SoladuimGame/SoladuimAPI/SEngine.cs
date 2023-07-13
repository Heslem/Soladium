using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace SoladuimAPI
{
    public class SEngine
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static float GetDeltaTime();
    }
}
