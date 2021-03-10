//Added Lance to search crate part - Cythera - 3/05
//Changed to where it works with spear - Cythera 8/05
//Added new weapontypes from creation and adjusted the merged ones. Nienne 3/07
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
   set_name("Tutorial room 2: interact with the world");
   set_short("%^WHITE%^%^BOLD%^Tutorial room 2: interact with the world%^RESET%^");
   set_smell("default","The air is utterly tasteless and clear of any scent.");
   set_listen("default","It is perfectly silent here.");
   set_long("%^WHITE%^%^BOLD%^Tutorial room 2: interact with the world%^RESET%^\n"
"%^CYAN%^You have progressed to the next room of the tutorial.  It looks exactly the same as the last one you "
"were in - a plain, white-walled room.  There is not much here to look at, only a single crate sitting at the "
"side of the room.  A short halfling is standing in the middle of the room, watching you.  If you are stuck, "
"you should %^YELLOW%^<ask>%^RESET%^%^CYAN%^ her what you have to do."
"\n\n%^CYAN%^If you are an experienced player here, you can use the %^YELLOW%^<skip>%^RESET%^%^CYAN%^ option "
"at any time to bypass the tutorial.%^RESET%^\n");
   set_items(([
   ]));
   set_exits(([
     "south":ROOMS"room3",
     "skip" : "/d/newbie/ooc/rules_room",
   ]));
   add_item("crate","There is a lonely crate sitting at the side of the room.");
   set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
   set_search("default",(:TO,"search_room":));
   set_search("crate",(:TO,"search_room":));
}

void init() {
   ::init();
   if (!present("tutorial2")) new(MON"tutorial2")->move(TO);
   add_action("quit_func","quit");
}

int quit_func(string str) {
   TP->move("/d/newbie/ooc/hub_room2");
   tell_object(TP,"%^BOLD%^%^WHITE%^You have been moved to the OOC hub, as you can't quit inside the tutorial"
".  If you wish to return to the tutorial later, please take the %^YELLOW%^<tutorial>%^WHITE%^ exit from this "
"room.  You can resume wherever you left off.%^RESET%^");
   TP->force_me("quit");
}

int GoThroughDoor(){
   object myroom;
   if((int)TP->query("offtutorial") > 1 || !newbiep(TP)) {
     tell_object(TP,"%^BOLD%^%^WHITE%^You decide that you already know what you're doing, so you move on."
"%^RESET%^");
     if((int)TP->query("newbtutorial2")) TP->delete("newbtutorial2");
     myroom = new(ROOMS"room3");
     TP->move(myroom);
     return 1;
   }
   if((int)TP->query("newbtutorial2") == 6) {
     TP->delete("newbtutorial2");
     TP->set("offtutorial",2);
     TP->add_exp(500);  // adds a little exp, first time through
     tell_object(TP,"%^BOLD%^%^WHITE%^You feel your practice here has taught you well.%^RESET%^");
     myroom = new(ROOMS"room3");
     TP->move(myroom);
     return 1;
   }
   tell_object(TP,"You need to complete the tutorial in this room before you can move on to the next, or "
"%^YELLOW%^<skip>%^RESET%^ it.  If you have forgotten what you have to do next, just %^YELLOW%^<ask>"
"%^RESET%^.");
   return 0;
}

int search_room(string str) {
    object ob;
    if (!str) {
      if((int)TP->query_property("newbtutorial2") != 4) tell_object(TP,"Where do you want to search?");
      else tell_object(TP,"Where do you want to search?  That %^YELLOW%^crate%^RESET%^ looks a bit out of "
"place.");
      return 1;
    }
    if (str != "crate") {
      tell_object(TP,"You don't find anything when you search the "+str+".");
      return 1;
    }
    if(!newbiep(TP) || (int)TP->query("offtutorial") > 1) {
      tell_object(TP,"You should have already found your free weapon.  If you're redoing the tutorial to "
"refresh your memory, though, you can just pretend that you have one with you and try the commands anyway!\n");
      return 1;
    }
    tell_object(TP,"You don't find anything when you search the crate.");
    return 1;
}
