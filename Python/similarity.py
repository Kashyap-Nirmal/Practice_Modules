import nltk
from nltk.corpus import wordnet
# Let's compare the noun of "fee" and "cost"

w1 = wordnet.synset('fee.n.01') # n here denotes the tag noun
w2 = wordnet.synset('cost.n.01')
print(w1.wup_similarity(w2))