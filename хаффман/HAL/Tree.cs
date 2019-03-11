using System;

namespace HAL
{
    public class Tree
    {
        private Tree right = null;
        private Tree left = null;

        public Char symbol = null;
        public String code = "";
        public int sum = 0;
        public int sum1 = 0;
        public int count = 0;
        public Tree(Char symbol)
        {
            this.symbol = symbol;
            this.sum = symbol.sum; 
        }

        public Tree(Tree xtree, Tree ytree)
        {
            if (ytree.sum > xtree.sum)
            {
                this.right = ytree;
                this.left = xtree;
            }
            else
            {
                this.right = xtree;
                this.left = ytree;
            }
            this.sum = xtree.sum + ytree.sum;
        }

        public void Encoding(Tree tree)
        {
            if (tree.left != null)
            {
                tree.left.code = tree.code + "1";
                tree.count++;
                Encoding(tree.left);
            }
            if (tree.right != null)
            {
                tree.right.code = tree.code + "0";
                Encoding(tree.right);
            }
            if (tree.symbol != null)
            {
                tree.symbol.code = tree.code;
                Console.WriteLine("Char: \'" + tree.symbol.symbol + "\', Sum: " 
                    + tree.symbol.sum + ",Code \'" + tree.symbol.code +"\'");
            }
        }
    }
}
