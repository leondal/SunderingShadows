// hobgobf2.c - Hobgoblin fighter2 for newbietown

#include <std.h>
#include "../../../newbie.h"

inherit "/std/monster";

int count;

create() {
    ::create();
        set_name("hobgoblin");
   	set_id(({"hobgoblin"}));
   	set_race("hobgoblin");
        set_gender("male");
        set_short("Hobgoblin hunter");
   set_long("%^RESET%^This fierce, barbaric looking humanoid warrior is over 6 ft. tall with a very rugged, stocky build.  His hairy hide is a dark reddish-brown but his flattened nose has a %^BLUE%^bluish tint to the wide, thick nostrils%^RESET%^.  Large, pointed ears stick out from the side of  wide, somewhat flattened face.  Yellow canine-type teeth jut upward from the lower jaw, clearly marking this creature as a carnivore.");
        set_level(6);
	set_class("fighter");
        add_search_path("/cmds/fighter");
        set_body_type("human");
      	set("aggressive", 12);
        set_hd(6,3);
        set_alignment(3);
        set_size(2);
        set_overall_ac(6);
        set_stats("intelligence",10);
        set_stats("wisdom",8);
        set_stats("strength",19);
        set_stats("charisma",5);
        set_stats("dexterity",10);
        set_stats("constitution",17);
        set_hp(random(15)+40);
        set_property("swarm",1);
        set_wielding_limbs( ({ "right hand", "left hand" }) );
  	new("/d/common/obj/weapon/two_hand_sword")->move(TO);
          command("wield sword");
        set_exp(220);
        add_money("gold",random(110)+200);
        add_money("silver",random(300)+110);
        add_money("copper",random(800));
        set_emotes(2, ({
	   "The burly, crude hobgoblin sniffs at you with his bluish flattened nose.", 
	   "%^MAGENTA%^The hobgoblin seems to be sizing you up and snarls menacingly.", 
	   "%^MAGENTA%^The fierce hobgoblin points the business end of its polearm at you and snarls."
	}) );
	set_achats(3, ({
	   "%^MAGENTA%^The fierce hobgoblin takes a wild swing at you with its polearm.", 
	   "%^MAGENTA%^The fierce hobgoblin grunts and charges toward you!!", 
	   "%^MAGENTA%^The hobgoblin uses the shaft of the polearm to block your attack." }) );
}

void init() {
	::init();
	if(interactive(TP) && !wizardp(TP) && !TP->query_invis() ){
    	count=0;
   	    TO->force_me("say %^YELLOW%^Leave or die!  We hunt here!!");
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
             	command("look "+targ->query_name());
             	force_me("cackle evilly");
         	    force_me("say %^ORANGE%^You have treasure.  Better yet.");
         	    force_me("say %^ORANGE%^Hah!  We kill and take for tribe!");
          	    call_out("do_kill",7,targ);
                break;
             case 2: 
          	    force_me("kill "+targ->query_name());
          	    force_me("parry");
          	    force_me("say %^BOLD%^TEST - Protect others");
          	    command("protect hobgoblin");
          	    command("protect hobgoblin 2");
          	    call_out("do_kill",7,targ);
                break;
             case 3..6: 
                TO->force_me("flash "+who);
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
               	targ->kill_ob(TO);
               	call_out("do_kill",5,targ);
                break;
             default:break;
        }
  }
}