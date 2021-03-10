#include <std.h>

inherit DAEMON;
int remove(string str, object who);
int help();


int cmd_stop(string str){
  object book;
  string message;
  message = TP->query_paralyzed_message("info");
  if (message == "You are busy memorizing"){
    if (objectp(book)){
      if ( (int)book->remove_call_out("flip")!=-1){
        TP->remove_paralyzed();
        book = present("book", TP);
      }
    }
  }
  return 1;
}


int help(){
   write(
@LUJKE
LUJKE
      );
   return 1;
}
