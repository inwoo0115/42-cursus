import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import csv

def read_mumax3_table(filename):

    from pandas import read_table
    
    table = read_table(filename)
    table.columns = ' '.join(table.columns).split()[1::2]
    
    return table

def read_mumax3_ovffiles(outputdir):
    
    from subprocess import run, PIPE, STDOUT
    from glob import glob
    from os import path
    from numpy import load

    fields = {}
    for npyfile in glob(outputdir+"/*.npy"):
        key = path.splitext(path.basename(npyfile))[0]
        fields[key] = load(npyfile)
    
    return fields

def run_mumax3(name, verbose=False):
    """ Executes a mumax3 script and convert ovf files to numpy files
    
    Parameters
    ----------
      script:  string containing the mumax3 input script
      name:    name of the simulation (this will be the name of the script and output dir)
      verbose: print stdout of mumax3 when it is finished
    """
    
    from subprocess import run, PIPE, STDOUT
    from os import path

    outputdir  = name + ".out"

    # call mumax3 to execute this script
        
    if path.exists(outputdir + "/table.txt"):
        table = read_mumax3_table(outputdir + "/table.txt")
    else:
        table = None
        
    fields = read_mumax3_ovffiles(outputdir)
    
    return table, fields

def save_table_to_csv(table, filename):
    with open(filename, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerows(table)
    print(f"The table has been saved to {filename}.")

table, fields = run_mumax3(name="standardproblem4", verbose=False)

save_table_to_csv(table, 'table.csv')

plt.figure()

nanosecond = 1e-9
plt.plot( table["t"]/nanosecond, table["mx"])
plt.plot( table["t"]/nanosecond, table["my"])
plt.plot( table["t"]/nanosecond, table["mz"])

plt.xlabel("Time (ns)")
plt.ylabel("Magnetization")

plt.show()

print(fields.keys())

m = fields["m000000"]

print("type  =", type(m))
print("shape =", m.shape)