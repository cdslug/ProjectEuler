with open('names.txt', 'r') as f:
	read_data = [l.replace("\"","") for l in f.readline().split(",")]
sorted_names = sorted(read_data)

name_score_total = 0
for name_index, name in enumerate(sorted_names):
	name_sum = 0
	for letter in name.lower():
		name_sum += ord(letter)-ord("a") + 1

	name_score_total += (name_index + 1) * name_sum

print("Name Score: " + str(name_score_total))