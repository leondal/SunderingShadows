//updated by Circe 9/7/04 with new desc
#include <std.h>;
inherit "/std/armour";

#define COLORS ({"%^BOLD%^white","%^RESET%^%^ORANGE%^brown","%^RESET%^%^ORANGE%^t%^YELLOW%^a%^RESET%^%^ORANGE%^n","%^BOLD%^%^BLUE%^blue","%^RESET%^%^BLUE%^navy","%^GREEN%^green","gray","%^RED%^red","%^RESET%^%^ORANGE%^orange","%^BOLD%^%^BLACK%^black"})

void create(){
   int i;
   string COLOR;
   ::create();
   i = random(sizeof(COLORS));
   COLOR = COLORS[i];
   set_name("cloak");
   set_id(({"cloak","cloak of good cloth"}));
   set_short("a "+COLOR+" cloak%^RESET%^");
   set_long("The light wool has been dyed "+COLOR+" %^RESET%^"+
      "and fashioned into a sensible - if well-made - cloak "+
      "with a deep hood.  A %^YELLOW%^brass frog %^RESET%^"+
      "closes the cloak at the neck, leaving the wearer's "+
      "hands free.");
   set_weight(1);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_size(random(3)+1);
   set_value(3);
}
