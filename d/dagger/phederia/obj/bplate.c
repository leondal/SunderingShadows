#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
  set_name("armor of broken bones");
  set_id(({"armor","armor of broken bones","bones"}));
  set_short("%^BOLD%^%^WHITE%^Armor of broken bones%^RESET%^");
  set_long(
  "  This armor is composed of the broken arm bones of many humanoids."
  "  Each bone bears a single %^RED%^rune%^RESET%^ which radiates a sense of evil."
  "  Although many gaps show between the bones to the flesh of the wearer below, the armor still seems to grant much protection from its dark enchantment."
  "  The boney hands all seems to be grasping at its wearer, who must be female from the form, in a most familiar way."
       );
  set_weight(50);
    set("value", 10000);
    set_type("armour");
    set_limbs( ({ "torso" }) );
  set_ac(5);
  set_property("enchantment",4);
  set_wear((:TO,"wearme":));
}
int wearme(){
  if((string)TP->query_gender() != "female") {
  tell_object(ETO,"\nThe skeletal hands find nothing they want to grasp so the armor wont stay on.");
  tell_room(environment(ETO),"\n"+ETO->query_cap_name()+"s armor rejects him!",ETO);
  TP->force_me("drop armor of broken bones");
  return 0;
}
  if((int)ETO->query_highest_level()>20){
  tell_object(ETO,"\nThe skeletal hands settle firmly around your body and you wonder if they really needed to give you that extra little pinch?");
  tell_room(environment(ETO),"\nThe skeletals hands that compromise "+ETO->query_cap_name()+"s armor wrap themselves firmly around her in a most familiar way.",ETO);
  return 1;
  }
  tell_object(ETO,"\nThe skeletal hands sense your lack of power and lock fingers and prevent you from wearing the armor.");
  return 0;
}
