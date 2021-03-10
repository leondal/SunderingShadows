#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_name("Before the Black Spire");
   set_short("%^BLUE%^Before the Black Spire%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Before the Black Spire%^RESET%^\n"
"%^BLUE%^This narrow path leads back toward the road from the massive enclosure that surrounds you.  Further into the "
"complex descends a massive stalactite of %^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^y s%^RESET%^to%^BOLD%^%^BLACK%^ne"
"%^RESET%^%^BLUE%^, surrounded on all sides by smaller stalagmites.  Here, at what seems to be the rear of the compound, "
"is a separately-enclosed area with a small gate held open to allow public access.  The path beneath your feet leads up "
"to an %^ORANGE%^im%^YELLOW%^p%^RESET%^%^ORANGE%^osi%^YELLOW%^n%^RESET%^%^ORANGE%^g %^BLUE%^structure, a spire cut from "
"one of the many stalagmites that towers above you, its upper limits lost to sight in the darkened recesses of the cavern "
"roof.  Where the path meets its base is what appears to be a %^CYAN%^glo%^GREEN%^wi%^CYAN%^ng %^BLUE%^portal, the only "
"obvious means of entry to the pillar of stone.%^RESET%^\n");

   add_item(({"house","stalactite","stalagmites"}),"%^BLUE%^To the southeast, a fenced compound encloses a massive "
"%^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^y sta%^RESET%^la%^BOLD%^%^BLACK%^cti%^RESET%^t%^BOLD%^%^BLACK%^e%^RESET%^"
"%^BLUE%^ that sweeps down from the ceiling to the cavern's floor.  Smaller stalagmites rise up around it, all obviously "
"inhabited, and with finely-wrought bridges of %^WHITE%^gl%^BOLD%^e%^RESET%^%^WHITE%^am%^BOLD%^in%^RESET%^%^WHITE%^g "
"^%^BLUE%^metal spanning the gaps between each one.  One lone stalagmite stands closer than the rest, segregated from its "
"brothers and with a gate allowing access from the road.%^RESET%^");
   add_item(({"structure","spire","stalagmite"}),"%^BLUE%^Here in the rear portion of the enclosure is another "
"stalagmite that reaches in vain toward the roof.  The entire piece is made of %^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^"
"%^BLACK%^y s%^RESET%^to%^BOLD%^%^BLACK%^ne%^RESET%^%^BLUE%^, left in its natural form despite clear signs of drow use.  "
"Where the path meets its base is a %^CYAN%^glo%^GREEN%^wi%^CYAN%^ng %^BLUE%^portal, which seems to be the only way in or "
"out of the impressive structure.%^RESET%^");
   add_item(({"path","narrow path"}),"%^BLUE%^A smooth stone path leads in from the road here, through what seems to be "
"only a secondary gate at the rear of this complex.  It leads up to the base of the nearest stalagmite, where a %^CYAN%^"
"glo%^GREEN%^wi%^CYAN%^ng %^BLUE%^portal seems to offer the only means in or out.%^RESET%^");
   add_item(({"portal","glowing portal","archway"}),"%^BLUE%^Where the path meets the base of the spire is a portal "
"limned in %^CYAN%^pa%^GREEN%^l%^CYAN%^e l%^GREEN%^ig%^CYAN%^ht%^BLUE%^.  It is bordered by an archway carved with "
"elaborate %^CYAN%^a%^BOLD%^rc%^RESET%^%^CYAN%^ane ru%^BOLD%^n%^RESET%^%^CYAN%^es%^BLUE%^, perhaps wards of some kind.  "
"It seems to be the only way in or out of the impressive structure.%^RESET%^");
   add_item("gate","%^BLUE%^A smaller gate, probably only secondary in this massive compound, allows access to the rear "
"section.  Unlike the rest of the city's enclosures, this one seems to be held permanently open, allowing public access "
"to the %^BOLD%^%^BLACK%^d%^RESET%^ar%^BOLD%^%^BLACK%^k s%^RESET%^pir%^BOLD%^%^BLACK%^e %^RESET%^%^BLUE%^within"
".%^RESET%^");
   set_exits(([
     "northwest":ROOMS"northeast1",
     "portal":ROOMS"tower2",
   ]));
   set_pre_exit_functions(({"portal"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
   if(TP->query_true_invis()) return 1;
   tell_object(TP,"%^RESET%^%^BLUE%^You step into the %^CYAN%^glo%^GREEN%^wi%^CYAN%^ng %^BLUE%^portal, and find yourself "
"elsewhere.%^RESET%^");
   if(!TP->query_invis()) tell_room(TO,"%^RESET%^%^BLUE%^"+TP->QCN+" steps into the %^CYAN%^glo%^GREEN%^wi%^CYAN%^ng "
"%^BLUE%^portal %^BLUE%^and vanishes in a flash of light!%^RESET%^",TP);
   else tell_room(TO,"%^RESET%^%^BLUE%^The %^CYAN%^glo%^GREEN%^wi%^CYAN%^ng %^BLUE%^portal emits a sudden flash of light"
".%^RESET%^",TP);
   return 1;
}