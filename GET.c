#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
  FILE *f;

  mongoc_client_t *client;
  mongoc_collection_t *collection;
  mongoc_cursor_t *cursor;
  bson_error_t error;
  const bson_t *doc;
  bson_t *filter;
  bson_t *opts;
  bson_iter_t iter;
  bson_iter_t username;
  bson_iter_t datetime;
  bson_iter_t message;

  mongoc_init ();
  client = mongoc_client_new ("mongodb+srv://toluooshy:DynamiChat123@dynamichat.h3mb4.mongodb.net/myFirstDatabase?retryWrites=true&w=majority");
  collection = mongoc_client_get_collection (client, "chats", argv[1]);
  filter = BCON_NEW ("message", BCON_REGEX("","s"));
  opts = BCON_NEW ("limit", BCON_INT64 (1000));
  cursor = mongoc_collection_find_with_opts (collection, filter, opts, NULL);

  f = fopen(argv[1], "w+");

  while (mongoc_cursor_next (cursor, &doc)) {
    if (bson_iter_init (&iter, doc) && bson_iter_find_descendant (&iter, "username", &username) && BSON_ITER_HOLDS_UTF8 (&username)) {
      fprintf(f, "%s", bson_iter_utf8 (&username, NULL));
      fprintf(f, "[");
    }

    if (bson_iter_init (&iter, doc) && bson_iter_find_descendant (&iter, "datetime", &datetime) && BSON_ITER_HOLDS_UTF8 (&datetime)) {
      fprintf(f, "%s", bson_iter_utf8 (&datetime, NULL));
      fprintf(f, "]:\n");
    }

    if (bson_iter_init (&iter, doc) && bson_iter_find_descendant (&iter, "message", &message) && BSON_ITER_HOLDS_UTF8 (&message)) {
      fprintf(f, "%s", bson_iter_utf8 (&message, NULL));
      fprintf(f, "\n");
      fprintf(f, "\n");
    }
  }
  fclose(f);

  if (mongoc_cursor_error (cursor, &error)) {
    fprintf (stderr, "An error occurred: %s\n", error.message);
  }

  mongoc_client_destroy (client);
  mongoc_collection_destroy (collection);
  mongoc_cursor_destroy (cursor);
  bson_destroy (filter);
  bson_destroy (opts);
  mongoc_cleanup ();
  return 0;
}
