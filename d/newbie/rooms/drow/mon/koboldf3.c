// koboldf3.c - Kobold for the newbietown forest

#include <std.h>
#include "../../../newbie.h"
#include "../drownew.h"

inherit "/std/monster";

void create() 
{
    ::create();
    set_name("kobold");
    set_id( ({ "kobold" }) );
    set_race("kobold");
    set_gender("female");
    set_short("red-eyed, smelly kobold");
    set_long(
@STYX
This ugly little creature has beady red eyes and two small horns that protrude from the top of its head.  Almost lizardlike in appearance with large pointy ears, she has dark rusty-brown scaly hide and a long hairless tail but stands upright on two legs.  Long skinny fingers end in sharp-looking and pointy fingernails that look more like animal claws.  She smells like something between a wet dog and stagnant water.  
STYX
   );
    set_class("fighter");
    set_class("thief");
    set_mlevel("fighter",2);
    set_mlevel("thief",2);
    set_body_type("human");
    set("aggressive", "kill_baddies");
    set_alignment(6);
    set_size(1);
    set_hd(5,2);
    set_hp(random(20)+45);
    set_overall_ac(8);
    set_stats("intelligence",6);
    set_stats("wisdom",6);
    set_stats("strength",17);
    set_stats("charisma",5);
    set_stats("dexterity",16);
    set_stats("constitution",14);
    set_max_hp(query_hp());
    set_wielding_limbs( ({ "right hand", "left hand" }) );
	new(CWEAP"mspear")->move(TO);
    command("wield spear");
    if(random(5) == 0) 
    {
        new(STUFF"kobvest")->move(TO);
        command("wear vest");
    }
    if(random(5) == 0) 
    {
        new(CMISC"fishing_rod")->move(TO);
        new(CMISC"fish")->move(TO);
    }
    if(random(5) < 2) 
    {
        new(CMISC"sack")->move(TO);
        new(CMISC"climb_tool")->move(TO);
        new(CMISC"rope")->move(TO);
        command("put tools in sack");
        command("put rope in sack");
    }
    set_wimpy(4);
    add_money("electrum",random(50)+20);
    add_money("silver",random(50));
    add_money("copper",random(20));
    set_exp(60);
    add_search_path("/cmds/thief");
    set_thief_skill("pick pockets", 30);
    toggle_steal();
    set_property("swarm",1);
    set_achats(5, ({"%^RED%^The kobold darts back and forth.%^RESET%^", "%^RED%^The kobold's tail twitches as he dodges for position.%^RESET%^"}) );
	set_emotes(2, ({"The kobold pokes one of the others and points at you.", 
	   "The kobold's tail twitches while he waves his spear at you.", 
	   "The kobold's beady red eyes nearly glow with hatred.", 
	   "The kobold barks out some gibberish.", 
	}), 0);
    set_new_exp(1, "very low");
}

int kill_baddies() {
   string race;
   race = (string)TP->query_race();
   if( race == "ogre-mage" || race == "ogre" || race == "wemic" || race == "firbolg" || race == "voadkyn" || race == "half-ogre") {
        force_me("say %^BOLD%^%^RED%^WHOOP WHOOP!!!  Kill da baddie!!");
        force_me("say Kill "+race+" afore it kill us!!");
        force_me("kill "+TPQN);
        return 1;
   }
   return 1;
}
