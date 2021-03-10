#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("mittens");
   set_id(({"mittens","mitten"}));
   set_short("%^BOLD%^%^GREEN%^S%^BLUE%^t%^CYAN%^r%^WHITE%^i%^RED%^p%^YELLOW%^e%^MAGENTA%^d %^WHITE%^mittens%^RESET%^");
   set_long(
      "%^BOLD%^%^CYAN%^These colorful mittens have been fashioned from soft "+
      "wool of many different colors.  Stripes of varying widths run along the "+
      "back of each mitten, ending in a gathered cuff at the wrist.  The mittens "+
      "have no individual fingers, instead having one large pocket and a separate "+
      "section for the thumb.  They seem warm and comfortable, but not really "+
      "suitable for delicate tasks."
   );
   set_lore("This is a finely-tailored pair of mittens made by Mariel "+
      "of Kildare Glen.  They are often given as gifts to small "+
      "children, though many others have taken to wearing them "+
      "as well.  A small tag bearing her mark has been "+
      "sewn into it.");
   set_property("lore difficulty",3);
   set_weight(3);
   set_value(30);
   set_size(random(3)+1);
   set_type("clothing");
   set_limbs(({"left arm","right arm"}));
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
}

int wearme() {
   tell_object(ETO,"%^BOLD%^%^CYAN%^You pull on the mittens and can't help "+
      "feeling like a kid again%^RESET%^.");
   tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" gives a "+
      "small grin as "+ETO->query_subjective()+" pulls on the mittens.%^RESET%^",ETO);
   return 1;
}

int unwearme() {
   tell_object(ETO,"%^RESET%^%^CYAN%^You feel older as you pull the mittens "+
      "off your hands.%^RESET%^");
   tell_room(environment(ETO),""+ETO->query_cap_name()+" frowns and seems older "+
      "as "+ETO->query_subjective()+" pulls off the mittens.%^RESET%^",ETO);
   return 1;
}
