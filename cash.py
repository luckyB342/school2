from cs50 import get_float

user_input = -1

# While loop to reprompt user when negative input is typed
while user_input < 0:
    user_input = get_float("How much change is owed: ")

c = round(user_input * 100)

# Divide by 25 to get number of quarters and save by the remainder
qc = int(c / 25)
r = int(c % 25)

# Divide by 10 to get number of dime to save remainder
dc = int(r / 10)
r = int(r % 10)

# Divide by 5 to get number of nickel to save remainder
nc = int(r / 5)
pc = int(r % 5)

# Get sum of count
coins = round(qc + dc + nc + pc)
print(f"The last number of coins is {coins}")
