import heapq


#小根堆的实现，如果大根堆的话，将数字都变为负数
head = [1,9,3,7,5,6]
heap = []
for i in head:
    heapq.heappush(heap,(i,"ans"))
print('head: ',head)
print('heap: ',heap)
while heap:
    print(heap[0])
    min = heapq.heappop(heap)
    # print('heap: ',heap)
