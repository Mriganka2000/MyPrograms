# More Pizza
# Solution for the Practice Round of Google Hash Code 2020
MAX, NUM=map(int, input().split())
inputList=list(map(int,input().strip().split()))

def solve(MAX, inputList):
    solutionIndexList = []  # To store the best solution indexes through out the solution generating
    solutionValueList = []  # To store the best solution values through out the solution generating
    currentIndexList = []  # To store the current solution indexes through out the solution generating
    currentValueList = []  # To store the current solution values through out the solution generating

    fullSize = len(inputList)

    maxScore = 0  # Stores the maximum score achieved through out the solution generating

    startIndex = fullSize  # Stores index which the solution generating should start from

    sum = 0

    # Solution generating starts from the last element of the inputList
    # If first element of currentIndexList becomes 0 that means solution generating is finished

    while ((len(currentIndexList) > 0 and currentIndexList[0] != 0) or len(currentIndexList) == 0):

        startIndex = startIndex - 1

        for i in range(startIndex, -1, -1):  # Used to traverse from end to start of the inputList

            currentValue = inputList[i]

            tempSum = sum + currentValue

            if (tempSum == MAX):  # If the temporary sum is equal to target that means the perfect solution is found
                sum = tempSum
                currentIndexList.append(i)  # Add current Pizza index to the solution
                currentValueList.append(currentValue)  # Add current Pizza value to the solution
                break  # Go to return solution

            elif (tempSum > MAX):  # If the temporary sum is greter than target
                continue  # Try next value

            elif (tempSum < MAX):  # If the temporary sum is lesser than target
                sum = tempSum
                currentIndexList.append(i)  # Add current Pizza index to the solution
                currentValueList.append(currentValue)  # Add current Pizza value to the solution
                continue  # Try next value

        if (maxScore < sum):  # If currently generated solution has the best score
            maxScore = sum  # Save its value

            solutionIndexList = []
            solutionValueList = []

            for y in currentIndexList:
                solutionIndexList.append(y)  # Save the currently best solution indexes
            for y in currentValueList:
                solutionValueList.append(y)  # Save the currently best solution values

        if (maxScore == MAX):  # If current solution is the perfect solution
            break  # Stop solution generating

        if (len(currentValueList) != 0):
            lastVal = currentValueList.pop()  # Remove the last element from current values
            sum = sum - lastVal  # Subtract it from sum

        if (len(currentIndexList) != 0):
            lastIndex = currentIndexList.pop()  # Remove the last element from current indexes
            startIndex = lastIndex  # Make it as the starting index for the next iteration

        if (len(currentIndexList) == 0 and (startIndex == 0)):  # If solution generating is almost finished
            break  # Stop solution generating

    return solutionIndexList  # Return indexes list of the best solution




outputList = solve(MAX, inputList)  # Solve the problem and get output

#  Print output data and create output file
print("{}".format(len(outputList)))
sol=outputList[::-1]
fsol=[str(a) for a in sol]
print(" ".join(fsol))