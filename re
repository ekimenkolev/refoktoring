using System;
using System.Drawing;
using System.Drawing.Drawing2D;


namespace RefactorMe
{
    class Painter
    {
        static float x, y;
        static Graphics graphicArts;

        public static void Initialize(Graphics newGraphic)
        {
            graphicArts = newGraphic;
            graphicArts.SmoothingMode = SmoothingMode.None;
            graphicArts.Clear(Color.Black);
        }

        public static void SetPosition(float x0, float y0)
        { x = x0; y = y0; }

        public static void MakeIt(Pen pen, double length, double angle)
        {
            //Делает шаг длиной dlina в направлении ugol и рисует пройденную траекторию
            var x1 = (float)(x + length * Math.Cos(angle));
            var y1 = (float)(y + length * Math.Sin(angle));
            graphicArts.DrawLine(pen, x, y, x1, y1);
            x = x1;
            y = y1;
        }

        public static void Change(double length, double angle)
        {
            x = (float)(x + length * Math.Cos(angle));
            y = (float)(y + length * Math.Sin(angle));
        }
    }
    
    public class ImpossibleSquare
    {
        public const float FirstConst = 0.375f;
        public const float SecondConst = 0.04f;
        public static void PaintSide1(int width, int height)
        {
            var min = Math.Min(width, height);
           
            Painter.MakeIt(Pens.Yellow, min * FirstConst, 0);
            Painter.MakeIt(Pens.Yellow, min * SecondConst * Math.Sqrt(2), Math.PI / 4);
            Painter.MakeIt(Pens.Yellow, min * FirstConst, Math.PI);
            Painter.MakeIt(Pens.Yellow, min * FirstConst - min * SecondConst, Math.PI / 2);
        }

        public static void PaintSide2(int width, int height)
        {
            var min = Math.Min(width, height);

            Painter.MakeIt(Pens.Yellow, min * FirstConst, -Math.PI / 2);
            Painter.MakeIt(Pens.Yellow, min * SecondConst * Math.Sqrt(2), -Math.PI / 2 + Math.PI / 4);
            Painter.MakeIt(Pens.Yellow, min * FirstConst, -Math.PI / 2 + Math.PI);
            Painter.MakeIt(Pens.Yellow, min * FirstConst - min * SecondConst, -Math.PI / 2 + Math.PI / 2);
        }

        public static void PaintSide3(int width, int height)
        {
            var min = Math.Min(width, height);

            Painter.MakeIt(Pens.Yellow, min * FirstConst, Math.PI);
            Painter.MakeIt(Pens.Yellow, min * SecondConst * Math.Sqrt(2), Math.PI + Math.PI / 4);
            Painter.MakeIt(Pens.Yellow, min * FirstConst, Math.PI + Math.PI);
            Painter.MakeIt(Pens.Yellow, min * FirstConst - min * SecondConst, Math.PI + Math.PI / 2);
        }

        public static void PaintSide4(int width, int height)
        {
            var min = Math.Min(width, height);

            Painter.MakeIt(Pens.Yellow, min * FirstConst, Math.PI / 2);
            Painter.MakeIt(Pens.Yellow, min * SecondConst * Math.Sqrt(2), Math.PI / 2 + Math.PI / 4);
            Painter.MakeIt(Pens.Yellow, min * FirstConst, Math.PI / 2 + Math.PI);
            Painter.MakeIt(Pens.Yellow, min * FirstConst - min * SecondConst, Math.PI / 2 + Math.PI / 2);
        }

        public static void Change1(int width, int height)
        {
            var min = Math.Min(width, height);
            Painter.Change(min * SecondConst, -Math.PI);
            Painter.Change(min * SecondConst * Math.Sqrt(2), 3 * Math.PI / 4);
        }

        public static void Change2(int width, int height)
        {
            var min = Math.Min(width, height);
            Painter.Change(min * SecondConst, -Math.PI / 2 - Math.PI);
            Painter.Change(min * SecondConst * Math.Sqrt(2), -Math.PI / 2 + 3 * Math.PI / 4);
        }

        public static void Change3(int width, int height)
        {
            var min = Math.Min(width, height);
            Painter.Change(min * SecondConst, Math.PI - Math.PI);
            Painter.Change(min * SecondConst * Math.Sqrt(2), Math.PI + 3 * Math.PI / 4);
        }

        public static void Change4(int width, int height)
        {
            var min = Math.Min(width, height);
            Painter.Change(min * SecondConst, Math.PI / 2 - Math.PI);
            Painter.Change(min * SecondConst * Math.Sqrt(2), Math.PI / 2 + 3 * Math.PI / 4);
        }

        public static void WeDrawEverything(int width, int height)
        {
            //Рисуем 1-ую сторону
            PaintSide1(width, height);
            Change1(width, height);

            //Рисуем 2-ую сторону
            PaintSide2(width, height);
            Change2(width, height);

            //Рисуем 3-ю сторону
            PaintSide3(width, height);
            Change3(width, height);

            //Рисуем 4-ую сторону
            PaintSide4(width, height);
            Change4(width, height);
        }

        public static void Draw(int width, int height, double angleOfRotation, Graphics graphic)
        {
            // ugolPovorota пока не используется, но будет использоваться в будущем
            Painter.Initialize(graphic);

            var min = Math.Min(width, height);

            var diagonal_length = Math.Sqrt(2) * (min * FirstConst + min * SecondConst) / 2;
            var x0 = (float)(diagonal_length * Math.Cos(Math.PI / 4 + Math.PI)) + width / 2f;
            var y0 = (float)(diagonal_length * Math.Sin(Math.PI / 4 + Math.PI)) + height / 2f;

            Painter.SetPosition(x0, y0);

            WeDrawEverything(width, height);
        }
    }
}
