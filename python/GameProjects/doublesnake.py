###############引入数据库与函数###############
from turtle import *
from gamebse import square
from random import randrange
from tkinter import messagebox

###############定义变量###############
snake = [[[0, 0], [10, 0], [20, 0]],
         [[0, 50], [10, 50], [20, 50]]]

apple_x = [randrange(-20, 18) * 10, randrange(-20, 18) * 10]
apple_y = [randrange(-19, 19) * 10, randrange(-19, 19) * 10]

aim_x = [10, 10]
aim_y = [0, 0]


###############定义函数###############
def init():
    global aim_x, aim_y, snake, apple_x, apple_y
    snake[0] = [[0, 0], [10, 0], [20, 0]]
    snake[1] = [[0, 50], [10, 50], [20, 50]]
    apple_x = [randrange(-20, 18) * 10, randrange(-20, 18) * 10]
    apple_y = [randrange(-19, 19) * 10, randrange(-19, 19) * 10]
    aim_x = [10, 10]
    aim_y = [0, 0]


def draw():
    # 画边框
    square(-210, -200, 410, "black")
    square(-200, -190, 390, "white")
    # 画苹果
    for i in range(2):
        square(apple_x[i], apple_y[i], 10, "red")

        for n in range(len(snake[0])):
            square(snake[i][n][0], snake[i][n][1], 10, "black")
    # # 画第一个蛇
    # for n in range(len(snake[0])):
    #     square(snake[0][n][0], snake[0][n][1], 10, "black")
    # # 画第二个蛇
    # for n in range(len(snake[1])):
    #     square(snake[1][n][0], snake[1][n][1], 10, "green")


# snake[0] dirrection
def change1(x, y):
    global aim_x, aim_y
    aim_x[0] = x
    aim_y[0] = y


# snake[1] dir
def change2(x, y):
    global aim_x, aim_y
    aim_x[1] = x
    aim_y[1] = y


def query():
    return messagebox.askquestion("你挂了！", "继续玩？")


def inside(snake):
    if (-200 <= snake[-1][0] <= 180 and -190 <= snake[-1][1] <= 190):
        return True
    return False


def crashed(snake):
    # dead is true
    if (not inside(snake)): return True
    for n in range(len(snake) - 1):
        if snake[-1][0] == snake[n][0] and snake[-1][1] == snake[n][1]:
            return True
    return False


def ateApple(snake):
    for n in range(2):
        if snake[0] == apple_x[n] and snake[1] == apple_y[n]:
            apple_x[n] = randrange(-20, 18) * 10
            apple_y[n] = randrange(-19, 19) * 10
            return True
    return False


def snakeGrow(snake, x, y):
    global apple_x, apple_y
    snake.append([snake[-1][0] + x, snake[-1][1] + y])
    for n in range(2):
        #     if not ateApple(snake[n]):
        # snake[0].pop(0)
        if (snake[n][-1][0] != apple_x[0] or snake[n][-1][1] != apple_y[0]) or (
                snake[n][-1][0] != apple_x[1] or snake[n][-1][1] != apple_y[1]):
            snake.pop(0)

        else:
            apple_x[0] = randrange(-20, 18) * 10
            apple_y[0] = randrange(-19, 19) * 10


def gameLoop():
    global apple_x, apple_y, aim_x, aim_y, snake
    # snake[0] grow
    snakeGrow(snake[0], aim_x[0], aim_y[0])
    # snake[1] grow
    snakeGrow(snake[1], aim_x[1], aim_y[1])
    # judge snake[0] dead
    if (crashed(snake[0])):
        square(snake[0][-1][0], snake[0][-1][1], 10, "red")
        update()
        if (query() == "no"):
            exit(0)
        init()
    # judge snake[1] dead
    if (crashed(snake[1])):
        square(snake[1][-1][0], snake[1][-1][1], 10, "red")
        update()
        if (query() == "no"):
            exit(0)
        init()
    clear()

    draw()
    ontimer(gameLoop, 100)
    update()


###############主程序###############
setup(420, 420, 0, 0)
hideturtle()
tracer(False)
listen()
# snake[0] movement
onkey(lambda: change1(0, 10), "w")
onkey(lambda: change1(0, -10), "s")
onkey(lambda: change1(-10, 0), "a")
onkey(lambda: change1(10, 0), "d")
# snake[1] movement
onkey(lambda: change2(0, 10), "Up")
onkey(lambda: change2(0, -10), "Down")
onkey(lambda: change2(-10, 0), "Left")
onkey(lambda: change2(10, 0), "Right")
gameLoop()
done()
