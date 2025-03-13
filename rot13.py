# Implementation of the ROT-13 algorithm
# Bugs - There is a problem of uniqueness as some characters example
# 4 and 'M' will all give you "A" and this brings the problem

upper = [x for x in range(ord('A'), ord('Z') + 1)]
lower = [x for x in range(ord('a'), ord('z') + 1)]

def ROT(new_word: str):
    """
    Returns a symmetric rotated character for the alphabets but
    return a character shifted by 13 places in the ASCII format
    """
    u_limit, l_limit = 77, 109
    rot = []
    
    for i in new_word:
        if ord(i) in upper:
            if ord(i) > u_limit:
                rot.append(chr(ord(i) - 13))
            # elif ord(i) == ord(" "):
            #     rot.append(" ")
            else:
                rot.append(chr(ord(i) + 13))

        elif ord(i) in lower:
            if ord(i) > l_limit:
                rot.append(chr(ord(i) - 13))
            # elif ord(i) == ord(" "):
            #     rot.append(" ")
            else:
                rot.append(chr(ord(i) + 13))
        elif ord(i) == ord(" "):
            rot.append(" ")
        else:
            rot.append(chr(ord(i)+ 13))

    return rot

def str_list(nlist):
    nword = ''
    for i in nlist:
        nword = nword + i
    return nword

# print(upper, lower)
word = input("Please enter your phrase to rot: ")

rot13 = ROT(word)
rotated = str_list(rot13)

print(rotated)
