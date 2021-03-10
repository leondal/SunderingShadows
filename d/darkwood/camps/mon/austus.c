#include <std.h>
#include "../elfisland1.h"

inherit BARKEEP;

void create() {
   ::create();
   set_name("austus");
   set_short("Austus Holimion");
   set_id( ({"austus","holimion","baker","elf"}) );
   set_long(
       "Austus is the baker and owner of this cafe. He gets up early every"+
       " morning and bakes fresh elven waybread and an assortment of pies."+
       " He also serves a large array of drinks from tea to some fine elven"+
       " wine. You can tell by the ever present smile on his face, that he"+
       " loves his job."
   );
   set_race("elf");
   set_body_type("elf");
   set_gender("male");
   set_hd(19,1);
   set("aggressive","kill_evil");
   add_money("gold",random(100));
   set_alignment(4);
   set_max_hp(245);
   set_languages( ({ "elven" }) );
   command("speak elven");
   set_hp(245);
   set_exp(10);
   remove_std_db();
   set_random_act_db("austusrandom");
   set_random_act_chance(5);
   set_currency("gold");
   set_property("swarm",0);
   set_menu(
      ({"water","ice tea","lemonade","herbal tea","feywine","elverquisst",
        "cucumber salad","fruit cup","elven waybread","peach cobbler",
        "slice of cherry pie"}),
      ({"water","soft drink","soft drink","soft drink","alcoholic","alcoholic",
        "food","food","food","food","food"}),
      ({1, 3, 3, 5, 75, 150, 3, 3, 5, 4, 7})
    );
    set_my_mess(
    ({
       "You drink a glass of water.",
      "The cool refreshing taste of the ice tea feels your throat.",
       "Your lips pucker from the juice apparently made from real lemons.",
       "The herbal tea goes down smooth and relaxes your senses.",
       "You drink the feywine and feel an almost magical, blissful peace wash"+
       " over you as your skin starts to tingle all over. The glass almost slips"+
       " from your hands as you hear a faerie giggling in your ear. You set the"+
       " glass down, letting the wine take full effect.",
       "With each sip of the magicaly distilled ruby colored drink you taste the full"+
       " effect of a different fruit. As the smooth drink runs down your throat you"+
       " almost feel like you are slipping from your body and becomming weightless.",
       "You eat the salad and feel full of energy.",
       "The combination of fruits makes for a tasty snack.",
       "You bite into the elven waybread and enjoy the filling taste of fresh cooked bread.",
       "You savor the sweetness of the peach cobbler.",
       "The slice of pie is definately made from fresh cherries.",
    })
    );
    set_your_mess(
    ({
        "drinks a glass of water.",
        "enjoys glass of ice tea.",
        "puckers up after drinking the lemonade.",
        "sighs softly after a cup of herbal tea.",
        "is overcome with an expression of peace and smiles softly.",
        "gets a distant look in the eyes while enjoying the Elverquisst.",
         "looks energetic after eating the salad.",
        "looks pleased with the fresh fruit.",
        "takes delight in the smell of the bread before eating it all.",
        "eats all the peach cobbler and looks pleased.",
         "scarfs down the entire slice of pie.",
    })
    );
    set_menu_short(
    ({
       "A glass of water",
       "A glass of ice tea",
       "A glass of lemonade",
       "A cup of herbal tea",
       "A glass of Feywine",
       "A glass of Elverquisst",
       "A bowl of salad",
       "A cup of cut fruit",
       "A loaf of elven waybread",
       "A cup of peach cobbler",
       "A slice of cherry pie",
    })
    );
    set_menu_long(
    ({
       "This is a tall glass of water.",
       "This is a nice tall glass of ice tea.",
       "This is cold glass of lemonade.",
       "This is a cup of hot herbal tea.",
       "The feywine comes up the halfway mark in this tall wine glass.",
       "This is wine glass, filled with a ruby colored substance.",
       "This is a bowl of salad, with extra cucumbers.",
       "This is a bowl of fruits that have been cut into cubes.",
       "This is a loaf of freshy baked elven waybread.",
       "This is a cup of recently made peach cobbler.",
       "This is a slice of pie that is over running with cherries.",
    })
    );
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
   if(query_hp() < 245) {
   command("yell HELP!!");
   tell_room(ETO,"You see a guard rush in to help the clerk.");
   ob = new(MON+"elguard");
   ob->move(ETO);
   ob->set_stats("strength",18);
   ob->set_exp(3500);
   ob->force_me("block out");
   ob->force_me("protect austus");
   ob->force_me("protect austus");
   ob->force_me("protect austus");
   ob->force_me("yell I will protect our people!");
   killers = query_attackers();
   for(i=0;i<sizeof(killers);i++){
      ob->kill_ob(killers[i],1);
   }
   }
}
