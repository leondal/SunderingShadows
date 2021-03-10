//Coded by Bane//
//Hm killer for Laerad//
#include <std.h>
#include <daemons.h>
inherit "/d/laerad/mon/wander/wander4.c";
object *attackers;

void create(){
    ::create();
    set_id(({"demon","fiend","pit fiend","Pit Fiend","Qualtatoth","qualtatoth"}));
    set_name("Qualtatoth");
    set_short("Qualtatoth, Lord of the Abyss");
    set_long(
	"The creature standing before you is one of the Pit Fiends from the Abyss.  "+
	"One of the strongest of all Demons, the Pit Fiend is a Lord "+
	"of that terrible domain.  It stands over 12 feet tall, its body is "+
	"enormously powerful looking.  Two huge wings waver on its back.  "+
	"Its head is topped with two massive horns that could rend buildings "+
	"apart.  This is a truly fearsome beast."
    );
    set_body_type("daemon");
    set_race("Pit Fiend");
    set_gender("male");
    set_size(3);
    set_alignment(9);
    set_overall_ac(-20);
    set_hd(40,500);
    set_hp(2920);
    set_exp(75000);
    set_stats("strength",20);
    add_limb("right wing","torso",0,0,0);
    add_limb("left wing","torso",0,0,0);
    add_limb("tail","torso",0,0,0);
    set_guild_level("fighter",40);
    set_mob_magic_resistance("average");
    set_property("no bows",1);
    set_property("magic",1);
    set_property("no animate",1);
    set_property("no steal",1);
    set_property("no dominate",1);
    set_property("no death",1);
    set_property("no rush",1);
    set_property("full attacks",1);
    add_money("gold",random(2500)+1000);
    add_money("silver",random(5000)+2000);
    add_money("copper",random(2000)+500);
    add_search_path("/cmds/fighter");
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/laerad/obj/ragnarok")->move(this_object());
    command("wield sword in right hand");
    set_funcs(({"hug","flame","equip","charge","heal_me"}));
    set_func_chance(45);
    set_emotes(9,({"%^MAGENTA%^Qualtatoth says%^RESET%^: Get going little one..."+
	"I am only interested in destroying the powerful.","Qualtatoth spreads "+
	"his wings and releases an ear shattering howl.","%^MAGENTA%^Qualtatoth "+
	"says%^RESET%^: You cannot possibly fathom my unearthly power.","Qualtatoth "+
	"cracks his knuckles and cackles.","%^MAGENTA%^Qualtatoth says%^RESET%^: "+
	"This realm will fall to its knees in wake of my destruction.",""+
	"%^MAGENTA%^Qualtatoth says%^RESET%^: I will crush any mortal who dares "+
	"to challenge my absolute power!","Qualtatoth stomps on the ground a few "+
	"times, the tremors nearly knocking you off your feet."}),0);
}
void init(){
    string *exits;
    int i;
    object *inven;
    exits = (string *)ETO->query_exits();
    for(i=0;i<sizeof(exits);i++)
        add_action("chase",exits[i]);
    ::init();
}
int chase(){
    string *exits, verb;
    int i;
    verb = query_verb();
    if((object *)TO->query_attackers() != ({})){
	call_out("go",1,verb);
	return 0;
    }
}
void go(string verb){
    object att;
    att = TO->query_current_attacker();
    if(!objectp(att) || !present(att,ETO)){
	force_me(verb);
    }
}
void hug(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand",-4)){
	tell_object(targ,"%^GREEN%^Qualtatoth grabs you up in a massive bear hug!");
	tell_room(ETO,"%^GREEN%^Qualtatoth grabs "+targ->query_cap_name()+" up in a massive bear hug!",targ);
	targ->set_paralyzed(70,"You are being held tight.");
	return 1;
    }
    tell_object(targ,"%^GREEN%^Qualtatoth grabs at you but misses!");
    tell_room(ETO,"%^GREEN%^Qualtatoth grabs at "+targ->query_cap_name()+" but misses!",targ);
    return 1;
}
void flame(){
    object *vars;
    int i;
    vars = all_living(ETO);
    for(i=0;i<sizeof(vars);i++){
	if(vars[i] == TO) continue;
	tell_object(vars[i],"%^RED%^Qualtatoth breathes a huge cone of flame across the room!");
	if(!"daemon/saving_d"->saving_throw(vars[i],"breath_weapon",-4)){
	    tell_object(vars[i],"%^RED%^Your flesh is burnt from your body!");
	    vars[i]->do_damage(vars[i]->return_target_limb(),roll_dice(10,10));
	} else {
	tell_object(vars[i],"%^RED%^You are singed badly!");
	vars[i]->do_damage(vars[i]->return_target_limb(),roll_dice(5,10));
	}
    }
}
void equip(object targ){
    if(!objectp(targ)) return;
    tell_object(targ,"%^CYAN%^Qualtatoth stares at you...");
    tell_room(ETO,"%^CYAN%^Qualtatoth stares at "+targ->query_cap_name()+".",targ);
    tell_room(ETO,"Qualtatoth waves his hand around in the air.");
    if(!targ->query_paralyzed()){
    targ->force_me("drop all");
    return 1;
    }
    tell_object(targ,"You roar out in pain!");
    tell_room(ETO,""+targ->query_cap_name()+" roars out in pain!",targ);
    targ->do_damage(targ->return_target_limb(),roll_dice(8,8));
    return 1;
}
void charge(object targ){
    tell_room(ETO,"Qualtatoth gets down on all fours and scrapes his back feet into the ground.");
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",-4)){
	tell_object(targ,"%^BOLD%^Qualtatoth rushes at you with incredible speed and slams into you full force!");
	tell_room(ETO,"%^BOLD%^Qualtatoth rushes at "+targ->query_cap_name()+" with incredible speed and slams into "+targ->query_objective()+" full force!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(15,8));
	targ->set_paralyzed(40,"You are recovering from that trampling.");
	return 1;
    }
    tell_object(targ,"%^BOLD%^Qualtatoth rushes at you with incredible speed but you manage to dodge out of the way!");
    tell_room(ETO,"%^BOLD%^Qualtatoth rushes at "+targ->query_cap_name()+" with incredible speed but "+targ->query_subjective()+" manages to dodge out of the way!",targ);
    return 1;
}
void heal_me(){
    tell_room(ETO,"%^BOLD%^YELLOW%^Qualtatoth chants an unholy prayer of healing!");
    if(TO->query_hp() < 1521){
	    TO->add_hp(200);
	    return 1;
    }
    TO->set_hp(2920);
    return 1;
}
void set_paralyzed(int time,string message){return 1;}
void heart_beat(){
    int i, j;
    object *att;
    object *inven;
    object targ;
    ::heart_beat();
    if(!objectp(TO)) return;
    if((att = (object *)TO->query_attackers()) != ({})){
	j = sizeof(att);
    TO->set_tripped(0);
    TO->set_unconscious(0);
	for(i=0;i<j;i++){
	    if(base_name(att[i]) != base_name(TO))
		call_out("force_me",2,"rush "+att[i]->query_name());
	    TO->set_paralyzed(0);
	    TO->set_disable(0);
	    if(!userp(att[i]) && att[i] != TO && base_name(att[i]) != base_name(TO)) att[i]->die();
	}
    }
    if(present("horse")){
	force_me("say I will not waste my energy on such a stupid beast...");
	if(targ = present("horse",environment(TO))){
	    tell_room(ETO,"Qualtatoth picks the horse up and throws it!");
	    targ->run_away();
	}
    }
    if(present("kit",ETO))
	force_me("offerall");
    if(present("hunter")){
	if(targ = present("hunter",ETO)){
	    tell_room(ETO,"Qualtatoth shoves the glory hunter out of the room.");
	    targ->run_away();
	}
    }
    if(sizeof(query_attackers())){
        inven = all_living(ETO);
	    j = sizeof(inven);
	    for(i=0;i<j;i++){
	        if(wizardp(inven[i])) continue;
	        if(base_name(inven[i]) != base_name(TO))
		    kill_ob(inven[i],1);
	    }
    }
    if(TO->query_hp() < 1521){
	TO->add_hp(20);
	return 1;
    }
}

void die(object ob) {
    message("info","%^RED%^The hell frozen over as the unbeatable Fiend meets his destiny!",
        users());
    ::die();
}
