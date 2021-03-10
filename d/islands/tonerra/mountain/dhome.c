#include <std.h>

#include "/d/islands/tonerra/areadefs.h"
inherit ROOM;

object dragon;

void create(){
   ::create();

  set_no_clean(1);
   set_name("dragon's home");
   set_short("Dragon' Home");
   set_long("This is the inside of the dormant volcano. The emerald dragon resides here.");
   set_smell("default","Fumes from the still raging fires below singe your nose");
   set_exits((["up":MOUNTAIN+"mount63"]));
}

void reset(){
   ::reset();
// taken out until the bug is fixed that is causing Daelmas to be bounced and have his gear duplicated when he returns.  Styx 9/26/01 11:46 pm
// Fixed the damn bug in contingency.
   if(!objectp(dragon)){
      dragon = new(MON+"edragon");
      dragon->move(TO);
   }
}
