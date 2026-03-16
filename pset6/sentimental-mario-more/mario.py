from cs50 import get_int
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

if height > 0 and height < 9:
    for i in range(height):
        space = height - i - 1
        hasht = i + 1
        m_space = 2
        print(" "*space + "#"*hasht + " "*m_space + "#"*hasht)
