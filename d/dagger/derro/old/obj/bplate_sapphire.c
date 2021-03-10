#include <std.h>
inherit "/d/dagger/derro/obj/bplate_inherit";

void create(){
   ::create();
   add_id("sapphire breastplate");
   set_short("%^BOLD%^%^BLUE%^Sap%^CYAN%^p%^BLUE%^hi%^CYAN%^r"+
      "%^BLUE%^e Breastplate%^RESET%^");
   set_long("%^RESET%^%^BLUE%^This flawless breastplate is fashioned "+
      "from a single %^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^hi%^CYAN%^r"+
      "%^BLUE%^e%^RESET%^%^BLUE%^.  The outer surface is completely "+
      "smooth, while the underside has been carved to allow for the "+
      "wearer's shape.  In lieu of the straps that normally attach "+
      "a breastplate, this one has been fitted with a matching thin "+
      "%^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^hi%^CYAN%^r"+
      "%^BLUE%^e%^RESET%^%^BLUE%^ backplate.  The two join together "+
      "at the sides and shoulders seamlessly, encasing the wearer in "+
      "a protective %^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^hi%^CYAN%^r"+
      "%^BLUE%^e%^RESET%^%^BLUE%^ shell.%^RESET%^");
   set_lore("The Sapphire Breastplate is naturally a favorite "+
      "among several faiths, especially those who follow Istishia "+
      "and Akadi.  The sparkling blue color of the sapphire is a "+
      "favorite among many, though, including Mystrans, "+
      "Aurilians, Tyrrans, and Helmites.  These breastplates "+
      "are said to be fashioned by "+
      "a curious little creature who is fascinated with gemstones "+
      "and their many colors and uses.  He is said to live well "+
      "below the earth's surface, somewhere up north in the Dagger "+
      "region.  There are only a few alive who know the secret "+
      "of crafting such a plate from a single stone, and all of "+
      "the methods involve magic.");
   set_remove((:TO,"unwearme":));
}

int unwearme(){
   tell_object(ETO,"%^BLUE%^The %^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^"+
      "hi%^CYAN%^r%^BLUE%^e%^RESET%^%^BLUE%^ ceases "+
      "glowing as you remove the breastplate.%^RESET%^");
   tell_room(EETO,"%^BLUE%^"+ETOQCN+" removes the breastplate, "+
      "and the %^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^hi%^CYAN%^r"+
      "%^BLUE%^e%^RESET%^%^BLUE%^ ceases glowing%^RESET%^.",ETO);
   ETO->set_property("magic resistance",-10);
   return 1;
}