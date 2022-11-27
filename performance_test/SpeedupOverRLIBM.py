
import math
overallLabel = ["log", "log2", "log10", "exp", "exp2", "exp10"]

rlibm=[]
rlibm_knuth=[]
rlibm_estrin=[]
rlibm_estrin_fma = []

fileName = ["log.txt", "log2.txt", "log10.txt", "exp.txt", "exp2.txt", "exp10.txt"]

for i in range(0, len(fileName)):
    fp_rlibm = open("rlibm/" + overallLabel[i] + ".txt", "r");
    line = fp_rlibm.readline()
    line = line.split(",");
    rlibm.append(float(line[0]));
    fp_rlibm.close();
    
    if i == 0 or  i == 2:
        rlibm_knuth.append(float(0));
    else:
        fp_knuth = open("rlibm/" + overallLabel[i] + "_adapt.txt", "r");
        line = fp_knuth.readline()
        line = line.split(",");
        rlibm_knuth.append(float(line[0]));
        fp_knuth.close();
    
    fp_estrin = open("rlibm/" + overallLabel[i] + "_estrin.txt", "r");
    line = fp_estrin.readline()
    line = line.split(",");
    rlibm_estrin.append(float(line[0]));
    fp_estrin.close();

    fp_estrin_fma = open("rlibm/" + overallLabel[i] + "_estrin_fma.txt", "r");
    line = fp_estrin_fma.readline()
    line = line.split(",");
    rlibm_estrin_fma.append(float(line[0]));
    fp_estrin_fma.close();

    
#print rlibm
#print rlibm_knuth
#print rlibm_estrin
#print rlibm_estrin_fma

print "Speedup of RLIBM-Knuth over RLIBM"
avg = 1.0
for i in range(0, len(fileName)):
    if i != 0 and i != 2:
        avg = avg * (rlibm[i]/rlibm_knuth[i]);
        speedup = (rlibm[i]/rlibm_knuth[i] - 1)* 100
        print overallLabel[i] + ": %0.2f" % speedup + "%"
    else:
        print overallLabel[i] + ": 0.00%"

Average_speedup = (math.pow(avg, 0.1667) - 1) * 100;
print "Average speedup of RLIBM-Knuth over RLIBM: %0.2f" % Average_speedup + "%"


print "Speedup of RLIBM-Estrin over RLIBM"
avg = 1.0
for i in range(0, len(fileName)):
    avg = avg * (rlibm[i]/rlibm_estrin[i]);
    speedup = (rlibm[i]/rlibm_estrin[i] - 1)* 100
    print overallLabel[i] + ": %0.2f" % speedup + "%"
    
Average_speedup = (math.pow(avg, 0.1667) - 1) * 100;
print "Average speedup of RLIBM-Estrin over RLIBM: %0.2f" % Average_speedup + "%"


print "Speedup of RLIBM-Estrin-FMA over RLIBM"
avg = 1.0
for i in range(0, len(fileName)):
    avg = avg * (rlibm[i]/rlibm_estrin_fma[i]);
    speedup = (rlibm[i]/rlibm_estrin_fma[i] - 1)* 100
    print overallLabel[i] + ": %0.2f" % speedup + "%"
    
Average_speedup = (math.pow(avg, 0.1667) - 1) * 100;
print "Average speedup of RLIBM-Estrin-FMA over RLIBM: %0.2f" % Average_speedup + "%"
