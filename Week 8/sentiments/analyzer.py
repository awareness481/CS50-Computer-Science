import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        pos = open(positives, "r")
        neg = open(negatives, "r")
        
        self.positives = set()
        for line in pos:
            if line.startswith(","):
                continue
            else:
                self.positives.add(str.strip(line))
        pos.close()
        
        self.negatives = set()
        for line in neg:
            if line.startswith(","):
                continue
            else:
                self.negatives.add(str.strip(line))
        neg.close()

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        self.tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = self.tokenizer.tokenize(text)
        
        total = 0
        
        for word in tokens:
            if word.lower() in self.positives:
                total = total + 1
            elif word.lower() in self.negatives:
                total = total - 1
            else:
                continue
        return total
