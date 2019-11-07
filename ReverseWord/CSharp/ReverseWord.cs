using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ReverseWord
{
    class ReverseWord
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Reverse("Hello World"));
            Console.WriteLine(ReverseRaiz("The cat in the hat"));
            Console.WriteLine(ReverseII("Hello World"));
            Console.ReadKey();
        }

        private static string Reverse(string elstring)
        {
            string[] words = elstring.Split(' ');
            
            for(int i = 0; i < words.Length; i++)
            {
                words[i] = new string(words[i].Reverse().ToArray());
            }

            string final = String.Join(" ", words);

            return final;
        }

        private static string ReverseWordI(string words)
        {
            int size = StringLength(words);
            string empty = "";            

            for (int i = size - 1; i >= 0; i--)            
                empty += words[i];

            return empty;
        }

        private static string ReverseII(string elstring)
        {
            int size = StringLength(elstring);
            int i = 0;

            string reverso = "";
            string word = "";

            while (i < size)
            {                
                if(elstring[i] == ' ' || i == size - 1)
                {
                    if(i == size - 1)
                        word += elstring[i];
                    reverso += ReverseWordI(word) + " ";
                    word = "";
                }
                word += elstring[i];
                i++;
            }

            return reverso;
        }

        private static string ReverseRaiz(string elstring)
        {
            int size = StringLength(elstring);

            char[] array = new char[size];

            int j = 0;

            for (int i = 0; i < size; i++)
            {                
                if(elstring[i] == ' ' || i == size - 1 )
                {

                    int auxSize;

                    if (i != size - 1)
                        auxSize = i;
                    else
                        auxSize = i + 1;

                    while (j < i && elstring[auxSize - 1] != ' ')
                    {
                        array[j] = elstring[auxSize - 1];
                        auxSize--;
                        j++;
                    }

                    if (i == size - 1)
                        array[j] = elstring[auxSize + i - j - 1];

                    j++;

                }
            }

            string finalString = "";

            for(int i = 0; i < size; i++)
            {
                finalString += array[i];
            }

            return finalString;
        }

        private static int StringLength(string elstring)
        {
            int i = 0;
            
            foreach(char c in elstring)
            {
                i++;
            }

            return i;
        }
    }
}
