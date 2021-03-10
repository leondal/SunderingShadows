//random scroll generator for avatars Circe 6/11/04
#include <std.h>
#include <daemons.h>
#include <move.h>

inherit DAEMON;
int help(){
    write(
@CIRCE
Usage:  randscroll <type> <level>

This will make a random scroll of a certain level.
Valid types are safe and normal.  Level can be any 
number 1-9.

If you want a specific spell, use <makescroll> instead.

CIRCE
    );
    return 1;
} 

int cmd_randscroll(string str){
  object ob;
  string type,level;
  if (!str) {
   help();
   return 1;
  }
  if(sscanf(str,"%s %d",type, level) == 2){
    if(type == "safe") { 
      ob = new("/d/magic/safe_scroll");
    }
    if(type == "normal") {
      ob = new("/d/magic/scroll");
    }
    if(!objectp(ob)) {
      tell_object(TP,"%^RED%^ERROR%^RESET%^:  Valid types are "+
      "%^CYAN%^<safe>%^RESET%^ or %^RED%^<normal>%^RESET%^");
      return 1;
    }
    if(level > 9 || level < 1) {
      tell_object(TP,"%^RED%^ERROR%^RESET%^: Level must "+
         "be a number from 1 to 9.");
      ob->remove();
      return 1;
    }
    ob->set_av_spell(level);
    tell_object(TP,"You have created a "+type+ 
        " scroll of a spell of level "+level+".");
    if(ob->move(TP) != MOVE_OK) {
      tell_object(TP,"%^RED%^ERROR%^RESET%^:  Moving "+type+
      " scroll to room instead.");
      ob->move(ETP);
      return 1;
    }
  return 1;
  }
  help();
  return 1;
}


