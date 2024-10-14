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
        public void f3Show(Point[] rand, Point[] standart, Point[] md5)
        {
            //for (int i = 0; i < rand.Length; i++)
            //{
            //    chart2.Series[0].Points.AddXY(rand[i].X, rand[i].Y);
            //}
            //for (int i = 0; i < standart.Length; i++)
            //{
                //chart2.Series[1].Points.AddXY(standart[i].X, standart[i].Y);
            //}
            for (int i = 0; i < md5.Length; i++)
            {
                chart2.Series[2].Points.AddXY(md5[i].X, md5[i].Y);
            }

            Refresh();
        }
    }
}
