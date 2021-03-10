#include <std.h>
#include "../dragon.h";
      
inherit BTOWN;
      
void create() {
   ::create();
   set_light(0);
   set_indoors(1);
   set_short("Ruined shop");
   set_long(
      "%^BOLD%^%^BLACK%^This shop is utterly destroyed. Only due to the various old rusted"+
      " swords and dusty forge can you tell that it was once a weapon shop."+
      " Two badly rusted two-handed swords are crossed above the broken"+
      " counter on the south wall. The shop has been caught in the complete destruction"+ 
      " like every other building in this town."
   );
   set_exits(([
      "east": TOWN+"roadSW2"
   ])); 
   set_items(([
      "swords" : "Weapons lay sporadically spread about the shop.",
      "forge" : "The forge is cold and useless now"
   ] ));
  }