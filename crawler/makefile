CC=g++
LIB = ..
WEB = ..

all: WebCrawler

WebCrawler: WebCrawler.cpp $(LIB)/Set.h $(WEB)/WebPage.h
	$(CC) -g -Wall WebCrawler.cpp $(WEB)/WebPage.cpp -o WebCrawler -I$(LIB) -I$(WEB)

.PHONY: clean

clean:
	rm -f *.o *~ WebCrawler
