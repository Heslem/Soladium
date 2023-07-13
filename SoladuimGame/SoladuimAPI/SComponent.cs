using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SoladuimAPI
{
    public abstract class SComponent
    {
        public GameObject GameObject { get; private set; }

        public virtual void Begin(ref GameObject obj)
        {
            GameObject = obj;
        }
        public abstract void Update();
        public abstract void End();
    }
}
