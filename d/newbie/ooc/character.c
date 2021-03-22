// /d/newbie/ooc/character.c

#include <std.h>

inherit "/std/npc.c";

create() {
	::create();
    	set_name("Riley");
        set_id(({"riley", "Riley", "human", "helper"}));
   	set_race("human");
      set_gender("male");
      set("short", "Riley, a player helper");
   	set("long","Riley is here to help you learn how to make your character memorable.  He will try to answer questions you may have but if you simply listen to what he says you will learn things you might not even think to ask about.  He will also point out some important things you need to do or consider in order to comply with the role-playing aspects of playing here in Sundering Shadows.");
      set_level(20);
		set_class("fighter");
      add_search_path("/cmds/fighter");
      set_body_type("human");
      set_hd(20,3);
      set_alignment(1);
      set_size(2);
      set_overall_ac(5);
      set_stats("intelligence",18);
      set_stats("wisdom",18);
      set_stats("strength",18);
      set_stats("charisma",10);
      set_stats("dexterity",10);
      set_stats("constitution",17);
      set_hp(random(25)+150);
      set_property("swarm",1);
      set_wielding_limbs( ({ "right hand", "left hand" }) );
      set_exp(5);
      remove_std_db();
}

void init(){
    ::init();
}

void kill_ob(object ob, int i) {
  new("/cmds/creator/_truce.c")->cmd_truce();
  return ;
}
