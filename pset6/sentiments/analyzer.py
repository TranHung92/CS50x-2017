import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        self.posWords = set()
        self.negWords = set()
        
        posFile = open(positives, "r")
        for posLine in posFile:
            if posLine.startswith(';') == False:
                self.posWords.add(posLine.rstrip("\n"))
        posFile.close()
        
        negFile = open(negatives, "r")
        for negLine in negFile:
            if negLine.startswith(';') == False:
                self.negWords.add(negLine.rstrip("\n"))
        negFile.close()

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        score = 0
        for token in tokens:
            if token.lower() in self.posWords:
                score += 1
            elif token.lower() in self.negWords:
                score -= 1
            else:
                score += 0
        return score
