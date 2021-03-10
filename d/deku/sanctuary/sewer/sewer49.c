#include <std.h>
#include "../dragon.h";

inherit "/std/vault";

void create() {
  ::create();
   set_property("light", -1);
   set_property("indoors", 1);
   set_property("no teleport", 1);
   set_short("Disgusting sewer");
   set_long(
      "%^BOLD%^%^BLACK%^This is a wider section of sewer under the city of Sanctuary. This"+
      " section of tunnel is dry compared to the other sections in these old"+
      " sewers. Faintly luminescent lichen clings to the walls, reflecting"+
      " lightly off the water that occasionally drip from the ceiling of the"+
      " tunnel. There is a large portal here."
  );
   set_items(([
     "sewers":"The disgusting tunnels of waste under Sanctuary.",
     "portal":"This portal glows a faint cyan light."
   ]));
   set_smell("default","The smell of stagnant water assaults your senses.");
   set_listen("default","There is only silence here.");
   set_terrain(SHALLOW_WATER);
   set_travel(SLICK_FLOOR);
   set_exits(([
     "south": SEWER+"sewer48",
     "portal": SEWER+"sewer50"]));
   set_pre_exit_functions(({"portal"}),({"GoThroughDoor"}));
}

void reset() {
  ::reset();
  if(!present("quaggoth")) {
  new(MON+"quaggoth")->move(TO);
  new(MON+"quaggoth")->move(TO);
}
}

int GoThroughDoor() {
    object obj,ring;
    if(obj=present("brotherhood ring",TP)){
        if (obj->query_worn()){
            write("You pass through the invisible barrier guarding the portal.");
            return 1;
        }else{
           write("You can't seem to break the invisible barrier shielding the portal.");
            return 0;
        }
    }else{
        write("You can't seem to break the invisible barrier shielding the portal.");
        return 0;
    }
}
