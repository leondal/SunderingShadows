#include <std.h>
#include <daemons.h>
#include "../meadow.h"
inherit VENDOR;

int should_interact;

void create()
{
   ::create();
   set_name("farith");
   set_short("Farith, a halfling seamstress");
   set_id(({"farith","halfling","seamstress","tailor","halfling seamstress"}));
   set_long(
   "Farith is a cute little halfling seamstress. She has long brown hair"+
   " and dancing hazel eyes and seems ready to help you in any way she can."+
   " She is wearing a stylish skirt and top, but is totally barefoot, showing"+
   " off her very hairy feet. She is also rather short, barely over two feet"+
   " tall."
   );
   set_gender("female");
   set_race("halfling");
   set_body_type("halfling");
   set_alignment(1);
   set_hd(10,5);
   set_class("thief");
   set_mlevel("thief",10);
   set_overall_ac(0);
   set_exp(100);
   set_storage_room(ROOMS+"storage/tailor_storage");
   set_items_allowed("clothing");
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
      force_me("say I'm not going to serve you "+ob->query_race()+"!");
      return 0;
   }
   if(member_array(ob->query_name(),KILLING_D->query_evil_bounties()) != -1) {
      force_me("say I've heard of you and your evil deeds, there's no way"+
      " I'm going to serve you!");
      return 0;
   }
   if(member_array(ob->query_name(),KILLING_D->query_bounties()) != -1) {
      force_me("say Law breakers are only trouble, now please move on, I won't"+
      " help you.");
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

