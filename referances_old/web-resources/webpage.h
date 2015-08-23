#ifndef WEBPAGE_H
#define WEBPAGE_H
#include <fstream>
#include "set.h"
#include <deque>

using namespace std;

class WebPage {
  public:
    WebPage ();    // constructor that creates an empty page
    WebPage (std::string filename);
          /* constructor that initializes the page from the given file.
         Should throw an exception if the file does not exist
         or has other problems. */


    ~WebPage ();   // destructor

    Set<string> allOutgoingLinks () const;
      /* Returns "pointers" to all webpages that this page has links to. 
         As discussed above, this could be as a set or via an iterator,
         and it could be as actual pointers, or as strings, 
         or possibly other. */   

    Set<string> allIncomingLinks () const;
      /* Returns "pointers" to all webpages that link to this page. 
         Same consideration as previous function. */   

    string filename () const;
      /* Returns the filename from which this page was read. */

    /* Based on which overall architecture you choose, you may 
       also need/want some or all of the following functions. */

    void addIncomingLink (string start);
      /* Adds a link from start to the current page 
         in the current page's storage. */

    void addOutgoingLink (string target); 
      /* Adds a link from the current page to the target
         in the current page's storage. */

    void updateOtherSites();
      /* Adds this site as an incoming link to outgoing links*/

    std::string getData() const;


    Set<std::string> allWords () const;
      /* Returns a set containing all individual words on the web page. */   

    friend std::ostream & operator<< (std::ostream & os, const WebPage & page);
      /* Declares an operator we can use to print the web page. */

  private:
    Set<string> incomingLinks;
    Set<string> outgoingLinks;
    string data;
    string name;
    bool fileGiven;

};

#endif