// /d/newbie/rooms/hilll/mon/halflingf.c  Halfling female for tents

#include <std.h>
#include "../../../newbie.h"

inherit "std/monster";

create() {
	::create();
    	set_name("halfling");
   	set_id(({"halfling", "hairfoot", "hairfoot halfling" }));
   	set_race("halfling");
      set_gender("female");
      set("short", "Hairfoot halfling female");
   	set("long","About the size of a dwarf but more nimble, this halfling female is also distinguished from dwarves by hairy feet and warts typical of the most common type of halfling.  She is wearing various trinkets she may have made or seems to be in the process of finishing.");
      set_level(6);
		set_class("thief");
      add_search_path("/cmds/thief");
      set_body_type("human");
      set_hd(6,3);
      set_alignment(1);
      set_size(1);
      set_overall_ac(8);
      set_stats("intelligence",12);
      set_stats("wisdom",12);
      set_stats("strength",16);
      set_stats("charisma",10);
      set_stats("dexterity",17);
      set_stats("constitution",17);
      set_hp(random(15)+50);
      set_property("swarm",1);
      set("aggressive",3);
      set_wielding_limbs( ({ "right hand", "left hand" }) );
  		new(CMISC"spouch")->move(TO);
        command("wear pouch");
  		new(MISC"gem")->move(TO);
  		new(FOREST"stuff/berries")->move(TO);
      set_exp(50);
      set_wimpy(30);
      add_money("gold",random(20)+10);
      add_money("silver",random(100)+70);
      add_money("copper",random(500));
      set_emotes(1, ({"The little halfling deftly sews some beads onto a decorative sash.", "The halfling sorts and polishes some beads.", "The halfling chips at a gem.", "The halfling female sets the craftwork aside and bounces around you curiously."}), 0);
		set_achats(4, ({"%^BOLD%^The halfling female screams loudly and tries to hide from the attack.", "%^BOLD%^The halfling glances furtively around for a way to escape.", "%^BOLD%^The halfling screams angrily as she tries to dodge your attacks.", "%^RED%^You realize you're doing something evil trying to kill a defenseless little halfling." }) );
}

void init(){
    ::init();
	 force_me("tent");
}
