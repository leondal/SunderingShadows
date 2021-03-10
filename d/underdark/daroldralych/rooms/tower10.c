#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("A glowing sphere");
   set_short("%^GREEN%^A glowing sphere%^RESET%^");
   set_long("%^BOLD%^%^GREEN%^A glowing sphere%^RESET%^\n"
"%^GREEN%^All around you is a massive sphere, its edges glowing faintly to shed an %^BOLD%^ee%^RESET%^%^GREEN%^ri"
"%^BOLD%^e l%^RESET%^%^GREEN%^ig%^BOLD%^ht %^RESET%^%^GREEN%^all around you.  Despite there being nothing visible "
"beneath your feet, you seem to be able to walk normally without falling.  The air seems verily abuzz with "
"%^CYAN%^gl%^BOLD%^i%^RESET%^%^CYAN%^tte%^RESET%^ri%^CYAN%^ng te%^BOLD%^%^WHITE%^nd%^RESET%^%^CYAN%^ri%^BOLD%^l"
"%^RESET%^%^CYAN%^s %^GREEN%^of arcane energy, almost tangible enough to reach out and touch.  Only a single item "
"breaks up the otherwise unfurnished area, in the form of a %^MAGENTA%^glow%^BOLD%^i%^RESET%^%^MAGENTA%^ng "
"%^GREEN%^portal in its very centre, bordered by a frame of %^BOLD%^%^BLACK%^gl%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^"
"ssy ob%^RESET%^si%^BOLD%^%^BLACK%^dian%^RESET%^%^GREEN%^.  Such a surreal place as this could only have been made "
"to allow magi to practice otherwise destructive spells without fear of damage to their surroundings.%^RESET%^\n");
   set_smell("default","%^RESET%^%^ORANGE%^The air is perfectly %^RESET%^still%^ORANGE%^.%^RESET%^");
   set_listen("default","%^RESET%^%^GREEN%^Only %^CYAN%^sil%^RESET%^en%^CYAN%^ce %^GREEN%^surrounds you.%^RESET%^");

   set_items(([
     ({"sphere","walls","floor","edges","light"}):"%^GREEN%^You are surrounded by a massive sphere that glows "
"with a faint, %^BOLD%^ee%^RESET%^%^GREEN%^ri%^BOLD%^e l%^RESET%^%^GREEN%^ig%^BOLD%^ht%^RESET%^%^GREEN%^.  "
"You seem to be standing in the middle of it, and are able to walk normally despite there being nothing visible "
"beneath your feet.  Such areas are prized by magetowers, allowing magi to practice otherwise destructive spells "
"without fear of damage to their surroundings.%^RESET%^",
     ({"portal","obsidian","frame"}):"%^GREEN%^Directly in the centre of the area, level with you, rests a "
"portal that emits a %^MAGENTA%^soft gl%^BOLD%^o%^RESET%^%^MAGENTA%^w%^GREEN%^.  It is encircled by a slender "
"oval frame of %^BOLD%^%^BLACK%^sm%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^oth ob%^RESET%^si%^BOLD%^%^BLACK%^dian "
"%^RESET%^%^GREEN%^which appears to be the only item in the sphere.%^RESET%^",
     ({"tendrils","energy"}):"%^CYAN%^Gl%^BOLD%^i%^RESET%^%^CYAN%^tte%^RESET%^ri%^CYAN%^ng te%^BOLD%^%^WHITE%^nd"
"%^RESET%^%^CYAN%^ri%^BOLD%^l%^RESET%^%^CYAN%^s %^GREEN%^of arcane energy fill the air, almost tangible enough "
"to reach out and touch.%^RESET%^",
   ]));
   set_exits(([
     "out":ROOMS"tower8",
   ]));
   set_pre_exit_functions(({"out"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
   if(TP->query_true_invis()) return 1;
   tell_object(TP,"%^RESET%^%^GREEN%^You step into the %^MAGENTA%^glo%^BOLD%^wi%^RESET%^%^MAGENTA%^ng %^GREEN%^portal, "
"and find yourself elsewhere.%^RESET%^");
   if(!TP->query_invis()) tell_room(TO,"%^RESET%^%^GREEN%^"+TP->QCN+" steps into the %^MAGENTA%^glo%^BOLD%^wi%^RESET%^"
"%^MAGENTA%^ng %^GREEN%^portal and vanishes in a flash of light!%^RESET%^",TP);
   else tell_room(TO,"%^RESET%^%^GREEN%^The %^MAGENTA%^glo%^BOLD%^wi%^RESET%^%^MAGENTA%^ng %^GREEN%^portal emits a sudden "
"flash of light.%^RESET%^",TP);
   return 1;
}