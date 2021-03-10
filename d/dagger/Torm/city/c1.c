#include <std.h>
#include "../tormdefs.h"
inherit VAULT;
void create()
  {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("indoors",1);
  set_door("gates","/d/dagger/Torm/road/path12","west","masterkey");
  set_door_description("gates", "%^BOLD%^%^BLACK%^Old iron gates that creak in the wind.");
  set_property("light",2);
    set_short("West gates of Torm");
  set_long(
  "West gates of Torm.\n"
  "  You stand at the gates of the city of Torm."
 "  To the west lies the road out of the city while to the east you can see the people of Torm go about their lives."
  "  The gate looks weak but carries mystic sigils much like the ones that adorn the outside of the thin green walls that surround the city on all sides but the sea."
  );
  set("night long",
  "%^BLUE%^"
  "  You stand at the gates of the city of Torm."
  "  The gates to the west are closed typically closed at night, since"+
  " there is little activity in the city during that time.  Visitors"+
  " may of course come and go as they please, but it is requested that"+
  " they close the gates behind them."
  );
  set_smell("default","You can smell the salt sea air.");
  set_listen("default","Far away the breakers of the Dagger Sea pound away at the docks.");
  set_exits(([
  "west":ROAD+"path12",
  "east":TCITY+"c40",
  ]));
  //set_open("gates",0);
  set_items(([
  "gates":"Thin bronze gates hang from weak looking hinges.  Aquatic scenes decorate the bronze and all along the edges of the gates mystic sigils are inscribed.",
  (({"sigils","mystic sigils"})):"Strange sigils are carved into the bronze and you can only assume they are the only thing that would keep anyone out if they wanted to come in and the gates were closed.",
  "walls":"The strange seafoam green walls of Torm are decorated with carvings and aquatic scenes with strange sigils inscribed along the walls at regular spacing.", 
  ]));
/* this is handled by ../road/path12, loops if you try to do both
   if(query_night() == 1) {
      //set_open("gates",0);
   }
   else {
       //set_open("gates",1);
   }
*/
}

void reset() {
  object ob;
  ::reset();
  if(!(query_night())) {
     if(!present("torm guard",TO)) {
        new(MON+"guard4")->move(TO);
     }
  }
}
