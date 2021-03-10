// /d/newbie/rooms/ruins/mon/hobgobf.c Hobgoblin for Newbietown
//Added fighter feats - Octothorpe 7/7/10

#include <std.h>
#include "../../../newbie.h"
#include "../drownew.h"

inherit "std/monster";

void kill_elves(object targ);

void create() 
{
    ::create();
        set_name("hobgoblin");
   	set_id(({"hobgoblin"}));
   	set_race("hobgoblin");
        set_gender("male");
        set_short("Fierce hobgoblin");
   set_long("This fierce, barbaric looking humanoid warrior is over 6 ft. tall with a very rugged, stocky build.  His hairy hide is a dark reddish-brown but his flattened nose has a bluish tint to the wide nostrils.  Large, pointed ears stick out from the side of  wide, somewhat flattened and almost ape-like, face.  Yellow teeth jut out from the lower jaw, clearly marking this creature as a carnivore.");
        set_level(5);
	set_class("fighter");
        add_search_path("/cmds/fighter");
        set_body_type("human");
      	set("aggressive", "kill_elves");
        set_hd(5,3);
        set_alignment(3);
        set_size(2);
        set_overall_ac(6);
        set_stats("intelligence",8);
        set_stats("wisdom",8);
        set_stats("strength",19);
        set_stats("charisma",5);
        set_stats("dexterity",10);
        set_stats("constitution",17);
        set_hp(random(10)+40);
        set_property("swarm",1);
        set_wielding_limbs( ({ "right hand", "left hand" }) );
	new("/d/common/obj/weapon/awlpike")->move(TO);
          command("wield awlpike");
        set_exp(200);
        add_money("gold",random(80)+180);
        add_money("silver",random(200)+270);
        add_money("copper",random(500));
        set_emotes(2, ({"The hobgoblin sniffs at you with his bluish flattened nose.", 
	   "%^ORANGE%^The hobgoblin seems to be sizing you up and snarls menacingly.", 
	   "The hobgoblin pulls some raw meat out of a pouch and gnaws on it."}), 0);
	set_achats(3, ({
	   "%^BOLD%^%^RED%^The hobgoblin lunges at you with its polearm, trying to run you through with it.", 
	   "%^YELLOW%^The hobgoblin lets out a blood-curdling scream and charges at you!!", 
	   "%^BOLD%^%^RED%^The hobgoblin snarls and growls savagely." 
	}) );
	set_monster_feats(({"parry"}));
    set_new_exp(1, "very low");
}


void kill_elves(object targ) {
   string race;
   if (!objectp(targ)) return; // added by lujke to try to catch a bug
   race = targ->query_race();
   if( race == "elf" || race == "half-elf" || race == "voadkyn" || race == "drow" || race == "half-drow") {
        force_me("say %^CYAN%^ARRRGGGGG!! You be "+race+"!");
	force_me("say %^CYAN%^Death to all you elf kinds!!!");
        force_me("kill "+targ->query_name());
        command("flash "+targ->query_name());
        command("parry");
        return;
   }
}
