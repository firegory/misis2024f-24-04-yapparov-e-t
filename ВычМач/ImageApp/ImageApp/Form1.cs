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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            short[,,] mas = readIm(textBox1.Text);
            //showImage(mas);
            saveImage(mas, "");
        }
        private short[,,] readIm(string path)
        {
            try
            {
                Bitmap image1 = new Bitmap(textBox1.Text, true);

                int x, y;
                short[,,] mas = new short[image1.Width, image1.Height, 3];
                for (x = 0; x < image1.Width; x++)
                {
                    for (y = 0; y < image1.Height; y++)
                    {
                        Color pixelColor = image1.GetPixel(x, y);
                        mas[x, y, 0] = pixelColor.R;
                        mas[x, y, 1] = pixelColor.G;
                        mas[x, y, 2] = pixelColor.B;
                    }
                }

                return mas;
            }
            catch (ArgumentException)
            {
                MessageBox.Show("There was an error." +
                    "Check the path to the image file.");
                return null;
            }
        }
        private void showImage(short[,,] mas)
        {
            Bitmap image1 = new Bitmap(mas.GetLength(0), mas.GetLength(1));
            int x, y;
            for (x = 0; x < image1.Width; x++)
            {
                for (y = 0; y < image1.Height; y++)
                {
                    Color newColor = Color.FromArgb(mas[x,y,0], mas[x, y, 1], mas[x, y, 2]);
                    image1.SetPixel(x, y, newColor);
                }
            }
            pictureBox1.Image = image1;

        }
        private void saveImage(short[,,] mas, string name)
        {
            List<Color> colors = new List<Color>();

            int x, y, k;
            bool a;
            for (x = 0; x < mas.GetLength(0); x++)
            {
                for (y = 0; y < mas.GetLength(1); y++)
                {
                    a = true;
                    for (k = 0; k < colors.Count(); k++)
                    {
                        if (colors[k].R == mas[x,y,0] && colors[k].G == mas[x, y, 1] && colors[k].B == mas[x, y, 2])
                        {
                            a = false;
                        }
                    }
                    if (a)
                    {
                        Color newColor = Color.FromArgb(mas[x, y, 0], mas[x, y, 1], mas[x, y, 2]);
                        colors.Add(newColor);
                    }
                }
            }
            MessageBox.Show(colors.Count().ToString());
        }

    }
}
