// hobgob.c - Hobgoblin for newbietown
//Added fighter feats - Octothorpe 7/7/10

#include <std.h>
#include "../../../newbie.h"
#include "../drownew.h"

inherit "/std/monster";

int count;

void create() {
    ::create();
    set_name("hobgoblin");
    set_id(({"hobgoblin"}));
    set_race("hobgoblin");
    set_gender("male");
    set_short("Hobgoblin");
    set_long("%^RESET%^This barbaric looking humanoid is over 6 ft. tall with a very rugged, stocky build.  His hairy hide is a dark reddish-brown but his flattened nose has a %^BLUE%^bluish tint to the wide, thick nostrils%^RESET%^.  Large, pointed ears stick out from the side of  wide, somewhat flattened face.  Yellow canine-type teeth jut upward from the lower jaw.");
    set_level(5);
    set_class("fighter");
    add_search_path("/cmds/fighter");
    set_body_type("human");
    set("aggressive", 12);
    set_hd(5,2);
    set_alignment(3);
    set_size(2);
    set_overall_ac(7);
    set_stats("intelligence",10);
    set_stats("wisdom",8);
    set_stats("strength",17);
    set_stats("charisma",5);
    set_stats("dexterity",10);
    set_stats("constitution",17);
    set_hp(random(15)+30);
    set_property("swarm",1);
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    new("/d/common/obj/weapon/handaxe")->move(TO);
      command("wield axe");
    set_exp(160);
    add_money("gold",random(110)+150);
    add_money("silver",random(300)+110);
    add_money("copper",random(800));
    set_emotes(1, ({"%^BLUE%^The burly, crude hobgoblin sniffs at you with his bluish flattened nose.", 
	"%^BLUE%^The hobgoblin seems to be sizing you up and snarls menacingly.", 
	"%^BLUE%^The hobgoblin brandishes his axe at you and snarls."
    }), 0 );
    set_achats(3, ({"%^BLUE%^The hobgoblin takes a cut at you with its axe.", 
	"%^BLUE%^The hobgoblin grunts and charges toward you!!", 
	"%^BLUE%^The hobgoblin takes a swipe at your neck with its axe!" 
    }) );
	set_monster_feats(({
	   "parry",
       "powerattack",
	   "shatter",
	   "sunder",
	   "rush"
	}));	
    set_new_exp(1, "very low");
}

void init() {
   ::init();
   if(interactive(TP) && !wizardp(TP) && !TP->query_invis() ){
    	count=0;
   	call_out("do_kill",10,TP);
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
          	  call_out("do_kill",10,targ);
                break;
             case 2..6: 
                TO->force_me("flash "+who);
                targ->kill_ob(TO);
                call_out("do_kill",10,targ);
                break;
             case 7:
            	  force_me("say %^BOLD%^%^RED%^EEIIAAHHH  Die DIE!!!");
                TO->force_me("rush "+who);
                targ->kill_ob(TO);
                call_out("do_kill",20,targ);
                break;
		 case 8..15: 
	         TO->force_me("flash "+who);
                targ->kill_ob(TO);
                call_out("do_kill",5,targ);
                break;
             default:break;
        }
  }
}