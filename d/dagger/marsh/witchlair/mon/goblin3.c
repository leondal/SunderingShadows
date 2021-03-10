#include <std.h>
#include "../witchlair.h"
inherit MONSTER;

void create(){
   ::create();
   set_name("goblin shaman");
   set_id(({"goblin","goblin slave","goblin shaman"}));
   set_short("%^RESET%^%^GREEN%^a %^BOLD%^%^BLACK%^c"
"%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^af%^RESET%^%^MAGENTA%^t"
"%^BOLD%^%^BLACK%^y %^RESET%^%^GREEN%^little goblin%^RESET%^");
   set_long("%^RESET%^%^BLUE%^A %^ORANGE%^s%^RED%^l"
"%^BOLD%^%^BLACK%^a%^RESET%^%^WHITE%^v%^ORANGE%^er%^GREEN%^i"
"%^YELLOW%^n%^RESET%^%^ORANGE%^g-m%^RED%^a%^ORANGE%^d%^BLUE%^,"
" wild-eyed goblin shaman. It's small, brown, ugly and mad. "
"What did you expect it to say here? It does what the box "
"says they do. Now %^BOLD%^%^RED%^kill %^RESET%^%^BLUE%^it.");
   set_race("goblin");
   set_body_type("humanoid");
   set_heart_beat(1);
   set_stats("intelligence",15);
   set_stats("wisdom",17);
   set_stats("strength",10);
   set_stats("charisma",15);
   set_stats("dexterity",12);
   set_stats("constitution",11);
   set_hd(20,10);
   set_max_hp(random(100)+140);
   set_hp(query_max_hp());
   set_class("cleric");
   set_mlevel("cleric",20);
   set_guild_level("cleric",20);
   set_alignment(9);
   set_gender("male");
   set_size(1);
   set_spells(({"insect plague","flame strike","unholy orb",
     "mass cause serious wounds"}));
     set_spell_chance(35);
     set("deity","bane");
   set_property("swarm",1);
   set_exp(2000);
   new("/d/shadow/room/goblin/obj/bone.c")->move(TO);
   command("wear armor");
   set("aggressive","agg_func");
   set_achats(2, ({"%^RESET%^%^GREEN%^The goblin shaman shakes"
" his staff and points at you, babbling incoherently!",}) );
}

void agg_fun(){
   tell_room(ETO,"%^BOLD%^%^BLACK%^A goblin descends on you, "
"leaping from the twisted branches of the trees above!");
   command("cackle");
   force_me("kill "+TP->query_name());
   new("/cmds/spells/d/_divine_weapon")->use_spell(TO,45,100,
"cleric");
   return 1;
  set_nogo(({ROOMS"archway",ROOMS"path1",ROOMS"path2"}));
}

void heart_beat(){
   ::heart_beat();
   if(TO->query_invis() && sizeof(TO->query_attackers()))
   TO->set_invis();
   if(!TO->query_invis() && !sizeof(TO->query_attackers()))
   TO->set_invis();
}
