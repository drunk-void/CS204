from string import whitespace as ws
from string import punctuation as pc

def read_and_parse(filename) :
    words=list()
    i=0
    wo=""
    with open(filename, 'r') as f :
        for line in f :
            l=list(line)
            for elem in l :
                if (elem in pc) :
                    l.remove(elem)
                elif (elem in ws) :
                    words.append(wo)
                    wo=""
                else : wo+=elem
    print(words)
    print(pc)
    
read_and_parse('text.txt')
