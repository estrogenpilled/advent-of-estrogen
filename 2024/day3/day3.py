import re
from argparse import ArgumentParser

parser = ArgumentParser(prog = 'AoC 2024 day 3 solution',
                        description = 'does what the title says',
                        epilog = 'Excuse me. For I have dabbled in the sinful language.'
                        );
parser.add_argument('-f', '--filename')
args = parser.parse_args();

def part2():
    sum = 0
    disabled = False
    input_file = open(args.filename)
    input = input_file.read()
    matches = re.findall(r'(do\(\)|don\'t\(\))|(mul\((?:\d|\,|\d)*\))', input)
    for tup in matches:
        list_itm = list(tup)
        for item in list_itm:
            multi = 1
            if item == "don't()":
                disabled = True
            elif item == "do()":
                disabled = False
            if disabled is not True and re.match(r'(mul\((?:\d|\,|\d)*\))', item) is not None:
                ints = re.findall(r'\d+', item)
                for i in ints:
                    multi *= int(i)
                sum += multi
    print("Part 2 result:", sum)

def part1():
    sum = 0
    input_file = open(args.filename)
    input = input_file.read()
    matches = re.findall(r'(mul\((?:\d|\,|\d)*\))', input)
    for mul in matches:
        ints = re.findall(r'\d+', mul)
        multi = 1
        for i in ints:
            multi *= int(i)
        sum += multi
    print("Part 1 result:", sum)


part1()
part2()
