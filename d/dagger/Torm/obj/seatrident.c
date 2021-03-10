// updated to use the trident inherit, nienne 05/07
#include <std.h>
inherit "/d/common/obj/weapon/trident.c";

void create()
{
   ::create();
   set_name("%^BOLD%^%^BLUE%^Trident of the Seas%^RESET%^");
   set_short("%^BOLD%^%^BLUE%^Trident of the Seas%^RESET%^");
   set_id(({"trident","sea trident","trident of the seas"}));
   set_long("%^BOLD%^%^CYAN%^The metal that the trident is made from"+
   " has a pale blue hue to it. It has a long shaft that ends in three"+
   " forked tines, with the center one being the longest. The entire"+
   " shaft is covered in creatures of the sea, everything ranging from"+
   " sea serpents and krakens to dolphins and whales. On the very bottom"+
   " of the shaft the wave symbol of Istishia has been engraved.");
   set_value(50);
   set_wield((:TO,"wieldme":));
   set_unwield("%^BOLD%^%^BLUE%^You release your grip on the trident and relax.");
   if(!random(20)) set_property("enchantment",1);
}

int wieldme()
{
   if((string)ETO->query_diety() == "kossuth") {
      return notify_fail("A Kossuth follower using a weapon of Istishia's just wouldn't be right.");
   }
   if((string)ETO->query_diety() == "istishia") {
      tell_object(ETO,"%^BLUE%^You feel the power of the sea within the trident.");
      return 1;
   }
   else {
      tell_object(ETO,"%^BOLD%^%^BLUE%^You feel as though the weight of the"+
      " sea is pressing down on you.");
      return 1;
   }
}
