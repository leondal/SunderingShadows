//updated by Circe 9/7/04 with new desc
#include <std.h>;
inherit "/std/armour";

#define COLORS ({"%^RESET%^%^BLUE%^navy blue","%^BOLD%^%^BLACK%^black","%^RESET%^%^ORANGE%^tan","%^BOLD%^%^WHITE%^white","%^RESET%^%^GREEN%^green","%^YELLOW%^yellow","%^RESET%^%^RED%^red","gray","%^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple"})

void create(){
   int i;
   string COLOR;
   ::create();
   i = random(sizeof(COLORS));
   COLOR = COLORS[i];
   set_name("hose leggings");
   set_id(({"hose","hose leggings","leggings"}));
   set_short(""+COLOR+" hose leggings%^RESET%^");
   set_long("This pair of leggings is made from thin "+COLOR+" silk "+
      "%^RESET%^that seems surprisingly quite durable.  There is no "+
      "manner of ornamentation about the leggings, and they are made "+
      "simple to cover the legs and feet, adding a bit of protection "+
      "from dust and debris.");
   set_type("clothing");
   set_limbs(({"right leg","left leg"}));
   set_weight(1);
   set_size(random(3)+1);
   set_value(3);
}
