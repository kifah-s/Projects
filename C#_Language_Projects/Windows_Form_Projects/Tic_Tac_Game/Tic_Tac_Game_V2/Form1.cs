using MyProject.Properties;
using System.Drawing;
using System.Windows.Forms;

namespace MyProject
{
    public partial class Form1 : Form
    {
        enum enPlayer
        {
            Player1,
            Player2
        }
        enPlayer PlayerTurn = enPlayer.Player1;

        enum enWinner
        {
            Player1,
            Player2,
            Draw,
            GameInProgress
        }

        struct stGameStatus
        {
            public enWinner Winner;
            public bool GameOver;
            public short PlayCount;
        }
        stGameStatus GameStatus;

        void RestButton(Button btn)
        {
            btn.Image = Resources.question_mark_96;
            btn.Tag = "?";
            btn.BackColor = Color.Transparent;
        }

        void RestartGame()
        {
            RestButton(button1);
            RestButton(button2);
            RestButton(button3);
            RestButton(button4);
            RestButton(button5);
            RestButton(button6);
            RestButton(button7);
            RestButton(button8);
            RestButton(button9);

            PlayerTurn = enPlayer.Player1;
            lblTurn.Text = "Player 1";
            GameStatus.PlayCount = 0;
            GameStatus.GameOver = false;
            GameStatus.Winner = enWinner.GameInProgress;
            lblWinner.Text = "In Progress";
        }

        bool CheckValues(Button btn1, Button btn2, Button btn3)
        {
            if (btn1.Tag.ToString() != "?" && btn1.Tag.ToString() == btn2.Tag.ToString() && btn1.Tag.ToString() == btn3.Tag.ToString())
            {
                btn1.BackColor = Color.GreenYellow;
                btn2.BackColor = Color.GreenYellow;
                btn3.BackColor = Color.GreenYellow;

                if (btn1.Tag.ToString() == "X")
                {
                    GameStatus.Winner = enWinner.Player1;
                    GameStatus.GameOver = true;
                    EndGame();
                    return true;
                }
                else
                {
                    GameStatus.Winner = enWinner.Player2;
                    GameStatus.GameOver = true;
                    EndGame();
                    return true;
                }
            }

            GameStatus.GameOver = false;

            return false;
        }

        void EndGame()
        {
            lblTurn.Text = "Game Over";

            switch (GameStatus.Winner)
            {
                case enWinner.Player1:
                    {
                        lblWinner.Text = "Player1";
                        break;
                    }

                case enWinner.Player2:
                    {
                        lblWinner.Text = "Player2";
                        break;
                    }

                default:
                    {
                        lblWinner.Text = "Draw";
                        break;
                    }
            }

            MessageBox.Show("GameOver", "GameOver", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        void CheckWinner()
        {
            // Checked rows.
            // Check Row1.
            if (CheckValues(button1, button2, button3))
            {
                return;
            }

            // Check Row2.
            if (CheckValues(button4, button5, button6))
            {
                return;
            }

            // Check Row3.
            if (CheckValues(button7, button8, button9))
            {
                return;
            }

            // Checked cols.
            // Check col1.
            if (CheckValues(button1, button4, button7))
            {
                return;
            }

            // Check col2.
            if (CheckValues(button2, button5, button8))
            {
                return;
            }

            // Check col3.
            if (CheckValues(button3, button6, button9))
            {
                return;
            }

            // Check Diagonal.
            // Check Diagonal1.
            if (CheckValues(button1, button5, button9))
            {
                return;
            }

            // Check Diagonal2.
            if (CheckValues(button3, button5, button7))
            {
                return;
            }
        }

        void ChangeImage(Button btn)
        {
            if (btn.Tag.ToString() == "?")
            {
                switch (PlayerTurn)
                {
                    case enPlayer.Player1:
                        {
                            btn.Image = Resources.X;
                            PlayerTurn = enPlayer.Player2;
                            lblTurn.Text = "Player 2";
                            GameStatus.PlayCount++;
                            btn.Tag = "X";
                            CheckWinner();
                            break;
                        }

                    case enPlayer.Player2:
                        {
                            btn.Image = Resources.O;
                            PlayerTurn = enPlayer.Player1;
                            lblTurn.Text = "Player 1";
                            GameStatus.PlayCount++;
                            btn.Tag = "O";
                            CheckWinner();
                            break;
                        }
                }
            }
            else
            {
                MessageBox.Show("Wrong Choice", "Worng", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            if (GameStatus.PlayCount == 9)
            {
                GameStatus.GameOver = true;
                GameStatus.Winner = enWinner.Draw;
                EndGame();
            }
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Color White = Color.White;
            Pen WhitePen = new Pen(White);
            WhitePen.Width = 10;
            WhitePen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            WhitePen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            // Drow Horizental Lines.
            // e.Graphics.DrawLine(WhitePen, 400, 220, 850, 220);
            // e.Graphics.DrawLine(WhitePen, 400, 350, 850, 350);

            // Drow Vertical Lines.
            // e.Graphics.DrawLine(WhitePen, 520, 140, 520, 420);
            // e.Graphics.DrawLine(WhitePen, 720, 140, 720, 420);

            int startX = 420;
            int startY = 120;
            int cellSize = 125;
            int totalSize = cellSize * 3;

            int x1 = startX + cellSize;
            int x2 = startX + (cellSize * 2);
            int y1 = startY + cellSize;
            int y2 = startY + (cellSize * 2);

            e.Graphics.DrawLine(WhitePen, startX, y1, startX + totalSize, y1);
            e.Graphics.DrawLine(WhitePen, startX, y2, startX + totalSize, y2);

            e.Graphics.DrawLine(WhitePen, x1, startY, x1, startY + totalSize);
            e.Graphics.DrawLine(WhitePen, x2, startY, x2, startY + totalSize);
        }

        private void button1_Click(object sender, System.EventArgs e)
        {
            ChangeImage(button1);
        }

        private void button2_Click(object sender, System.EventArgs e)
        {
            ChangeImage(button2);
        }

        private void button3_Click(object sender, System.EventArgs e)
        {
            ChangeImage(button3);
        }

        private void button4_Click(object sender, System.EventArgs e)
        {
            ChangeImage(button4);
        }

        private void button5_Click(object sender, System.EventArgs e)
        {
            ChangeImage(button5);
        }

        private void button6_Click(object sender, System.EventArgs e)
        {
            ChangeImage(button6);
        }

        private void button7_Click(object sender, System.EventArgs e)
        {
            ChangeImage(button7);
        }

        private void button8_Click(object sender, System.EventArgs e)
        {
            ChangeImage(button8);
        }

        private void button9_Click(object sender, System.EventArgs e)
        {
            ChangeImage(button9);
        }

        private void btnRestartGame_Click(object sender, System.EventArgs e)
        {
            RestartGame();
        }
    }
}
