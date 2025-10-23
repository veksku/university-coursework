import numpy as np
from numpy import linalg
import math
np.set_printoptions(precision=5, suppress=True) 

def kameraK(T):

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
    K = np.linalg.inv(R)
    K = K * (1/K[-1][-1])
    K = np.where(np.isclose(K, 0) , 0.0 , K)
    return K