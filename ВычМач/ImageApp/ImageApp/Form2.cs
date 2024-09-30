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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }
        public void f2Show(Point[] png, Point[] normal, Point[] better)
        {
            for (int i = 0; i < png.Length; i++)
            {
                chart1.Series[0].Points.AddXY(png[i].X, png[i].Y);
            }
            for (int i = 0; i < normal.Length; i++)
            {
                chart1.Series[1].Points.AddXY(normal[i].X, normal[i].Y);
            }
            for (int i = 0; i < better.Length; i++)
            {
                chart1.Series[2].Points.AddXY(better[i].X, better[i].Y);
            }
            float mnoz1 = 0;
            float mnoz2 = 0;
            for (int i = 0; i < png.Length; i++)
            {
                mnoz1 += normal[i].Y / png[i].Y;
                mnoz2 += better[i].Y / png[i].Y;
            }

            mnoz1 /= png.Length;
            mnoz2 /= png.Length;
            
            label1.Text = "Normal algorithm is in general " + Math.Round(mnoz1) + " times less effective than PNG";
            label2.Text = "Better algorithm is in general " + Math.Round(mnoz2) + " times less effective than PNG";
            Refresh();
        }
    }
}
