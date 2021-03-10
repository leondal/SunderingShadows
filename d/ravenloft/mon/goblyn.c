// Coded by Bane
// goblyn.c
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"goblyn","evil","evil goblyn"}));
    set_name("goblyn");
    set_short("An evil goblyn");
    set_long(
	"Goblyn's are hideous creatures with slightly bloated "+
	"heads, pointed ears, and glowing red eyes.  They have "+
	"long, mangy hair which grows only on the back of their "+
	"heads and necks.  About half of their face is taken up with a wide "+
	"mouth full of needle-sharp teeth."
    );
    set_body_type("human");
    set_race("goblyn");
    set_gender("male");
    set_size(2);
    set_alignment(6);
    set_hd(random(3)+4,4);
    set_hp(query_hd()*12 + 4);
    set_class("thief");
    set_class("fighter");
    set_mlevel("thief",query_hd());
    set_mlevel("fighter",query_hd());
    set_exp(query_hd()*100);
    set_overall_ac(4);
    set("aggressive",15);
    set_stats("strength",12);
    set_stats("charisma",3);
    set_stats("dexterity",17);
    set_stats("constitution",12);
    set_stats("wisdom",3);
    set_stats("intelligence",5);
    set_property("swarm",1);
    set_mob_magic_resistance("average");
    add_money("gold",random(10));
    add_money("silver",random(5));
    add_money("copper",random(50));
    set_attack_limbs(({"right hand","left hand"}));
    set_base_damage_type("slashing");
    set_attacks_num(2);
    set_damage(1,6);
    set_hit_funcs( ([
	"left hand":(:TO,"hit_it":),
	"right hand":(:TO,"hit_it":)
    ]) );
}
void hit_it(object ob){
    if(!random(6)){
	if(!SAVING_D->saving_throw(ob,"rod_staff_wand")){
	    tell_object(ob,"%^RED%^The Goblyn jumps up onto your chest clawing at your throat!");
	    tell_room(ETO,"%^RED%^The Goblyn jumps up onto "+ob->query_cap_name()+" clawing away at "+ob->query_possessive()+" throat!",ob);
        ob->cause_typed_damage(ob, ob->return_target_limb(), roll_dice(2, 6), "slashing");
	    return 1;
	}
    }
}
int kill_ob(object victim, int which){
    int hold;
    hold = ::kill_ob(victim, which);
    if(hold){
	if(!SAVING_D->saving_throw(victim,"paralyzation_poison_death")){
	    tell_object(victim,"The goblyn bares its teeth and you freeze up in fear.");
	    tell_room(ETO,"The goblyn bares its teeth and "+victim->query_cap_name()+" freezes up in fear.",victim);
	    victim->set_paralyzed(10,"You are frozen with fear.");
	    return 1;
	}
	return 1;
    }
}
