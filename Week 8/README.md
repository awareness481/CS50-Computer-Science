_Text copied from http://docs.cs50.net/problems/sentiments/sentiments.html_

# Sentiments

## Setup
1. Make sure you're in the *sentiments* directory `$ cd sentiments`    
2. Set Flask app `$ export FLASK_APP=application.py`    *
3. Install the requirements `$ pip3 install --user -r requirements.txt`    
4. Signup/Signin on twitter, and create a new app on https://apps.twitter.com/        
5. Define the API key `$ export API_KEY=value`    
6. Define the API secret `$ export API_SECRET=value`    
7. To run the app, use `$ flask run`

*tl;dr*
Implement a program that categorizes a word as positive or negative.

`$ ./smile love`    
:)    
`$ ./smile hate`    
:(    
`$ ./smile Stanford`    
:|    
Implement a program that categorizes a user’s tweets as positive or negative.

`$ ./tweets @cs50`    
 0 hello, @world    
 1 I love you, @world    
-1 I hate you, @world    
...
*Implement a website that generates a pie chart categorizing a user’s tweets.*


![](http://i.imgur.com/7J4dRiK.png?raw=true)
