using System;
using System.Windows.Forms;

namespace MyProject
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int SelectSize(int TotalPrice)
        {
            if (Rbtn_Small.Checked)
            {
                TotalPrice += 20;
                LA_Size.Text = "Size: Small";
            }
            else if (Rbtn_Medium.Checked)
            {
                TotalPrice += 30;
                LA_Size.Text = "Size: Medium";
            }
            else if (Rbtn_Large.Checked)
            {
                TotalPrice += 40;
                LA_Size.Text = "Size: Large";
            }

            return TotalPrice;
        }

        int SelectCrustType(int TotalPrice)
        {
            if (Rbtn_ThinCrust.Checked)
            {
                LA_CrustType.Text = "Crust Type: Thin";
            }
            else if (Rbtn_ThinkCrust.Checked)
            {
                TotalPrice += 5;
                LA_CrustType.Text = "Crust Type: Think";
            }

            return TotalPrice;
        }

        int WhereToEat(int TotalPrice)
        {
            if (Rbtn_EatIn.Checked)
            {
                LA_WhereToEat.Text = "Where To Eat: Eat In";
            }
            else if (Rbtn_TakeOut.Checked)
            {
                TotalPrice += 5;
                LA_WhereToEat.Text = "Where To Eat: Take Out";
            }

            return TotalPrice;
        }


        int SelectToppings(int TotalPrice)
        {
            string Toppings = "Toppings: ";

            if (ChB_ExtraChees.Checked)
            {
                TotalPrice += 5;
                Toppings = Toppings + " |Extra Chess| ";
            }
            if (ChB_Mushrooms.Checked)
            {
                TotalPrice += 5;
                Toppings = Toppings + " |Mushrooms| ";
            }
            if (ChB_Tomatoes.Checked)
            {
                TotalPrice += 5;
                Toppings = Toppings + " |Tomatoes| ";
            }
            if (ChB_Onion.Checked)
            {
                TotalPrice += 5;
                Toppings = Toppings + " |Onion| ";
            }
            if (ChB_Olives.Checked)
            {
                TotalPrice += 5;
                Toppings = Toppings + " |Olives| ";
            }
            if (ChB_GreenPeppers.Checked)
            {
                TotalPrice += 5;
                Toppings = Toppings + " |Green Peppers| ";
            }
            LA_Toppings.Text = Toppings;

            return TotalPrice;
        }

        private void UpdateOrderSummary()
        {
            int TotalPrice = 0;

            TotalPrice = SelectSize(TotalPrice);

            TotalPrice = SelectCrustType(TotalPrice);

            TotalPrice = WhereToEat(TotalPrice);

            TotalPrice = SelectToppings(TotalPrice);

            LA_TotalPrice.Text = $"Total Price: {TotalPrice} $";
        }


        private void GB_Size_CheckedChanged(object sender, EventArgs e)
        {
            UpdateOrderSummary();
        }

        private void GB_CrustType_CheckedChanged(object sender, EventArgs e)
        {
            UpdateOrderSummary();
        }
        private void GB_WhereToEat_CheckedChanged(object sender, EventArgs e)
        {
            UpdateOrderSummary();
        }

        private void GB_Toppings_CheckedChanged(object sender, EventArgs e)
        {
            UpdateOrderSummary();
        }

        private void btn_OrderPizza_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Confirm Order", "Confirm", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);

            if (result == DialogResult.OK)
            {
                MessageBox.Show("Order Placed Successfully", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);

                GB_Size.Enabled = false;
                GB_CrustType.Enabled = false;
                GB_Toppings.Enabled = false;
                GB_WhereToEat.Enabled = false;
                btn_OrderPizza.Enabled = false;
            }
        }

        private void btn_ResetForm_Click(object sender, EventArgs e)
        {
            GB_Size.Enabled = true;
            GB_CrustType.Enabled = true;
            GB_Toppings.Enabled = true;
            GB_WhereToEat.Enabled = true;
            btn_OrderPizza.Enabled = true;

            Rbtn_Medium.Checked = true;
            Rbtn_ThinCrust.Checked = true;
            Rbtn_EatIn.Checked = true;

            ChB_ExtraChees.Checked = false;
            ChB_Mushrooms.Checked = false;
            ChB_Tomatoes.Checked = false;
            ChB_Onion.Checked = false;
            ChB_Olives.Checked = false;
            ChB_GreenPeppers.Checked = false;
        }
    }
}
