#include <std.h>
#include "../meadow.h"
#include <daemons.h>
inherit VENDOR;

int should_interact;

void create() {
   ::create();
   set_name("Meriago");
   set_short("Meriago, a halfling trader");
   set_id(({"trader","meriago","halfling","halfling trader","vendor"}));
   set_long(
   "Meriago is a simple halfling who seems to be happy living in his hut"+
   " next to a pond and trading with those who might pass by. He has brown"+
   " hair and clear blue eyes and is just over two and a half feet in height,"+
   " which is tall by halfling standards. He has a simple pair of sandals on"+
   " and you can see his very hairy feet. His clothing is simple and consists"+
   " of a green tunic and some brown leggings. He seems like a friendly"+
   " person."
   );
   set_gender("male");
   set_race("halfling");
   set_body_type("halfling");
   set_hd(15,8);
   set_alignment(1);
   set_class("thief");
   set_mlevel("thief",15);
   set_exp(100);
   set_items_allowed("clothing");
   set_storage_room(ROOMS+"storage/general_storage");
}

int should_interact(object ob)
{
    string race;
    object shape;
    race = ob->query_race();
    if(objectp(shape = ob->query_property("shapeshifted"))) race = (string)shape->query_shape_race();
    if(objectp(shape = ob->query_property("altered"))) race = (string)shape->query_shape_race();
//   if(!::should_interact(ob)) return 0;
   if(race == "drow" || race == "ogre" || race == "bugbear" || race == "kobold" || race == "goblin" || race == "orc" || race == "half-orc" || race == "half-ogre" || race == "half-drow" || race == "hobgoblin" || race == "gnoll" || race == "ogre-mage" || race == "yuan-ti" || race == "minotaur") {
      force_me("say I'm not going to serve you "+ob->query_race()+", now get"+
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

