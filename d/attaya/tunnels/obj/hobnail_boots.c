// Coded by Lujke. These are the devilkin's dancing boots. They are
// enchanted to +1, have an ac setting of -1 when worn, but give a bonus
// of +1 to dex.
// updated dex bonus from the new system. Nienne, 09/07.

#include <std.h>
#include <move.h>
inherit ARMOUR;

string master;

void create()
{
  ::create();
  set_obvious_short("%^RESET%^dull gray circlet");
  set_name("gray circlet");
  set_short("%^BOLD%^%^BLACK%^c%^RESET%^i%^BOLD%^%^BLACK%^rcl%^RESET%^e"
           +"%^BOLD%^%^BLACK%^t %^RESET%^of %^CYAN%^c%^RESET%^o%^CYAN%^"
           +"ntr%^RESET%^o%^CYAN%^l%^RESET%^");
  set_id(({"circlet","gray circlet","dull circlet","dull gray circlet"}));
  set_long("A circlet of dull gray metal. It is designed to curve around"
          +" the wearer's head. The band swells and tapers in a curve. It"
          +" is widest across the centre of the forehead and tapers"
          +" somewhat over the temples.");
  set_lore("");
  set_property("lore difficulty",14);
  set_weight(5);
  set_type("clothing");
  set_limbs(({"left foot","right foot"}));
  set_ac(0);
  set_property("enchantment",4);
  set_value(50);
  set_wear((:TO,"wearme":));
  set_remove((:TO,"removeme":));
  switch (random(6))
  {
  case 0:
    set_size(1);
    break;
  case 1:
    set_size(3);
  default:
    set_size(2);
  }
  set_item_bonus("dexterity",2);
}

int wearme()
{
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  tell_object(ETO,"!");
  tell_room(EETO,ETO->query_cap_name() + " slides on the " + query_short()
                + " and laces them up tightly.\n\n"+ ETO->query_cap_name()
                + " sh%^ORANGE%^u%^RESET%^ffl%^CYAN%^e%^RESET%^s "
                + ETO->QP +" feet slightly", ETO);
  return 1;
}

int removeme()
{
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  tell_object(ETO,"" + query_short() + " ");
  tell_room(EETO, ETO->query_cap_name()+" unlaces the " + query_short()
                  +" and slides them off " + ETO->QP+" feet. " 
                  + ETO->QS + " looks a little more heavy-footed");
   return 1;
}
