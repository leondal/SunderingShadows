#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("ooc room",1);
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
   set_name("Tutorial room 4: basic combat");
   set_short("%^WHITE%^%^BOLD%^Tutorial room 4: basic combat%^RESET%^");
   set_smell("default","The air is utterly tasteless and clear of any scent.");
   set_listen("default","It is perfectly silent here.");
   set_long("%^WHITE%^%^BOLD%^Tutorial room 4: basic combat%^RESET%^\n"
"%^CYAN%^You have progressed to the next room of the tutorial.  It looks exactly the same as the last one you "
"were in - a plain, white-walled room.  There is not much here to look at, only a towering firbolg standing "
"in the middle of the room, watching you.  If you are stuck, you should %^YELLOW%^<ask>%^RESET%^%^CYAN%^ him "
"what you have to do."
"\n\n%^CYAN%^If you are an experienced player here, you can use the %^YELLOW%^<skip>%^RESET%^%^CYAN%^ option "
"at any time to bypass the tutorial.%^RESET%^\n");
   set_items(([
   ]));
   set_exits(([
     "north":ROOMS"room5",
//     "out" : "/d/newbie/ooc/rules_room",
     "skip" : "/d/newbie/ooc/rules_room",
   ]));
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
//   set_pre_exit_functions(({"out"}),({"GoThroughDoor"}));
}

void init() {
   ::init();
   if (!present("tutorial4")) new(MON"tutorial4")->move(TO);
   add_action("quit_func","quit");
}

int quit_func(string str) {
   TP->move("/d/newbie/ooc/hub_room2");
   tell_object(TP,"%^BOLD%^%^WHITE%^You have been moved to the OOC hub, as you can't quit inside the tutorial"
".  If you wish to return to the tutorial later, please take the %^YELLOW%^<tutorial>%^WHITE%^ exit from this "
"room.  You can resume wherever you left off.%^RESET%^");
   TP->force_me("quit");
}

int GoThroughDoor()
{
   object myroom;
   if((int)TP->query("offtutorial") > 3 || !newbiep(TP)) {
     tell_object(TP,"%^BOLD%^%^WHITE%^You decide that you already know what you're doing, so you leave."
"%^RESET%^");
     if((int)TP->query("newbtutorial4")) TP->delete("newbtutorial4");
     myroom = new(ROOMS"room5");
     TP->move(myroom);
     return 1;
   }
   if((int)TP->query("newbtutorial4") == 8) {
     TP->delete("newbtutorial4");
     TP->set("offtutorial",4);
     TP->add_exp(500);  // adds a little exp, first time through
     tell_object(TP,"%^BOLD%^%^WHITE%^You feel your practice here has taught you well. Check your %^YELLOW%^<score>%^RESET%^");
     myroom = new(ROOMS"room5");
     TP->move(myroom);
     return 1;
   }
   tell_object(TP,"You need to complete the tutorial in this room before you can move on to the next, or "
"%^YELLOW%^<skip>%^RESET%^ it.  If you have forgotten what you have to do next, just %^YELLOW%^<ask>"
"%^RESET%^.");
   return 0;
}