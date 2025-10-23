import numpy as np
from numpy import linalg
import math
np.set_printoptions(precision=5, suppress=True) 

def dveJednacine(img, orig):
    
    nula = np.zeros(4)
    prva = np.array(np.concatenate((nula, -img[2]*orig, img[1]*orig)))
    druga = np.array(np.concatenate((img[2]*orig, nula, -img[0]*orig)))
    return [prva, druga]

def napraviMatricu(imgs, origs):
    
    mat = []
    
    for img,orig in zip(imgs,origs):
        jed1, jed2 = dveJednacine(img, orig)
        mat.append(jed1.tolist())
        mat.append(jed2.tolist())
    return mat

def matricaKamere(pts2D, pts3D):

    a = napraviMatricu(pts2D, pts3D)
    a = np.array(a)
    _, _, Vh = np.linalg.svd(a)
    T = Vh[-1]
    T = T.reshape(3,4)
    T = (1/T[-1][-1]) * T
    T = np.where(np.isclose(T, 0) , 0.0 , T)
    return T