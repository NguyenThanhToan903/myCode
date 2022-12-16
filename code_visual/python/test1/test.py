from math import sqrt

def nhapdiem():
 ma = []
 for i in range(3):
    ma.append([])
    x = int(input('Nhập x: '))
    y = int(input('Nhập y: '))
    ma[i].append(x) 
    ma[i].append(y) 
 return ma
def kh_cach(a,b):
 return sqrt((a[0]-b[0])**2 + (a[1]-b[1])**2) 
def daicanh(x): 
 a = kh_cach(x[0],x[1]) 
 b = kh_cach(x[1],x[2])
 c = kh_cach(x[0],x[2]) 
 return a, b, c 
def chuvi(x):
 cv = 0 
 for i in daicanh(x):
    cv += i 
 return cv
def dientich(x):
 p = chuvi(x)/2 
 dc = daicanh(x) 
 s = sqrt(p*(p-dc[0])*(p-dc[1])*(p-dc[2])) 
 return s 
def tinhchat(x): 
 tc = ''
 d = daicanh(x) 
 if (d[0] == d[1]) and (d[1] == d[2]):
    tc = 'Tam giác đều'
 elif (d[0] == d[1]) or (d[1] == d[2]):
    tc = 'cân'
 elif (d[0]**2+ d[1]**2 == d[2]**2) or (d[0]**2+ d[2]**2 
== d[1]**2) or (d[1]**2+ d[2]**2 == d[0]**2): 
    tc = 'Tam giác vuông'
 else:
    tc = 'Tam giác thường'
 return tc
tg = nhapdiem()
print('Tọa độ 2 đỉnh của tam giác là: ', tg) 
print('Tính chất:', tinhchat(tg)) 
print('Chu vi tam giác = ', round(chuvi(tg),3)) 
print('Diện tích của tam giác =', round(dientich(tg),3))
input()