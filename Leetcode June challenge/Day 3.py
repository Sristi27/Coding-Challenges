Question:
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0],
and the cost of flying the i-th person to city B is costs[i][1].
Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.


//Python soln

class Solution:

    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        n=len(costs)
        #print(n)
        //sort on basis of their absolute differences
        costs.sort(key=lambda x:abs(x[0]-x[1]))
        #print(costs)
        c1,c2,s,l=0,0,0,n//2
        for i in range(n-1,-1,-1):
            if (costs[i][0]<=costs[i][1] and c1<l) or c2==l:
                s+=costs[i][0]
                c1+=1
            else:
                s+=costs[i][1]
                c2+=1
        return s
