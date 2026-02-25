namespace MyProject
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.LA_Header = new System.Windows.Forms.Label();
            this.GB_Size = new System.Windows.Forms.GroupBox();
            this.Rbtn_Large = new System.Windows.Forms.RadioButton();
            this.Rbtn_Medium = new System.Windows.Forms.RadioButton();
            this.Rbtn_Small = new System.Windows.Forms.RadioButton();
            this.GB_Toppings = new System.Windows.Forms.GroupBox();
            this.ChB_GreenPeppers = new System.Windows.Forms.CheckBox();
            this.ChB_Olives = new System.Windows.Forms.CheckBox();
            this.ChB_Onion = new System.Windows.Forms.CheckBox();
            this.ChB_Tomatoes = new System.Windows.Forms.CheckBox();
            this.ChB_Mushrooms = new System.Windows.Forms.CheckBox();
            this.ChB_ExtraChees = new System.Windows.Forms.CheckBox();
            this.GB_OrderSummary = new System.Windows.Forms.GroupBox();
            this.LA_TotalPrice = new System.Windows.Forms.Label();
            this.LA_WhereToEat = new System.Windows.Forms.Label();
            this.LA_CrustType = new System.Windows.Forms.Label();
            this.LA_Toppings = new System.Windows.Forms.Label();
            this.LA_Size = new System.Windows.Forms.Label();
            this.GB_CrustType = new System.Windows.Forms.GroupBox();
            this.Rbtn_ThinkCrust = new System.Windows.Forms.RadioButton();
            this.Rbtn_ThinCrust = new System.Windows.Forms.RadioButton();
            this.GB_WhereToEat = new System.Windows.Forms.GroupBox();
            this.Rbtn_TakeOut = new System.Windows.Forms.RadioButton();
            this.Rbtn_EatIn = new System.Windows.Forms.RadioButton();
            this.btn_OrderPizza = new System.Windows.Forms.Button();
            this.btn_ResetForm = new System.Windows.Forms.Button();
            this.GB_Size.SuspendLayout();
            this.GB_Toppings.SuspendLayout();
            this.GB_OrderSummary.SuspendLayout();
            this.GB_CrustType.SuspendLayout();
            this.GB_WhereToEat.SuspendLayout();
            this.SuspendLayout();
            // 
            // LA_Header
            // 
            this.LA_Header.AutoSize = true;
            this.LA_Header.Font = new System.Drawing.Font("Bowlby One SC", 36F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LA_Header.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.LA_Header.Location = new System.Drawing.Point(132, 23);
            this.LA_Header.Name = "LA_Header";
            this.LA_Header.Size = new System.Drawing.Size(505, 74);
            this.LA_Header.TabIndex = 0;
            this.LA_Header.Text = "Make Your Pizza";
            // 
            // GB_Size
            // 
            this.GB_Size.Controls.Add(this.Rbtn_Large);
            this.GB_Size.Controls.Add(this.Rbtn_Medium);
            this.GB_Size.Controls.Add(this.Rbtn_Small);
            this.GB_Size.Location = new System.Drawing.Point(55, 121);
            this.GB_Size.Name = "GB_Size";
            this.GB_Size.Size = new System.Drawing.Size(200, 100);
            this.GB_Size.TabIndex = 1;
            this.GB_Size.TabStop = false;
            this.GB_Size.Text = "Size";
            // 
            // Rbtn_Large
            // 
            this.Rbtn_Large.AutoSize = true;
            this.Rbtn_Large.Location = new System.Drawing.Point(7, 68);
            this.Rbtn_Large.Name = "Rbtn_Large";
            this.Rbtn_Large.Size = new System.Drawing.Size(52, 17);
            this.Rbtn_Large.TabIndex = 2;
            this.Rbtn_Large.TabStop = true;
            this.Rbtn_Large.Tag = "40";
            this.Rbtn_Large.Text = "Large";
            this.Rbtn_Large.UseVisualStyleBackColor = true;
            this.Rbtn_Large.CheckedChanged += new System.EventHandler(this.GB_Size_CheckedChanged);
            // 
            // Rbtn_Medium
            // 
            this.Rbtn_Medium.AutoSize = true;
            this.Rbtn_Medium.Checked = true;
            this.Rbtn_Medium.Location = new System.Drawing.Point(8, 44);
            this.Rbtn_Medium.Name = "Rbtn_Medium";
            this.Rbtn_Medium.Size = new System.Drawing.Size(61, 17);
            this.Rbtn_Medium.TabIndex = 1;
            this.Rbtn_Medium.TabStop = true;
            this.Rbtn_Medium.Tag = "30";
            this.Rbtn_Medium.Text = "Medium";
            this.Rbtn_Medium.UseVisualStyleBackColor = true;
            this.Rbtn_Medium.CheckedChanged += new System.EventHandler(this.GB_Size_CheckedChanged);
            // 
            // Rbtn_Small
            // 
            this.Rbtn_Small.AutoSize = true;
            this.Rbtn_Small.Location = new System.Drawing.Point(7, 20);
            this.Rbtn_Small.Name = "Rbtn_Small";
            this.Rbtn_Small.Size = new System.Drawing.Size(49, 17);
            this.Rbtn_Small.TabIndex = 0;
            this.Rbtn_Small.Tag = "20";
            this.Rbtn_Small.Text = "Small";
            this.Rbtn_Small.UseVisualStyleBackColor = true;
            this.Rbtn_Small.CheckedChanged += new System.EventHandler(this.GB_Size_CheckedChanged);
            // 
            // GB_Toppings
            // 
            this.GB_Toppings.Controls.Add(this.ChB_GreenPeppers);
            this.GB_Toppings.Controls.Add(this.ChB_Olives);
            this.GB_Toppings.Controls.Add(this.ChB_Onion);
            this.GB_Toppings.Controls.Add(this.ChB_Tomatoes);
            this.GB_Toppings.Controls.Add(this.ChB_Mushrooms);
            this.GB_Toppings.Controls.Add(this.ChB_ExtraChees);
            this.GB_Toppings.Location = new System.Drawing.Point(279, 121);
            this.GB_Toppings.Name = "GB_Toppings";
            this.GB_Toppings.Size = new System.Drawing.Size(210, 100);
            this.GB_Toppings.TabIndex = 2;
            this.GB_Toppings.TabStop = false;
            this.GB_Toppings.Text = "Toppings";
            // 
            // ChB_GreenPeppers
            // 
            this.ChB_GreenPeppers.AutoSize = true;
            this.ChB_GreenPeppers.Location = new System.Drawing.Point(106, 66);
            this.ChB_GreenPeppers.Name = "ChB_GreenPeppers";
            this.ChB_GreenPeppers.Size = new System.Drawing.Size(97, 17);
            this.ChB_GreenPeppers.TabIndex = 5;
            this.ChB_GreenPeppers.Text = "Green Peppers";
            this.ChB_GreenPeppers.UseVisualStyleBackColor = true;
            this.ChB_GreenPeppers.CheckedChanged += new System.EventHandler(this.GB_Toppings_CheckedChanged);
            // 
            // ChB_Olives
            // 
            this.ChB_Olives.AutoSize = true;
            this.ChB_Olives.Location = new System.Drawing.Point(107, 43);
            this.ChB_Olives.Name = "ChB_Olives";
            this.ChB_Olives.Size = new System.Drawing.Size(55, 17);
            this.ChB_Olives.TabIndex = 4;
            this.ChB_Olives.Text = "Olives";
            this.ChB_Olives.UseVisualStyleBackColor = true;
            this.ChB_Olives.CheckedChanged += new System.EventHandler(this.GB_Toppings_CheckedChanged);
            // 
            // ChB_Onion
            // 
            this.ChB_Onion.AutoSize = true;
            this.ChB_Onion.Location = new System.Drawing.Point(107, 21);
            this.ChB_Onion.Name = "ChB_Onion";
            this.ChB_Onion.Size = new System.Drawing.Size(54, 17);
            this.ChB_Onion.TabIndex = 3;
            this.ChB_Onion.Text = "Onion";
            this.ChB_Onion.UseVisualStyleBackColor = true;
            this.ChB_Onion.CheckedChanged += new System.EventHandler(this.GB_Toppings_CheckedChanged);
            // 
            // ChB_Tomatoes
            // 
            this.ChB_Tomatoes.AutoSize = true;
            this.ChB_Tomatoes.Location = new System.Drawing.Point(13, 66);
            this.ChB_Tomatoes.Name = "ChB_Tomatoes";
            this.ChB_Tomatoes.Size = new System.Drawing.Size(73, 17);
            this.ChB_Tomatoes.TabIndex = 2;
            this.ChB_Tomatoes.Text = "Tomatoes";
            this.ChB_Tomatoes.UseVisualStyleBackColor = true;
            this.ChB_Tomatoes.CheckedChanged += new System.EventHandler(this.GB_Toppings_CheckedChanged);
            // 
            // ChB_Mushrooms
            // 
            this.ChB_Mushrooms.AutoSize = true;
            this.ChB_Mushrooms.Location = new System.Drawing.Point(13, 43);
            this.ChB_Mushrooms.Name = "ChB_Mushrooms";
            this.ChB_Mushrooms.Size = new System.Drawing.Size(80, 17);
            this.ChB_Mushrooms.TabIndex = 1;
            this.ChB_Mushrooms.Text = "Mushrooms";
            this.ChB_Mushrooms.UseVisualStyleBackColor = true;
            this.ChB_Mushrooms.CheckedChanged += new System.EventHandler(this.GB_Toppings_CheckedChanged);
            // 
            // ChB_ExtraChees
            // 
            this.ChB_ExtraChees.AutoSize = true;
            this.ChB_ExtraChees.Location = new System.Drawing.Point(13, 20);
            this.ChB_ExtraChees.Name = "ChB_ExtraChees";
            this.ChB_ExtraChees.Size = new System.Drawing.Size(85, 17);
            this.ChB_ExtraChees.TabIndex = 0;
            this.ChB_ExtraChees.Text = "Extra Chees";
            this.ChB_ExtraChees.UseVisualStyleBackColor = true;
            this.ChB_ExtraChees.CheckedChanged += new System.EventHandler(this.GB_Toppings_CheckedChanged);
            // 
            // GB_OrderSummary
            // 
            this.GB_OrderSummary.Controls.Add(this.LA_TotalPrice);
            this.GB_OrderSummary.Controls.Add(this.LA_WhereToEat);
            this.GB_OrderSummary.Controls.Add(this.LA_CrustType);
            this.GB_OrderSummary.Controls.Add(this.LA_Toppings);
            this.GB_OrderSummary.Controls.Add(this.LA_Size);
            this.GB_OrderSummary.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.GB_OrderSummary.Location = new System.Drawing.Point(516, 121);
            this.GB_OrderSummary.Name = "GB_OrderSummary";
            this.GB_OrderSummary.Size = new System.Drawing.Size(272, 267);
            this.GB_OrderSummary.TabIndex = 3;
            this.GB_OrderSummary.TabStop = false;
            this.GB_OrderSummary.Text = "Order Summary";
            // 
            // LA_TotalPrice
            // 
            this.LA_TotalPrice.AutoSize = true;
            this.LA_TotalPrice.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LA_TotalPrice.Location = new System.Drawing.Point(7, 243);
            this.LA_TotalPrice.Name = "LA_TotalPrice";
            this.LA_TotalPrice.Size = new System.Drawing.Size(112, 16);
            this.LA_TotalPrice.TabIndex = 4;
            this.LA_TotalPrice.Tag = "0";
            this.LA_TotalPrice.Text = "Total Price: 30 $";
            // 
            // LA_WhereToEat
            // 
            this.LA_WhereToEat.AutoSize = true;
            this.LA_WhereToEat.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LA_WhereToEat.Location = new System.Drawing.Point(7, 200);
            this.LA_WhereToEat.Name = "LA_WhereToEat";
            this.LA_WhereToEat.Size = new System.Drawing.Size(141, 16);
            this.LA_WhereToEat.TabIndex = 3;
            this.LA_WhereToEat.Text = "Where To Eat: Eat In";
            // 
            // LA_CrustType
            // 
            this.LA_CrustType.AutoSize = true;
            this.LA_CrustType.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LA_CrustType.Location = new System.Drawing.Point(7, 157);
            this.LA_CrustType.Name = "LA_CrustType";
            this.LA_CrustType.Size = new System.Drawing.Size(112, 16);
            this.LA_CrustType.TabIndex = 2;
            this.LA_CrustType.Text = "Crust Type: Thin";
            // 
            // LA_Toppings
            // 
            this.LA_Toppings.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LA_Toppings.Location = new System.Drawing.Point(7, 58);
            this.LA_Toppings.Name = "LA_Toppings";
            this.LA_Toppings.Size = new System.Drawing.Size(259, 99);
            this.LA_Toppings.TabIndex = 1;
            this.LA_Toppings.Text = "Toppings: No Toppings";
            this.LA_Toppings.UseCompatibleTextRendering = true;
            // 
            // LA_Size
            // 
            this.LA_Size.AutoSize = true;
            this.LA_Size.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LA_Size.Location = new System.Drawing.Point(7, 21);
            this.LA_Size.Name = "LA_Size";
            this.LA_Size.Size = new System.Drawing.Size(91, 16);
            this.LA_Size.TabIndex = 0;
            this.LA_Size.Text = "Size: Meduim";
            // 
            // GB_CrustType
            // 
            this.GB_CrustType.Controls.Add(this.Rbtn_ThinkCrust);
            this.GB_CrustType.Controls.Add(this.Rbtn_ThinCrust);
            this.GB_CrustType.Location = new System.Drawing.Point(55, 249);
            this.GB_CrustType.Name = "GB_CrustType";
            this.GB_CrustType.Size = new System.Drawing.Size(200, 82);
            this.GB_CrustType.TabIndex = 4;
            this.GB_CrustType.TabStop = false;
            this.GB_CrustType.Text = "Crust Type";
            // 
            // Rbtn_ThinkCrust
            // 
            this.Rbtn_ThinkCrust.AutoSize = true;
            this.Rbtn_ThinkCrust.Location = new System.Drawing.Point(8, 52);
            this.Rbtn_ThinkCrust.Name = "Rbtn_ThinkCrust";
            this.Rbtn_ThinkCrust.Size = new System.Drawing.Size(79, 17);
            this.Rbtn_ThinkCrust.TabIndex = 1;
            this.Rbtn_ThinkCrust.Tag = "10";
            this.Rbtn_ThinkCrust.Text = "Think Crust";
            this.Rbtn_ThinkCrust.UseVisualStyleBackColor = true;
            this.Rbtn_ThinkCrust.CheckedChanged += new System.EventHandler(this.GB_CrustType_CheckedChanged);
            // 
            // Rbtn_ThinCrust
            // 
            this.Rbtn_ThinCrust.AutoSize = true;
            this.Rbtn_ThinCrust.Checked = true;
            this.Rbtn_ThinCrust.Location = new System.Drawing.Point(8, 24);
            this.Rbtn_ThinCrust.Name = "Rbtn_ThinCrust";
            this.Rbtn_ThinCrust.Size = new System.Drawing.Size(74, 17);
            this.Rbtn_ThinCrust.TabIndex = 0;
            this.Rbtn_ThinCrust.TabStop = true;
            this.Rbtn_ThinCrust.Tag = "5";
            this.Rbtn_ThinCrust.Text = "Thin Crust";
            this.Rbtn_ThinCrust.UseVisualStyleBackColor = true;
            this.Rbtn_ThinCrust.CheckedChanged += new System.EventHandler(this.GB_CrustType_CheckedChanged);
            // 
            // GB_WhereToEat
            // 
            this.GB_WhereToEat.Controls.Add(this.Rbtn_TakeOut);
            this.GB_WhereToEat.Controls.Add(this.Rbtn_EatIn);
            this.GB_WhereToEat.Location = new System.Drawing.Point(279, 249);
            this.GB_WhereToEat.Name = "GB_WhereToEat";
            this.GB_WhereToEat.Size = new System.Drawing.Size(210, 59);
            this.GB_WhereToEat.TabIndex = 5;
            this.GB_WhereToEat.TabStop = false;
            this.GB_WhereToEat.Text = "Where To Eat";
            // 
            // Rbtn_TakeOut
            // 
            this.Rbtn_TakeOut.AutoSize = true;
            this.Rbtn_TakeOut.Location = new System.Drawing.Point(107, 24);
            this.Rbtn_TakeOut.Name = "Rbtn_TakeOut";
            this.Rbtn_TakeOut.Size = new System.Drawing.Size(69, 17);
            this.Rbtn_TakeOut.TabIndex = 1;
            this.Rbtn_TakeOut.TabStop = true;
            this.Rbtn_TakeOut.Text = "Take Out";
            this.Rbtn_TakeOut.UseVisualStyleBackColor = true;
            this.Rbtn_TakeOut.CheckedChanged += new System.EventHandler(this.GB_WhereToEat_CheckedChanged);
            // 
            // Rbtn_EatIn
            // 
            this.Rbtn_EatIn.AutoSize = true;
            this.Rbtn_EatIn.Checked = true;
            this.Rbtn_EatIn.Location = new System.Drawing.Point(12, 24);
            this.Rbtn_EatIn.Name = "Rbtn_EatIn";
            this.Rbtn_EatIn.Size = new System.Drawing.Size(54, 17);
            this.Rbtn_EatIn.TabIndex = 0;
            this.Rbtn_EatIn.TabStop = true;
            this.Rbtn_EatIn.Text = "Eat In";
            this.Rbtn_EatIn.UseVisualStyleBackColor = true;
            this.Rbtn_EatIn.CheckedChanged += new System.EventHandler(this.GB_WhereToEat_CheckedChanged);
            // 
            // btn_OrderPizza
            // 
            this.btn_OrderPizza.Location = new System.Drawing.Point(279, 357);
            this.btn_OrderPizza.Name = "btn_OrderPizza";
            this.btn_OrderPizza.Size = new System.Drawing.Size(75, 31);
            this.btn_OrderPizza.TabIndex = 6;
            this.btn_OrderPizza.Text = "Order Pizza";
            this.btn_OrderPizza.UseVisualStyleBackColor = true;
            this.btn_OrderPizza.Click += new System.EventHandler(this.btn_OrderPizza_Click);
            // 
            // btn_ResetForm
            // 
            this.btn_ResetForm.Location = new System.Drawing.Point(414, 357);
            this.btn_ResetForm.Name = "btn_ResetForm";
            this.btn_ResetForm.Size = new System.Drawing.Size(75, 31);
            this.btn_ResetForm.TabIndex = 7;
            this.btn_ResetForm.Text = "Reset Form";
            this.btn_ResetForm.UseVisualStyleBackColor = true;
            this.btn_ResetForm.Click += new System.EventHandler(this.btn_ResetForm_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 403);
            this.Controls.Add(this.btn_ResetForm);
            this.Controls.Add(this.btn_OrderPizza);
            this.Controls.Add(this.GB_WhereToEat);
            this.Controls.Add(this.GB_CrustType);
            this.Controls.Add(this.GB_OrderSummary);
            this.Controls.Add(this.GB_Toppings);
            this.Controls.Add(this.GB_Size);
            this.Controls.Add(this.LA_Header);
            this.Name = "Form1";
            this.Text = "Pizza Order";
            this.GB_Size.ResumeLayout(false);
            this.GB_Size.PerformLayout();
            this.GB_Toppings.ResumeLayout(false);
            this.GB_Toppings.PerformLayout();
            this.GB_OrderSummary.ResumeLayout(false);
            this.GB_OrderSummary.PerformLayout();
            this.GB_CrustType.ResumeLayout(false);
            this.GB_CrustType.PerformLayout();
            this.GB_WhereToEat.ResumeLayout(false);
            this.GB_WhereToEat.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label LA_Header;
        private System.Windows.Forms.GroupBox GB_Size;
        private System.Windows.Forms.GroupBox GB_Toppings;
        private System.Windows.Forms.GroupBox GB_OrderSummary;
        private System.Windows.Forms.GroupBox GB_CrustType;
        private System.Windows.Forms.GroupBox GB_WhereToEat;
        private System.Windows.Forms.RadioButton Rbtn_Large;
        private System.Windows.Forms.RadioButton Rbtn_Medium;
        private System.Windows.Forms.RadioButton Rbtn_Small;
        private System.Windows.Forms.RadioButton Rbtn_ThinkCrust;
        private System.Windows.Forms.RadioButton Rbtn_ThinCrust;
        private System.Windows.Forms.RadioButton Rbtn_EatIn;
        private System.Windows.Forms.RadioButton Rbtn_TakeOut;
        private System.Windows.Forms.Button btn_OrderPizza;
        private System.Windows.Forms.Button btn_ResetForm;
        private System.Windows.Forms.CheckBox ChB_Olives;
        private System.Windows.Forms.CheckBox ChB_Onion;
        private System.Windows.Forms.CheckBox ChB_Tomatoes;
        private System.Windows.Forms.CheckBox ChB_Mushrooms;
        private System.Windows.Forms.CheckBox ChB_ExtraChees;
        private System.Windows.Forms.CheckBox ChB_GreenPeppers;
        private System.Windows.Forms.Label LA_Size;
        private System.Windows.Forms.Label LA_CrustType;
        private System.Windows.Forms.Label LA_Toppings;
        private System.Windows.Forms.Label LA_TotalPrice;
        private System.Windows.Forms.Label LA_WhereToEat;
    }
}

