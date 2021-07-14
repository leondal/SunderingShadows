#include <std.h>
#include <daemons.h>
#include "../meadow.h"
inherit VENDOR;

int should_interact;

void create() {
   ::create();
   set_name("Periodo");
   set_short("Periodo, a halfling crafter");
   set_nwp("hunting", 10);
   set_nwp("forage", 10);
   set_nwp("skinning", 10);
   set_id(({"vendor","periodo","halfling","crafter","halfling crafter"}));
   set_long(
   "Periodo is obviously a tallfellow since he reaches just over four feet"+
   " in height. His hair is blonde and his eyes are a steel-blue shade."+
   " He is wearing boots, some tan pants and a dark green shirt. He seems"+
   " like a pleasant enough sort, if a little bit distant. He obviously"+
   " keeps to himself a lot in this secluded cabin, but seems interested"+
   " in trading his wares to those who might come and visit him."
   );
   set_gender("male");
   set_race("halfling");
   set_body_type("halfling");
   set_hd(20,5);
   set_alignment(1);
   set_class("ranger");
   set_mlevel("ranger",20);
   set_exp(100);
   set_items_allowed("all");
   set_storage_room(ROOMS+"storage/craft_storage");
}

int should_interact(object ob) {
    string race;
    object shape;
    race = ob->query_race();
    if(objectp(shape = ob->query_property("shapeshifted"))) race = (string)shape->query_shape_race();
    if(objectp(shape = ob->query_property("altered"))) race = (string)shape->query_shape_race();
//   if(!::should_interact(ob)) return 0;
   if(race == "drow" || race == "ogre" || race == "bugbear" || race == "kobold" || race == "goblin" || race == "orc" || race == "half-orc" || race == "half-ogre" || race == "half-drow" || race == "hobgoblin" || race == "gnoll" || race == "ogre-mage" || race == "yuan-ti" || race == "minotaur") {
      force_me("say I'm not going to serve you "+race+", now get"+
      " out of here!");
      return 0;
   }
   if(member_array(ob->query_name(),KILLING_D->query_evil_bounties()) != -1) {
      force_me("say I've heard of you and your evil deeds, there's no way"+
      " I'm going to trade with you!");
      return 0;
   }
   if(member_array(ob->query_name(),KILLING_D->query_bounties()) != -1) {
      force_me("say Law breakers are only trouble, now please move on, I"+
      " won't trade with you.");
      return 0;
   }
   return 1;
}

/*void heart_beat() {
    object *attackers;
    ::heart_beat();
    
    attackers = (object *)this_player()->query_attackers();
    if(attackers){
        tell_room(ETP,"%^BOLD%^%^CYAN%^The halfling grabs a small orb, smashing it and creating a huge cloud of smoke! When it clears, the halfling is nowhere to be found.%^RESET%^");
        TO->move("/d/shadowgate/void.c");
        TO->remove();
        return;
    }
}*/

