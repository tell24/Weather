using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Http;
using System.Threading;
using System.Runtime.InteropServices;

namespace TestingSoftware
{
    public partial class Form1 : Form
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

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            PostCurrent();
        }


        static byte[] getCurrentBytes(data_packet_1 str)
        {
            int size = Marshal.SizeOf(str);
            byte[] arr = new byte[size];

            IntPtr ptr = Marshal.AllocHGlobal(size);
            Marshal.StructureToPtr(str, ptr, true);
            Marshal.Copy(ptr, arr, 0, size);
            Marshal.FreeHGlobal(ptr);
            return arr;
        }

        static async Task PostCurrent()
        {
            //    
            data_packet_1 remote_data;
            remote_data.out_temp = 100;
            remote_data.in_temp = 246;
            remote_data.out_hum = 784;
            remote_data.in_hum = 549;
            remote_data.wind_speed = 34;
            remote_data.peak_wind_speed = 86;
            remote_data.bearing = 253;
            remote_data.pressure = 1026;
            remote_data.rainfall = 77;
            remote_data.rainfall_rate = 167;
            remote_data.timestamp = 6588290;

            byte[] bin = new byte[Marshal.SizeOf(remote_data)];
            bin = getCurrentBytes(remote_data);
            // var questionId = 1;
            ByteArrayContent byteContent = new ByteArrayContent(bin);

            string url = "http://192.168.0.39:80/1";

            var uri = new Uri(Uri.EscapeUriString(url));
            var myHttpClient = new HttpClient();
            var response = await myHttpClient.PostAsync(uri.ToString(), byteContent);
            var result = await response.Content.ReadAsStringAsync();
            Console.WriteLine($"{url}: {url.Length / 2:N0} characters");
            Console.WriteLine(response.ToString());
        }

        static byte[] getHistoryBytes(data_packet_2 str)
        {
            int size = Marshal.SizeOf(str);
            byte[] arr = new byte[size];

            IntPtr ptr = Marshal.AllocHGlobal(size);
            Marshal.StructureToPtr(str, ptr, true);
            Marshal.Copy(ptr, arr, 0, size);
            Marshal.FreeHGlobal(ptr);
            return arr;
        }

        static async Task PostHistory()
        {
            //    
            data_packet_2 remote_data;
            remote_data.out_temp_H = 123;
            remote_data.out_temp_L = 97;
            remote_data.in_temp_H = 239;
            remote_data.in_temp_L = 195;
            remote_data.out_hum_H = 967;
            remote_data.out_hum_L = 598;
            remote_data.in_hum_H = 608;
            remote_data.in_hum_L = 407;
            remote_data.wind_speed = 75;
            remote_data.peak_wind_speed = 156;
            remote_data.bearing = 254;
            remote_data.pressure_H = 1026;
            remote_data.pressure_L = 998;
            remote_data.rainfall = 890;
            remote_data.timestamp = 6588290; ;

            byte[] bin = new byte[Marshal.SizeOf(remote_data)];// StructureToByteArray(remote_data);
            bin = getHistoryBytes(remote_data);
            // var questionId = 1;
            ByteArrayContent byteContent = new ByteArrayContent(bin);

            string url = "http://192.168.0.39:80/2";

            var uri = new Uri(Uri.EscapeUriString(url));
            var myHttpClient = new HttpClient();
            var response = await myHttpClient.PostAsync(uri.ToString(), byteContent);
            var result = await response.Content.ReadAsStringAsync();
            Console.WriteLine($"{url}: {url.Length / 2:N0} characters");
            Console.WriteLine(result.ToString());
        }
    }
}
