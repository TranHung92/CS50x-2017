from flask import Flask, redirect, render_template, request, url_for

import helpers
import os
import sys
from analyzer import Analyzer

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "").lstrip("@")
    if not screen_name:
        return redirect(url_for("index"))

    # get screen_name's tweets
    tweets = helpers.get_user_timeline(screen_name)
    
    # absolute paths to lists
    positives = os.path.join(sys.path[0], "positive-words.txt")
    negatives = os.path.join(sys.path[0], "negative-words.txt")

    # instantiate analyzer
    analyzer = Analyzer(positives, negatives)

    # analyze tweets
    count_pos = 0
    count_neg = 0
    count_neu = 0
    if tweets == None:
        exit(1)
    else:
        for tweet in tweets:
            score = analyzer.analyze(tweet)
            if score > 0:
                count_pos += 1
            elif score < 0:
                count_neg += 1
            else:
                count_neu += 1
    total = count_pos + count_neg + count_neu      
    positive, negative, neutral = count_pos/total*100, count_neg/total*100, count_neu/total*100

    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
