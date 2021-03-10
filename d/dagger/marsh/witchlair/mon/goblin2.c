#include <std.h>
#include "../witchlair.h"
inherit MONSTER;

void create() {
   object obj;
   ::create();
   set_name("goblin rogue");
   set_id(({"goblin","goblin slave","goblin thief"}));
   set_short("%^RESET%^%^GREEN%^a %^BOLD%^%^BLACK%^s"
"%^RESET%^%^BLUE%^n%^BOLD%^%^BLACK%^ea%^RESET%^%^BLUE%^k"
"%^BOLD%^%^BLACK%^y %^RESET%^%^GREEN%^little goblin%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Clad in blackened leathers, "
"this nasty little beast desires nothing more than to slice "
"you to bits! Leathery, grayish flesh aids the goblin in "
"blending into the trees overhead, and is pulled tautly over"
" its leering, beady-eyed face. The scrawny creature's "
"movements are nimble and precise for such a being. This "
"malicious little thing is a nuisance deserving only of death"
". You'd better oblige it before those twin bone daggers it"
" just pulled out are buried in your flesh!");
   set_race("goblin");
   set_body_type("humanoid");
   set_heart_beat(1);
   set_stats("intelligence",12);
   set_stats("wisdom",10);
   set_stats("strength",10);
   set_stats("charisma",10);
   set_stats("dexterity",19);
   set_stats("constitution",16);
   set_hd(20,6);
   set_max_hp(random(100)+120);
   set_hp(query_max_hp());
   set_class("thief");
   set_mlevel("thief",20);
   set_guild_level("thief",20);
   set_alignment(9);
   set_gender("male");
   set_size(1);
   set_monster_feats(({
     "dodge","mobility","evasion","scramble","whirl"
   }));
   set_property("swarm",1);
   set_exp(2000);
   set_overall_ac(2);
   set_wielding_limbs(({"right hand","left hand"}));
   obj = new("/d/shadow/room/goblin/obj/gdagger.c");
   if(random(10)) obj->set_property("monsterweapon",1);
   command("wield dagger");
   obj->move(TO);
   obj = new("/d/shadow/room/goblin/obj/gdagger.c");
   if(random(10)) obj->set_property("monsterweapon",1);
   command("wield dagger");
   obj->move(TO);
   new("/d/shadow/room/goblin/obj/bone.c")->move(TO);
   command("wear armor");
   set_achats(2, ({"%^BOLD%^%^BLACK%^The goblin moves silent "
"and swift, grinning hideously as it closes in for the kill!",
"%^RESET%^%^GREEN%^The goblin snarls and recoils as he is struck"
", glaring at you with hate-filled %^RED%^eyes%^GREEN%^!",}) );
  set_nogo(({ROOMS"archway",ROOMS"path1",ROOMS"path2"}));
}

void agg_fun(){
   tell_room(ETO,"%^BOLD%^%^BLACK%^A goblin descends on you, "
"leaping from the twisted branches of the trees above!");
   command("cackle");
   force_me("kill "+TP->query_name());
}

void heart_beat(){
   ::heart_beat();
   if(TO->query_invis() && sizeof(TO->query_attackers()))
   TO->set_invis();
   if(!TO->query_invis() && !sizeof(TO->query_attackers()))
   TO->set_invis();
}
