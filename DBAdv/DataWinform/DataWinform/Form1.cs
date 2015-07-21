using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Linq.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DataWinform
{
    public partial class DBTest : Form
    {
        DataClasses1DataContext context = new DataClasses1DataContext();
        public DBTest()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void maskedTextBox1_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();
            string value = maskedTextBox1.Text;

            switch (comboBox1.SelectedItem.ToString())
            {
                case "Id":
                    {
                        int id = Convert.ToInt32(value);
                        var result = from record in context.restorant
                                     where record.no == id
                                     select record;

                        foreach (var res in result)
                        {
                            this.dataGridView1.Rows.Add(res.no, res.업종, res.업태, res.업소명, res.소재지, res.신고_허가_일자);
                        }
                    }
                    break;
                case "업종":
                    {
                        var result = from record in context.restorant
                                     where SqlMethods.Like(record.업종, "%" + value + "%")
                                     select record;

                        foreach (var res in result)
                        {
                            this.dataGridView1.Rows.Add(res.no, res.업종, res.업태, res.업소명, res.소재지, res.신고_허가_일자);
                        }
                    }
                    break;
                case "업소명":
                    {
                        var result = from record in context.restorant
                                     where SqlMethods.Like(record.업소명, "%" + value + "%")
                                     select record;

                        foreach (var res in result)
                        {
                            this.dataGridView1.Rows.Add(res.no, res.업종, res.업태, res.업소명, res.소재지, res.신고_허가_일자);
                        }
                    }
                    break;
                case "업태":
                    {
                        var result = from record in context.restorant
                                     where SqlMethods.Like(record.업태, "%" + value + "%")
                                     select record;

                        foreach (var res in result)
                        {
                            this.dataGridView1.Rows.Add(res.no, res.업종, res.업태, res.업소명, res.소재지, res.신고_허가_일자);
                        }
                    }
                    break;
                case "소재지":
                    {
                        var result = from record in context.restorant
                                     where SqlMethods.Like(record.소재지, "%" + value + "%")
                                     select record;

                        foreach (var res in result)
                        {
                            this.dataGridView1.Rows.Add(res.no, res.업종, res.업태, res.업소명, res.소재지, res.신고_허가_일자);
                        }
                    }
                    break;

                case "신고일자":
                    {
                        var result = from record in context.restorant
                                     where SqlMethods.Like(record.신고_허가_일자, "%" + value + "%")
                                     select record;

                        foreach (var res in result)
                        {
                            this.dataGridView1.Rows.Add(res.no, res.업종, res.업태, res.업소명, res.소재지, res.신고_허가_일자);
                        }
                    }
                    break;
                default:
                    return;
            }


        }

        private int ToInt32(string value)
        {
            throw new NotImplementedException();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
          
        }
    }
}
