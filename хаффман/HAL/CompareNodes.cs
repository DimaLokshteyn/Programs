using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HAL
{
    class CompareNodes : IComparer<Tree>
    {
        public int Compare(Tree x, Tree y)
        {
            return (new CaseInsensitiveComparer().Compare(x.sum, y.sum));
        }
    }
}
