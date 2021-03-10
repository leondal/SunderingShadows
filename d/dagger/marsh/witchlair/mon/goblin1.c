#include <std.h>
#include "../witchlair.h"
inherit WEAPONLESS;

void create() {
 ::create();
 set_name("goblin barbarian");
 set_id(({"goblin","goblin slave"}));
 set_short("%^RESET%^%^GREEN%^a %^BOLD%^%^BLACK%^v%^RESET%^%^RED%^i"
"%^BOLD%^%^RED%^c%^BLACK%^io%^RED%^u%^BLACK%^s %^RESET%^%^GREEN%^little"
" goblin%^RESET%^");
 set_long("%^RESET%^%^GREEN%^Someone or something has driven this wretch "
"to madness and beyond. While inherently vicious, this goblin has gone "
"beyond its kin's wicked nature into an evident %^MAGENTA%^primal "
"%^GREEN%^reversion. It stands in a hunched, apelike posture, fighting "
"with one fist against the ground. Rows of jagged little %^YELLOW%^"
"t%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^e%^YELLOW%^t%^RESET%^%^WHITE%^h "
"%^GREEN%^snap together as it snarls and growls at you, wide mouth held in "
"a horrid snarl.%^RESET%^");
 set_race("goblin");
 set_body_type("humanoid");
 set_heart_beat(1);
 set_stats("intelligence",2);
 set_stats("wisdom",14);
 set_stats("strength",17);
 set_stats("charisma",0);
 set_stats("dexterity",17);
 set_stats("constitution",16);
 set_hd(20,10);
 set_max_hp(random(100)+250);
 set_hp(query_max_hp());
 set_class("barbarian");
 set_mlevel("barbarian",20);
 set_guild_level("barbarian",20);
 set_alignment(9);
 set_gender("male");
 set_size(1);
 new("/d/shadow/room/goblin/obj/bone.c")->move(this_object());
 command("wear armor");
 set_monster_feats(({
   "rage","dodge","mobility","evasion","rush"
 }));
 set_property("swarm",1);
 set_exp(2000);
 set_overall_ac(2);
 set_attack_limbs( ({"left hand","right hand","head"}) );
 set_attacks_num(3);
 set_base_damage_type("bludgeoning");
 set_damage(2,6);
 set("aggressive","agg_fun");
 set_achats(2, ({"%^BOLD%^%^BLACK%^A rabid growl flies from the goblin's "
"filthy maw!%^RESET%^",
"%^RESET%^%^GREEN%^The goblin grinds its teeth and rushes at you, running"
" on all fours!",}) );
TO->set_invis();
 set_nogo(({ROOMS"archway",ROOMS"path1",ROOMS"path2"}));
}

void agg_fun(){
   tell_room(ETO,"%^BOLD%^%^BLACK%^A goblin descends on you, "
"leaping from the twisted branches of the trees above!");
   command("roar");
   force_me("kill "+TP->query_name());
}
void heart_beat(){
   ::heart_beat();
   if(TO->query_invis() && sizeof(TO->query_attackers()))
   TO->set_vis();
   if(!TO->query_invis() && !sizeof(TO->query_attackers()))
   TO->set_invis();
}
