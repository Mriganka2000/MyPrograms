n = int(input())

nums = []

for i in range(0, n):
    x = int(input())
    nums.append(x)

max_sum, count = 0, 0

# Add all the integers greater than or equal to 0

for num in nums:

    if num >= 0:
        max_sum += num

        count += 1

if not count:

    print(f"{max(nums)} 1")

else:

    print(f"{max_sum} {count}")