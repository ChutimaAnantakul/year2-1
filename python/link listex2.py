def Option():
    print("Menu")
    print("[1]:Traverse")
    print("[2]:Insert")
    print("[3]:Search")
    print("[4]:Delete")
    print("[5]:Stop")
    ch=int(input("Please select menu==> "))
    return ch
def Traverse(score):
    num=0
    for num in range(len(score)):
        if len(score)==0:
            print("------------!!No Data!!--------------")
            break 
        print("Student number:",num+1,",Score:",score[num])
        
def Insert():
    i=0
    data=[]
    st=int(input("How many student?==>"))
    n=1
    for n in range(st):
        s=int(input("Enter student score==> "))
        while s>100 or s<0:
            s=int(input("Error!!...Enter student score again==> "))   
        data.append(s)
    a = len(data)
    j=0
    for i in range(a):
        for j in range(1,a):
            if data[j-1] < data[j]:
                (data[j-1], data[j]) = (data[j], data[j-1])   
    print("----------!!Save complete!!----------")
    return data

def Search(score):
    num=0
    for num in range(len(score)):
        if len(score)==0:
            print("------------!!No Data!!--------------")
            break
    searchsc=int(input("Enter to search==> "))
    if searchsc in score:
        print("-----------!!Found Data!!------------")
    else :
        print("------------!!Not Found!!------------")
def Delete(score):
    Traverse(score)
    Del=int(input("What score do you want to delete?==> "))
    if Del in score:
       d=Del
       score.remove(d)
       print("----------!!Delete Complete!!------------")
    else:
       print("------------!!Not Found!!------------")
    return score

opt=Option()
score=[]
while opt!=5:
    if opt==1:
        if len(score)==0:
            print("------------!!No Data!!--------------")
        Traverse(score)
        opt=Option()
    elif opt==2:
        score=Insert()
        opt=Option()
    elif opt==3:
        Search(score)
        opt=Option()
    elif opt==4:
        score=Delete(score)
        opt=Option()
    else:
        print("!!Invalid Menu!!")
        opt=Option()
print("---------!!Finish Program!!----------")
