from turtle import *
from gamebse import square, line
from random import randrange, choice

balloons = []
size = 50
color_Option = ["red", "blue", "light blue", "pink", "dark blue", "green"]


def distance(x, y, a, b):
    return (((a - x) ** 2 + (b - y) ** 2) ** 0.5)


def tap(x, y):
    for n in range(len(balloons)):
        if distance(x, y, balloons[n][0], balloons[n][1]) < (size / 2):
            balloons.pop(n)
            return


def draw():
    clear()
    for n in range(1, len(balloons) + 1):
        line(balloons[-n][0], balloons[-n][1], balloons[-n][0], balloons[-n][1] - size * 1.5, 2, "black")
        up()
        goto(balloons[-n][0], balloons[-n][1])
        dot(size, balloons[-n][2])
        balloons[-n][1] = balloons[-n][1] + 1
    update()


def gameLoop():
    if randrange(0, 50) == 1:
        x = randrange(-200 + size, 200 - size)
        c = choice(color_Option)
        balloons.append([x, -200 - size, c])
    draw()
    ontimer(gameLoop, 10)


setup(420, 420, 0, 0)
hideturtle()
tracer(False)
listen()
onscreenclick(tap)
gameLoop()
done()
