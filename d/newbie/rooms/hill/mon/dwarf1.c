// /d/newbie/rooms/hilll/mon/dwarf.c Dwarf for tents

#include <std.h>
#include "../../../newbie.h"

inherit "std/monster";

//object ob;

create() {
	::create();
    	set_name("dwarf");
   	set_id(({"dwarf"}));
   	set_race("dwarf");
      set_gender("male");
      set("short", "Dwarven craftsman");
   	set("long","Short and stocky, this guy is also quite muscular.  His cheeks are ruddy and his skin a rugged-looking natural deep brown even without help from the sun.  His brown hair is long, including his well-kept full beard and mustache.  Dressed in sturdy earth-tone clothing, he looks rather dour.");
      set_level(6);
		set_class("fighter");
      add_search_path("/cmds/fighter");
      set_body_type("human");
      set_hd(6,3);
      set_alignment(1);
      set_size(1);
      set_overall_ac(8);
      set_stats("intelligence",12);
      set_stats("wisdom",12);
      set_stats("strength",18);
      set_stats("charisma",10);
      set_stats("dexterity",10);
      set_stats("constitution",17);
      set_hp(random(15)+50);
      set_property("swarm",1);
      set_wielding_limbs( ({ "right hand", "left hand" }) );
  		new(CWEAP"warhammer")->move(TO);
        command("wield hammer");
      set_exp(60);
      add_money("gold",random(20)+10);
      add_money("silver",random(200)+70);
      add_money("copper",random(500));
      set_emotes(1, ({"The dour dwarf grumbles as he sits down tiredly.", "The dwarf polishes his warhammer.", "The dwarf tugs at his long beard thoughtfully.", "%^CYAN%^The dour dwarf sits down on a cot and grumbles to himself.","The dwarf wipes some blood from his warhammer and curses about hobgoblins under his breath."}) );
		set_achats(4, ({"%^BOLD%^The dwarf glares at you defiantly as he fights for his life.", "%^BOLD%^The dour dwarf fights fiercely for his life.", "%^BOLD%^The dwarf swings his warhammer fiercely trying to defend himself." }) );
}

void init(){
    ::init();
	 force_me("tent");
}
