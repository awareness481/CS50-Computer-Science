rows = int(input("Rows: "))
while (rows > 23):
    rows = int(input("Enter a number lower than 24: "))

for i in range(rows):
    spaces = rows - i - 1
    print(" " * spaces + "#" * i + "##")

    