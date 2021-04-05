#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
  mongoc_client_t *client;
  mongoc_collection_t *collection;
  bson_error_t error;
  bson_oid_t oid;
  bson_t *doc;
  
  mongoc_init ();

  client = mongoc_client_new ("mongodb+srv://toluooshy:DynamiChat123@dynamichat.h3mb4.mongodb.net/myFirstDatabase?retryWrites=true&w=majority");
  collection = mongoc_client_get_collection (client, "chats", argv[1]);

  doc = bson_new ();
  bson_oid_init (&oid, NULL);
  BSON_APPEND_OID (doc, "_id", &oid);
  BSON_APPEND_UTF8 (doc, "username", argv[2]);
  BSON_APPEND_UTF8 (doc, "datetime", argv[3]);
  BSON_APPEND_UTF8 (doc, "message", argv[4]);

  if (!mongoc_collection_insert_one (collection, doc, NULL, NULL, &error)) {
    fprintf(stderr, "%s\n", error.message);
  }

  bson_destroy (doc);
  mongoc_collection_destroy (collection);
  mongoc_client_destroy (client);
  mongoc_cleanup ();

  return 0;
}
