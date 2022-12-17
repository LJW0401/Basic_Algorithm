from audioop import reverse


a=[5,4,7,2,7,9,6,3,6,12,6,43,98]

#直接插入排序
def insert_sort(a:list,reverse=False):
    if reverse:
        sign=-1
    else:
        sign=1
    #sign = (0.5-int(reverse))//1
    #print(sign)
    for i in range(1,len(a)):
        k = i
        while a[k]*sign < a[k-1]*sign and k > 0:
            temp = a[k-1]
            a[k-1] = a[k]
            a[k] = temp
            k = k-1
    return a

#折半插入排序
def half_isert_sort(a:list,reverse=False):
    if reverse:
        sign=-1
    else:
        sign=1
    for i in range(1,len(a)):
        left = 0
        right = i-1
        while left <= right:
            mid = (left+right)//2
            if a[mid]*sign <= a[i]*sign:
                left = mid+1
            else:
                right = mid+1
        if left != i:
            t = a[left]
            a[left] = a[i]
            a[i] = t
    return a

#希尔排序
def hill_sort(a:list,reverse=False):
    pass

#冒泡排序
def bubble_sort(a:list,reverse=False):
    if reverse:
        sign=-1
    else:
        sign=1
    for i in range(0,len(a)-1):
        for j in range(len(a)-1,i,-1):
            if a[j-1]*sign > a[j]*sign:
                temp = a[j]
                a[j] = a[j-1]
                a[j-1] = temp
    return a

#快速排序
def quick_sort(a:list,reverse=False):
    if len(a)==0:
        return []
    if reverse:
        sign=-1
    else:
        sign=1
    c=0
    key=a[0]
    left=0
    right=len(a)-1
    while left < right:
        if a[left] * sign > a[right] * sign:
            c += 1
            t = a[left]
            a[left] = a[right]
            a[right] = t
        if c%2==0:
            right -= 1
        elif c%2==1:
            left += 1
    a = quick_sort(a[:right],reverse) + [key] + quick_sort(a[left+1:],reverse)
    return a

#简单选择排序
def easy_choose_sort(a:list,reverse=False):
    if reverse:
        sign=-1
    else:
        sign=1
    for i in range(0,len(a)-1):
        k = i
        for j in range(i+1,len(a)):
            if a[k] * sign > a[j] * sign:
                k = j
        if k != i:
            t = a[k]
            a[k] = a[i]
            a[i] = t
    return a

#堆排序
def pile_sort(a:list,reverse=False):
    pass

print("---升序测试---")
print("升序排序结果：",sorted(a))
print("直接插入升序：",insert_sort(a))
print("折半插入升序：",half_isert_sort(a))
#print("希尔排序升序：",hill_sort(a))
print("冒泡排序升序：",bubble_sort(a))
print("快速排序升序：",quick_sort(a))
print("简单选择升序：",easy_choose_sort(a))
print("---降序测试---")
print("降序排序结果：",sorted(a,reverse=True))
print("直接插入降序：",insert_sort(a,reverse=True))
print("折半插入降序：",half_isert_sort(a,reverse=True))
#print("希尔排序降序：",hill_sort(a,reverse=True))
print("冒泡排序降序：",bubble_sort(a,reverse=True))
print("快速排序降序：",quick_sort(a,reverse=True))
print("简单选择降序：",easy_choose_sort(a,reverse=True))
# print("测试：")
# print(quick_sort([50,36,66,76,12,25]))