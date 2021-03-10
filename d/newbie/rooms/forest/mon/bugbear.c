// /d/newbie/rooms/forest/mon/bugbear.c

#include <std.h>
#include "../../../newbie.h"

inherit "std/monster";

create() {
    ::create();
    set_name("bugbear");
    set_id(({"bugbear"}));
    set_race("bugbear");
    set_gender("male");
    set_short("Bugbear");
   set_long("Unlike their smaller goblin cousins, bugbears are larger than humans at around 7 ft. tall and very muscular.  More animal than human in appearance, their nose is much like a bear's and they have a keen sense of smell.  Their teeth are much like animal fangs.  Large, wedge shaped ears stick out high on the side of their head above bushy reddish-brown hair.  Their skin is a yellowish brown and they are generally hairy all over.  Dressed in scraps of armor, they look like formidable opponents for the inexperienced.");
        set_level(2);
        set_body_type("human");
        set("aggressive",10);
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
        set_hp(random(25)+10);
        set_max_hp(query_hp());
        set_property("swarm",1);
        set_wielding_limbs( ({ "right hand", "left hand" }) );
	new(CWEAP"club")->move(TO);
          command("wield club");
        set_exp(120);
        add_money("gold",random(80)+80);
        add_money("silver",random(200)+170);
        add_money("copper",random(500));
        set_emotes(2, ({"The bugbear grunts as he sits down heavily.", "The bugbear rummages around in a pile of junk.", "The bugbear grunts and waves his weapon menacingly."}) );
	set_achats(5, ({"%^BOLD%^The bugbear lets out a blood-curdling scream and swings wildly at you.", "%^YELLOW%^The bugbear tries to knock you against the wall!!", "%^BOLD%^The bugbear snarls and growls savagely." }) );
}