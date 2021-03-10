//cath_tower10 - bell tower for new Seneca
//~Circe~ 1/14/08
#include <std.h>
#include "../seneca.h"

inherit STORAGE"cath_tower";

void create(){
   ::create();
   set_long(::query_long()+"\nHere, the stairs end at "+
      "a narrow %^ORANGE%^wooden platform %^RESET%^that curves "+
      "around the %^ORANGE%^brass bells%^RESET%^, giving "+
      "them plenty of room to ring.  The sides and tops of the "+
      "bells are visible from here, letting you realize that this "+
      "landing must be meant for repairs.  Great gusts of "+
      "%^CYAN%^wind %^RESET%^blow through the openings here "+
      "at the top of the tower, much larger than the windows "+
      "below to allow all of Seneca to see the bells.\n");
   set_exits(([
      "down" : ROOMS"cath_tower9"
   ]));
   add_item("bells","%^ORANGE%^The two %^BOLD%^brass bells "+
      "%^RESET%^%^ORANGE%^hang from a beam just level with "+
      "you.  The bells are immense, thick creations that are "+
      "polished often, giving them a faint sheen.%^RESET%^");
   add_item("brass bells","%^ORANGE%^The two %^BOLD%^brass bells "+
      "%^RESET%^%^ORANGE%^hang from a beam just level with "+
      "you.  The bells are immense, thick creations that are "+
      "polished often, giving them a faint sheen.%^RESET%^");
   add_item("bell","%^ORANGE%^The two %^BOLD%^brass bells "+
      "%^RESET%^%^ORANGE%^hang from a beam just level with "+
      "you.  The bells are immense, thick creations that are "+
      "polished often, giving them a faint sheen.%^RESET%^");
   add_item("beam","%^ORANGE%^The thick wooden beam runs into "+
      "the very sandstone of the walls, making the structure "+
      "stable.  Standing here, you can see that what looks to "+
      "be one solid beam is actually two.  A clever design "+
      "allows the main support to run directly into the walls, "+
      "while a second yoke is attached to the bells, giving "+
      "them free movement when the rope is pulled.%^RESET%^");
   add_item("platform","The narrow catwalk allows room for "+
      "someone to make repairs or clean the bells but little "+
      "more.  There is no railing, and the proximity to the "+
      "bells makes it a rather percarious place to stand.");
   add_item("openings","Rather than small windows, the top "+
      "of the bell tower features large arched openings on all "+
      "four sides.  You can see all of Seneca from here and "+
      "much of Attaya.  The %^BOLD%^%^CYAN%^ocean %^RESET%^"+
      "stretches out endlessly while the vague %^BOLD%^%^BLACK%^"+
      "outline%^RESET%^ of the %^BOLD%^%^BLACK%^Crystalline "+
      "Tower of the Black Dawn %^RESET%^stands ominously in "+
      "the distant reaches of the north.");
}