def checkPalindrome(s, lo, hi):
  while lo>=0 and hi<len(s) and s[lo]==s[hi]:
    lo -= 1
    hi += 1
    return s[lo+1:hi]


def longestPalindrome(s):
  res = ""
  for i in range(len(s)):
    word1 = checkPalindrome(s, i, i)
    word2 = checkPalindrome(s, i, i+1)
    word1 = word1 if len(word1) >= len(word2) else word2
    res = word1 if len(word1) >= len(res) else res  
  print(res)
  return res 

# binary search 101 
# recursive approach
def binarySerachRec(arr, l, r, x):
  if r >= l:
    mid = l + (r + 1) // 2
    if arr[mid] == x:
      return mid
    elif arr[mid] > x:
      return binarySearch(arr, l, mid - 1, x)
    else:
      return binarySerach(arr, mid + 1, r, x)
  else:
    return -1

# iterative approach
def binarySearchIt(arr, l, r, x):
  while l <= r:
    mid = l + (r - 1) // 2
    if arr[mid] == x:
      return mid
    elif arr[mid] < x:
      l = mid + 1
    else:
      r = mid - 1
  return -1

def median(arr):
  n = len(arr)
  if n % 2 == 0:
    return (arr[n // 2] + arr[(n // 2) - 1]) / 2
  else:
    return arr[n // 2]
"""    z = n // 2
    e = arr[z]
    q = arr[z-1]
    ans = (e + q) / 2
"""

def findMedianSortedArrays(nums1, nums2):

  nums3 = (nums1 + nums2).sort()
  return median(nums3)

class Solution:
  def findMedianSortedArrays(self, A, B):
    l = len(A) + len(B)
    return self.findKth(A,B,l//2) if l%2==1 \
      else (self.findKth(A,B,l//2-1)+self.findKth(A,B,l//2))/2.0

  def findKth(self,A,B,k):
    if len(A)>len(B):
      A,B=B,A
    if not A:
      return B[k]
    if k==len(A)+len(B)-1:
      return max(A[-1],B[-1])
    i=len(A)//2
    j=k-i
    if A[i]>B[j]:
      return self.findKth(A[:i],B[j:],i)
    else:
      return self.findKth(A[i:],B[:j],j)

solution = Solution()
arr1 = [1,3,5,7,9]
arr2 = [2,4,6,8]
print(solution.findMedianSortedArrays(arr1,arr2))

# Find median from two sorted arrays with different lengths
# Big O notation O(log(min(m,n))
class Solution:
  def findMedianSortedArrays(self, A, B):
    l = len(A) + len(B)
    return self.findKth(A,B,l//2) if l % 2 == 1 else \
      (self.findKth(A,B,l//2-1) + self.findKth(A,B,//2))/2.0
  
  def findKth(self,A,B,k):
    if len(A) > len(B):
      A,B = B,A
    if not A:
      return B[k]
    if len(A)+len(B)-1 == k:
      return max(A[-1],B[-1])
    i=len(A)//2
    j=k-i
    if A[i]>B[j]:
      return self.findKth(A[:i],B[j:],i)
    else:
      return self.findKth(A[i:],B[:j],j)
