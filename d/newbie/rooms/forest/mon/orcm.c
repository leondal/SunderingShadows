// orcm.c - Orc marauder for newbietown

#include <std.h>
#include "../../../newbie.h"
#include "../forest.h"

inherit "/std/monster";

int count;

create() {
   object ob;
   ::create();
   set_name("orc");
   set_id( ({ "orc", "marauder", "orc marauder" }) );
   set_race("orc");
   set_gender("male");
   set_short("Orc marauder");
   set_long( 
@STYX
By any civilized race's standards, this orc is ugly.  A snout resembles that of a wild boar, complete with tusks and almost pig-like ears sticking out from under matted stringy hair on his head.  With a generally humanoid body he walks upright, although stooped over and more ape-like.  Grey-green skin is covered with short coarse hair and he smells bad too.
STYX
   );
        set_body_type("human");
        set("aggressive",6);  /*Call_out on init causes attack.*/
        set_alignment(3);
        set_size(2);
        set_hd(5,2);
        set_hp(random(15)+45);
        set_overall_ac(10);
        set_stats("intelligence",6);
        set_stats("wisdom",6);
        set_stats("strength",18);
        set_stats("charisma",5);
        set_stats("dexterity",14);
        set_stats("constitution",14);
        set_max_hp(query_hp());
        new(CWEAP"battle_axe")->move(TO);
          command("wield axe");  		
        new(CARMOR"hide")->move(TO);
          command("wear hide");
        switch(random(3)) {
	   case 0:
        	new(CWEAP"club")->move(TO);
        	command("wield club");
        	new(CMISC"lantern")->move(TO);
        	new(CMISC"oil")->move(TO);
        	break;
	   case 1:
        	new(ARMOR"shieldcrude")->move(TO);
        	command("wear shield");
        	new(CMISC"torch")->move(TO);
        	break;
           case 2:
        	new(CWEAP"handaxe")->move(TO);
        	command("wield axe");
        	ob = new("/d/magic/scroll");
	        ob->set_spell(3);
        	ob->move(TO);
        	break;
        };
        add_money("gold",random(150)+50);        
        add_money("silver",random(200)+80);
        add_money("copper",random(20));
        set_exp(200);
        add_search_path("/cmds/fighter");
        set_property("swarm",1);
        set_achats(8, ({"%^BOLD%^%^RED%^The orc lets out a blood-curdling scream and charges toward you.", "%^BOLD%^%^RED%^The orc grunts as he swings his axe wildly."}) );
	set_emotes(2, ({"The ugly orc swings his axe at you menacingly.", "The vicious orc sniffs and pokes his axe at you." }) );
	set_monster_feats(({"parry"}));
}

void init() {
	::init();
	if(interactive(TP) && !wizardp(TP) && !TP->query_invis() ){
    	count=0;
   	   TO->force_me("say %^BOLD%^STOP!!! We want treasure!");
   		TO->force_me("say %^BOLD%^Take yours, haha!");
	   	call_out("do_kill",7,TP);
  	}
}

void do_kill(object targ){
    string who, str;
    if(objectp(targ) && present(targ,environment(TO))){
        count++;
        who = targ->query_name();
        switch (count) {
                case 1: 
          	        force_me("kill "+targ->query_name());
          	        force_me("parry");
          	        call_out("do_kill",5,targ);
                    break;
                case 2..8: 
                	TO->force_me("flash "+who);
                	targ->kill_ob(TO);
                	call_out("do_kill",5,targ);
                    break;
		default:  break;
        }
  }
}