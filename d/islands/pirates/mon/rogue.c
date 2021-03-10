#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

void stab_em(object targ);

void create(){
   ::create();
   set_name("pirate");
   set_id(({"pirate","thief"}));
   set_short("A pirate");
   set_long("This is one of the local ruffians, perhaps a pirate taking some time away from his ship.  He "
"has a cold appearance, with rough clothes and sturdy boots.  With a weapon in each hand, his intentions "
"probably aren't friendly.");
   switch(random(10)) {
     case 0..4:
     set_race("human");
     set_size(2);
     break;
     case 5..7:
     set_race("half-elf");
     set_size(2);
     break;
     case 8:
     set_race("halfling");
     set_size(1);
     break;
     case 9:
     set_race("half-orc");
     set_size(2);
     break;
   }
   set_gender("male");
   set_body_type("human");
   set_hd(17,15);
   set_wielding_limbs( ({ "right hand", "left hand" }) );
   set_stats("strength",17);
   set_stats("intelligence",10);
   set_stats("wisdom",10);
   set_stats("dexterity",18);
   set_stats("constitution",15);
   set_stats("charisma",10);
   set("aggressive","agg_func");
   set_class("thief");
   set_mlevel("thief",17);
   set_guild_level("thief",17);
   add_search_path("/cmds/thief");
   set_thief_skill("move silently",100);
   set_thief_skill("hide in shadows",100);
   set_thief_skill("pick pockets",100);
   set_hidden(1);
   set_scrambling(1);
   set_hp(120);
   set_max_hp(120);
   set_exp(1500);
   set_max_level(25);
   add_money("silver", random(500)+50);
   set_overall_ac(0);
   new(OBJ"longdagger")->move(TO);
   command("wield dagger");
   new("/d/common/obj/weapon/rapier")->move(TO);
   command("wield rapier");
   toggle_steal();
   set_speed(random(20)+40);
}

int agg_func(){
   if(TP->query_invis()) return 1;
   stab_em(TP);
   return 1;
}

void stab_em(object targ){
   command("say All yer treasures will be mine!");
   if(!TO->query_hidden()) set_hidden(1);
   command("stab "+targ->query_name());
   command("kill "+targ->query_name());
}
