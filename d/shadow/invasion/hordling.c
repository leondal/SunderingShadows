//Coded by Bane for invasions...hordling monster that makes itself//
#include <std.h>
inherit "/d/shadow/invasion/wandering.c";
void make_me();
void create(){
    ::create();
    set_id(({"hordling","Hordling"}));
    set_name("Hordling");
    set_long(
	"A disgusting mass of body parts and assorted limbs.  These creatures "+
	"are from the darkest levels of the abyss and are extremely gruesome "+
	"and disgusting.  Eyes and mouths cover the bodies of these beasts.  Claws "+
	"are present on nearly every limb...you are in serious trouble friend."
    );
    set_body_type("human");
    set_race("hordling");
    set_size(2);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    make_me();
}
void init(){
    if((string)TP->query_level() > 12 && interactive(TP) && !wizardp(TP)){
	force_me("kill "+TPQCN);
	TO->kill_ob(TP,1);
    }
}
void make_me(){
    object ob;
    int i, j, k;
    string class, short, ac, hd;
    i = random(5);
    switch(i){
    case(0): hd = 10;
    break;
    case(1): hd = 12;
    break;
    case(2): hd = 15;
    break;
    case(3): hd = 17;
    break;
    case(4): hd = 20;
    }
    set_exp(0);
    switch(i){
    case(0): class = "fighter";
    break;
    case(1): class = "thief";
    break;
    case(2): class = "mage";
    break;
    case(3): class = "cleric";
    break;
    case(4): class = "antipaladin";
    }
    set_class(class);
    set_mlevel(class, hd);
    set_hd(hd,2);
    set_hp(TP->query_max_hp());
    switch(class){
    case "fighter": 
	set_base_damage_type("slashing");
	set_attack_limbs(({"right hand","left hand","head"}));
	set_attacks_num(4);
	set_damage(1,10);
	set_stats("strength",19);
	break;
    case "thief":
	set_base_damage_type("slashing");
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(2);
	set_damage(1,8);
	set_stats("strength",17);
	set_funcs(({"stab_me"}));
	set_func_chance(30);
	break;
    case "mage":
	set_base_damage_type("slashing");
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(1);
	set_damage(1,6);
	set_stats("strength",16);
	set_spells(({
	    "magic missile",
	    "vampiric touch",
	    "fireball",
	    "lightning bolt",
	    "hold person",
	    "cone of cold",
	    "finger of death"
	}));
	set_spell_chance(75);
	break;
    case "cleric":
	set_base_damage_type("slashing");
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(2);
	set_damage(1,8);
	set_stats("strength",18);
	set_spells(({
	    "limb attack",
	    "call lightning",
	    "cause critical wounds",
	    "cause serious wounds",
	    "flame strike"
	}));
	set_spell_chance(50);
	break;
    case "antipaladin":
	set_base_damage_type("slashing");
	set_attack_limbs(({"right hand","left hand","head"}));
	set_attacks_num(4);
	set_damage(1,8);
	set_stats("strength",18);
	set_spells(({
	    "limb attack",
	    "call lightning",
	    "cause serious wounds"
	}));
	set_spell_chance(25);
	set_funcs(({"terror"}));
	set_func_chance(25);
    }
    switch(i){
    case(0): ac = 0;
    break;
    case(1): ac = -2;
    break;
    case(2): ac = -5;
    break;
    case(3): ac = -7;
    break;
    case(4): ac = -10;
    }
    set_overall_ac(ac);
    switch(i){
    case(0): short = "A nasty Hordling";
    break;
    case(1): short = "A terrifying Hordling";
    break;
    case(2): short = "A disgusting Hordling";
    break;
    case(3): short = "A horrible Hordling";
    break;
    case(4): short = "A putred Hordling";
    }
    set_short(short);
}
void stab_me(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^The Hordling stabs you in the back with a hidden dagger!");
	tell_room(ETO,"%^BOLD%^The Hordling stabs "+targ->query_cap_name()+" in the back with a hidden dagger!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(8,8));
	return 1;
    }
    tell_object(targ,"%^BOLD%^The Hordling tries to stab you in the back!");
    tell_room(ETO,"%^BOLD%^The Hordling tries to stab "+targ->query_cap_name()+" in the back!",targ);
    return 1;
}
void terror_me(object targ){
    tell_object(targ,"The Hordling stares at you.");
    tell_room(ETO,"The Hordling stares at "+targ->query_cap_name()+".",targ);
    if(!"daemon/saving_d"->saving_throw(targ,"spell")){
	tell_object(targ,"%^BOLD%^BLUE%^An immense feeling of terror overcomes you!");
	tell_room(ETO,"%^BOLD%^BLUE%^"+targ->query_cap_name()+" starts to shake and quiver!",targ);
	targ->run_away();
	targ->run_away();
	targ->run_away();
	targ->run_away();
	targ->run_away();
	targ->run_away();
	return 1;
    }
    tell_object(targ,"%^BOLD%^BLUE%^You feel a little scared.");
    tell_room(ETO,"%^BOLD%^BLUE%^"+targ->query_cap_name()+" shivers a little.",targ);
    return 1;
}
