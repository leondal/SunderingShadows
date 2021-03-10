//updated by Circe 9/7/04 with new desc
#include <std.h>;
inherit ARMOUR;

#define COLORS ({"%^BOLD%^white","%^RESET%^%^ORANGE%^brown","%^RESET%^%^ORANGE%^t%^YELLOW%^a%^RESET%^%^ORANGE%^n","%^BOLD%^%^BLUE%^blue","%^RESET%^%^BLUE%^navy","%^GREEN%^green","gray","%^RED%^red","%^RESET%^%^ORANGE%^orange","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple"})

void create(){
   int j;
   string COLOR;
   ::create();
   j = random(sizeof(COLORS));
   COLOR = COLORS[j];
   set_name("shoes");
   set_id(({"shoes"}));
   set_short("a pair of "+COLOR+" velvet %^RESET%^shoes");
   set_long("This pair of velvet shoes is unlikely to be worn "+
      "anywhere but within the confines of a noble's home.  They "+
      "have been dyed "+COLOR+"%^RESET%^, clearly meant to match "+
      "a particular outfit.  The shoes are simple slip-ons with "+
      "leather soles and are often in fashion among nobles.");
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_weight(1);
   set_size(random(3)+1);
   set_value(16);
}
