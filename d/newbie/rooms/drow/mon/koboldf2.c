// koboldf2.c - Kobold for the newbietown forest

#include <std.h>
#include "../../../newbie.h"
#include "../drownew.h"

inherit "/std/monster";

void kill_baddies(object targ);

void create() {
    ::create();
       set_name("kobold");
       set_id( ({ "kobold" }) );
       set_race("kobold");
       set_gender("male");
       set_short("red-eyed, smelly kobold");
       set_long(
@STYX
This ugly little creature has beady red eyes and two small horns that protrude from the top of its head.  Almost lizardlike in appearance with large pointy ears, it has dark rusty-brown scaly hide and a long hairless tail but stands upright on two legs.  Long skinny fingers end in sharp-looking and pointy fingernails that look more like animal claws.  It smells like something between a wet dog and stagnant water.  It carries a spear pointed your direction and pokes it toward you threateningly.
STYX
   );
        set_level(2);
        set_body_type("human");
	set("aggressive", "hate_types");
        set_alignment(6);
        set_size(1);
        set_hd(5,3);
        set_hp(65);
        set_overall_ac(8);
        set_stats("intelligence",6);
        set_stats("wisdom",9);
        set_stats("strength",17);
        set_stats("charisma",5);
        set_stats("dexterity",16);
        set_stats("constitution",14);
        set_max_hp(query_hp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
  	new(CWEAP"mspear")->move(TO);
          command("wield spear");
        if(random(5) == 0) {
        	new(STUFF"kobvest")->move(TO);
        	command("wear vest");
       	}
        if(random(7) < 3) {
	        new(MISC"gem")->move(TO);
       	}
        set_wimpy(4);
        add_money("gold",random(80)+30);
        add_money("silver",random(500));
        add_money("copper",random(300));
        set_exp(80);
	set_property("swarm",1);
        set_achats(5, ({"%^RED%^The kobold darts back and forth poking his spear at you.%^RESET%^", "%^RED%^The kobold's rat-like tail twitches as he dodges for position.%^RESET%^"}) );
	set_emotes(2, ({"The kobold tries to sharpen his spear on a rock.", 
	   "The kobold's rat-like tail twitches.", 
	   "The kobold points his spear at you.", 
	   "The kobold runs past and tries to trip you." }), 0);
    set_new_exp(1, "very low");
}

int hate_types(){
   if(wizardp(TP))return 1;
   if(TP->query_invis())return 1;
   if(!TO->query_invis()) kill_baddies(TP);
}

void kill_baddies(object targ) {
   string race;
   race = (string)targ->query_race();
   if( race == "ogre-mage" || race == "ogre" || race == "wemic" || race == "firbolg" || race == "voadkyn" || race == "half-ogre");
        force_me("say %^BOLD%^%^RED%^EEIIIAAEEE!!!  Kill da BIG mean baddie "+race+"!!");
        force_me("say Dey kill my momma!!");
        force_me("kill "+targ->query_name());
        return;
}
