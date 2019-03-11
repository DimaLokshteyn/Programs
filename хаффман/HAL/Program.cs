
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HAL
{
    class Program
    {
        static void Main(string[] args)
        {
            String text = Console.ReadLine();
            List<Char> symbols = TextConvert.Convert(text);
            CharSet set = new CharSet(symbols);
            set.Encoding();
            Console.ReadKey();
        }
    }
}
