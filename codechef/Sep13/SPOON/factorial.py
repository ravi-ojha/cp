c = [1, 1, 2, 3, 6, 10, 20, 35, 70, 126, 252, 462, 924, 1716L, 3432L, 6435L, 12870L, 24310L, 48620L, 92378L, 184756L, 352716L, 705432L, 1352078L, 2704156L, 5200300L, 10400600L, 20058300L, 40116600L, 77558760L, 155117520L, 300540195L, 601080390L, 1166803110L, 2333606220L, 4537567650L, 9075135300L, 17672631900L, 35345263800L, 68923264410L, 137846528820L, 269128937220L, 538257874440L, 1052049481860L, 2104098963720L, 4116715363800L, 8233430727600L, 16123801841550L, 32247603683100L, 63205303218876L, 126410606437752L, 247959266474052L, 495918532948104L, 973469712824056L, 1946939425648112L, 3824345300380220L, 7648690600760440L, 15033633249770520L, 30067266499541040L, 59132290782430712L, 118264581564861424L, 232714176627630544L, 465428353255261088L, 916312070471295267L, 1832624140942590534L]

##def factorial():
##    res = 1
##    for i in xrange(1,65):
##        res = res*i
##        a.append(res)
##        print res*i
###factorial()
##
##def nCr():
##    for i in xrange(2,65):
##        if i%2 == 0:
##            res = a[i]/a[i/2]
##            res = res/a[i/2]
##            c.append(res)
##        else:
##            res = a[i]/a[i/2]
##            res = res/a[i-i/2]
##            c.append(res)

def spoon():
##    factorial()
##    nCr()
##    for t in xrange(input()):
##        n = input()
##    factorial()
##    nCr()
    #print c
    #print c[64]
    for t in xrange(input()):
        n = input()
        for i in xrange(2,65):
            if n > c[i-1] and n <= c[i]:
                print i
                break
spoon()
