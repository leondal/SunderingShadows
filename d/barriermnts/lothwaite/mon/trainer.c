#include <std.h>

inherit "/std/trainer";

void create(){
   ::create();
   set_name("Mallaric Roselfel");
   set_short("Mallaric Roselfel, Master at Arms");
   set_long("This burly firbolg stands well over fourteen feet tall "+
      "with massive arms and a bulky frame.  He is clad simply in a "+
      "leather breastplate above soft leather breeches, apparently "+
      "unafraid of the blows that might be directed at him.  He "+
      "spends much of his day in the field, ready to train any of "+
      "those he can in the weapon of their choosing.");
   set_hd(30,4);
   set_exp(1);
   set_property("no bows",1);
   set_stats("strength",10);
   set_stats("dexterity",20);
   set_max_hp(300);
   set_hp(300);
   set_id(({"mallaric","Mallaric","roselfel","Roselfel","master","master at arms","trainer","weapon skill trainer"}));
   set_attack_limbs(({"right hand","left hand"}));
   set_attacks_num(1);
   set_damage(1,1);
   set_race("firbolg");
   set_gender("male");
   set_base_damage_type("bludgeoning");
   set_overall_ac(0);
   set_size(3);
}

void reset(){
   ::reset();
   if(query_night()){
      tell_room(ETO,"%^BOLD%^%^GREEN%^Mallaric heads off toward his home.");
      TO->move("/d/shadowgate/void");
      destruct(TO);
   }
}
