#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit CORRIDOR;

string long_desc();

void create() {
  
  ::create();
  set_short("stone corridor");
  set_smell("default","The musty air cloggs your nose with the"
                     +" dust of ages long past");
  set_listen("default","Hardly a sound makes it inside here. All is"
                      +" still");

  set_exits( ([ "south" : ROOMS + "corridor3",
                "north": ROOMS + "corridor1", 
                "west": ROOMS + "process_start" ])  );
  set_door("damaged door",ROOMS+"process_start","west",0); 
  set_door_description("damaged door","A heavy stone door, which has sustained heavy damage.");
}



string long_desc(){
    return "A stone corridor, running north to south. The"
          +" east wall is lined from floor to ceiling with"
          +" dark recesses. They are regularly spaced and each one is"
          +" about a foot and a half square. The rest of the stonework is"
          +" covered with carvings and motifs.";
}
