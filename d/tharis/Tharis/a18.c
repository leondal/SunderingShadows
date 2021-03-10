//a18.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_short("%^ORANGE%^Dark alley through Tharis%^RESET%^");
   set_long(
@JAVAMAKER
     %^RED%^Dark alley through Tharis%^RESET%^
The high stone walls block most of the sun from the street
in these back alleyways. The ground here is still stone but
uncared for. The broken stone is cleaner here even though,
or perhaps because, it seems to be a dead end. 
The shadows seem to move, reminding you that you never 
know what is in these dark alleys.
JAVAMAKER
   );
   set_items(([
      ({"stone", "stones", "stone walls" }): "Most of the stones here have not been tended since the erection of the walls around them and are split and dirty, but the eastern wall seems different somehow.",
      "walls":"These walls are dark and dank.  The one to the east seems odd somehow.",
   ]));
   set_exits(([
      "east":ROOMS"temple1",
      "west":ROOMS"a17",
   ]));
    set_smell("default","You smell only slight traces of really anything.");
   set_listen("default","Dead silence.");

   set_invis_exits(({"east",}));
   set_trap_functions(({}),({}),({}));
//   set_pre_exit_functions(({"east",}),({"east_preExit",}));
   set_post_exit_functions(({}),({}));
}

//int FLAG = 1;

void reset(){
   ::reset();
// FLAG = 1;

}

void init(){
   ::init();
//   add_action("recite","recite");
}

/* commenting out to equalize from people using ooc info. and make it
accessible to all who search
int east_preExit(){
   if(FLAG){
      tell_object(TP,"You cannot go that way");	
      return 0;
    }
 return 1;
}

int recite(string str){
   if(!str || (str != "Niflheim open to me" && str != "niflheim open to me")){
      return 0;
   }
   TP->force_me("emote recites something under "+TP->query_possessive()+"  breath.");
   tell_object(TO,"%^BLUE%^You see a blue shimmering to the east.");
   FLAG = 0;
   return 1;
}

void resetFlag(){ FLAG = 1;}
*/