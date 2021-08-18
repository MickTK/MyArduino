using System;
using System.Diagnostics;
using System.Drawing;
using System.IO.Ports;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace PortReader
{
    public partial class PortReader : Form
    {
        [DllImport("user32.dll")]
        public static extern void keybd_event(byte virtualKey, byte scanCode, uint flags, IntPtr extraInfo);

        public const int KEYEVENTF_EXTENTEDKEY = 1;
        public const int KEYEVENTF_KEYUP = 0;
        public const int VK_MEDIA_NEXT_TRACK = 0xB0;
        public const int VK_MEDIA_PLAY_PAUSE = 0xB3;
        public const int VK_MEDIA_PREV_TRACK = 0xB1;
        public const int VK_VOLUME_MUTE = 0xAD;
        public const int VK_VOLUME_DOWN = 0xAE;
        public const int VK_VOLUME_UP = 0xAF;

        string s;
        bool on = false;
        SerialPort sp = new SerialPort("COM4", 9600);
        public PortReader()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                sp.DataReceived += new SerialDataReceivedEventHandler(sp_DataReceived);
                sp.Open();
                labelStatus.ForeColor = Color.FromArgb(0, 255, 0);
                labelStatus.Text = "On";
                on = true;
            }
            catch (Exception ex)
            {
                labelStatus.ForeColor = Color.FromArgb(255, 0, 0);
                labelStatus.Text = "Off";
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                on = false;
            }
        }

        private void sp_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            s += sp.ReadExisting();

            try
            {
                if (comp(s, "play") || comp(s, "pause"))
                {
                    keybd_event(VK_MEDIA_PLAY_PAUSE, 0, KEYEVENTF_EXTENTEDKEY, IntPtr.Zero);
                    sp.WriteLine("Done!");
                    s = "";
                }

                else if (comp(s, "vol-"))
                {
                    keybd_event(VK_VOLUME_DOWN, 0, KEYEVENTF_EXTENTEDKEY, IntPtr.Zero);
                    sp.WriteLine("Done!");
                    s = "";
                }

                else if (comp(s, "vol+"))
                {
                    keybd_event(VK_VOLUME_UP, 0, KEYEVENTF_EXTENTEDKEY, IntPtr.Zero);
                    sp.WriteLine("Done!");
                    s = "";
                }

                else if (comp(s, "fast forward"))
                {
                    keybd_event(VK_MEDIA_NEXT_TRACK, 0, KEYEVENTF_EXTENTEDKEY, IntPtr.Zero);
                    sp.WriteLine("Done!");
                    s = "";
                }

                else if (comp(s, "fast back"))
                {
                    keybd_event(VK_MEDIA_PREV_TRACK, 0, KEYEVENTF_EXTENTEDKEY, IntPtr.Zero);
                    sp.WriteLine("Done!");
                    s = "";
                }

                GC.Collect();
                //Console.Write(s);
            }
            catch (Exception ex)
            {

            }
        }

        public static bool comp(string port, string x)
        {
            string g = port.ToLower();
            x = x.ToLower();

            try
            {
                for (int i = 0; i < x.Length; i++)
                {
                    g = g.Substring(g.IndexOf(x[i]));
                }
                return true;
            }
            catch (Exception e)
            {
                return false;
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if(!on)
                try
                {
                    sp.DataReceived += new SerialDataReceivedEventHandler(sp_DataReceived);
                    sp.Open();
                    labelStatus.ForeColor = Color.FromArgb(0, 255, 0);
                    labelStatus.Text = "On";
                    on = true;
                }
                catch (Exception ex)
                {
                    labelStatus.ForeColor = Color.FromArgb(255, 0, 0);
                    labelStatus.Text = "Off";
                    MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    on = false;
                }
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Process.Start("https://github.com/MickTK");
        }
    }
}
