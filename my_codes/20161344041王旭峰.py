#!/usr/bin/env python
# coding=utf-8
dir_x=[1,+1,+1,0]
dir_y=[0,-1,+1,1]

def PrintBoard():
    print(' 0 1 2 3 4 5 6 7 8 9 a b c d e f')
    for i in range(16):
        print(hex(i)[2],end='')
        for j in range(16):
            print(board[i][j],end=' ')
        print()

def OutWall(x_y):
    lis=list(range(0,16))
    if x_y[0] in lis and x_y[1] in lis: 
        return False
    else:
        return True

def Win(i,j,chess):
    for cnt in range(4):
        num=1
        left_x,left_y=i,j
        right_x,right_y=i,j
        for k in range(5):
            if OutWall([right_x+dir_x[cnt],right_y+dir_y[cnt]])==False and board[right_x+dir_x[cnt]][right_y+dir_y[cnt]]==chess:
                right_x+=dir_x[cnt]
                right_y+=dir_y[cnt]
                num+=1
            if OutWall([left_x-dir_x[cnt],left_y-dir_y[cnt]])==False and  board[left_x-dir_x[cnt]][left_y-dir_y[cnt]]==chess:
                left_x-=dir_x[cnt]
                left_y-=dir_y[cnt]
                num+=1
        if num>=5:
            return True
    return False



def play(player=0):
    index=''
    chess=''
    if player==0:
        index=input("黑棋落子:")
        chess='@'
    else:
        index=input("白棋落子:")
        chess='0'
    x_y=[int(index[0],16),int(index[1],16)]
    if len(index)!=2 or OutWall(x_y)==True:
        print("输入坐标不正确，请重新输入!")
        play(player)
    elif board[x_y[0]][x_y[1]]!='*':
        print("此处已有棋子，请重新输入!")
        play(player)
    else:
        board[x_y[0]][x_y[1]]=chess
        PrintBoard()
        if Win(x_y[0],x_y[1],chess)==True:
            print("黑方胜利!" if player==0 else "白方胜利!")
        else:
            play(1-player)

if __name__ == '__main__':
    while True:
        board=[['*' for i in range(16)] for i in range(16)]
        play()
        re=input("重新开始请按s:")
        if re!='s':
            break
