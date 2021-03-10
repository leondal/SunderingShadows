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
  set_exits( ([ "east" : ROOMS + "corridor4",
                "north": ROOMS + "corridor6", 
                                             ])  );
}



string long_desc(){
    return "The corner of a stone corridor, going north and east. The"
          +" south and east walls are lined from floor to ceiling with"
          +" dark recesses. They are regularly spaced and each one is"
          +" about a foot and a half square. The rest of the stonework is"
          +" covered with carvings and motifs.";
}
