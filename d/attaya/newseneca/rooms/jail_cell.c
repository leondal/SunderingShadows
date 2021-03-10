//jail_cell.c by ~Circe~ 11/22/07 for new Seneca

#include <std.h>
#include "../seneca.h"

#define JAILMAIN "/d/attaya/newseneca/rooms/jail_main"

inherit "/std/jail_cell.c";

void create(){
   ::create();
   set_jail(JAILMAIN);
   set_jail_location("Seneca");
   set_release_to("/d/attaya/beach20");
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(1);
   set_indoors(1);
   set_name("Seneca jail cell");
   set_short("%^BOLD%^%^BLACK%^A Jail Cell in Seneca%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A Jail Cell in Seneca%^RESET%^\n"+
      "%^BOLD%^%^BLACK%^You are in a dank, musty jail cell that "+
      "measures only about six feet by eight feet.  There are two "+
      "%^RESET%^%^ORANGE%^piles of straw %^BOLD%^%^BLACK%^that "+
      "are perhaps intended to be beds.  In the southwestern corner "+
      "is a %^RESET%^hole %^BOLD%^%^BLACK%^in the stone floor that "+
      "serves as a %^RESET%^%^ORANGE%^latrine%^BOLD%^%^BLACK%^.  "+
      "The cell would be utterly dark were it not for the small "+
      "%^RESET%^iron grate %^BOLD%^%^BLACK%^in the thick %^RESET%^"+
      "%^ORANGE%^door %^BOLD%^%^BLACK%^of the cell that lets in a "+
      "weak light from the room beyond.  The stone is cold and damp, "+
      "and little has been done to make anything here comfortable - "+
      "or clean.%^RESET%^\n");
   set_listen("default","You can hear occasional voices from the outer "+
      "room over the scurrying of rats.");
   set_smell("default","A nauseating smell rises from the filthy, damp "
      "floor.");
   set_items(([
      "grate" : "The grate is small and filled with iron bars.  There is "+
         "certainly no escape that way, but perhaps you can peer through "+
         "the grate to see who is in the outer room.",
      ({"piles","straw","piles of straw","beds","bed"}) : "%^ORANGE%^The "+
         "only beds are piles of straw that have started to %^GREEN%^mold"+
         "%^ORANGE%^.  There seems to be just enough to raise you a slight "+
         "bit above the dank floor.%^RESET%^",
      ({"hole","latrine"}) : "%^GREEN%^Taking a look in the latrine, "+
         "you soon wish you hadn't.  Ugh, that thing has not been cleaned
"+
         "out...ever.%^RESET%^"
   ]));
   set_exits(([
      "north": JAILMAIN,
      "grate" : JAILMAIN
   ]));
   set_invis_exits(({"grate"}));
   set_pre_exit_functions(({"grate"}),({"GoThroughDoor"}));
   set_door("cell door",JAILMAIN,"north","Seneca jail key");
   set_open("cell door",0);
   set_locked("cell door",1);
   lock_difficulty("cell door",-90);
   set_door_description("cell door", "This is a door made of three inch "
      "thick oaken boards.  It has a section cut out and replaced with a "
      "grate of inch diameter iron bars so that some air can still get to "
      "the prisoners.");
   set_string("cell door","open","The cell door creaks slightly as it "
      "swings open.");
   set_string("cell door","close","An ominous thud echoes off the walls "
      "as the heavy cell door shuts solidly.");
   set_trap_functions(({"cell door"}),({"bind_me"}),({"pick"}));
}

void init() {
   ::init();
   add_action("peer_out", "peer");
}

void reset() {
   ::reset();
   if(!trapped("cell door"))  
      toggle_trap("cell door");
   if(query_open("cell door") && sizeof(all_living(TO)) < 1 ){
      set_open("cell door", 0);
      set_locked("cell door", 1);
      //causes recursion errors
     // JAILMAIN->set_open("cell door", 0);
     // JAILMAIN->set_locked("cell door", 1);
   }
}

int GoThroughDoor(){
   if(query_verb() == "grate") {  
     tell_object(TP,"You quickly abandon the idea after realizing there is
"+
        "no way you'd fit through the grate.");
     tell_room(TO,""+TPQCN+" studies the grate, almost as if considering "+
        "trying to squeeze through it.",TP);
     return 0;
   }
   return ::GoThroughDoor();
}

int bind_me(string str){
   object ob;
   if(interactive(TP)){
      toggle_trap("cell door");
      tell_object(TP,"As you attempt to pick the lock you hear an "
         "ominous click and suffer a paralyzing shock!");
      tell_room(ETP,TPQCN+" bends down to work at the lock but shudders "
         "and freezes when a click sounds from it!",TP);
      TP->set_paralyzed(50,"Your muscles are frozen from the shock!");
      tell_object(TP,"A guard rushes in and binds you, then takes your
tools!");
      tell_room(ETP,"A guard rushes in and binds "+TPQCN+", then takes "
         +TP->query_possessive()+" tools.",TP);
      TP->set_bound(500);
      ob = present("thief tools", TP);
      if(objectp(ob))  ob->remove();
      return 1;
   }
}

int peer_out(string str) {
   if(!str) {
      tell_object(TP,"Peer where?");
      return 1;
   }
   if(str == "grate" || str == "through grate") {
        tell_object(TP,"You step up to the door and peer out into the
jail.\n");
        tell_room(TO,""+TPQCN+" steps up to the cell door and peers
out.\n",TP);
        tell_room("/d/attaya/newseneca/rooms/jail_main","You hear a
scratching "
           "at the door and a glimpse of movement through the grate.\n",TP);
        TP->force_me("peer grate 1");
        return 1;
   }
   return 0;
}
