from recordtype import recordtype
import method

word=method.key_word(22)
lenth=method.art_len()
article=[]
x=1
while x<1001:   #計算關鍵字在目標文章中的頻率
    f=open("training\\training\\%d.txt" %x,'r')
    line=str(f.readline())
    line=line.rstrip('\n')
    line=line.rstrip(' ')
    lines=line.split(' ')
    y=0
    weight=[]
    for i in word:
        temp=0
        for c in lines:
            if i==c:
                temp+=1
        temp=(temp/lenth[x-1]) *20      
        weight.append(temp)
    article.append(weight)
    x+=1
f.close()
x=1
while x<1001:   #將頻率輸出
    f=open("training\\t_data\\%d.txt"%x,'w')
    for c in article[x-1]:
            f.write('%.3f'%c+' ')
    f.close()
    x+=1


