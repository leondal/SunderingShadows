#include <std.h>
inherit "/d/dagger/derro/obj/bplate_inherit";

void create(){
   ::create();
   add_id("amethyst breastplate");
   set_short("%^MAGENTA%^A%^BOLD%^m%^RESET%^%^MAGENTA%^e%^BOLD%^t"+
      "%^RESET%^%^MAGENTA%^h%^BOLD%^y%^RESET%^%^MAGENTA%^s%^BOLD%^t "+
      "Breastplate%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^This flawless breastplate is fashioned "+
      "from a single %^MAGENTA%^a%^BOLD%^m%^RESET%^%^MAGENTA%^e%^BOLD%^t"+
      "%^RESET%^%^MAGENTA%^h%^BOLD%^y%^RESET%^%^MAGENTA%^s%^BOLD%^t"+
      "%^RESET%^%^MAGENTA%^.  The outer surface is completely "+
      "smooth, while the underside has been carved to allow for the "+
      "wearer's shape.  In lieu of the straps that normally attach "+
      "a breastplate, this one has been fitted with a matching thin "+
      "%^MAGENTA%^a%^BOLD%^m%^RESET%^%^MAGENTA%^e%^BOLD%^t"+
      "%^RESET%^%^MAGENTA%^h%^BOLD%^y%^RESET%^%^MAGENTA%^s%^BOLD%^t"+
      "%^RESET%^%^MAGENTA%^ backplate.  The two join together "+
      "at the sides and shoulders seamlessly, encasing the wearer in "+
      "a protective %^MAGENTA%^a%^BOLD%^m%^RESET%^%^MAGENTA%^e%^BOLD%^t"+
      "%^RESET%^%^MAGENTA%^h%^BOLD%^y%^RESET%^%^MAGENTA%^s%^BOLD%^t"+
      "%^RESET%^%^MAGENTA%^ shell.%^RESET%^");
   set_lore("The Amethyst Breastplate is naturally a favorite "+
      "among several faiths, especially those who follow Shar. "+
      "The sparkling purples of the amethyst also endear it to "+
      "Cyricists, Tyrrans, and Tymorans - as well as some who "+
      "follow Istishia.  These breastplates are said to be fashioned by "+
      "a curious little creature who is fascinated with gemstones "+
      "and their many colors and uses.  He is said to live well "+
      "below the earth's surface, somewhere up north in the Dagger "+
      "region.  There are only a few alive who know the secret "+
      "of crafting such a plate from a single stone, and all of "+
      "the methods involve magic.");
   set_remove((:TO,"unwearme":));
}

int unwearme(){
   tell_object(ETO,"%^MAGENTA%^The %^MAGENTA%^a%^BOLD%^m%^RESET%^"+
      "%^MAGENTA%^e%^BOLD%^t%^RESET%^%^MAGENTA%^h%^BOLD%^y%^RESET%^"+
      "%^MAGENTA%^s%^BOLD%^t%^RESET%^%^MAGENTA%^ ceases "+
      "glowing as you remove the breastplate.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" removes the breastplate, "+
      "and the %^MAGENTA%^a%^BOLD%^m%^RESET%^%^MAGENTA%^e%^BOLD%^t"+
      "%^RESET%^%^MAGENTA%^h%^BOLD%^y%^RESET%^%^MAGENTA%^s%^BOLD%^t"+
      "%^RESET%^%^MAGENTA%^ ceases glowing%^RESET%^.",ETO);
   ETO->set_property("magic resistance",-10);
   return 1;
}