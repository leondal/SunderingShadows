//updated by Circe 9/7/04 with new desc
#include <std.h>;
inherit "/std/armour";

#define COLORS ({"%^BOLD%^white","%^RESET%^%^ORANGE%^brown","%^RESET%^%^ORANGE%^t%^YELLOW%^a%^RESET%^%^ORANGE%^n","%^BOLD%^%^BLUE%^blue","%^RESET%^%^BLUE%^navy","%^GREEN%^green","gray","%^RED%^red","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple"})

void create(){
   int i;
   string COLOR;
   ::create();
   i = random(sizeof(COLORS));
   COLOR = COLORS[i];
   set_name("breeches");
   set_id(({"breeches","pants","leather breeches","leather pants"}));
   set_short(""+COLOR+" leather breeches%^RESET%^");
   set_long("This pair of breeches is made from tight-fitting "+
      "supple "+COLOR+" leather%^RESET%^.  The leather is thin "+
      "and form-fitting, accentuating every aspect of the wearer's "+
      "legs - good or bad.  Only the most self-assured would "+
      "probably wear such pants - though they would likely look "+
      "quite nice in them.");
   set_type("clothing");
   set_limbs(({"right leg","left leg"}));
   set_weight(2);
   set_size(random(3)+1);
   set_value(12);
}
