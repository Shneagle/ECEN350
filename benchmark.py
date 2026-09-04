SIZE = 50000

#initialize arrays A, B and C
A = [0] * SIZE
B = [0] * SIZE
C = [0] * SIZE

for i in range(SIZE): #input values into A, B and C
    A[i] = i
    B[i] = SIZE-i
    C[i] = 0

#for each element in C, compute sum of B[j] from 0 to A[i]
for i in range(SIZE):
    total = 0
    for j in range(A[i] + 1):
        total += B[j]
    C[i] = total

checksum = sum(C) #final sum

#output checksum and compare against expected
expected_checksum = 41667916675000
print(f"Computed checksum: {checksum}")

if checksum != expected_checksum:
    print(f"Error: checksum is incorrect. Expected {expected_checksum}, got {checksum}", flush=True)
    import sys
    sys.exit(1) #exit with nonzero error value of 1 if incorrect

