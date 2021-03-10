#include <std.h>
inherit "/d/dagger/derro/obj/bplate_inherit";

void create(){
   ::create();
   add_id("ruby breastplate");
   set_short("%^BOLD%^%^RED%^Ruby Breastplate%^RESET%^");
   set_long("%^RESET%^%^RED%^This flawless breastplate is fashioned "+
      "from a single %^BOLD%^ruby%^RESET%^%^RED%^.  The outer "+
      "surface is completely "+
      "smooth, while the underside has been carved to allow for the "+
      "wearer's shape.  In lieu of the straps that normally attach "+
      "a breastplate, this one has been fitted with a matching thin "+
      "%^BOLD%^ruby%^RESET%^%^RED%^ backplate.  The two join together "+
      "at the sides and shoulders seamlessly, encasing the wearer in "+
      "a protective %^BOLD%^ruby%^RESET%^%^RED%^ shell.%^RESET%^");
   set_lore("The Ruby Breastplate is naturally a favorite "+
      "among the Kossuthians, but it is also valued by any who "+
      "prize the brilliant red color.  A few Mystrans wear rubies "+
      "in emulation of their holy symbols, and some followers of "+
      "Bane favor red over green.  These breastplates are "+
      "said to be fashioned by "+
      "a curious little creature who is fascinated with gemstones "+
      "and their many colors and uses.  He is said to live well "+
      "below the earth's surface, somewhere up north in the Dagger "+
      "region.  There are only a few alive who know the secret "+
      "of crafting such a plate from a single stone, and all of "+
      "the methods involve magic.");
   set_remove((:TO,"unwearme":));
}

int unwearme(){
   tell_object(ETO,"%^RED%^The %^BOLD%^ruby%^RESET%^%^RED%^ ceases "+
      "glowing as you remove the breastplate.%^RESET%^");
   tell_room(EETO,"%^RED%^"+ETOQCN+" removes the breastplate, "+
      "and the %^BOLD%^ruby%^RESET%^%^RED%^ ceases glowing%^RESET%^.",ETO);
   ETO->set_property("magic resistance",-10);
   return 1;
}