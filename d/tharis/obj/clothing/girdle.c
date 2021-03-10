//updated by Circe 9/7/04 with new desc
#include <std.h>;
inherit ARMOUR;

#define COLORS ({"%^RESET%^%^ORANGE%^brown","%^BOLD%^%^WHITE%^white","%^BOLD%^%^BLACK%^black","%^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^y","%^RESET%^%^BLUE%^navy blue","%^RESET%^%^GREEN%^deep green","%^RESET%^%^RED%^red","%^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple"})

void create(){
   int i;
   string COLOR;
   ::create();
   i = random(sizeof(COLORS));
   COLOR = COLORS[i];
   set_name("corset");
   set_id(({"corset","leather corset","girdle"}));
   set_short(""+COLOR+" leather corset%^RESET%^");
   set_long("This tight-fitting corset is a necessity for any "+
      "well-bred lady.  It is made of leather dyed "+COLOR+"%^RESET%^.  "+
      "The corset is fashioned with %^BOLD%^ivory bones %^RESET%^"+
      "that aid in keeping a woman's figure the perfect hourglass.  "+
      "The two straps have been decorated with light embroidery "+
      "of a slightly shimmering "+COLOR+" thread%^RESET%^, adding "+
      "a touch of elegance that continues down over the front of "+
      "the corset.");
   set_type("ring");
   set_limbs(({"torso"}));
   set_weight(1);
   set_size(random(3)+1);
   set_value(20);
   set_property("repairtype",({ "tailor" }));
}
