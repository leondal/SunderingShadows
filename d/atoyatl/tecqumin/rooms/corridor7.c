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
  set_items(([  ({"recess", "recesses"}): "peering into the recesses, you"
                 +" can make out that each one contains a complete human"
                 +" skeleton"
  ]) );
  set_exits( ([ "south" : ROOMS + "corridor6" ])  );
}



string long_desc(){
    return "A stone corridor, coming to a dead end to the north. The"
          +" north and west walls are lined from floor to ceiling with"
          +" dark recesses. They are regularly spaced and each one is"
          +" about a foot and a half square. The rest of the stonework is"
          +" covered with carvings and motifs.";
}
