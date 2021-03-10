#include <std.h>
inherit "/d/dagger/derro/obj/bplate_inherit";

void create(){
   ::create();
   add_id("moonstone breastplate");
   set_short("%^BOLD%^%^WHITE%^M%^RESET%^o%^BOLD%^o%^RESET%^n"+
      "%^BOLD%^s%^RESET%^t%^BOLD%^o%^RESET%^n%^BOLD%^e "+
      "Breastplate%^RESET%^");
   set_long("This flawless breastplate is fashioned "+
      "from a single %^BOLD%^%^WHITE%^m%^RESET%^o%^BOLD%^o%^RESET%^n"+
      "%^BOLD%^s%^RESET%^t%^BOLD%^o%^RESET%^n%^BOLD%^e%^RESET%^.  The "+
      "outer surface is completely "+
      "smooth, while the underside has been carved to allow for the "+
      "wearer's shape.  In lieu of the straps that normally attach "+
      "a breastplate, this one has been fitted with a matching thin "+
      "%^BOLD%^%^WHITE%^m%^RESET%^o%^BOLD%^o%^RESET%^n"+
      "%^BOLD%^s%^RESET%^t%^BOLD%^o%^RESET%^n%^BOLD%^e%^RESET%^ "+
      "backplate.  The two join together "+
      "at the sides and shoulders seamlessly, encasing the wearer in "+
      "a protective %^BOLD%^%^WHITE%^m%^RESET%^o%^BOLD%^o%^RESET%^n"+
      "%^BOLD%^s%^RESET%^t%^BOLD%^o%^RESET%^n%^BOLD%^e%^RESET%^ shell.%^RESET%^");
   set_lore("The Moonstone Breastplate is naturally a favorite "+
      "among Selunites, who prize its milky color as a sign of their "+
      "goddess.  The white sheen is also prized by Aurilites who "+
      "recognize the similarity to snow.  Sharrans strictly avoid "+
      "moonstone and view it as an abomination.  These "+
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
   tell_object(ETO,"%^BOLD%^%^WHITE%^The %^BOLD%^%^WHITE%^m%^RESET%^o%^BOLD%^o%^RESET%^n"+
      "%^BOLD%^s%^RESET%^t%^BOLD%^o%^RESET%^n%^BOLD%^e ceases "+
      "glowing as you remove the breastplate.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" removes the breastplate, "+
      "and the %^BOLD%^%^WHITE%^m%^RESET%^o%^BOLD%^o%^RESET%^n"+
      "%^BOLD%^s%^RESET%^t%^BOLD%^o%^RESET%^n%^BOLD%^e ceases "+
      "glowing.%^RESET%^",ETO);
   ETO->set_property("magic resistance",-10);
   return 1;
}