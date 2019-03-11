using System;
using System.IO;

namespace cesar
{
    class Program
    {
        static void Main(string[] args)
        {
            int key = 1;
            string PathToFile = @"C:\Users\student\Desktop\cesar\OriginalText.txt";
            string s = null;
            if (File.Exists(PathToFile))
                s = File.ReadAllText(PathToFile);
            else
            {
                Console.WriteLine("Не получается найти файл по указанному пути");
                Console.ReadLine();
                Environment.Exit(0);
            }
            Console.WriteLine("ИСХОДНЫЙ ТЕКСТ:  \n" + s); 
            Console.WriteLine("ВВЕДИТЕ КЛЮЧ");
            key = Convert.ToInt32(Console.ReadLine());

                string str1 = "";
                string abc = "abcdefghijklmnopqrstuvwxyz";

                for (int i = 0; i < s.Length; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                    if (s[i] == '.')
                    {
                        str1 += '.';
                        break;
                    }

                    if (s[i] == ';')
                    {
                        str1 += ';';
                        break;
                    }

                    if (s[i] == ' ')
                    {
                        str1 += ' ';
                        break;
                    }

                    if (s[i] == '!')
                    {
                        str1 += '!';
                        break;
                    }

                    if (s[i] == '?')
                    {
                        str1 += '?';
                        break;
                    }

                    if (s[i] == '-')
                    {
                        str1 += '-';
                        break;
                    }

                    if (s[i] == '\"')
                    {
                        str1 += "\"";
                        break;
                    }

                    if (s[i] == abc[j])
                        {
                            int tmp = j + key;

                            while (tmp >= 26)
                                tmp -= 26;

                            str1 = str1 + abc[tmp];
                        }
                    }
                }
                Console.WriteLine("\n\nЗАШИФРОВАННЫЙ ТЕКСТ:   \n" + str1);
                Console.WriteLine("\n---------------------------------------------------------------");



            double[] ArrAlf = new double[] { 0.0817, 0.0149, 0.0278, 0.0425, 0.0127, 0.0223, 0.0202, 0.0609, 0.0697, 0.0015, 0.0077, 0.0403, 0.0241, 0.0675, 0.0751, 0.0193, 0.001, 0.0599, 0.0633, 0.0906, 0.0276, 0.0098, 0.0236, 0.0015, 0.0197, 0.005 };

            double temp2 = 0;
            double[] ArrShifr = new double[26];

            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < str1.Length; j++)
                {
                    if (abc[i] == str1[j])
                        temp2++;
                }
                ArrShifr[i] = Convert.ToDouble(temp2 / str1.Length);
                temp2 = 0;
            }
            double d = 0;
            int fKey = 0;
            double min = 100000;

            for (int j = 0; j < 26; j++)
            {
                for (int i = 0; i < 26; i++)
                {
                    if ((i + j) > 25)
                        d = d + Math.Pow(ArrAlf[i] - ArrShifr[i + j - 26], 2);
                    else
                        d = d + Math.Pow(ArrAlf[i] - ArrShifr[i + j], 2);

                }
                if (d < min)
                {
                    min = d;
                    fKey = j;
                }
                d = 0;
            }


            string str2 = "";
            for (int i = 0; i < str1.Length; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (str1[i] == '.')
                    {
                        str2 += '.';
                        break;
                    }

                    if (str1[i] == ';')
                    {
                        str2 += ';';
                        break;
                    }

                    if (str1[i] == ' ')
                    {
                        str2 += ' ';
                        break;
                    }

                    if (str1[i] == '?')
                    {
                        str2 += '?';
                        break;
                    }

                    if (str1[i] == '!')
                    {
                        str2 += '!';
                        break;
                    }

                    if (str1[i] == '-')
                    {
                        str2 += '-';
                        break;
                    }

                    if (str1[i] == '\"')
                    {
                        str2 += "\"";
                        break;
                    }

                    if (str1[i] == abc[j])
                    {
                        int temp = j - fKey;

                        if (temp < 0)
                        {
                            temp = temp + 26;
                        }
                        if (temp > 26)
                        {
                            temp = temp - 26;
                        }
                        str2 = str2 + abc[temp];
                    }
                }
            }

            Console.WriteLine("\n\nРАСШИФРОВАННЫЙ ТЕКСТ:    \n" + str2);
            Console.ReadLine();
        }
    }
}
        