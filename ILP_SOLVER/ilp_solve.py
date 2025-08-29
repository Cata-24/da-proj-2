# ilp_solve.py


from pulp import LpProblem, LpMaximize, LpVariable, lpSum, LpBinary, PULP_CBC_CMD

class Pallet:
    def __init__(self, id, profit, weight):
        self.id = id
        self.profit = profit
        self.weight = weight

f = open("../ILP_SOLVER/input.txt", 'r')
lines = f.readlines()
max_weight = int(lines[0].strip())
pallets = []
for i in range(1, len(lines)):
    parts = list(map(int, lines[i].strip().split()))
    pallets.append(Pallet(*parts))
n = len(pallets)

model = LpProblem("ilp_aproach", LpMaximize)
x = []
for i in range(n):
    x.append(LpVariable(f"x{i}", cat=LpBinary))

total_weight = 0
for i in range(n):
    total_weight += x[i] * pallets[i].weight
model += (total_weight <= max_weight)

total_profit = 0
for i in range(n):
    total_profit += x[i] * pallets[i].profit
model += total_profit

model.solve(PULP_CBC_CMD(msg=0))

result = []
for i in range(n):
    if x[i].varValue > 0.5:
        result.append(pallets[i])

f = open("../ILP_SOLVER/output.txt", 'w')
for i in range(0, len(result)):
    if i == len(result) - 1:
        f.write(f"{result[i].id} {result[i].profit} {result[i].weight}")
        continue
    f.write(f"{result[i].id} {result[i].profit} {result[i].weight}\n")
