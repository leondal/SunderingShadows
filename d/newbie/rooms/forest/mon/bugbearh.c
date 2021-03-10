// /d/newbie/rooms/forest/mon/bugbearh.c  Bugbear, hungry

#include <std.h>
#include "../../../newbie.h"
#include "../forest.h"

inherit "std/monster";

void kill_types(object targ);

create() {
    ::create();
        set_name("bugbear");
	set_id(({"bugbear"}));
	set_race("bugbear");
        set_gender("male");
        set_short("Hungry bugbear");
   set_long("Unlike their smaller goblin cousins, bugbears are larger than humans at around 7 ft. tall and very muscular.  More animal than human in appearance, their nose is much like a bear's and they have a keen sense of smell.  Their teeth are much like animal fangs.  Large, wedge shaped ears stick out high on the side of their head above bushy reddish-brown hair.  Their skin is a yellowish brown and they are generally hairy all over.  Dressed in scraps of armor, they look like formidable opponents for the inexperienced.");
        set_level(3);
	set_class("fighter");
        add_search_path("/cmds/fighter");
        set_body_type("human");
        set("aggressive","food_types");
        set_hd(3,3);
        set_alignment(9);
        set_size(2); /* should be large ?? deku & laerad have them 2 though */
        set_overall_ac(6);
        set_stats("intelligence",8);
        set_stats("wisdom",8);
        set_stats("strength",19);
        set_stats("charisma",3);
        set_stats("dexterity",10);
        set_stats("constitution",17);
        set_hp(random(10)+30);
        set_max_hp(query_hp());
        set_property("swarm",1);
        set_wielding_limbs( ({ "right hand", "left hand" }) );
	new(CWEAP"club")->move(TO);
        command("wield club");
        new(CMISC"spouch")->move(TO);
        command("wear pouch");
        new(MISC"gem")->move(TO);
        command("put gem in pouch");
        new(MISC"gem")->move(TO);
        command("put gem in pouch");
        set_exp(150);
        add_money("gold",random(100)+150);
        add_money("silver",random(400)+50);
        add_money("copper",random(500));
        set_emotes(2, ({"%^RED%^The bugbear pokes at a pile of bones and growls hungrily.", 
	   "%^ORANGE%^The bugbear grunts and sits down on one of the piles of leaves.", 
	   "The bugbear looks you over and drools disgustingly."}) );
	set_achats(5, ({"%^BOLD%^The bugbear lets out a blood-curdling scream and swings wildly at you.", 
	   "%^YELLOW%^The bugbear tries to back you into a corner!!", 
	   "%^BOLD%^The bugbear snarls and growls savagely." }) );
}

int food_types(){
if(wizardp(TP))return 1;
if(TP->query_invis())return 1;
if(!TO->query_invis()) kill_types(TP);
}

void kill_types(object targ) {
   string race;
   race = targ->query_race();
   if ( race == "kobold" || race == "goblin" || race == "hobgoblin" || race == "dwarf" || race == "halfling"); {
        force_me("say %^CYAN%^FOOOD!!  No more hungry!!");
        force_me("say %^CYAN%^You make good stew after me smash you little "+race+"!!");
        force_me("kill "+targ->query_name());
        return;
    }
}