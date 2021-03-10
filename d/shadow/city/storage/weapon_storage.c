//Octothorpe (6/4/16)
//Shadow, Weapon Storage Room

#include <std.h>
#include "../defs.h"
inherit "/d/common/inherit/wpn_storage_full";

void create(){
   ::create();
   set_property("no teleport",1);
   set_light(2);
   set_indoors(1);
   set_name("Valchor's Weaponsmithy Storage");
   set_short("Valchor's Weaponsmithy Storage");
   set_long("This is a storage room filled with all sorts of weapons. "+
      "You shouldn't be here!");
   set_exits(([
       "up" : ROOMS"weapon"
   ]));
}