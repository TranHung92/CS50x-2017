import cs50
import sys


if len(sys.argv) != 2:
    print("Usage: python caesar.py k")
    exit(1)
        
k = int(sys.argv[1])
    
print("plaintext: ", end="")
p = cs50.get_string()
if p != None:
    print("ciphertext: ", end="")
    for c in p:
        if c.isalpha():
            i = ord(c)
            if c.islower():
                ch = chr((((i-97)+k)%26)+97)
                print(ch, end="")
            else:
                ch = chr((((i-65)+k)%26)+65)
                print(ch, end="")
        else:
            print(c, end="")
    print()
else:
    exit(2)
exit(0)    
