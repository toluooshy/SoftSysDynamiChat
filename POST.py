from pymongo import MongoClient
from datetime import datetime
import random
import sys

client = MongoClient("mongodb+srv://toluooshy:DynamiChat123@dynamichat.h3mb4.mongodb.net/myFirstDatabase?retryWrites=true&w=majority")

db = client.get_database('chats')
room = db[str(sys.argv[1])]

newEntry = {
    'username': str(sys.argv[2]),
    'datetime': str(sys.argv[3]),
    'message': str(sys.argv[4]),
}
room.insert_one(newEntry)
