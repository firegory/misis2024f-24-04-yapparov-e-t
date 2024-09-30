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
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.InitialDirectory = "C:\\Users\\Light Flight PC\\Pictures\\Screenshots";
            openFileDialog.RestoreDirectory = true;
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                //Get the path of specified file
                string path = openFileDialog.FileName;
                short[,,] mas = readIm(path);
                saveImage(mas, 1);
            }
            else
            {
                MessageBox.Show("A loading error occured");
            }
        }
        private void getStats()
        {
            Point[] png = new Point[296];
            Point[] normal = new Point[296];
            Point[] better = new Point[296];
            png[0].X = 1;
            png[0].Y = 1;
            normal[0].X = 1;
            normal[0].Y = 1;
            better[0].X = 1;
            better[0].Y = 1;
            short[,,] tempImg;
            int[] length;
            for (int i = 1; i < png.Length; i++)
            {
                tempImg = readIm("C:\\Users\\Light Flight PC\\Desktop\\work\\-misis2024f-24-00-yapparov-e-t\\ВычМач\\ImageApp\\images\\2 (" + i + ").png");
                png[i].X = tempImg.GetLength(0) * tempImg.GetLength(1);
                normal[i].X = png[i].X;
                better[i].X = png[i].X;
                png[i].Y = (int)new System.IO.FileInfo("C:\\Users\\Light Flight PC\\Desktop\\work\\-misis2024f-24-00-yapparov-e-t\\ВычМач\\ImageApp\\images\\2 (" + i + ").png").Length;
                length = saveImage(tempImg, 3);
                normal[i].Y = length[0];
                better[i].Y = length[1];

            }
            Point temp;
            for (int write = 0; write < png.Length; write++)
            {
                for (int sort = 0; sort < png.Length - 1; sort++)
                {
                    if (png[sort].X > png[sort + 1].X)
                    {
                        temp = png[sort + 1];
                        png[sort + 1] = png[sort];
                        png[sort] = temp;
                        temp = normal[sort + 1];
                        normal[sort + 1] = normal[sort];
                        normal[sort] = temp;
                        temp = better[sort + 1];
                        better[sort + 1] = better[sort];
                        better[sort] = temp;
                    }
                }
            }
            Form2 f2 = new Form2();
            f2.Show();
            f2.f2Show(png, normal, better);
        }
        private void button2_Click(object sender, EventArgs e)
        {
            showImage(decodeImageBetter(openFile()));
        }
        private short[,,] readIm(string path)
        {
            try
            {
                Bitmap image1 = new Bitmap(path, true);

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
        private int[] saveImage(short[,,] masT, int state)
        {
            int x, y;
            int[,] mas = new int[masT.GetLength(0), masT.GetLength(1)];
            for (x = 0; x < masT.GetLength(0); x++)//Перевод в одно число вместо трех
            {
                for (y = 0; y < masT.GetLength(1); y++)
                {
                    mas[x, y] = masT[x, y, 0] * 65536 + masT[x, y, 1] * 256 + masT[x, y, 2];
                }
            }

            bool[] allColors = new bool[16777216];//2**24
            List<int> colors = new List<int>();

            for (x = 0; x < mas.GetLength(0); x++)//Запись всех уникальных цветов
            {
                for (y = 0; y < mas.GetLength(1); y++)
                {
                    allColors[mas[x, y]] = true;
                }
            }
            for (int i = 0; i < allColors.Length; i++)
            {
                if (allColors[i])
                {
                    colors.Add(i);
                }
            }
            byte[] im;
            if (state == 1)
            {
                im = encodeImageBetter(mas, colors);
                saveAs(im);
            }
            else if(state == 2)
            {
                im = encodeImageStandart(mas, colors);
                saveAs(im);
            }
            else if(state == 3)
            {
                int[] lengths = new int[2];
                lengths[0] = getLengthStandart(mas, colors);
                lengths[1] = getLengthBetter(mas, colors);
                return lengths;
            }
            return (null);
        }
        private int getLengthStandart(int[,] mas, List<int> colors)
        {
            int pixelWeight = Convert.ToInt32(Math.Ceiling(Math.Log(colors.Count(), 2)));

            int fyleLength =
            24 + //Байты, отведенные под количество кодируемых цветов
            16 * 2 +//Байты, отведенные под ширину и высоту
            24 * colors.Count() +//Байты, отведенные под расшивровку цветов
            pixelWeight * mas.GetLength(0) * mas.GetLength(1);//Байты под пиксели

            return fyleLength;
        }
        private byte[] encodeImageStandart(int[,] mas, List<int> colors)
        {
            int pixelWeight = Convert.ToInt32(Math.Ceiling(Math.Log(colors.Count(), 2)));

            int fyleLength = getLengthStandart(mas, colors);
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

            label1.Text = "Image ecoded. File weight: " + image.Length + " bytes";
            return image;
        }
        private int getLengthBetter(int[,] mas, List<int> colors)
        {
            int pixelWeight = Convert.ToInt32(Math.Ceiling(Math.Log(colors.Count(), 2)));

            int fyleLength =
            24 + //Байты, отведенные под количество кодируемых цветов
            16 * 2 +//Байты, отведенные под ширину и высоту
            24 * colors.Count();//Байты, отведенные под расшивровку цветов

            int counter = 0;
            for (int x = 0; x < mas.GetLength(0) * mas.GetLength(1) - 1; x++)//Байты под пиксели
            {
                counter += 1;
                if (counter == 255 || mas[(x + 1) / mas.GetLength(1), (x + 1) % mas.GetLength(1)] != mas[x / mas.GetLength(1), x % mas.GetLength(1)])
                {
                    fyleLength += 8;
                    fyleLength += pixelWeight;
                    counter = 0;
                }
            }
            fyleLength += 8;
            fyleLength += pixelWeight;

            return fyleLength;
        }
        private byte[] encodeImageBetter(int[,] mas, List<int> colors)
        {
            int pixelWeight = Convert.ToInt32(Math.Ceiling(Math.Log(colors.Count(), 2)));

            int fyleLength = getLengthBetter(mas, colors);


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


            int counter = 0;
            for (int x = 0; x < mas.GetLength(0) * mas.GetLength(1) - 1; x++)//Байты под пиксели
            {
                counter += 1;
                if (counter == 255 || mas[(x + 1) / mas.GetLength(1), (x + 1) % mas.GetLength(1)] != mas[x / mas.GetLength(1), x % mas.GetLength(1)])
                {
                    insert(ref image, index, toNeededLength(counter, 8));
                    index += 8;
                    insert(ref image, index, toNeededLength(colors.IndexOf(mas[x / mas.GetLength(1), x % mas.GetLength(1)]), pixelWeight));
                    index += pixelWeight;
                    counter = 0;
                }
            }
            counter += 1;
            insert(ref image, index, toNeededLength(counter, 8));
            index += 8;
            insert(ref image, index, toNeededLength(colors.IndexOf(mas[mas.GetLength(0)-1, mas.GetLength(1)-1]), pixelWeight));
            index += pixelWeight;

            label1.Text = "Image incoded. File weight: " + image.Length + " bytes";
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
        private short[,,] decodeImageBetter(byte[] mas)
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

            short[,,] image = new short[width, height, 3];
            int colorInd = 0;
            int pixelWeight = Convert.ToInt32(Math.Ceiling(Math.Log(colorsNumber, 2)));

            int counter = 0;
            for (int x = 0; x < width; x++)
            {
                for (int y = 0; y < height; y++)
                {
                    if (counter == 0)
                    {
                        counter = getFromNeededLength(mas, ind, 8);
                        ind += 8;
                        colorInd = getFromNeededLength(mas, ind, pixelWeight);
                        ind += pixelWeight;
                    }
                    image[x, y, 0] = colors[colorInd, 0];
                    image[x, y, 1] = colors[colorInd, 1];
                    image[x, y, 2] = colors[colorInd, 2];
                    counter -= 1;
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
        public byte[] openFile()
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
                string path = openFileDialog.FileName;
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

        private void button3_Click(object sender, EventArgs e)
        {
            getStats();
        }
    }
}
