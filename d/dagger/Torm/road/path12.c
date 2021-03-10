#include <std.h>
inherit VAULT;
void create() {
    ::create();
    set_property("light", 2);
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
  set_door("gates","/d/dagger/Torm/city/c1","east","masterkey");
  set_door_description("gates", "%^BOLD%^%^BLACK%^Old iron gates that creak in the wind.");
  set_open("gates",1);
  set_short("Before the west gates of Torm");
    set_long(
  "%^CYAN%^"
 "The west gates of Torm are a stones throw to the east."
  "  The low green wall runs north and south blocking the view of the sea, boardwalks and boats that you've been watching as you approached the city."
  "  As you look north and south of the city you see the road bordered by low cliffs surmounted by the start of forests that move inland and a golden beach to the west."
    );
  set("night long",
 "%^BLUE%^"
  "The west gates of Torm lie closed to the east, with most everyone"+
  " having gone to bed at night, only to rise at the crack of dawn.  Any"+
  " travelers who wish to venture into Torm at such a late hour may do"+
  " so, but are asked to close the doors after they've entered.  Most of"+
  " the shops are probably closed, however.  The walls continue north"+
  " and south around the city."
  );
    set_items(([
	"boardwalk" : "A long wooden boardwalk stretches out over the Dagger"+
   " Sea.",
	"boats" : "You can see many boats of various styles constantly moving"+
   " in and out of Torm during the daytime, but it is too dangerous"+
   " at night with the fog, so only the most desperate dare to dock then.",
      ]));

    set_exits(([
  "northwest":"/d/dagger/Torm/road/path11",
  "north":"/d/dagger/Torm/road/path33",
  "south":"/d/dagger/Torm/road/path13",
  "east":"/d/dagger/Torm/city/c1",
      ]));

  set_listen("default","Seabirds chirp in the air over the boardwalks.");
  set_smell("default","Salty sea air mixes with the smells of many types of cooking.");
  set_pre_exit_functions(({"northeast","south","north"}),({"townsperson"}));
   if(query_night() == 1) {
      set_open("gates",0);
      "/d/dagger/Torm/city/c1"->set_open("gates",0);
  }
  else {
     set_open("gates",1);
     "/d/dagger/Torm/city/c1"->set_open("gates",1);
  }
}

int townsperson(){
  if(TP->query_property("blocked")){
    return 0;
  }
}

