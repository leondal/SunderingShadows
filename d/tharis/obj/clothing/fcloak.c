//updated by Circe 9/7/04 with new desc
#include <std.h>;
inherit ARMOUR;

#define COLORS ({"%^BOLD%^pristine white","%^RESET%^%^ORANGE%^light tan","%^RESET%^%^ORANGE%^mot%^YELLOW%^t%^RESET%^%^ORANGE%^led b%^YELLOW%^r%^RESET%^%^ORANGE%^own","%^BOLD%^%^BLACK%^inky black","%^BOLD%^%^BLACK%^dus%^RESET%^ky %^BOLD%^%^BLACK%^gray"})

void create(){
   int i;
   string COLOR;
   ::create();
   i = random(sizeof(COLORS));
   COLOR = COLORS[i];
   set_name("fur cloak");
   set_id(({"fur cloak","cloak"}));
   set_short("a fine "+COLOR+" fur %^RESET%^cloak");
   set_long("Clearly worn by those with wealth and power rather "+
      "than the simpletons who skin their own animals, this fine "+
      "cloak is made of the softest wool with a "+COLOR+" fur "+
      "collar%^RESET%^.  The cloak fastens about the neck with a "+
      "thick %^YELLOW%^gold clasp %^RESET%^in the shape of a "+
      "lion's head with glittering %^YELLOW%^to%^RESET%^%^ORANGE%^"+
      "pa%^YELLOW%^z eyes%^RESET%^.  The cloak has no hood and "+
      "seems more ornamental than practical.");
   set_weight(2);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_size(random(3)+1);
   set_value(75);
}
