#include "/d/common/common.h"
#include "../graveyard.h"
#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("zombie");
   set_id(({"zombie","Zombie","undead","hulking zombie"}));
   set_gender("male");
   set_race("zombie");
   set_short("%^RESET%^%^GREEN%^A hulking zombie%^RESET%^");
   set_long("%^GREEN%^This zombie is much larger than most humans you've met, and surprisingly less rotted "
"than most zombies you've met, as though something were preventing him from decaying.  His flesh, while having "
"a sickly %^BOLD%^green %^RESET%^%^GREEN%^tinge to it, is mostly intact, although it emits a %^BLUE%^foul "
"%^GREEN%^smell into the air around you.  Thin, greasy strands of %^YELLOW%^straw-yellow hair "
"%^RESET%^%^GREEN%^hang over his face, within which are two %^RED%^dull glowing eyes%^GREEN%^.  A few shreds "
"of clothing still hang off its hulking figure, swaying as it lumbers around the tomb.%^RESET%^");
   set_hd(5,1);
   set_body_type("human");
   set_class("fighter");
   set_level(5);
   set_size(2);
   set_alignment(9);
   set_stats("intelligence",16);
   set_stats("wisdom",8);
   set_stats("strength",16);
   set_stats("charisma",3);
   set_stats("dexterity",12);
   set_stats("constitution",10);
   set_hp(40);
   set_max_hp(query_hp());
   set("aggressive",20);
   add_money("gold",random(75)+25);
   set_overall_ac(6);
   set_exp(120);
   set_achats(1,
     ({ "%^GREEN%^The zombie takes a swing at you with one rotting hand.%^RESET%^",
        "%^BLUE%^The zombie moans and staggers toward you.%^RESET%^"
     }) );
   set_funcs(({"smell_fun","smack_fun"}));
   set_func_chance(30);
   new(GRAVEYARD"obj/ring")->move(TO);
   command("wear ring");
   set_new_exp(1, "very low");
}

int smell_fun(object target) {
   object *pplz;
   int i;
   pplz = all_living(ETO);
   tell_room(ETO,"%^GREEN%^The zombie moans woefully, and his putrid breath makes you want to retch!");
   for(i=0;i<sizeof(pplz);i++) {
     if(!avatarp(pplz[i])) pplz[i]->do_damage("torso",roll_dice(4,2));
   }
   return 1;
}

int smack_fun(object target) {
   int hp,maxhp,tester;
   string dir,dir2;
   if(random(2)) dir = "east";
   else dir = "north";
   dir2 = (string)ETO->query_exit(dir);
   hp = target->query_hp();
   maxhp = target->query_max_hp();
   tester = maxhp-hp;
   if(tester > hp) {
     tell_room(ETO,"%^ORANGE%^The zombie lunges forward and smacks "+target->QCN+" hard, sending "+target->QO+
" flying "+dir+" down the hall!%^RESET%^",target);
     tell_object(target,"%^ORANGE%^The zombie lunges forward and smacks you hard, sending you flying down the "
"hall!%^RESET%^");
     target->move(dir2);
     tell_room(environment(target),"%^ORANGE%^"+target->QCN+" comes flying in through the air, landing on the "
"ground with an audible thud!%^RESET%^",target);
   }
   else {
     tell_room(ETO,"%^ORANGE%^The zombie lunges forward and smacks "+target->QCN+" hard against the wall, "
"dazing "+target->QO+"!%^RESET%^",target);
     tell_object(target,"%^ORANGE%^The zombie lunges forward and smacks you hard against the wall, knocking "
"you into a daze!%^RESET%^");
     target->set_paralyzed(5);
     target->do_damage("torso",roll_dice(4,2));
   }
   return 1;
}
