//boots.c - for Lothwaite, Circe 12/19/04
#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_id(({"shoes","leather shoes"}));
   set_name("leather shoes");
   set_short("%^RESET%^%^ORANGE%^leather shoes%^RESET%^");
   set_long(
      "%^RESET%^%^ORANGE%^These dark brown leather shoes are "+
      "made with a thick leather sole boiled and hardened to "+
      "protect the wearer's feet.  The upper portion of the shoe "+
      "has been left open and consists of several curved flaps of "+
      "soft suede, three on each side.  Each of the flaps has a "+
      "small hole through which a leather thong runs.  The shoes "+
      "reach just above the wearer's ankles, and the two ends of the "+
      "thong may be gathered and tied to secure the shoes.%^RESET%^"
   );
   set_lore("These shoes are common in the firbolg village of Lothwaite.  "+
      "There, most of the men wear such shoes, which offer some "+
      "protection while within the village.  When leaving, most of "+
      "them switch to harder soled leather boots.");
   set_property("lore difficulty",3);
   set_value(25);
   set_size(3);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
}