#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_HIGH;

void create() {
  object waystation;
  ::create();

  waystation = new (OBJ+"waystation1");
  waystation->set_short("A stone carved jaguar head");
  waystation->set_long("The carved head of a jaguar protrudes from the"
                      +" side of the ziggurat. Its features are stylised,"
                      +" but surprisingly accurate. The eyes have no"
                      +" colour, which give it a somewhat alien air, and"
                      +" the lips draw back in a slight snarl.");
  waystation->set_weight(2000);
  waystation->set_value(20000);
  waystation->move(TO);
  waystation->set_id(({"head", "jaguar head","carved head", "stone head",
     "stone carved jaguar head", "waystation", "waystation1"}));

  set_exits( ([ "south" : ROOMS + "zighigh101" ,
	          "north" : ROOMS + "zighigh103"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh201",5,6,20}),
       "descend":({ROOMS + "zigmid204",5,6,20}),
  ]));
}

