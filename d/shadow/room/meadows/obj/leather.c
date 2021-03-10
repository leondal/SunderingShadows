// updated cha bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("leather");
   set_short("Dirty leather armor");
   set_id(({"leather","leather armor","armor","dirty leather armor","dirty armor","dirty leather"}));
   set_long("This is a suit of some rather ragged and dirty leather armor."+
   " It is more or less intact, but looks as though whoever wore it liked"+
   " to inhabit swamps and sewers.");
   set_size(1);
   set_type("leather");
   set_weight(10);
   set_limbs(({"torso"}));
   set_ac(2);
   set_value(2);
   set_cointype("silver");
   if(!random(6)) set_property("enchantment",1);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
   set_item_bonus("charisma",-1);
}

int wearme()
{
   tell_object(ETO,"%^ORANGE%^You notice a few fleas jump from the leather to you as you slip it on.");
   return 1;
}

int removeme()
{
   tell_object(ETO,"%^ORANGE%^You take off the leather, too bad the bugs decided to stay on you.");
   return 1;
}
