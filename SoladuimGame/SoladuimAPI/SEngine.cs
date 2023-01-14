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
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void Close();
    }
}
