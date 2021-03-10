//Octothorpe (6/4/16)
//Shadow, Armor Storage Room

#include <std.h>
#include "../defs.h"
inherit "/d/common/inherit/armor_storage_full";

void create(){
   ::create();
   set_property("no teleport",1);
   set_light(2);
   set_indoors(1);
   set_name("Flugar's Armory Storage");
   set_short("Flugar's Armory Storage");
   set_long("This is a storage room filled with all sorts of armor. "+
      "You shouldn't be here!");
   set_exits(([
       "up" : ROOMS"armor"
   ]));
}