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
  add_item("hole", "The hole has been smashed through the stones of the floor."
    +" Underneath, it is %^BOLD%^%^BLACK%^dark%^RESET%^, but you can make out a wall"
    +" within reach of the hole, with hand and footholds cut into it.");
  set_exits( ([ "east" : ROOMS + "corridor3",
                "west": ROOMS + "corridor5", 
                "hole": ROOMS + "head_room"        ])  );
}



string long_desc(){
    return "A stone corridor, running east to west. The"
          +" south wall is lined from floor to ceiling with"
          +" dark recesses. They are regularly spaced and each one is"
          +" about a foot and a half square. The rest of the stonework is"
          +" covered with carvings and motifs. A large hole in the floor disappears into darkness";}
