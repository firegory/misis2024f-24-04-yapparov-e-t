using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ImageApp
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }
        public void f3Show(Point[] rand, Point[] standart)
        {
            for (int i = 0; i < rand.Length; i++)
            {
                chart1.Series[0].Points.AddXY(rand[i].X, rand[i].Y);
            }
            for (int i = 0; i < standart.Length; i++)
            {
                chart1.Series[1].Points.AddXY(standart[i].X, standart[i].Y);
            }
           
            Refresh();
        }
    }
}
