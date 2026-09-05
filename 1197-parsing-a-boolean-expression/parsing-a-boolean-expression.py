class Solution(object):
    def parseBoolExpr(self, expression):
        """
        :type expression: str
        :rtype: bool
        """
        def evaluate(op , arr):
            bool_vals = [True if x=='t' else False for x in arr]

            if(op=='!'):
                res = not bool_vals[0]
            elif op=='&':
                res = all(bool_vals)
            elif op=='|':
                res = any(bool_vals)
            
            return 't' if res else 'f'

        stk = []

        for ch in expression :
            if ch==',' : 
                continue
            elif ch==')' : # )
                temp = []
                while(len(stk)!=0 and stk[-1] != '('):
                    temp.append(stk.pop())
                stk.pop() # remove top ')' 
                op = stk.pop() # our operation
                evaluation = evaluate(op,temp)
                stk.append(evaluation)
            else: # t f ! & | (
                stk.append(ch)
        return stk[-1]=='t'

                    

        