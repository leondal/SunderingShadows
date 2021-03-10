//Octothorpe (1/24/09)
//Underdark Mining Caverns, Svirfneblin Cavern Master Room Inherit

#include <std.h>
#include "../defs.h"
inherit CROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_travel(DECAYED_FLOOR);
   set_terrain(BUILT_TUNNEL);

   set_name("%^BOLD%^%^BLACK%^A r%^RESET%^o%^BOLD%^%^BLACK%^ughly-hewn "+
      "tunnel%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^A r%^RESET%^o%^BOLD%^%^BLACK%^ughly-hewn "+
      "tunnel%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A r%^RESET%^o%^BOLD%^%^BLACK%^ughly-hewn "+
      "tunnel\n "+
      "On initial inspection, one might suspect that this tunnel is "+
      "of a natural origin, perhaps the remnant of an underground river or a "+
      "lava tube. Even though the walls of the tunnel appear to be in a "+
      "rough, nautral state, the evidence of a civilized force in the "+
      "area puts that theory into doubt. The passage is roughly oval in "+
      "shape, reaching to a height of approximately seven feet by five "+
      "feet wide. In some places, an eerie %^GREEN%^g%^RESET%^"+
      "%^MAGENTA%^l%^BOLD%^o%^RESET%^%^GREEN%^w %^BOLD%^%^BLACK%^bleeds "+
      "through cracks in the %^RESET%^limestone%^BOLD%^%^BLACK%^."+
      "%^RESET%^\n");
   set_items(([
      ({"faerzress","crystals","crystal","cracks"}):"%^BOLD%^%^BLACK%^"+
         "The glow from the faerzress provides an eerie, muted "+
         "illumination to this tunnel.",
      "limestone" : "%^BOLD%^%^BLACK%^The %^RESET%^limestone %^BOLD%^"+
         "%^BLACK%^appears to be in a natural state, untouched by "+
         "mortal hands. In some places, cracks in the rock reveal the "+
         "presence of faerzress underneath. The glow from the faerzress "+
         "casts the %^RESET%^limestone %^BOLD%^%^BLACK%^in an eerie "+
         "light.",
      "tunnel" : "%^BOLD%^%^BLACK%^This natural-looking tunnel has most "+
         "likely been recently dug through the hard %^RESET%^limestone "+
         "%^BOLD%^%^BLACK%^around you. Cracks in the walls of the "+
         "tunnel provide a dim source of illumination. The dimensions "+
         "of this passage can accomadate a normal surface humanoid, and "+
         "is certainly more than large enough for a member of a small "+
         "race to work in.",
   ]));
   set_smell("default","The limestone dust in the area begins to "+
      "irritate your nose.");
   set_listen("default","Muffled clangs and rumbles echo down the "+
      "tunnel walls.");
}

