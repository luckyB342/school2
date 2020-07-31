from sys import argv, exit
import csv

while len(argv) != 3:
        print("Usage error!")
        exit(1)
# Open text file and load into memory
sequence_file = open(str(argv[2]), 'r')
read_txt = sequence_file.read()
txtseq = str(read_txt)
sequence_file.close()

# Open database in a read mode and copy into a dictionary data struture
db_dic = []
with open(str(argv[1]), 'r') as db_dict:
    read_Dic = csv.DictReader(db_dict, delimiter=',')
    for i in read_Dic:
        db_dic.append(i)
        
# Tracks the longest run for each STR
STRs = ['AGATC', 'AATG', 'TATC']
result = [0, 0, 0]
i = 0
for strings in STRs:
    count = 0
    temp = strings

    while strings in txtseq:
        count += 1
        strings += temp
    result[i] = count
    i += 1
# Match the results and print the right name
j = 0

for person in db_dic:
    if int(db_dic[j]['AGATC']) == result[0] and int(db_dic[j]['AATG']) == result[1] and int(db_dic[j]['TATC']) == result[2]:
        print(db_dic[j]['name'])
        exit(0)
    j += 1
print('No match')
exit(0)
