
def key_word (a):
    x=0
    word=[]
    f=open("data/Dictionary.txt",'r') #取得前22名關鍵字
    while x<a:     
        temp=str(f.readline())
        temp=temp.rstrip('\n')
        temps=temp.split(' ')
        word.append(temps[0])
        x+=1
    f.close()
    return word
def art_len():
    x=0
    lenth=[]
    f=open("data/article_len.txt",'r') #取得文章長度
    while x<1000:
        temp=str(f.readline())
        temp=temp.strip('\n')
        lenth.append(int(temp))
        x+=1
    f.close()
    return lenth
