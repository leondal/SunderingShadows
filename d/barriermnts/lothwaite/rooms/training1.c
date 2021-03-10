//Training ground for Lothwaite.  Circe 9/17/04
#include <std.h>
#include "../lothwaite.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_indoors(0);
   set_light(2);
   set_name("Training Ground");
   set_short("A Narrow Pathway");
   set_long("This narrow pathway is paved in %^BOLD%^%^BLACK%^gravel "+
      "%^RESET%^and leads just beside the %^BOLD%^stone building "+
      "%^RESET%^of the village smithy.  Just to the south, it passes "+
      "through a gate in a %^ORANGE%^tall wooden fence %^RESET%^that "+
      "encloses a %^GREEN%^grassy training ground %^RESET%^often in "+
      "use by the warriors of the village.  To the north, it leads "+
      "back to the much wider pathway that meanders through the "+
      "rest of the town.\n");
   set_items(([
      ({"path","pathway","gravel"}) : "This narrow pathway runs just "+
         "beside the building with no twists or turns.  It is lined with "+
         "small black and gray gravel to combat the mud produced by "+
         "the river's mist.",
      ({"building","stone building","smithy"}) : "From here, you "+
         "can see little more of the smithy than its stone wall.",
      ({"fence","wooden fence","gate"}) : "The wooden fence is "+
         "over six feet tall - tall to humans but rather short to "+
         "firbolgs.  It is meant to provide boundaries for the "+
         "practice field rather than keep out prying eyes.  Its "+
         "gate is most often open.",
      ({"field","training field","grass","mud"}) : "The grassy field "+
         "is rather large, seeming to take up a good portion of the "+
         "southwestern part of the village.  There is not much there "+
         "except an open area for the firbolgs to practice upon."
   ]));
   set_smell("default","You smell a slight dank scent on the air.");
   set_listen("default","The occasional clang of metal on metal rises over the wind.");
   set_exits(([
      "south" : PATHEXIT"training3",
      "north" : PATHEXIT"pathway19"
   ]));
}