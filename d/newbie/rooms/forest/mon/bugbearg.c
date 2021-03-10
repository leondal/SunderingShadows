// /d/newbie/rooms/forest/mon/bugbearg.c Bugbear guard

#include <std.h>
#include "../../../newbie.h"
#include "../forest.h"

inherit "std/monster";

create() {
    ::create();
    set_name("bugbear");
    set_id(({"bugbear", "guard", "bugbear guard"}));
    set_race("bugbear");
    set_gender("male");
    set_short("Bugbear guard");
   set_long("Unlike their smaller goblin cousins, bugbears are larger than humans at around 7 ft. tall and very muscular.  More animal than human in appearance, their nose is much like a bear's and they have a keen sense of smell.  Their teeth are much like animal fangs.  Large, wedge shaped ears stick out high on the side of their head above bushy reddish-brown hair.  Their skin is a yellowish brown and they are generally hairy all over.  Dressed in scraps of armor, they look like formidable opponents for the inexperienced.");
        set_level(3);
	set_class("fighter");
        add_search_path("/cmds/fighter");
        set_body_type("human");
        set_hd(3,3);
        set_alignment(9);
        set_size(2); /* should be large ?? deku & laerad have them 2 though */
        set_overall_ac(6);
        set_stats("intelligence",8);
        set_stats("wisdom",8);
        set_stats("strength",20);
        set_stats("charisma",3);
        set_stats("dexterity",10);
        set_stats("constitution",17);
        set_hp(35);
        set_max_hp(query_hp());
        set_property("swarm",1);
        set_wielding_limbs( ({ "right hand", "left hand" }) );
	new(CWEAP"two_hand_sword")->move(TO);
        command("wield sword");
        set_exp(150);
        add_money("gold",random(50)+100);
        add_money("silver",random(200)+70);
        add_money("copper",random(500));
        set_emotes(2, ({"The bugbear grunts as he sits down near the fire and pokes at it.%^RESET%^", "%^RED%^The bugbear pokes a stick into the kettle and spears a piece of stringy meat to chew on.%^RESET%^", "The bugbear stands between you and the rest of the cave." }) );
	set_achats(5, ({"%^BOLD%^The bugbear lets out a blood-curdling scream and tries to throw you out.", "%^YELLOW%^The bugbear tries to knock you into the fire!!", "%^BOLD%^The bugbear snarls and growls savagely." }) );
}

void init(){
    ::init();
    command("block southeast");
    if(!TP->query_invis())
       tell_room(ETO,"%^CYAN%^Bugbear guard steps in front of you and growls menacingly.");
}
