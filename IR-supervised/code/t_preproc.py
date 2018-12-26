import method
from sklearn import svm
from sklearn.externals.joblib import load
f_number=100   #檔案數量
#取得前22名關鍵字
word=method.key_word(22)
#將文章根據關鍵字頻率轉換成數值
x=1
article=[] #每篇包含22個關鍵字權重
while x<(f_number+1):  #計算權重
    weight=[] #各關鍵字權重
    f=open("training\\training\\%d.txt"%x,'r') #路徑和x值根據文件位址和檔名
    line=str(f.readline())
    #文章切割成單字(in voc)
    line=line.strip('\n')   
    line=line.strip(' ')
    voc=line.split(' ')
    #文章長度
    l=0
    for i in voc:
        l+=1
    #文章中關鍵字出現頻率
    for i in word:
        temp=0
        for c in voc:
            if i==c:
                temp+=1
        temp=(temp/l) *20  
        temp=float("%.2f"%temp)     
        weight.append(temp)
    article.append(weight)
    x+=1

#預測
clf=load("model\\train_model.m")
res=clf.predict(article)
#答案存成陣列
answer=[]
x=1
while x<(f_number+1):   
    f=open("training\\training文件種類\\%da.txt"%x,'r')
    temp=f.read(1)
    answer.append(temp)
    x+=1
    f.close()

#準確度計算
x=0
correct=0
while(x<f_number):
    if(res[x]==answer[x]):
        correct=correct+1
    x=x+1
print(str((correct/f_number)*100)+'%')
x=1
while x<(f_number+1):
    f=open("data\\output\\%da.txt"%x,'w')
    f.write(res[x-1])
    f.close()
    x=x+1
