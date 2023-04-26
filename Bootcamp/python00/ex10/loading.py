#!/usr/bin/env python3
import time
import sys

def ft_progress(lst):
    bgn = time.time()
    big = max(lst)
    length = len(str(max(lst)))
    eta = 0
    barsize = 40
    for i in lst:
        if big is not 0:
            perc = i/big*100
            bar = int(i/big*barsize)
            t = time.time() - bgn
            if perc != 0:
                eta = t/perc*100
            sys.stdout.write('\r')
            sys.stdout.write("ETA: %.2fs [%3d%%] [%-*.*s] %*d/%d | elapsed time %.2fs" % (eta, perc, barsize, barsize, '='*bar+'>', length, i, big, t))
            sys.stdout.flush()
            yield i
        

if __name__ == "__main__":
    listy = range(1001)
    ret = 0
    for elem in ft_progress(listy):
        ret += elem
        time.sleep(0.005)
    print()
    print(ret)