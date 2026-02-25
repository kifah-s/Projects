using MyProject.Properties;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace MyProject
{
    public partial class frmTicTacToeGame : Form
    {
        public frmTicTacToeGame()
        {
            InitializeComponent();
        }

        void ChangePicture(object sender)
        {
            if (lblTurn.Text == "Player 1" && ((PictureBox)sender).Tag.ToString() == "?")
            {
                ((PictureBox)sender).Image = Resources.X;
                ((PictureBox)sender).Tag = "X";
                lblTurn.Text = "Player 2";
            }
            else if (lblTurn.Text == "Player 2" && ((PictureBox)sender).Tag.ToString() == "?")
            {
                ((PictureBox)sender).Image = Resources.O;
                ((PictureBox)sender).Tag = "O";
                lblTurn.Text = "Player 1";
            }
            else if (((PictureBox)sender).Tag.ToString() == "X" || ((PictureBox)sender).Tag.ToString() == "O")
            {
                MessageBox.Show("Wrong Choice", "Wrong", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        void Player1Winner()
        {
            if (pictureBox1.Tag.ToString() == "X" && pictureBox2.Tag.ToString() == "X" && pictureBox3.Tag.ToString() == "X")
            {
                lblWinner.Text = "Player 1";
                lblTurn.Text = "Game Over";
                pictureBox1.BackColor = Color.Green;
                pictureBox2.BackColor = Color.Green;
                pictureBox3.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox4.Tag.ToString() == "X" && pictureBox5.Tag.ToString() == "X" && pictureBox6.Tag.ToString() == "X")
            {
                lblWinner.Text = "Player 1";
                lblTurn.Text = "Game Over";
                pictureBox4.BackColor = Color.Green;
                pictureBox5.BackColor = Color.Green;
                pictureBox6.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox7.Tag.ToString() == "X" && pictureBox8.Tag.ToString() == "X" && pictureBox9.Tag.ToString() == "X")
            {
                lblWinner.Text = "Player 1";
                lblTurn.Text = "Game Over";
                pictureBox7.BackColor = Color.Green;
                pictureBox8.BackColor = Color.Green;
                pictureBox9.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox1.Tag.ToString() == "X" && pictureBox4.Tag.ToString() == "X" && pictureBox7.Tag.ToString() == "X")
            {
                lblWinner.Text = "Player 1";
                lblTurn.Text = "Game Over";
                pictureBox1.BackColor = Color.Green;
                pictureBox4.BackColor = Color.Green;
                pictureBox7.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox2.Tag.ToString() == "X" && pictureBox5.Tag.ToString() == "X" && pictureBox8.Tag.ToString() == "X")
            {
                lblWinner.Text = "Player 1";
                lblTurn.Text = "Game Over";
                pictureBox2.BackColor = Color.Green;
                pictureBox5.BackColor = Color.Green;
                pictureBox8.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox3.Tag.ToString() == "X" && pictureBox6.Tag.ToString() == "X" && pictureBox9.Tag.ToString() == "X")
            {
                lblWinner.Text = "Player 1";
                lblTurn.Text = "Game Over";
                pictureBox3.BackColor = Color.Green;
                pictureBox6.BackColor = Color.Green;
                pictureBox9.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox1.Tag.ToString() == "X" && pictureBox5.Tag.ToString() == "X" && pictureBox9.Tag.ToString() == "X")
            {
                lblWinner.Text = "Player 1";
                lblTurn.Text = "Game Over";
                pictureBox1.BackColor = Color.Green;
                pictureBox5.BackColor = Color.Green;
                pictureBox9.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox3.Tag.ToString() == "X" && pictureBox5.Tag.ToString() == "X" && pictureBox7.Tag.ToString() == "X")
            {
                lblWinner.Text = "Player 1";
                lblTurn.Text = "Game Over";
                pictureBox3.BackColor = Color.Green;
                pictureBox5.BackColor = Color.Green;
                pictureBox7.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        void Player2Winner()
        {
            if (pictureBox1.Tag.ToString() == "O" && pictureBox2.Tag.ToString() == "O" && pictureBox3.Tag.ToString() == "O")
            {
                lblWinner.Text = "Player 2";
                lblTurn.Text = "Game Over";
                pictureBox1.BackColor = Color.Green;
                pictureBox2.BackColor = Color.Green;
                pictureBox3.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox4.Tag.ToString() == "O" && pictureBox5.Tag.ToString() == "O" && pictureBox6.Tag.ToString() == "O")
            {
                lblWinner.Text = "Player 2";
                lblTurn.Text = "Game Over";
                pictureBox4.BackColor = Color.Green;
                pictureBox5.BackColor = Color.Green;
                pictureBox6.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox7.Tag.ToString() == "O" && pictureBox8.Tag.ToString() == "O" && pictureBox9.Tag.ToString() == "O")
            {
                lblWinner.Text = "Player 2";
                lblTurn.Text = "Game Over";
                pictureBox7.BackColor = Color.Green;
                pictureBox8.BackColor = Color.Green;
                pictureBox9.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox1.Tag.ToString() == "O" && pictureBox4.Tag.ToString() == "O" && pictureBox7.Tag.ToString() == "O")
            {
                lblWinner.Text = "Player 2";
                lblTurn.Text = "Game Over";
                pictureBox1.BackColor = Color.Green;
                pictureBox4.BackColor = Color.Green;
                pictureBox7.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox2.Tag.ToString() == "O" && pictureBox5.Tag.ToString() == "O" && pictureBox8.Tag.ToString() == "O")
            {
                lblWinner.Text = "Player 2";
                lblTurn.Text = "Game Over";
                pictureBox2.BackColor = Color.Green;
                pictureBox5.BackColor = Color.Green;
                pictureBox8.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox3.Tag.ToString() == "O" && pictureBox6.Tag.ToString() == "O" && pictureBox9.Tag.ToString() == "O")
            {
                lblWinner.Text = "Player 2";
                lblTurn.Text = "Game Over";
                pictureBox3.BackColor = Color.Green;
                pictureBox6.BackColor = Color.Green;
                pictureBox9.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox1.Tag.ToString() == "O" && pictureBox5.Tag.ToString() == "O" && pictureBox9.Tag.ToString() == "O")
            {
                lblWinner.Text = "Player 2";
                lblTurn.Text = "Game Over";
                pictureBox1.BackColor = Color.Green;
                pictureBox5.BackColor = Color.Green;
                pictureBox9.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (pictureBox3.Tag.ToString() == "O" && pictureBox5.Tag.ToString() == "O" && pictureBox7.Tag.ToString() == "O")
            {
                lblWinner.Text = "Player 2";
                lblTurn.Text = "Game Over";
                pictureBox3.BackColor = Color.Green;
                pictureBox5.BackColor = Color.Green;
                pictureBox7.BackColor = Color.Green;
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        void DrowPlayers()
        {
            if (pictureBox1.Tag.ToString() != "?" && pictureBox2.Tag.ToString() != "?" && pictureBox3.Tag.ToString() != "?" && pictureBox4.Tag.ToString() != "?" && pictureBox5.Tag.ToString() != "?" && pictureBox6.Tag.ToString() != "?" && pictureBox7.Tag.ToString() != "?" && pictureBox8.Tag.ToString() != "?" && pictureBox9.Tag.ToString() != "?")
            {
                lblWinner.Text = "Draw";
                lblTurn.Text = "Game Over";
                MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        void RestartGame()
        {
            for (int i = 1; i <= 9; i++)
            {
                PictureBox pb = this.Controls.Find("pictureBox" + i, true).FirstOrDefault() as PictureBox;

                if (pb != null)
                {
                    pb.Image = Properties.Resources.question_mark_96;
                    pb.BackColor = Color.Black;
                    pb.Tag = "?";
                }
            }

            // pictureBox1.Image = Resources.question_mark_96;
            // pictureBox2.Image = Resources.question_mark_96;
            // pictureBox3.Image = Resources.question_mark_96;
            // pictureBox4.Image = Resources.question_mark_96;
            // pictureBox5.Image = Resources.question_mark_96;
            // pictureBox6.Image = Resources.question_mark_96;
            // pictureBox7.Image = Resources.question_mark_96;
            // pictureBox8.Image = Resources.question_mark_96;
            // pictureBox9.Image = Resources.question_mark_96;

            // pictureBox1.BackColor = Color.Black;
            // pictureBox2.BackColor = Color.Black;
            // pictureBox3.BackColor = Color.Black;
            // pictureBox4.BackColor = Color.Black;
            // pictureBox5.BackColor = Color.Black;
            // pictureBox6.BackColor = Color.Black;
            // pictureBox7.BackColor = Color.Black;
            // pictureBox8.BackColor = Color.Black;
            // pictureBox9.BackColor = Color.Black;

            // pictureBox1.Tag = "?";
            // pictureBox2.Tag = "?";
            // pictureBox3.Tag = "?";
            // pictureBox4.Tag = "?";
            // pictureBox5.Tag = "?";
            // pictureBox6.Tag = "?";
            // pictureBox7.Tag = "?";
            // pictureBox8.Tag = "?";
            // pictureBox9.Tag = "?";

            lblTurn.Text = "Player 1";
            lblWinner.Text = "In Progress";
        }

        private void frmTicTacToeGame_Paint(object sender, PaintEventArgs e)
        {
            int left = 470;
            int top = 120;
            int cellSize = 110;
            int cols = 3;
            int rows = 3;

            Pen pen = new Pen(Color.White, 4);

            for (int i = 0; i <= cols; i++)
            {
                int x = left + i * cellSize;
                e.Graphics.DrawLine(pen, x, top, x, top + rows * cellSize);
            }

            for (int i = 0; i <= rows; i++)
            {
                int y = top + i * cellSize;
                e.Graphics.DrawLine(pen, left, y, left + cols * cellSize, y);
            }
        }

        private void frmTicTacToeGame_Load(object sender, System.EventArgs e)
        {
            Player1Winner();
            Player2Winner();
            DrowPlayers();
        }

        private void pictureBox1_Click(object sender, System.EventArgs e)
        {
            ChangePicture(sender);
            frmTicTacToeGame_Load(sender, e);
        }

        private void pictureBox2_Click(object sender, System.EventArgs e)
        {
            ChangePicture(sender);
            frmTicTacToeGame_Load(sender, e);
        }

        private void pictureBox3_Click(object sender, System.EventArgs e)
        {
            ChangePicture(sender);
            frmTicTacToeGame_Load(sender, e);
        }

        private void pictureBox4_Click(object sender, System.EventArgs e)
        {
            ChangePicture(sender);
            frmTicTacToeGame_Load(sender, e);
        }

        private void pictureBox5_Click(object sender, System.EventArgs e)
        {
            ChangePicture(sender);
            frmTicTacToeGame_Load(sender, e);
        }

        private void pictureBox6_Click(object sender, System.EventArgs e)
        {
            ChangePicture(sender);
            frmTicTacToeGame_Load(sender, e);
        }

        private void pictureBox7_Click(object sender, System.EventArgs e)
        {
            ChangePicture(sender);
            frmTicTacToeGame_Load(sender, e);
        }

        private void pictureBox8_Click(object sender, System.EventArgs e)
        {
            ChangePicture(sender);
            frmTicTacToeGame_Load(sender, e);
        }

        private void pictureBox9_Click(object sender, System.EventArgs e)
        {
            ChangePicture(sender);
            frmTicTacToeGame_Load(sender, e);
        }

        private void button1_Click(object sender, System.EventArgs e)
        {
            RestartGame();
        }
    }
}
