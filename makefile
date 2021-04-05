dynamichat: dynamichat.c common.h
	gcc dynamichat.c common.h -o dynamichat

keyboard: keyboard.c common.h
	gcc keyboard.c common.h -o keyboard

GET: GET.c
	gcc -o GET GET.c -I/usr/local/include/libmongoc-1.0 -I/usr/local/include/libbson-1.0/ -lmongoc-1.0 -lbson-1.0

POST: POST.c
	gcc -o POST POST.c -I/usr/local/include/libmongoc-1.0 -I/usr/local/include/libbson-1.0/ -lmongoc-1.0 -lbson-1.0
