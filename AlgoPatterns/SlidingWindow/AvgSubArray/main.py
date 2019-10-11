def find_averages_of_subarrays(K, arr):
  result = []
  for i in range(len(arr)-K+1):
    # find sum of next 'K' elements
    _sum = 0.0
    for j in range(i, i+K):
      _sum += arr[j]
    result.append(_sum/K)  # calculate average

  return result


def main():
  K = 5
  result = find_averages_of_subarrays(K, [1, 3, 2, 6, -1, 4, 1, 8, 2])
  print("Averages of subarrays of size {}: ".format(K) + str(result))


main()