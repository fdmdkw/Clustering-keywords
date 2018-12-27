from sklearn import svm  
from sklearn.externals import joblib
t_data=[]
x=1
while x<1001:
    data=[]
    f=open("training/t_data/%d.txt"%x,'r')
    line=str(f.readline())
    line=line.rstrip(' ')
    freqs=line.split(' ')
    for i in freqs:
        data.append(i)
    t_data.append(data)
    x+=1
    f.close()
t_class=[]
x=1
while x<1001:
    f=open("training/training文件種類/%da.txt"%x,'r')
    temp=f.read(1)
    t_class.append(temp)
    x+=1
    f.close()
clf=svm.SVC()
clf.fit(t_data,t_class)
joblib.dump(clf,"train_model.m")

"""X = [[0, 0], [1, 1],[1,0] ] # training samples   
y = [0, 1,1]  # training target  
clf = svm.SVC()  # class   
clf.fit(X, y)  # training the svc model  
  
result = clf.predict([[3,3 ]]) # predict the target of testing samples   
print (result)  # target   
  
print (clf.support_vectors_)  #support vectors  
  
print (clf.support_)  # indeices of support vectors  
  
print (clf.n_support_)  # number of support vectors for each class"""
