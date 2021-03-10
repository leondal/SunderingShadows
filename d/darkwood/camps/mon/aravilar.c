#include <std.h>
#include "../elfisland1.h"

inherit "/std/npc.c";
create() {
   ::create();
   make_me();
   set("aggressive", "kill_evil");
   set_level(19);
   set_alignment(7);
   set_languages( ({ "elven" }) );
   command("speak elven");
   set_property("swarm",0);
   set_race("elf");
   set_hd(19,1);
   add_money("gold",random(100));
   set_body_type("human");
   set_size( 2 );
   set_random_act_db("aravilarrandom");
   set_random_act_chance(10);
   set_property("no attack", 1);
   set_hp(243);
   set_max_hp(243);
   set_exp(400);
   set_nwp("healing",10);
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
   if(query_hp() <243) {
   command("yell HELP!!");
   tell_room(ETO,"You see a guard rush in to help the clerk.");
   ob = new(MON+"elguard");
   ob->move(ETO);
   ob->set_stats("strength",18);
   ob->set_exp(3500);
   ob->force_me("block out");
   ob->force_me("protect aravilar");
   ob->force_me("protect aravilar");
   ob->force_me("protect aravilar");
   ob->force_me("yell I will protect our people!");
   killers = query_attackers();
   for(i=0;i<sizeof(killers);i++){
     ob->kill_ob(killers[i],1);
   }
   }
}

void make_me() {
   // switch(random(2)) {
      // case 0:
      set_name("aravilar");
      set_id( ({"aravilar","healer","calaudra","aravilar calaudra"}) );
      set_short("Aravilar Calaudra");
      set_long("Aravilar is an eldery looking male high elf. He has long jet black hair"+
        " that flows down to his mid back. His facial features are very sharp and angular,"+ 
        " common in most elves. He has no facial hair at all. His hands are smooth, even"+
        " after years of working with herbal medicine. He is busy at work, aiding the ill"+
        " and injured.");
      set_gender("male");
      // break;
      // case 1:
      // set_name("maranwe");
      // set_id( ({"maranwe","annare","healer","maranwe annare"}) );
      // set_short("Maranwe Annare");
      // set_long("Maranwe is a young elf, barely over one hundred years old. She has the"+
       // " typical dark hair and green eyes of high elves with the facial features to match."+
       // " She tends to the shop with Aravilar can not be around to do it himself. She looks"+
       // " ready willing to help the injured or ill.");
      // set_gender("female");
}
