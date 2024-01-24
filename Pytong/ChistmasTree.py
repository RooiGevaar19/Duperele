def holidaybush(n):
	for i in range(n):
		print(("+" * (i * 2 + 1)).center(n * 2 - 1))
	print(("|").center(n * 2 - 1))
	print(("|").center(n * 2 - 1))

holidaybush(5)

