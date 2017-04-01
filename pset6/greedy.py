import cs50

while True:
    # get non-negative float from user
    print("How much change is owed?")
    amount = cs50.get_float()
    if amount > 0:
        break

# convert the float into cents rounded
cents = round(amount * 100)

# quarters
coins_returned = cents//25  # '//' for integer 
cents %= 25

# dimes
coins_returned += cents//10
cents %= 10

# nickels
coins_returned += cents//5
cents %= 5

# pennies
coins_returned += cents

print(coins_returned)