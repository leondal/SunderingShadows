#include <std.h>
#include "../gantioch.h"
inherit OBJECT;

create(){
   ::create();
   set_id(({"caravan","wreckage","remnants"}));
   set_name("caravan");
   set_obvious_short("%^BOLD%^%^RED%^The %^BOLD%^%^BLACK%^rem%^BOLD%^%^RED%^na%^BOLD%^%^BLACK%^nts %^BOLD%^%^RED%^of a caravan");
   set_short("%^BOLD%^%^RED%^The %^BOLD%^%^BLACK%^rem%^BOLD%^%^RED%^na%^BOLD%^%^BLACK%^nts %^BOLD%^%^RED%^of a caravan");
   set_long(
      "%^RESET%^%^ORANGE%^This caravan has been utterly ransacked and nearly completely destroyed."+
      " %^BOLD%^%^BLACK%^Smoldering %^RESET%^%^ORANGE%^planks of wood litter the area as well as abandoned supplies."+
      " The wood looks to have been hacked to pieces by axes, and %^RESET%^%^RED%^blood %^RESET%^%^ORANGE%^covers the"+
	  " wood in thick splatter. Whatever happened to this caravan was terrible. Perhaps someone is still...alive."
   );
   set_weight(1000000);
   set_value(1300);
}

