#include <std.h>
inherit "/d/dagger/derro/obj/bplate_inherit";

void create(){
   ::create();
   add_id("black opal breastplate");
   set_short("%^BOLD%^%^BLACK%^B%^GREEN%^l%^BLACK%^a%^BLUE%^c%^BLACK%^k "+
      "%^RED%^O%^BLACK%^p%^YELLOW%^a%^BLACK%^l Breastplate%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This flawless breastplate is fashioned "+
      "from a single %^BOLD%^%^BLACK%^b%^GREEN%^l%^BLACK%^a%^BLUE%^"+
      "c%^BLACK%^k %^RED%^o%^BLACK%^p%^YELLOW%^a%^BLACK%^l.  The "+
      "outer surface is completely "+
      "smooth, while the underside has been carved to allow for the "+
      "wearer's shape.  In lieu of the straps that normally attach "+
      "a breastplate, this one has been fitted with a matching thin "+
      "%^BOLD%^%^BLACK%^b%^GREEN%^l%^BLACK%^a%^BLUE%^"+
      "c%^BLACK%^k %^RED%^o%^BLACK%^p%^YELLOW%^a%^BLACK%^l "+
      "backplate.  The two join together "+
      "at the sides and shoulders seamlessly, encasing the wearer in "+
      "a protective %^BOLD%^%^BLACK%^b%^GREEN%^l%^BLACK%^a%^BLUE%^"+
      "c%^BLACK%^k %^RED%^o%^BLACK%^p%^YELLOW%^a%^BLACK%^l shell.%^RESET%^");
   set_lore("The Black Opal Breastplate is naturally a favorite "+
      "among several faiths.  The riot of muted color makes them a "+
      "popular choice for the more chaotic religions, particularly "+
      "Talos.  Most any followers of a darker deity prize the gem, "+
      "however.  Though not chaotic, the clergy of Bane like black "+
      "opals for the reds and greens seen inside.  These "+
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
   tell_object(ETO,"%^BOLD%^%^BLACK%^The %^BOLD%^%^BLACK%^b"+
      "%^GREEN%^l%^BLACK%^a%^BLUE%^"+
      "c%^BLACK%^k %^RED%^o%^BLACK%^p%^YELLOW%^a%^BLACK%^l ceases "+
      "glowing as you remove the breastplate.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" removes the breastplate, "+
      "and the %^BOLD%^%^BLACK%^b%^GREEN%^l%^BLACK%^a%^BLUE%^"+
      "c%^BLACK%^k %^RED%^o%^BLACK%^p%^YELLOW%^a%^BLACK%^l ceases "+
      "glowing%^RESET%^.",ETO);
   ETO->set_property("magic resistance",-10);
   return 1;
}