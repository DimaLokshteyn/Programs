using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HAL
{
    class CharSet
    {
        CompareNodes comparer = new CompareNodes();

        public List<Tree> nodes;
        public List<Char> result;

        public CharSet(List<Char> symbols)
        {
            nodes = new List<Tree>();
            result = new List<Char>();
            for (int i = 0; i < symbols.Count; i++)
            {
                nodes.Add(new Tree(symbols[i]));
            }
            nodes.Sort(comparer);
        }

        public void Encoding()
        {
            while (nodes.Count > 1)
            {
                Tree temp = new Tree(nodes[0], nodes[1]);
                nodes.RemoveAt(1);
                nodes.RemoveAt(0);
                nodes.Add(temp);
                nodes.Sort(comparer);
            }
            nodes[0].Encoding(nodes[0]);
        }

        public void Entropy()
        {
           
        }
    }
}
