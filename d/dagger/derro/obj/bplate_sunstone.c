//removed references to old gods ~Circe~ 7/30/19
#include <std.h>
inherit "/d/dagger/derro/obj/bplate_inherit";

void create(){
   ::create();
   add_id("sunstone breastplate");
   set_short("%^RESET%^%^ORANGE%^S%^BOLD%^u%^RESET%^%^ORANGE%^n%^BOLD%^s%^RESET%^%^ORANGE%^t%^BOLD%^o%^RESET%^%^ORANGE%^n%^BOLD%^e Breastplate%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This flawless breastplate is fashioned from a single %^RESET%^%^ORANGE%^s%^BOLD%^u%^RESET%^%^ORANGE%^n%^BOLD%^s%^RESET%^%^ORANGE%^t%^BOLD%^o%^RESET%^%^ORANGE%^n%^BOLD%^e%^RESET%^%^ORANGE%^.  The outer surface is completely smooth, while the underside has been carved to allow for the wearer's shape.  In lieu of the straps that normally attach a breastplate, this one has been fitted with a matching thin %^RESET%^%^ORANGE%^s%^BOLD%^u%^RESET%^%^ORANGE%^n%^BOLD%^s%^RESET%^%^ORANGE%^t%^BOLD%^o%^RESET%^%^ORANGE%^n%^BOLD%^e %^RESET%^%^ORANGE%^backplate.  The two join together at the sides and shoulders seamlessly, encasing the wearer in a protective %^RESET%^%^ORANGE%^s%^BOLD%^u%^RESET%^%^ORANGE%^n%^BOLD%^s%^RESET%^%^ORANGE%^t%^BOLD%^o%^RESET%^%^ORANGE%^n%^BOLD%^e %^RESET%^%^ORANGE%^shell.%^RESET%^");
   set_lore("The Sunstone Breastplate is naturally a favorite among the followers of Jarmila, but it is also valued by any who prize the golden yellow color.  Many Ryorik and Kreysneothosies followers have favored sunstones as well.  These breastplates are said to be fashioned by a curious little creature who is fascinated with gemstones and their many colors and uses.  He is said to live well below the earth's surface, somewhere up north in the Dagger region.  There are only a few alive who know the secret of crafting such a plate from a single stone, and all of the methods involve magic.");
   set_remove((:TO,"unwearme":));
}

int unwearme(){
   tell_object(ETO,"%^ORANGE%^The %^RESET%^%^ORANGE%^s%^BOLD%^u"+
      "%^RESET%^%^ORANGE%^n%^BOLD%^s%^RESET%^%^ORANGE%^t%^BOLD%^o"+
      "%^RESET%^%^ORANGE%^n%^BOLD%^e %^RESET%^%^ORANGE%^ceases "+
      "glowing as you remove the breastplate.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" removes the breastplate, "+
      "and the %^RESET%^%^ORANGE%^s%^BOLD%^u%^RESET%^%^ORANGE%^n"+
      "%^BOLD%^s%^RESET%^%^ORANGE%^t%^BOLD%^o%^RESET%^%^ORANGE%^n"+
      "%^BOLD%^e %^RESET%^%^ORANGE%^ceases glowing%^RESET%^.",ETO);
   return 1;
}