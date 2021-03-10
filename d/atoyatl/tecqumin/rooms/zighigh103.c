#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_HIGH;

void create() {
  object waystation;
  ::create();

  waystation = new (OBJ+"waystation1");
  waystation->set_short("A feathered serpent carved in stone");
  waystation->set_long("A feathered serpent is carved into the side of"
                      +" the ziggurat here. Its body is coiled, with the"
                      +" head and the end of the tail protruding from the"
                      +" coils. The plumes sprout from just behind the"
                      +" serpent's head and further along its undulating"
                      +" back.");
  waystation->set_weight(2000);
  waystation->set_value(20000);
  waystation->move(TO);
  waystation->set_id(({"serpent", "feathered serpent","carved serpent",
                      "stone serpent","stone feathered serpent", 
                      "waystation", "waystation1"}));

  set_exits( ([ "south" : ROOMS + "zighigh102" ,
	          "north" : ROOMS + "zighigh104"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh202",5,6,20}),
       "descend":({ROOMS + "zigmid205",5,6,20}),
  ]));
}
