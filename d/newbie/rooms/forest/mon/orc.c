// orcbandit.c - Orc bandit for newbietown

#include <std.h>
#include "../../../newbie.h"
#include "../forest.h"

inherit "/std/monster";

create() {
    ::create();
       set_name("orc");
       set_id( ({ "orc", "bandit", "orc bandit" }) );
       set_race("orc");
       set_gender("male");
       set_short("Orc bandit");
       set_long( 
@STYX
By any civilized races standards, this orc is ugly.  A snout resembles that of a wild boar, complete with tusks and almost pig-like ears sticking out from under matted stringy hair on his head.  With a generally humanoid body he walks upright, although stooped over and more ape-like.  Grey-green skin is covered with short coarse hair and he smells bad too.
STYX
   );
      set_body_type("human");
      set("aggressive",8); 
      set_alignment(3);
      set_size(2);
      set_hd(5,2);
      set_class("thief");
      set_mlevel("thief", 5);
      set_hp(random(15)+35);
      set_overall_ac(10);
      set_stats("intelligence",6);
      set_stats("wisdom",6);
      set_stats("strength",18);
      set_stats("charisma",5);
      set_stats("dexterity",16);
      set_stats("constitution",14);
      set_max_hp(query_hp());
      new(CWEAP"battle_axe")->move(TO);
      	command("wield axe");  		
      new(CARMOR"hide")->move(TO);
      	command("wear hide");
      switch(random(3)) {
          case 0:
        	new(CWEAP"handaxe")->move(TO);
        	command("wield axe");
        	new(CMISC"bullseye")->move(TO);
        	break;
	  case 1:
        	new(ARMOR"shieldcrude")->move(TO);
        	command("wear shield");
        	new(CMISC"oil")->move(TO);
        	new(CMISC"rope")->move(TO);
        	break;
          case 2:
        	new(CMISC"beacon")->move(TO);
        	new(CMISC"fish")->move(TO);
        	break;
        };
        add_money("gold",random(20)+20);        
        add_money("silver",random(50));
        add_money("copper",random(20));
        set_exp(180);
        add_search_path("/cmds/thief");
        set_thief_skill("pick pockets", 60);
        toggle_steal();
        set_property("swarm",1);
        set_achats(2, ({"%^BOLD%^%^RED%^The orc lets out a blood-curdling scream and charges toward you.", "%^BOLD%^%^RED%^The orc grunts as he swings his axe wildly."}) );
	set_emotes(2, ({"The ugly orc swings his axe at you menacingly.", "The vicious orc sniffs and pokes his axe at you." }) );
}