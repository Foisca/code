from turtle import *


def square(x, y, size, color_name):
    up()
    goto(x, y)
    down()
    color(color_name)
    begin_fill()

    forward(size)
    left(90)
    forward(size)
    left(90)
    forward(size)
    left(90)
    forward(size)
    left(90)

    end_fill()


def line(x, y, a, b, line_width=1, color_name="black"):
    up()
    goto(x, y)
    down()
    color(color_name)
    width(line_width)
    goto(a, b)

# setup(420, 420, 0, 0)
# hideturtle()
# tracer(False)
# square(50, 50, 10, "red")
# done()
