using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HAL
{
    class CompareChar : IComparer<Char>
    {
        public int Compare(Char x, Char y)
        {
            return (new CaseInsensitiveComparer().Compare(x.sum, y.sum));
        }
    }
}
