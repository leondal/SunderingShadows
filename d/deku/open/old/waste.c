#include <std.h>

inherit "/d/deku/inherits/vexia-lair.c";

void create() {
    ::create();
    set_short("Waste Dump");
    set_long(
@KAYLA
Piled up against the walls of this 20 X 30 ft. chamber is a mass of
disgusting scraps and waste material.  The floor is covered with slop 
and dung along with a few small bones.  Even an ogre wouldn't want 
to spend any time in this mess.
KAYLA
    );
     set_smell("default","There is a sickening putrid odor that fills the air.");
     set_listen("default","You're too sick from the smell to notice any sounds.");
    set_items(([
      ({"scraps", "slop"}) : "Moldy food scraps and slimy bits of slop ooze "
          "amongst the other refuse in the room.",
      ({"waste","dung"}) : "%^BOLD%^%^BLACK%^EWWWW! Thats just nasty.",
       "bones" : "The dull white of broken bones pokes up from the foul "
          "smelling refuse that lines the room.",
    ] ));
    set_exits(([ "south" : "/d/deku/open/cave_r4" ] ));
}
