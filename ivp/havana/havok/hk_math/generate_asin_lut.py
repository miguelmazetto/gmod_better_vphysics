import math

#print("{ ", end='')
#xofs = 0
#for s in range(-256, 256):
#    x = math.pow(abs(s/256), 1/3)
#    if s < 0: x = -x
#
#    print(f"{math.asin(x)}, ", end='')
#
#print(f"{math.asin(1)} {'}'}", end='')

size = 1024

print("{ ", end='')
xofs = 0
for s in range(-size/2, size/2):
    x = math.pow(abs(s/256), 1/3)
    if s < 0: x = -x
#
    print(f"{math.asin(x)}, ", end='')
#
print(f"{math.asin(1)} {'}'}", end='')