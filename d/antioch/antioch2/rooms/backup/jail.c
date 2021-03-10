// switched to the new jail inherit 1/26/06 *Styx*

#include <std.h>

#define JAILMAIN "/d/antioch/antioch2/rooms/jail_main"

inherit "/std/jail_cell.c";

void create(){
   ::create();
   set_jail(JAILMAIN);
   set_jail_location("Antioch");
   set_release_to("/d/antioch/antioch2/rooms/gates");
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Antioch jail cell");
   set_short("An Antioch jail cell");
   set_long(
@STYX
You are in a gloomy, dank jail cell, about six feet wide by
eight feet deep.  The walls are cold, damp stone and rats are scurrying
about the straw mat on the floor that serves as a bed.  The only light
comes through a small window that is heavily barred or through the six
inch square grate in the door.  The damp air chills your body.  Obviously
your stay here is not meant to be a pleasant experience.
STYX
   );
   set_listen("default","You can hear the rats scurrying around.");
   set_smell("default","A nauseating smell rises from the filthy, damp "
      "floor.");
   set_items(([
      "grate" : "Perhaps you can peer through the grate to see who is in "
         "the main jail.",
      "window" : "You can see the top of the gallows from here.  You "
         "might be able to peer out and see who is there, if you really "
         "want to know.",
   ]));
   set_exits(([
      "out": JAILMAIN,
      "grate" : JAILMAIN,
      "window" : "/d/antioch/antioch2/rooms/street1",
   ]));
   set_invis_exits( ({"window", "grate" }) );
   set_pre_exit_functions( ({ "window", "grate" }), ({ "GoThroughDoor","GoThroughDoor" }) );
   set_door("cell door",JAILMAIN,"up","Shadow jail key");
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
//   JAILMAIN->set_open("cell door",0);
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
   if( query_open("cell door") && sizeof(all_living(TO)) < 1 ) {
      set_open("cell door", 0);
      set_locked("cell door", 1);
   }
}

int GoThroughDoor() {
   if(query_verb() == "grate" || query_verb() == "window") {  
     write("You wish... but you won't fit through there!");
     tell_room(ETP, TPQCN+" seems to be trying to get out through the
grate!",TP);
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
      tell_object(TP,"A guard rushes in and binds you, then takes your tools!");
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
        tell_object(TP,"You step up to the door and peer out into the jail.\n");
        tell_room(ETP,TPQCN+" steps up to the cell door and peers out.\n",TP);
        tell_room("/d/shadow/city/room/jail_main","You hear a scratching "
           "at the door and a glimpse of movement through the grate.\n",TP);
        TP->force_me("peer grate 1");
        return 1;
   }
   if(str == "window" || str == "out window" || str == "out") {
        tell_object(TP,"You climb up to the window and peer outside.\n");
        tell_room(ETP,TPQCN+" climbs up to the window and peers out.\n",TP);
        TP->force_me("peer window 1");
        return 1;
   }
   return 0;
}
