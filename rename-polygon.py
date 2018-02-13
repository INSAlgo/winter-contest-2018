import os
import sys
import re

# Execute me in every input/ and output/ folder:
#
# $ python rename-polygon.py .

p = re.compile('([a-z]+)-([0-9]+)\..*')

for filename in os.listdir(sys.argv[1]):
    m = p.match(filename)
    folder = 'input' if m.group(1) == 'input' else 'output'
    nb = int(m.group(2)) - 1
    os.rename(filename, '{}{}.txt'.format(folder, nb))

