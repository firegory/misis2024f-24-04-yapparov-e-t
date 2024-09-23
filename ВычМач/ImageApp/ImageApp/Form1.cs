using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;

namespace ImageApp
{
    public partial class Form1 : Form
    {
        private byte[] toNeededLength(byte[] mas, int l)
        {
            if (mas.Length == l)
            {
                return mas;
            }
            else
            {
                byte[] mas1 = new byte[l];
                for (int i = 0; i < l; i++)
                {
                    if (mas.Length - l + i >= 0)
                    {
                        mas1[i] = mas[mas.Length - l + i];
                    }
                    else
                    {
                        mas1[i] = 0;
                    }
                }
                return mas1;
            }
        }
        private byte[] toNeededLength(int n, int l)
        {
            byte[] mas = new byte[l];
            for (int i = 0; i < l; i++)
            {
                mas[l - i - 1] = Convert.ToByte(Math.Floor(n / Math.Pow(2, i)) % 2);
            }
            return mas;
        }
        private int getFromNeededLength(byte[] mas, int ind, int l)
        {
            int n = 0;
            for (int i = 0; i < l; i++)
            {
                n += mas[ind + i] * Convert.ToInt32(Math.Pow(2, l - i - 1));
            }
            return n;
        }
        private void insert(ref byte[] mas, int ind, byte[] mas1)
        {
            for (int i = 0; i < mas1.Length; i++)
            {
                mas[ind + i] = mas1[i];
            }
        }
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
        private void button2_Click(object sender, EventArgs e)
        {
            showImage(decodeImageStandart(openFile(textBox1.Text)));
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
                    Color newColor = Color.FromArgb(mas[x, y, 0], mas[x, y, 1], mas[x, y, 2]);
                    image1.SetPixel(x, y, newColor);
                }
            }
            pictureBox1.Image = image1;

}
        private byte[] saveImage(short[,,] masT, string name)
        {
            List<int> colorsT = new List<int>();
            int x, y;
            int[,] mas = new int[masT.GetLength(0), masT.GetLength(1)];
            for (x = 0; x < masT.GetLength(0); x++)//Перевод в одно число вместо трех
            {
                for (y = 0; y < masT.GetLength(1); y++)
                {
                    mas[x, y] = masT[x, y, 0] * 65536 + masT[x, y, 1] * 256 + masT[x, y, 2];
                }
            }
            for (x = 0; x < mas.GetLength(0); x++)//Поиск всех уникальных цветов
            {
                for (y = 0; y < mas.GetLength(1); y++)
                {
                    if (colorsT.IndexOf(mas[x, y]) == -1)
                    {
                        colorsT.Add(mas[x, y]);
                    }
                }
            }


            int len = colorsT.Count();
            label1.Text = len + "colors proceeded";
            int min;
            int ind;
            List<int> colors = new List<int>();
            for (int i = 0; i < len; i++)//Сортировка от меньшего к большему
            {
                min = int.MaxValue;
                foreach (int item in colorsT)
                {
                    if (item < min)
                    {
                        min = item;
                    }
                }
                ind = colorsT.IndexOf(min);
                colors.Add(colorsT[ind]);
                colorsT.RemoveAt(ind);
            }
            label1.Text = "Colors have been sorted";
            byte[] im = encodeImageStandart(mas, colors);
            saveAs(im);
            return (im);
        }
        private byte[] encodeImageStandart(int[,] mas, List<int> colors)
        {
            int pixelWeight = Convert.ToInt32(Math.Ceiling(Math.Log(colors.Count(), 2)));

            int fyleLength =
            24 + //Байты, отведенные под количество кодируемых цветов
            16 * 2 +//Байты, отведенные под ширину и высоту
            24 * colors.Count() +//Байты, отведенные под расшивровку цветов
            pixelWeight * mas.GetLength(0) * mas.GetLength(1);//Байты под пиксели
            byte[] image = new byte[fyleLength];
            int index = 0;


            insert(ref image, index, toNeededLength(colors.Count(), 24));//Байты, отведенные под количество кодируемых цветов
            index += 24;

            insert(ref image, index, toNeededLength(mas.GetLength(0), 16));//Байты, отведенные под ширину и высоту
            index += 16;
            insert(ref image, index, toNeededLength(mas.GetLength(1), 16));
            index += 16;


            for (int i = 0; i < colors.Count(); i++)//Байты, отведенные под расшивровку цветов
            {
                insert(ref image, index, toNeededLength(colors[i], 24));
                index += 24;
            }



            int x, y;
            for (x = 0; x < mas.GetLength(0); x++)//Байты под пиксели
            {
                for (y = 0; y < mas.GetLength(1); y++)
                {
                    insert(ref image, index, toNeededLength(colors.IndexOf(mas[x, y]), pixelWeight));
                    index += pixelWeight;
                }
            }

            label1.Text = "Image icoded. Fyle weight: " + image.Length + " bytes";
            return image;
        }
        private short[,,] decodeImageStandart(byte[] mas)
        {
            int ind = 0;

            int colorsNumber = getFromNeededLength(mas, ind, 24);
            ind += 24;

            int width = getFromNeededLength(mas, ind, 16);
            ind += 16;
            int height = getFromNeededLength(mas, ind, 16);
            ind += 16;

short[,] colors = new short[colorsNumber, 3];
            for (int i = 0; i < colorsNumber; i++)
            {
                colors[i, 0] = (short)getFromNeededLength(mas, ind, 8);
                ind += 8;
                colors[i, 1] = (short)getFromNeededLength(mas, ind, 8);
                ind += 8;
                colors[i, 2] = (short)getFromNeededLength(mas, ind, 8);
                ind += 8;
            }

            int x, y;
            short[,,] image = new short[width, height, 3];
            int colorInd = 0;
            int pixelWeight = Convert.ToInt32(Math.Ceiling(Math.Log(colorsNumber, 2)));

            for (x = 0; x < width; x++)
            {
                for (y = 0; y < height; y++)
                {
                    colorInd = getFromNeededLength(mas, ind, pixelWeight);
                    ind += pixelWeight;
                    image[x, y, 0] = colors[colorInd, 0];
                    image[x, y, 1] = colors[colorInd, 1];
                    image[x, y, 2] = colors[colorInd, 2];
                }
            }
            return image;
        }
        private void saveAs(byte[] im)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.InitialDirectory = "C:\\Users\\fireg\\OneDrive\\Рабочий стол\\работа\\git\\-misis2024f-24-04-yapparov-e-t\\ВычМач\\ImageApp\\images";
            saveFileDialog.Filter = "bin files (*.bin)|*.bin|All files (*.*)|*.*";
            saveFileDialog.FilterIndex = 1;
            saveFileDialog.DefaultExt = ".bin";
            saveFileDialog.RestoreDirectory = true;

            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                //Get the path of specified file
                string path = saveFileDialog.FileName;
                WriteToBinaryFile(im, path);
            }
            else
            {
                MessageBox.Show("A saving error occured");
            }
        }
        private void WriteToBinaryFile(byte[] im, string path)
        {
            BinaryFormatter bf = new BinaryFormatter();
            FileStream fs = new FileStream(path, FileMode.Create, FileAccess.Write);
            bf.Serialize(fs, im);
            fs.Close();
        }
        public static byte[] openFile(string path)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.InitialDirectory = "C:\\Users\\fireg\\OneDrive\\Рабочий стол\\работа\\git\\-misis2024f-24-04-yapparov-e-t\\ВычМач\\ImageApp\\images";
            openFileDialog.Filter = "bin files (*.bin)|*.bin|All files (*.*)|*.*";
            openFileDialog.FilterIndex = 1;
            openFileDialog.DefaultExt = ".bin";
            openFileDialog.RestoreDirectory = true;
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                //Get the path of specified file
                path = openFileDialog.FileName;
                return ReadFromBinaryFile(path);
            }
            MessageBox.Show("A loading error occured");
            return null;
        }
        public static byte[] ReadFromBinaryFile(string path)
        {
            BinaryFormatter bf = new BinaryFormatter();
            FileStream fs = new FileStream(path, FileMode.Open, FileAccess.Read);
            byte[] im = (byte[])bf.Deserialize(fs);
            fs.Close();
            return im;
        }


    }
}