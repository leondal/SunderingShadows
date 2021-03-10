// /d/newbie/rooms/forest/mon/bugbearch.c - bugbear chieftain

#include <std.h>
#include "../../../newbie.h"

inherit "std/monster";

create() {
    ::create();
    set_name("bugbear");
    set_id(({"bugbear", "chief"}));
    set_race("bugbear");
    set_gender("male");
    set_short("Bugbear chieftain");
    set_long("This bugbear is even larger and more savage than most, probably the reason he's become a leader.  The muscles on his hairy arms bulge as he grips the rather large sword he carries.  His clothing and weapons are blood-stained and he looks quite dangerous.");
    set_level(5);
    set_class("fighter");
    set_body_type("human");
    set("aggressive",10);
    set_hd(5,3);
    set_alignment(9);
    set_size(2); /* should be large ?? deku, laerad & players are 2 though */
        set_overall_ac(6);
        set_stats("intelligence",8);
        set_stats("wisdom",8);
        set_stats("strength",20);
        set_stats("charisma",3);
        set_stats("dexterity",10);
        set_stats("constitution",17);
        set_hp(random(15)+35);
        set_max_hp(query_hp());
        set_property("swarm",1);
        set_wielding_limbs( ({ "right hand", "left hand" }) );
	new(CWEAP"bastard")->move(TO);
          command("wield sword");
        new(CARMOR"buckler")->move(TO);
          command("wear shield");
        new(CARMOR"robe")->move(TO);
          command("wear robe");
        new(CMISC"spouch")->move(TO);
          command("wear pouch");
        new(MISC"gem")->move(TO);
          command("put gem in pouch");
        new(MISC"gem")->move(TO);
	  command("put gem in pouch");
        set_exp(220);
        add_money("gold",random(100)+250);
        add_money("silver",random(200)+270);
        add_money("copper",random(100));
	set_achats(5, ({"%^BOLD%^The bugbear lets out a blood-curdling scream and swings wildly at you.", "%^BOLD%^The bugbear snarls and growls savagely." }) ); 
}
