#include <std.h>
inherit "/d/dagger/derro/obj/bplate_inherit";

void create(){
   ::create();
   add_id("emerald breastplate");
   set_short("%^RESET%^%^GREEN%^Em%^BOLD%^er%^RESET%^a%^BOLD%^"+
      "%^GREEN%^l%^RESET%^%^GREEN%^d %^BOLD%^"+
      "Breastplate%^RESET%^");
   set_long("%^GREEN%^This flawless breastplate is fashioned "+
      "from a single %^RESET%^%^GREEN%^em%^BOLD%^er%^RESET%^a%^BOLD%^"+
      "%^GREEN%^l%^RESET%^%^GREEN%^d.  The "+
      "outer surface is completely "+
      "smooth, while the underside has been carved to allow for the "+
      "wearer's shape.  In lieu of the straps that normally attach "+
      "a breastplate, this one has been fitted with a matching thin "+
      "%^RESET%^%^GREEN%^em%^BOLD%^er%^RESET%^a%^BOLD%^"+
      "%^GREEN%^l%^RESET%^%^GREEN%^d "+
      "backplate.  The two join together "+
      "at the sides and shoulders seamlessly, encasing the wearer in "+
      "a protective %^RESET%^%^GREEN%^em%^BOLD%^er%^RESET%^a%^BOLD%^"+
      "%^GREEN%^l%^RESET%^%^GREEN%^d shell.%^RESET%^");
   set_lore("The Emerald Breastplate is naturally a favorite "+
      "among clerics of the Forest Queen, who like to emulate the "+
      "colors of the seasons.  Of course, it is also a favorite among "+
      "the faithful of Bane who relate stories of the green fire in "+
      "the Dark One's eyes.  These "+
      "breastplates are said to be fashioned by "+
      "a curious little creature who is fascinated with gemstones "+
      "and their many colors and uses.  He is said to live well "+
      "below the earth's surface, somewhere up north in the Dagger "+
      "region.  There are only a few alive who know the secret "+
      "of crafting such a plate from a single stone, and all of "+
      "the methods involve magic.");
   set_remove((:TO,"unwearme":));
}

int unwearme(){
   tell_object(ETO,"%^GREEN%^The %^RESET%^%^GREEN%^em%^BOLD%^er%^RESET%^a%^BOLD%^"+
      "%^GREEN%^l%^RESET%^%^GREEN%^d ceases "+
      "glowing as you remove the breastplate.%^RESET%^");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" removes the breastplate, "+
      "and the %^RESET%^%^GREEN%^em%^BOLD%^er%^RESET%^a%^BOLD%^"+
      "%^GREEN%^l%^RESET%^%^GREEN%^d ceases "+
      "glowing.%^RESET%^",ETO);
   ETO->set_property("magic resistance",-10);
   return 1;
}