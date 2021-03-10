//wolfpen.c
//added a loot here -hades 4/8/13
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CVAULT;
void make_wolves();
int items = 0;
void create(){
   make_wolves();
::create();
   set_property("light",2);
   set_travel(GAME_TRACK);
   set_terrain(ROCKY);
   set_name("%^RESET%^%^ORANGE%^The inside of a dusty pen%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^A dirty pen%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","It stinks in here.");
   set_listen("default","%^RESET%^Chains clank against the fencing "+
   "as the wind rushes past them.");
   set_items(([
   ({"remains","animal remains"}):"%^BOLD%^%^BLACK%^Dark, stinking piles of "+
   "animal dung lay everywhere.%^RESET%^",
   ({"fur","tufts of fur"}):"%^BOLD%^%^BLACK%^Dark tufts of animal "+
   "fur hang from some of the fencing and chains.  Some of the tufts"+
   " still have skin attached, as though the animal fought to free "+
   "itself of its bindings.%^RESET%^",
   "chains":"%^RESET%^The chains look as though they are well used."+
   "  They are %^ORANGE%^rusted %^RESET%^and broken in some places, "+
   "while in others still look to be quite sturdy. Tufts of "+
   "%^BOLD%^%^BLACK%^dark fur %^RESET%^still hang from various pieces of the chains.",
   "gate":"A large, heavy gate lies to the east and looks like it "+
   "would be difficult to open, but not impossible.",
   ({"meat","pieces of meat"}):"%^RESET%^%^RED%^Some pieces of meat "+
   "hang from a large center pole and looks like it has been there "+
   "for some time.  Other pieces have been taken from the pole and "+
   "scattered around the pen, mostly half-eaten.%^RESET%^",
   ({"pole","poles"}):"There are several wooden poles around the pen,"+
   " some of them still have chains attached to them.  The largest "+
   "pole in the center looks like it is what is used to feed the "+
   "animals with, as it still has many pieces of meat hanging from it.",
   "barrel":"%^RESET%^%^ORANGE%^This is a small barrel filled with"+
   " %^BOLD%^%^BLACK%^dark, murky water, %^RESET%^%^ORANGE%^most "+
   "likely the water the animals have to drink.",
   "water":"Yeah, the water is disgusting looking.  There may even "+
   "be a few bugs swimming in it, but you can't quite tell, it's that dark.",
   ({"fence","fencing"}):"The fencing is composed of large stones, "+
   "wood and whatever other odd objects could be stuffed into the cracks.",
   ]));
   set_search("default", "%^ORANGE%^Nothing here really looks interesting."+
   "  Except maybe that extra big pile of dung?%^RESET%^");
   set_search("dung", (: TO, "searching" :) );;
   set_exits((["east":INRMS+"kgroom"]));
   set_door("gate",INRMS+"kgroom","east",0);
}
string ldesc(string str){
   return("%^RESET%^%^ORANGE%^This is the inside of a very dusty pen.  Animal"
" remains lay all over the ground and tufts of %^BOLD%^%^BLACK%^dark fur"
" %^RESET%^%^ORANGE%^hang off of the fencing that surrounds the area.  A few"
" %^RESET%^chains %^ORANGE%^lay on on the ground and hang from poles, most likely"
" to keep the more troublesome animals in place.  A large, heavy gate lies"
" to the"
" eastern side of the pen.  A few pieces of %^RED%^meat %^ORANGE%^hang from a"
" larger pole in the center of the pen, while other half-eaten pieces look"
" like"
" they've been dragged around and are scattered everywhere.  A barrel of"
" %^BOLD%^%^BLACK%^murky %^BLUE%^water %^RESET%^%^ORANGE%^sets next to the center"
" pole.%^RESET%^\n");
}
void reset() {
  ::reset();
  set_open("gate",0);
  make_wolves();
  items = 1;
}
void searching() {
   object ob;

   if(present("wolf")) {
      write("The wolves are too close to the pile of dung for"+
	  " you to search thoroughly.");
      return;
   }
   if(!items) {
      write("Looks like someone beat you to whatever was there.");
      return;
   }
      write("You find a pillar in the pile of wolf poop!");
      tell_room(TO,""+TPQCN+" finds a pillar in the pile of wolf poop.",TP);
      ob = new(OBJD+"pillar");
      ob->move(TO);
    
        items = 0;
        return;
          
}
void make_wolves()
{
   int monsters;
   monsters = has_mobs();
   if(!monsters) {
      if(mons) { mons = ([]); }
      set_monsters( ({TMONDIR+"dwolf.c"}),({random(10)+12}) );
   }
}
