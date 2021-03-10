#include <std.h>
inherit ARMOUR;
  object ob;
void create(){
  ::create();
  set_name("plate");
  set("id",({"plate","armor","red plate","guilded red plate"}));
  set_short("%^RED%^Guilded Red Plate%^RESET%^");
   set_long("  %^BOLD%^%^RED%^This armor is meant for a truly huge creature.  "
   "It's 12 feet around the chest and looks on the scale of a dwarf who is 18 feet tall."
  "  Its red surface has gold trim and looks scorched as if by intense heat."
 );
  set_weight(100);
  set_value(10000);
  set_type("armour");
  set_limbs(({"torso"}));
  set_ac(0);
  set_property("enchantment",4);
  set_wear((:TO,"wear":));
}
int wear(){
  if((string)TP->query_race() != "giant"){
   write("This armor is much too large for you!");
  return 0;
  }
  return 1;
}
