namespace tictactoeApp
{
    // an immutable class
    // can't modify the instance but can create a new one with desired values
    public class Position
    {
        public int Row { get; }
        public int Column { get; }
        public Position(int row, int column)
        {
            Row = row;
            Column = column;
        }
    }
}