#include <std.h>
inherit "/d/common/obj/armour/fullplate";

void create()
{
   ::create();
   set_name("%^BOLD%^%^CYAN%^Full plate of the Waves%^RESET%");
   set_short("%^BOLD%^%^CYAN%^Full plate of the Waves%^RESET%^");
   set_id(({"armor","full plate armor","plate","full plate","fullplate","full plate of the waves","waves plate","waves fullplate","waves full plate"}));
   set_long("%^BOLD%^%^CYAN%^This is an impressive suit of full plate armor"+
   " that has been carefully and excellently crafted. The metal has been"+
   " given a blue tint somehow and in the center of the chest the wave"+
   " symbol of Istishia has been added in a %^BLUE%^darker blue%^CYAN%^"+
   " metal.");
   set_value(13000);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
}

int wearme()
{
   if((string)ETO->query_diety() == "kossuth") {
      return notify_fail("There is no way you're going to put on armor wearing Istishia's symbol!");
   }
   if((string)ETO->query_diety() == "istishia") {
      tell_object(ETO,"%^BOLD%^%^CYAN%^You put the normally hot and bulky"+
      " armor on, yet continue to feel cool.");
      tell_room(environment(ETO),"%^BOLD%^%^CYAN%^You almost think you hear"+
      " the faint crashing of waves in the distance as "+ETO->query_cap_name()+""+
      " puts on the plate armor.",ETO);
      return 1;
   }
   else {
      tell_object(ETO,"You slip into the plate armor, incredibly conscious"+
      " of the fact that you don't follow Istishia.");
      tell_room(environment(ETO),""+ETO->query_cap_name()+" seems a little"+
      " worried as "+ETO->query_subjective()+" gets into the full plate.",ETO);
      return 1;
   }
}

int removeme()
{
   if((string)ETO->query_diety() == "istishia") {
      tell_object(ETO,"%^BOLD%^%^BLUE%^You get out of the bulky armor but"+
      " still feel relatively cool.");
      return 1;
   }
   else {
      tell_object(ETO,"You can't help but be relieved and grateful that"+
      " nothing horrible happened to you while wearing the plate.");
      return 1;
   }
}
