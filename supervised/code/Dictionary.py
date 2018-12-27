from recordtype import recordtype
dic=recordtype('dic',['word','times'])
all=[]
lenth=[]
x=1
while(x<1001):
    f=open("training/training/%d.txt" %x,'r')
    line=f.readlines()
    for sub_string in line:
        sub_string=sub_string.rstrip('\n')
        sub_string=sub_string.rstrip(' ')
        voc=sub_string.split(' ')
        lenth.append(len(voc))
        for sub_voc in voc:
            flag=True
            for i in all:
                if i.word==sub_voc:
                    i.times+=1
                    flag=False
                    break
            if flag:
                t=dic(sub_voc,1)
                all.append(t)
    f.close()
    x+=1
l=len(all)
i=0
while(i<l):
    c=0
    while(c<i):
        if c==(i-1):
            break
        if(all[c].times<all[i].times):
            temp=all[c]
            all[c]=all[i]
            all[i]=temp
        c+=1
    i+=1

f=open("data/Dictionary.txt",'w')
for i in all:
    f.write(i.word+' '+str(i.times)+'\n')
f.close()
f=open("data/article_len.txt",'w')
for i in lenth:
    f.write(str(i)+'\n')
f.close()
