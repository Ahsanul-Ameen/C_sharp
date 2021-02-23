using System;

namespace tictactoeApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Board board = new Board();
            WinChecker winChecker = new WinChecker();
            Renderer renderer = new Renderer();
            Player player1 = new Player();
            Player player2 = new Player();

            while(!winChecker.IsDraw(board) && winChecker.Check(board) == State.Undecided)
            {
                renderer.Render(board);
                Position nextMove = (board.NextTurn == State.X) ? player1.GetPosition(board) : player2.GetPosition(board);
                if(!board.SetState(nextMove, board.NextTurn))
                    Console.WriteLine("That is not a legal move.");
            }

            renderer.Render(board);
            renderer.RenderResults(winChecker.Check(board));

            Console.ReadKey();
        }
    }
}
