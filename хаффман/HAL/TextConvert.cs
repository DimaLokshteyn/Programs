using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HAL
{
    class TextConvert
    {
        static CompareChar comparer;

        public static List<Char> Convert(String text)
        {
            List<Char> symbols = new List<Char>();
            List<char> temp = new List<char>();
            for (int i = 0; i < text.Length; i++)
            {
                int index = temp.LastIndexOf(text[i]);
                if (index < 0)
                {
                    temp.Add(text[i]);
                    symbols.Add(new Char(text[i], 1, 0));
                }
                else
                {
                    symbols[index].sum++;
                }
            }
            comparer = new CompareChar();
            symbols.Sort(comparer);
            return symbols;
        }
    }
}
