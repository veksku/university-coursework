import numpy as np
from numpy import linalg
import math
np.set_printoptions(precision=5, suppress=True) 

def kameraA(T):

    t0 = np.delete(T,3,1)
    t0_inv = np.linalg.inv(t0)
    Q, R = np.linalg.qr(t0_inv)
    if(R[0][0]<0):
        R = np.matmul(np.diag([-1,1,1]), R)
        Q = np.matmul(Q, np.diag([-1,1,1]))
    if(R[1][1]<0):
        R = np.matmul(np.diag([1,-1,1]), R)
        Q = np.matmul(Q, np.diag([1,-1,1]))
    if(R[2][2]<0):
        R = np.matmul(np.diag([1,1,-1]), R)
        Q = np.matmul(Q, np.diag([1,1,-1]))
    A = Q
    A = np.where(np.isclose(A, 0) , 0.0 , A)
    if np.linalg.det(A) >= 0:
        return A
    else:
        return -A