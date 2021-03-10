// first room of the tutorial now, others are in /d/newbie/tutorial/rooms
// these tutorial rooms thanks to Nienne 3/2005

#include <std.h>
#include <objects.h>
#include "/d/newbie/tutorial/defs.h"
#define NEWB_D "/d/newbie/ooc/newbie_d.c"

inherit ROOM;

string myLong()
{
    string tmp;
    tmp = "%^WHITE%^%^BOLD%^Tutorial room 1: basic commands%^RESET%^\n"+
    "%^RESET%^%^CYAN%^This white-walled room is where you begin to learn basic commands.  There is not much here "+
    "to look at, only a man standing in the middle of the room, watching you.  If you are stuck, you should "+
    "%^YELLOW%^<ask>%^RESET%^%^CYAN%^ him what you have to do."+
    "\n\n%^CYAN%^If you are an experienced player here, you can use the %^YELLOW%^<skip>%^RESET%^%^CYAN%^ option "+
    "at any time to bypass the tutorial.%^RESET%^\n";
    if(objectp(TP))
    {
        if((int)OB_ACCOUNT->is_non_newbie((string)TP->query_true_name()))
        {
            tmp += "\n%^CYAN%^Since you have a non newbie character on your account you can also "+
            "completely %^YELLOW%^<bypass>%^RESET%^%^CYAN%^ the newbie area. This will result in you "+
            "ending in a total character "+
            "level of six with basic equipment, and in Tabor or Muuldaan, after being moved to "+
            "a special trainer where you can set up your adjective, description, and anything else "+
            "that you wish to do.%^RESET%^\n";
        }
    }
    return tmp;
}


void create()
{
   ::create();
   set_property("ooc room",1);
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
   set_name("Tutorial room 1: basic commands");
   set_short("%^WHITE%^%^BOLD%^Tutorial room 1: basic commands%^RESET%^");
   set_smell("default","The air is utterly tasteless and clear of any scent.");
   set_listen("default","It is perfectly silent here.");
   set_long((:TO, "myLong":));
   set_items(([
   ]));
   set_exits(([
     "east":ROOMS"room2",
     "skip" : "/d/newbie/ooc/rules_room",
   ]));
   set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
}

void init()
{
    ::init();
    if (!present("tutorial1")) new(MON"tutorial1")->move(TO);
    add_action("quit_func","quit");
    add_action("bypass_func", "bypass");
}

int bypass_func(string str)
{
    object myRoom, ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    tell_object(TP, "non newbie = " +(int)OB_ACCOUNT->is_non_newbie("lorath"));
    if(!(int)OB_ACCOUNT->is_non_newbie((string)TP->query_true_name())) return 0;
    NEWB_D->spawn_eq(TP, 1);
    NEWB_D->advance_level(TP);
    NEWB_D->spawn_eq(TP, 2);
    NEWB_D->advance_level(TP);
    NEWB_D->spawn_eq(TP, 3);
    NEWB_D->advance_level(TP);
    NEWB_D->spawn_eq(TP, 4);
    NEWB_D->advance_level(TP);
    NEWB_D->spawn_eq(TP, 5);
    NEWB_D->advance_level(TP);
    NEWB_D->advance_level(TP);
    NEWB_D->advance_level(TP);
    if(objectp(ob = present("newbiemassobject", TP))) ob->remove();
    tell_object(TP, "\n%^BOLD%^%^WHITE%^You feel the world around you "+
    "shifting and changing as you suddenly find yourself somewhere "+
    "else!%^RESET%^");
    tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ suddenly shifts and wavers "+
    "before blinking out of existence!", TP);
    myRoom = new("/d/newbie/ooc/trainer");
    myRoom->set_for(TP);
    TP->move_player(myRoom);
    return 1;
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
   if((int)TP->query("offtutorial") || !newbiep(TP)) {
     tell_object(TP,"%^BOLD%^%^WHITE%^You decide that you already know what you're doing, so you move on."
"%^RESET%^");
     if((int)TP->query("newbtutorial")) TP->delete("newbtutorial");
     myroom = new(ROOMS"room2");
     TP->move(myroom);
     return 1;
   }
   if((int)TP->query("newbtutorial") == 8) {
     TP->delete("newbtutorial");
     TP->set("offtutorial",1);
     TP->add_exp(500);  // adds a little exp, first time through
     tell_object(TP,"%^BOLD%^%^WHITE%^You feel your practice here has taught you well.%^RESET%^");
     myroom = new(ROOMS"room2");
     TP->move(myroom);
     return 1;
   }
   tell_object(TP,"You need to complete the tutorial in this room before you can move on to the next, or "
"%^YELLOW%^<skip>%^RESET%^ it.  If you have forgotten what you have to do next, just %^YELLOW%^<ask>"
"%^RESET%^.");
   return 0;
}
