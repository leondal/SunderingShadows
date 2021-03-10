#include <std.h>
#include "../elfisland1.h"
inherit VENDOR;

create() {
        ::create();
        make_me();
        set_race("elf");
        set_gender("male");
        set_alignment(7);
        set_hd(19,5);
        set_languages( ({ "elven" }) );
        command("speak elven");
        set_items_allowed("misc");
        set_max_hp(200);
        set("aggressive","kill_evil");
        set_property("swarm",0);
        set_hp(200);
        set_exp(10);
        set_storage_room(SROOM+"gs_storage");
        remove_std_db();
        set_db("miscvendors");
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
   ob->force_me("protect caldur");
   ob->force_me("protect caldur");
   ob->force_me("protect caldur");
   ob->force_me("yell I will protect our people!");
   killers = query_attackers();
   for(i=0;i<sizeof(killers);i++){
     ob->kill_ob(killers[i],1);
   }
   }
}

void make_me() {
   switch(random(2)) {
      case 0:
      set_name("caldur");
        set_short("Caldur Starsinger");
        set_id(({"caldur","starsinger","clerk","shopkeeper","shop keeper"}));
        set_long(
           "Caldur is one of the many elves that come to the market to sell"+
         " crafted goods. He makes his space on one of the wide tables set up"+
           " neatly with his products spaced out. He has friendly green eyes"+
           " and smile to go with it. He stands here waiting and hoping to make"+
           " a sale.");
      break;
      case 1:
      set_name("taurnil");
      set_short("Taurnil Annare");
      set_id(({"taurnil","annare","clerk","shopkeeper","shop keeper"}));
      set_long(
      "Taurnil is a young looking elf with piercing green eyes and dark black hair. He"+
      " stands here selling some of the goods crafted by Caldur Starsinger when Caldur"+
      " has business to attend to elsewhere.");
      }
}
