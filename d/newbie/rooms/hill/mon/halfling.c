// /d/newbie/rooms/hilll/mon/halfling.c  Halfling male for tents

#include <std.h>
#include "../../../newbie.h"

inherit "std/monster";

create() {
	::create();
    	set_name("halfling");
   	set_id(({"halfling", "hairfoot", "hairfoot halfling"}));
   	set_race("halfling");
      set_gender("male");
      set("short", "Hairfoot halfling male");
   	set("long","About the size of a dwarf but more nimble, this halfling male is also distinguished from dwarves by hairy feet and warts typical of the most common type of halfling.  He has fresh blisters on his hands, possibly from helping in the mines.");
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
  		new(CWEAP"dagger")->move(TO);
		  command("wield dagger");
  		new(FOREST"stuff/berries")->move(TO);
      set_exp(50);
      set_wimpy(30);
      add_money("gold",random(20)+10);
      add_money("silver",random(100)+70);
      add_money("copper",random(500));
      set_emotes(1, ({"The little halfling rubs his blisters and sits down to rest.", "The halfling pokes around in his pouch and pulls out some berries to eat.", "The halfling polishes and sharpens his dagger.", "The halfling checks the coins in his pocket and eyes you appraisingly.", "The halfling rubs a scar on his arm and mumbles some curses about hobgoblins.", "%^BOLD%^The halfling peers out the tent flap and mutters something about hobgoblins."}), 0);
		set_achats(4, ({"%^BOLD%^%^BLUE%^The halfling scrambles around trying to dodge your blows.", "%^BOLD%^%^BLUE%^The halfling glances furtively around for a way to escape.", "%^BOLD%^%^RED%^The halfling curses your evil soul as he fights for his life.", "%^BOLD%^%^BLUE%^The halfling takes a swipe at you with his dagger, desperately trying to defend himself." }) );
}

void init(){
    ::init();
	 force_me("tent");
}