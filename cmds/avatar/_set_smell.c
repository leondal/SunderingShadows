#include <std.h>

inherit DAEMON;
int remove(string str, object who);
int help();


int cmd_set_smell(string str){
  object room;
  if (!avatarp(TP)){
    return 0;
  }
  room = environment(TP);
  if (!objectp(room)){
    notify_fail("There's some problem with the room you are in.");
    return 0;
  }
  if (!str){
    tell_object(TP, "Try 'set_smell <smell>'");
    return 1;
  }
  room->set_smell("default", str);
  tell_object(TP, "You change the smell in the room to: " + str);
  return 1;
}

int help(){
   write(
@OLI
   set_smell
   
   Usage: set_smell <smell>
  
   Changes the 'smell' in the room you are in to whatever you want.
   Only lasts till the next reboot.

OLI
      );
   return 1;
}
