#include <std.h>
#include "../elfisland1.h"

inherit "/std/npc.c";
void create() {
   ::create();
   set_name("amra");
   set_short("Amra Laelithar");
   set_id( ({"teller","amra","laelithar"}) );
   set_long("Amra is a lean, youthful looking female highe elf. She has"+
      " typical sharp features to match her pointy ears. Her emerald eyes"+
      " are offset by her rose red hair. She holds her head up and her back"+
      " straight while moving with grace."
   );
   set_race("elf");
   set_gender("female");
   set_hd(19,5);
   set_alignment(4);
   set_languages( ({ "elven" }) );
   command("speak elven");
   set_max_hp(200);
   set("aggressive", "kill_evil");
   set_hp(200);
   set_exp(400);
   set_property("swarm",0);
   set_db("teller");
   remove_std_db();
   set_random_act_db("amrarandom");
   set_random_act_chance(10);
}

void init() {
   ::init();
   if( (string)TP->query_name() == "raider") {
      command("yell %^BOLD%^%^GREEN%^Someone help!%^RESET%^");
      command("kill raider");
   }
}

void kill_evil() {
   string race;
   race = TP->query_race();
      if( race == "drow" || race == "half-drow" || race == "goblin" || race == "hobgoblin" ||
      race == "orc" || race == "half-orc" || race == "ogre" || race == "half-ogre" ||
      race == "kobold" || race == "ogre-mage" || race == "bugbear" || race == "wemic" ||
      race == "gnoll") {
   force_me("yell %^BOLD%^%^GREEN%^Someone help me!%^RESET%^");
   force_me("kill "+TP->query_name());
   return;
   }
}

void heart_beat() {
   object ob,*killers;
   int i;
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if(present("guard 2",ETO)) return;
   if(query_hp() <200) {
   command("yell HELP!!");
   tell_room(ETO,"You see a guard rush in to help the clerk.");
   ob = new(MON+"elguard");
   ob->move(ETO);
   ob->set_stats("strength",18);
   ob->set_exp(3500);
   ob->force_me("block out");
   ob->force_me("protect amra");
   ob->force_me("protect amra");
   ob->force_me("protect amra");
   ob->force_me("yell I will protect our people!");
   killers = query_attackers();
   for(i=0;i<sizeof(killers);i++){
     ob->kill_ob(killers[i],1);
   }
   }
}

