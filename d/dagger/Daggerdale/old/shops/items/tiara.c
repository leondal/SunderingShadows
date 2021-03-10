#include <std.h>
inherit ARMOUR;

void create()
{
   ::create();
   set_name("moonstone tiara");
   set_short("%^BOLD%^%^WHITE%^A moonstone tiara%^RESET%^");
   set_id(({"moonstone tiara","tiara","dagger_jewelry"}));
   set_long("%^BOLD%^This delicate tiara is made from white gold and it will"+
   " rest easily upon the head. In the center of the tiara is a very"+
   " large oval of polished moonstone. There are two smaller circles"+
   " of moonstone on either side of it, and then several perfectly"+
   " round pearls that slowly decrease in size as you get to the end"+
   " of the tiara.%^RESET%^\n");
   set_weight(3);
   set_type("ring");
   set_limbs(({"head"}));
   set_value(1000);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
}

int wearme()
{
   if((string)TP->query_gender() == "female") {
      tell_object(TP,"You feel regal as you slip the tiara onto your head.");
      return 1;
   }
   tell_object(TP,"You feel really silly as you put the tiara on.");
   return 1;
}

int removeme()
{
   if((string)TP->query_gender() == "female") {
      tell_object(TP,"You slip the dainty tiara off, careful not to pull your hair.");
      return 1;
   }
   tell_object(TP,"You feel much more manly after removing the tiara.");
   return 1;
}
