change = float(input("How much change is owed? "))
while change <= 0:
    change = float(input("Please enter a number bigger than 0"))

coins = 0;
change = round(change, 2)
while change > 0:
    if change >= 0.25:
        change -= 0.25    
    elif change >= 0.1:
        change -= 0.10
    elif change >= 0.05:
        change -= 0.05
    else:
	    change -= 0.01
    coins = coins + 1
print(coins)