using SimpleTCP;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TestingSoftware
{
    struct data_packet_1
    {
        public Int16 out_temp;
        public Int16 in_temp;
        public Int16 out_hum;
        public Int16 in_hum;
        public Int16 wind_speed;
        public Int16 peak_wind_speed;
        public Int16 bearing;
        public Int16 pressure;
        public Int16 rainfall;
        public Int16 rainfall_rate;
        public UInt32 timestamp;
    }


    struct data_packet
    {
        public Int16 temp;
        public Int16 hum;
        public Int16 wind_speed;
        public Int16 peak_wind_speed;
        public Int16 rain;
        public Int16 bearing;
        public byte checksum;
    }

    public partial class Form1 : Form
    {

       


        struct data_packet_2
        {
            public Int16 out_temp_H;
            public Int16 out_temp_L;
            public Int16 in_temp_H;
            public Int16 in_temp_L;
            public Int16 out_hum_H;
            public Int16 out_hum_L;
            public Int16 in_hum_H;
            public Int16 in_hum_L;
            public Int16 wind_speed;
            public Int16 peak_wind_speed;
            public Int16 bearing;
            public Int16 pressure_H;
            public Int16 pressure_L;
            public Int16 rainfall;
            public UInt32 timestamp;
        }

        data_packet remote;

        public Form1()
        {
            InitializeComponent();
        }

        // private void update_txtReply(object sender, string msg) { txtReply.Text = msg; }

        private void button1_Click(object sender, EventArgs e)
        {
            //    TcpClient client = new TcpClient("192.168.0.39", 80);
            //    string d = "Terry";
            //    int byteCount = Encoding.ASCII.GetByteCount(d);
            //    byte[] sendData = new byte[byteCount];
            //    sendData = Encoding.ASCII.GetBytes(d);

            //    NetworkStream stream = client.GetStream();
            //    stream.Write(sendData, 0, sendData.Length);

            //    if (stream.CanRead)
            //    {
            //        // Reads NetworkStream into a byte buffer.
            //        byte[] bytes = new byte[client.ReceiveBufferSize];

            //        // Read can return anything from 0 to numBytesToRead. 
            //        // This method blocks until at least one byte is read.
            //        stream.Read(bytes, 0, (int)client.ReceiveBufferSize);

            //        // Returns the data received from the host to the console.
            //        string returndata = Encoding.UTF8.GetString(bytes);
            //        TextBox.CheckForIllegalCrossThreadCalls = false;
            //        txtReply.AppendText(returndata);
            //    }

            //    stream.Close();
            //    client.Close();
            //}
            // connect to device
            TcpClient client = new TcpClient();
            client.Connect(System.Net.IPAddress.Parse("192.168.0.40"), 80);
            
            byte[] data = new byte[24];
            remote.temp = 201;
            remote.hum = 700;
            remote.wind_speed = 200;
            remote.peak_wind_speed = 400;
            remote.bearing = 200;
            remote.checksum = Sum(remote);

        // create post data to be sent
        string postDataAsString = @"POST /r / HTTP/1.1" + Environment.NewLine +
            "Host: 192.168.0.40" + Environment.NewLine +
            "Content-Length: 13" + Environment.NewLine +
            Environment.NewLine +
            Environment.NewLine;
            int headerSize = Encoding.ASCII.GetByteCount(postDataAsString);
            byte[] DataBinary = System.Text.Encoding.UTF8.GetBytes(postDataAsString);

            byte[] postDataBinary = new byte[headerSize + 13];
            Array.Copy(DataBinary, postDataBinary, headerSize);
            int len = 13;
            IntPtr ptr = Marshal.AllocHGlobal(len);
            Marshal.StructureToPtr(remote, ptr, true);
            Marshal.Copy(ptr, postDataBinary, headerSize, len);
            Marshal.FreeHGlobal(ptr);

            // make post request
            client.Client.Send(postDataBinary);

            // get response
            byte[] bytes = new byte[1024];
            int lengthOfResponse = client.Client.Receive(bytes);

            var resp = System.Text.Encoding.UTF8.GetString(bytes, 0, lengthOfResponse);

                    TextBox.CheckForIllegalCrossThreadCalls = false;
                    txtReply.AppendText(resp);
        }

        byte Sum(data_packet message)
        {
            byte sum = 0;
            byte[] block = new byte[13];
            IntPtr ptr = Marshal.AllocHGlobal(13);
            Marshal.StructureToPtr(message, ptr, true);
            Marshal.Copy(ptr, block, 0, 12);
            Marshal.FreeHGlobal(ptr);

            int nBytes = 0;
            while (nBytes< 13)
            {
                sum += block[nBytes++];

            }

            return (sum);

        }   /* Sum() */

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
    }
