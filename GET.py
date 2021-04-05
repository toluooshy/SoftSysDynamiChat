from pymongo import MongoClient
from datetime import datetime
import random
import sys

client = MongoClient("mongodb+srv://toluooshy:DynamiChat123@dynamichat.h3mb4.mongodb.net/myFirstDatabase?retryWrites=true&w=majority")

db = client.get_database('chats')
room = db[str(sys.argv[1])]
f = open(str(sys.argv[1]), 'w+')

for i in range(len(list(room.find()))):
    username = str(list(room.find())[i]['username'])
    datetime = str(list(room.find())[i]['datetime'])
    message = str(list(room.find())[i]['message'])
    f.write(username + '[' + datetime + ']:\n' + message + '\n\n')

f.close()
