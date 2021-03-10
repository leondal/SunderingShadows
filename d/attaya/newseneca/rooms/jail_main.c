//jail_main.c by ~Circe~ for new Seneca 11/22/07
//added 2 psion guards 11/15/09 Hades
#include <std.h>
#include "../seneca.h"

#define CELL "/d/attaya/newseneca/rooms/jail_cell"

#define DESTD "/daemon/destinations_d"
#define ADEST(B,C) "/daemon/destinations_d"->add_waystation("/d/shadow/city/room/jail_main",B,C)

inherit "/std/jail_main.c";

void create(){
   ::create();
   set_jail_location("Seneca");

   DESTD->clear_waystations("/d/attaya/newseneca/rooms/jail_main");
   ADEST("/d/attaya/newseneca/rooms/jail_main",1);

   ADEST("/d/attaya/newseneca/rooms/estreet14",2);
   ADEST("/d/attaya/newseneca/rooms/street8",2);

   ADEST("/d/attaya/newseneca/rooms/street4",3);
   ADEST("/d/attaya/newseneca/rooms/skyline43",3);
   ADEST("/d/attaya/newseneca/rooms/viento58",3);
   ADEST("/d/attaya/newseneca/rooms/estreet18",3);

   ADEST("/d/attaya/newseneca/rooms/wstreet40",4);
   ADEST("/d/attaya/newseneca/rooms/skyline46",4);
   ADEST("/d/attaya/newseneca/rooms/viento54",4);
   ADEST("/d/attaya/newseneca/rooms/estreet22",4);

   ADEST("/d/attaya/newseneca/rooms/wstreet36",5);
   ADEST("/d/attaya/newseneca/rooms/sstreet29",5);
   ADEST("/d/attaya/newseneca/rooms/sstreet26",5);

   ADEST("/d/attaya/newseneca/rooms/wstreet33",6);
   
   set_cell(CELL);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Jail Office, Seneca");
   set_short("Jail Office, Seneca");
   set_long("%^BOLD%^Jail Office, Seneca%^RESET%^\n"+
      "Considered an unfortunate necessity, this jailer's office is "+
      "the place where criminals in Seneca are checked in before being "+
      "put into a jail cell.  The office is small but tidy, with a "+
      "large %^ORANGE%^wooden desk %^RESET%^set in front of the cell "+
      "door so that anyone entering must go around it to get to the cell. 
"+
      "Atop the desk is a thick %^BOLD%^%^BLACK%^tome %^RESET%^that likely "+
      "details the list of prisoners and their offenses and release dates. 
"+
      "Behind the desk is a %^ORANGE%^chair %^RESET%^for the guard on duty "+
      "to use, while a narrow shelf along the western wall holds an %^YELLOW%^"+
      "oil lamp %^RESET%^to light the room.\n");
   set_items(([
      "grate" : "Perhaps the guard won't mind if you peer through the "
          "grate to see who is in the cell.",
      "desk" : "The wooden desk is large, and its surface is very neat.  A
"+
          "bottle of ink and quill are placed beside a large, leather-bound
tome.",
      "tome" : "The tome is bound in dark leather and includes a list of
names.",
      "chair" : "Not overly comfortable, the chair is wooden and provides
"+
          "guards with a place to sit.",
      ({"shelf","lamp","oil lamp"}) : "The narrow shelf holds nothing save
"+
          "an oil lamp with a glass hood.  The lamp provides some light "+
          "for the room, but it certainly becomes dark at night when the "+
          "sun is not streaming through the doorway."
   ]));
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","Occasional noise from the jail cell can be
heard over the buzzing of Seneca.");
   }
   set_smell("default","The refreshing fragrance of the ocean is covered by
the foul smell from the cell.");
   set_exits(([
      "north" : ROOMS"street11",
      "cell" : CELL,
      "grate" : CELL
   ]));
   add_invis_exit("grate");
   add_pre_exit_function("grate", "GoThroughDoor");
   set_door("cell door",CELL,"cell","Seneca jail key","lock");
   set_open("cell door",0);
   set_locked("cell door", 1, "lock");
   lock_difficulty("cell door",-90, "lock");
   set_lock_description("cell door", "lock",
      "This lock is sandwiched between two very heavy "
      "metal plates to prevent tampering.  The mechanism appears to be "
      "not only complex but require a very sturdy key to get the pieces "
      "to even move.");
   set_door_description("cell door", "This is a door made of three inch "
      "thick oaken boards.  It has a section cut out and replaced with a "
      "grate of inch diameter iron bars so that some air can still get to "
      "the prisoners.");
   set_string("cell door","open","The cell door creaks loudly as it "
      "swings open.");
   set_string("cell door","close","An ominous thud echoes off the walls "
      "as the heavy cell door slams shut solidly.");
   set_door("door","/d/attaya/newseneca/rooms/street11","north",0,0);
   set_door_description("door","The door to the north is made of thick "+
      "%^ORANGE%^wooden planks %^RESET%^bound with %^BOLD%^%^BLACK%^"+
      "iron%^RESET%^.  A small, %^BOLD%^%^BLACK%^barred window %^RESET%^"+
      "is near the top of the door.");
}

void init() {
   ::init();
   add_action("peer_out", "peer");
}

void reset() {
   ::reset();
   if(!present("Seneca jailer"))
      new("/d/attaya/newseneca/mon/jailer")->move(TO);
   if(!present("Seneca Guard"))
      new("/d/attaya/newseneca/mon/city_guard")->move(TO);
   if(!present("Seneca Guard 2"))
      new("/d/attaya/newseneca/mon/city_guard")->move(TO);
   if(!present("psion"))new("/d/attaya/newseneca/mon/psi_guard")->move(TO);
   if(!present("psion 2"))new("/d/attaya/newseneca/mon/psi_guard")->move(TO);
}

int GoThroughDoor() {
   if(query_verb() == "grate") {  
     write("You won't fit through there, silly.");
     return 0;
   }
// need this to allow normal GoThroughDoor for the regular door exits
   return ::GoThroughDoor();
}

int peer_out(string str) {
   if(!str) {
      tell_object(TP,"Peer where?");
      return 1;
   }
   if(str == "grate" || str == "through grate"){
        tell_object(TP,"You step up to the door and peer into the cell.\n");
        tell_room(ETP,TPQCN+" steps up to the cell door and peers
inside.\n",TP);
        tell_room(CELL,"You hear footsteps and catch "
            "a glimpse of movement through the grate in the door.\n",TP);
        TP->force_me("peer grate 1");
                return 1;
   }
}
