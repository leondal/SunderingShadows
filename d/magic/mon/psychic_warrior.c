#include <std.h>

inherit WEAPONLESS;

void create(){
   ::create();
   set_name("psionic fighter");
   set_short("Ephemeral psionic fighter");
   set("not living",1);
   set_id(({"warrior","psychic warrior","ephemeral psychic warrior","fighter","psionic fighter","emphemeral psionic fighter","summoned monster"}));
   set_long("%^BOLD%^%^BLUE%^This ephemeral psionic fighter seems "+
      "to fade in and out of existence.  Its body appears forceful, "+
      "if not substantial, though it carries no weapons and wears no "+
      "armor.  Clearly, this being's power must come from somewhere else.%^RESET%^");
   set_race("human");
   set_property("no animate",1);
   set_gender("male");
   set_hd(16,1);
   set_stats("strength",10);
   set_hp(150);
   set_max_hp(150);
   set_attack_bonus(3);
   set_weight(10000);
   set_damage_bonus(3);
   set_overall_ac(0);
   set_damage(1,10);
   set_attacks_num(2);
   set_base_damage_type("bludgeoning");
   set("magic",1);
}

void die(object ob){
   int i;
   tell_room(ETO,"%^RED%^The psionic fighter shimmers and vanishes.%^RESET%^");
   remove();
   return;
}

int isMagic() {return 3;}
