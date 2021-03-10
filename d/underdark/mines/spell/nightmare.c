//Octothorpe (12/28/08)
//Underdark Mining Caverns, Dragon Scale Cloak Nightmare Mob
//Using Nightmare Shadow from Ovadexal as inherit
///d/islands/dreams/mons/nightmare_shade.c

#include <std.h>
#include "../defs.h"
inherit DRM+"nightmare_shade";

void create(){
   ::create();
}

void die(object ob){
   tell_room(ETO,"%^BOLD%^The %^BOLD%^%^BLACK%^shadow %^WHITE%^"+
      "dissipates into thin air.%^RESET%^");
   TO->move("/d/shadowgate/void");
   TO->remove();
   return;
}   


