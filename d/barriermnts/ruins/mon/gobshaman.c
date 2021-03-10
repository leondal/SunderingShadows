#include <std.h>
#include "../inherit/ruins.h"
inherit WEAPONLESS;

create() {
   ::create();
   set_name("goblin");
   set_id(({ "goblin","goblinoid","grimy goblin","goblin shaman","shaman"}));
   set_short("%^RESET%^%^RED%^grimy-robed goblin%^RESET%^");
   set_wimpy(10);
   set_property("swarm",1);
   set_long("%^GREEN%^This little goblin is clad in %^BLACK%^%^BOLD%^dark, dirty robes%^RESET%^%^GREEN%^ "
"that have probably not seen a hint of colour in a long time.  A horrid stench emanates from the "
"creature, you could only imagine what it is keeping in its pockets.  Its pointed ears stick through its "
"%^BLACK%^%^BOLD%^long, greasy hair%^RESET%^%^GREEN%^, and its skin is a dull %^ORANGE%^yellow%^GREEN%^ "
"shade.  Its face is flat, with a squashed nose above a wide mouth of small, sharp "
"%^YELLOW%^yellowed%^RESET%^%^GREEN%^ teeth.  Glinting %^RED%^%^BOLD%^red%^RESET%^%^GREEN%^ eyes peer "
"out from its face, with a wicked hint of intelligence in them.%^RESET%^");
   set_hd(10,12);
   set_class("cleric");
   set_mlevel("cleric",18);
   set_guild_level("cleric",18);
   add_search_path("/cmds/priest");
   set_spells(({"limb attack","limb attack","hold person","cause serious wounds","cause critical wounds","flame strike"}));
   set_spell_chance(60);
   set_body_type("human");
   set_stats("intelligence",11);
   set_stats("wisdom",15);
   set_stats("strength",14);
   set_stats("charisma",5);
   set_stats("dexterity",13);
   set_stats("constitution",16);
   set_alignment(6);
   set_race("goblin");
   set_gender("male");
   set_size(1);
   set_exp(2000);
   set_overall_ac(0);
   set_max_hp(random(50)+125);
   set_hp(query_max_hp());
   set_property("full attacks",1);
   add_money("silver",random(100)+15);
   add_money("electrum",random(50)+50);
   command("speak goblin");
   set_property("full attacks",1);
   set("aggressive","agg_fun");
   set_emotes(1, ({"The goblin searches around in its dirty pockets.",
"A horrible smell emanates from the goblin.",
"The goblin sits down and begins picking at its grimy toenails."}), 0);
   set_achats(2, ({"The little goblin waves his arms.",
"The goblin glares menancingly at you.",
"The goblin growls and takes a step back."}) );
   set_nogo(({"/d/barriermnts/ruins/room/b1-3","/d/barriermnts/ruins/room/u1-3","/d/barriermnts/ruins/room/entry","/d/barriermnts/ruins/room/inner1"}));
   set_speed(40);
   set_moving(1);
   new(OBJ+"sigilred")->move(TO);
}

int agg_fun() {
   if (!TP->query_invis()) {
     if(sizeof(TO->query_attackers()) < 1) {
       force_me("emote spreads its scrawny arms.");
       force_me("speech shriek");
       force_me("say Kills it for us, good feeding today!");
     }
     force_me("kill "+TP->query_name());
   }
}