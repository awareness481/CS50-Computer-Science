import sys

if len(sys.argv) != 2:
    print("Error")
    exit(1)

key = int(sys.argv[1])
text = input("plaintext: ")
buffer = ""
for s in text:
    if s.islower():
        buffer += chr((ord(s) + key - 97) % 26 + 97)
    elif s.isupper():
        buffer += chr((ord(s) + key - 65) % 26 + 65)
    else:
        buffer += s
print(buffer)
