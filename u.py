import random as  r

def ran():
    l=r.randint(3,2000)
    s=""
    for i in range(l):
        s+="ACGT"[r.randint(0,3)]
    return s
        
    
    


def search(x:str)->int:
    l=[]
    for i in range(len(x)-2):
        if(x[i]=="A"):
            if(x[i+1]=="C"):
                if(x[i+2]=="G"):
                    l.append(i)
    if l:
        return l
    return []


s=ran()
l=search(s)
p=0

class col:
    def __init__(self,text,c) -> None:
        self.text=text
        self.r=c[0]
        self.g=c[1]
        self.b=c[2]
    def __str__(self) -> str:
        return f"\033[38;2;{self.r};{self.g};{self.b}m{self.text}\033[0m"
    def __add__(s,o):
        if isinstance(o,(col,str)):
            return str(s)+str(o)
        
        
def serac(text:str,x:str):
    l=[]
    for i in range(len(text)-len(x)+1):
        k=0
        f=True
        while k<len(x):
            if(text[i]!=x[k]):
                f=False
                k=len(x)
            else:
                k+=1
        if f:
            l.append(i)
    return l
            
while p<len(s):
    if l:
        if l[0]==p:
            print(col("ACG",(0,255,0)),end="")
            p+=3
            l.pop(0)
        else:
            print(s[p],end="")
            p+=1
            
    else:
        print(s[p],end="")
        p+=1
    
    
print(serac(s,"ACG"))