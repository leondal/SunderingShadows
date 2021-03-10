// orcf.c - Orc fighter for newbietown

#include <std.h>
#include "../../../newbie.h"
#include "../forest.h"

inherit "/std/monster";

int count;

create() {
   ::create();
   set_name("orc");
   set_id( ({ "orc", "fighter", "orc fighter" }) );
   set_race("orc");
   set_gender("male");
   set_short("Orc fighter");
   set_long( 
@STYX
By any civilized race's standards, this orc is ugly.  A snout resembles that of a wild boar, complete with tusks and almost pig-like ears sticking out from under matted stringy hair on his head.  With a generally humanoid body he walks upright, although stooped over and more ape-like.  Grey-green skin is covered with short coarse hair and he smells bad too.
STYX
   );
        set_body_type("human");
        set("aggressive",2); /*Call_out on init causes attack.*/
        set_alignment(3);
        set_size(2);
        set_hd(4,2);
        set_hp(random(15)+35);
        set_overall_ac(10);
        set_stats("intelligence",6);
        set_stats("wisdom",6);
        set_stats("strength",17);
        set_stats("charisma",5);
        set_stats("dexterity",14);
        set_stats("constitution",16);
        set_max_hp(query_hp());
	new(CWEAP"bardiche")->move(TO);
          command("wield bardiche");  		
        new(CARMOR"hide")->move(TO);
          command("wear hide");
        switch(random(4)) {
           case 0:
        	new(CMISC"bait")->move(TO);
          	new(CMISC"flint")->move(TO);
	       	break;
	   case 1:
        	new(CMISC"sack")->move(TO);
        	new(CMISC"wood")->move(TO);
        	new(CMISC"flint")->move(TO);
	        new(MISC"gem")->move(TO);
         	command("put wood in sack");
        	command("put flint in sack");
        	command("put gem in sack");
        	break;
           case 2:
        	new(CMISC"pouch")->move(TO);
        	new(CMISC"climb_tool")->move(TO);
        	command("put tools in pouch");
                command("wear pouch");
        	break;
           case 3:
        	new(CMISC"bait")->move(TO);
        	new(CMISC"bait")->move(TO);
        	new(CMISC"fishing_rod")->move(TO);
        	new(STUFF"centdagger")->move(TO);
        	break;
        };
        add_money("gold",random(100)+50);        
        add_money("silver",random(200)+80);
        add_money("copper",random(50)+100);
        set_exp(180);
        add_search_path("/cmds/fighter");
        set_property("swarm",1);
        set_achats(4, ({"%^ORANGE%^The orc fighter takes a wild swing with the bardiche.", 
	   "%^BOLD%^%^RED%^The orc fighter grunts as he swings the bardiche at your knees!",
	   "%^BOLD%^%^RED%^The orc takes a mighty swing with the bardiche and the axe-like head barely misses cutting your arm off!"
	}) );
	set_emotes(2, ({ "The orc rests the shaft of the bardiche on the ground and licks some blood from the blade.", 
	  "The orc sniffs and pokes the axe-end of the bardiche at you." 
	}) );
	set_monster_feats(({"parry"}));
}

void init() {
	::init();
	if(interactive(TP) && !wizardp(TP) && !TP->query_invis() ){
    	count=0;
   	    TO->force_me("say %^MAGENTA%^Food and treasure!");
	   	call_out("do_kill",8,TP);
  	}
}

void do_kill(object targ){
    string who, str;
    if(objectp(targ) && present(targ,ETO)) {
        count++;
        who = targ->query_name();
        switch (count) {
                case 1: 
          	        force_me("kill "+targ->query_name());
          	        force_me("parry");
          	        call_out("do_kill",7,targ);
                    break;
                case 2..6: 
        	       	TO->force_me("flash "+who);
//                	force_me("say %^BOLD%^%^GREEN%^Test - trying to flash!");
                	targ->kill_ob(TO);
                	call_out("do_kill",7,targ);
                    break;
                case 7:
                    	TO->force_me("rush "+who);
                	targ->kill_ob(TO);
                    	call_out("do_kill",20,targ);
                    break;
		case 8..15: 
                	TO->force_me("flash "+who);
//                	force_me("say %^BOLD%^%^GREEN%^Test - trying to flash!");
                	targ->kill_ob(TO);
                	call_out("do_kill",5,targ);
                    break;
                default:break;
        }
  }
}