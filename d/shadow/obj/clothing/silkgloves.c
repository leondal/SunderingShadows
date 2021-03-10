//updated by Circe 6/10/04 with better desc, etc.
// fixed old code TP in wear/remove that bugs *Styx* 2/16/06
#include <std.h>

inherit ARMOUR;

void create() {
   ::create();
   set_name("gloves of silk");
   set_id(({"gloves","silk gloves","gloves of silk"}));
   set_short("%^BOLD%^%^WHITE%^gloves of silk%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This pair of luxurious gloves is made "+
      "of supple silk of the highest quality.  Not a snag or imperfection "+
      "can be found in the gloves and they seem somehow to mold "+
      "themselves to the wearer's hands.");
   set_type("clothing");
   set_limbs( ({"left arm","right arm"}) );
   set_weight(1);
   set_ac(0);
   set_item_bonus("magic resistance",1);
   set_value(800);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
}

int wear_func() {
   if( (string)ETO->query_gender() == "female" )
      write("%^ORANGE%^The silk feels so soft! Every female must love "
         "this feeling.");
   if( (string)ETO->query_gender() == "male" )
      write("%^ORANGE%^The silk feels so soft! But are you sure you "
         "want to wear this?");
   return 1;
}

int remove_func() {
   if( (string)ETO->query_gender() == "female" )
      write("%^ORANGE%^You hesitantly remove the gloves.");
   if( (string)ETO->query_gender() == "male" )
      write("%^ORANGE%^You feel more like a man now!");
   return 1;
}
