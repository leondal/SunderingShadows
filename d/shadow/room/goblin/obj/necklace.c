//updated by Circe 6/1/04 with new desc, lore, etc, by Shar
// updated to jewelry with new non-stacking armor system. N, 4/19.
#include <std.h>
inherit ARMOUR;

nosave int flag;

void create() {
    ::create();
    set_name("necklace");
    set_id(({"necklace","skull necklace","necklace of skulls"}));
    set_short("%^BLUE%^Necklace of %^BOLD%^%^WHITE%^Skulls%^RESET%^");
    set_long(
       "%^BLUE%^Strung onto a length of hemp rope are seven small "+
       "%^BOLD%^%^WHITE%^skulls%^RESET%^%^BLUE%^.  The skulls vary "+
       "in size, suggesting that they might have been taken from "+
       "different races.  Thin, weathered %^ORANGE%^leather flesh"+
       "%^BLUE%^ still covers most of the skulls, though signs of "+
       "decomposition are apparent.  Some skulls still possess a "+
       "lock of hair or two, though it's hard to tell with the grime "+
       "and dirt that covers this fetish.%^RESET%^"
    );
    set_lore("This goblin fetish you come to realize is a very sacred "+
       "item to the goblinoid races.  The skulls are made from the "+
       "head of the foes of the goblinoid race, from elves, gnomes, "+
       "halflings, and humans.  The goblin shaman and witches feel "+
       "that wearing the heads of their victims grants them an unholy "+
       "strength and protection from these races.");
    set_property("lore difficulty",6);
    set_weight(5);
    set_value(50);
    set_type("ring");
    set_limbs(({"neck"}));
    set_ac(0);
   set_property("magic nonstacking",1); // potential for stat point, non-stacking.
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
    flag = 0;
}
int wearit() {
  if((int)ETO->query_alignment() == 6 || (int)ETO->query_alignment() == 8 || (int)ETO->query_alignment() == 9) { // CN, NE, CE
    set_item_bonus("charisma",1);
    flag = 1;
    tell_object(ETO,"%^BOLD%^%^BLUE%^The skulls on the necklace let out a cry of agony!%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^BLUE%^The skulls on the necklace held by "+ETOQCN+" let out a cry of agony.%^RESET%^",ETO);
    return 1;
  }
  tell_object(ETO,"Ugh, this thing is gross!");
  tell_room(EETO,""+ETO->QCN+" looks a little uneasy as "+ETO->QS+" wears the necklace.",ETO);
  flag = 0;
  set_item_bonus("charisma",0);
  return 1;
}

int removeit() {
   if(flag) {
     flag = 0;
     tell_object(ETO,"%^BOLD%^%^BLUE%^You feel a strange power leave your body.%^RESET%^");
   }
   return 1;
}
