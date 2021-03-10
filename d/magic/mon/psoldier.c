//psoldier.c

#include <std.h>

inherit MONSTER;

void create(){
   ::create();

   set_name("phantom soldier");
   set_short("%^RESET%^%^RED%^Shimmering phantom soldier");
   set("not living",1);

   set_id(({"soldier","phantom","phantom soldier","construct","summoned monster"}));
   set_long("%^CYAN%^This shimmering form is a soldier. Translucent in some form, it seems very real in another.");
   set_race("human");
   set_body_type("human");
    set_property("no animate",1);
   set_gender("male");
   set_hd(16,1);
   set_stats("strength",10);
   set_hp(150);
   set_attack_bonus(3);
   set_weight(10000);
   new("/d/common/obj/weapon/longsword")->move(TO);
   command("wield sword");
   set_damage_bonus(3);
   set_size(2);
   set_overall_ac(0);
   set("magic",1);
}

void die(object ob){
   int i;
   tell_room(ETO,"%^RED%^The phantom soldier shimmers and is dispelled.");
// added by *Styx* 10/12/02 to remove swords when they dispel
   for(i=0;i<sizeof(all_inventory(TO));i++)
	all_inventory(TO)[i]->remove();
   remove();
   return;
}

int isMagic() {return 3;}
