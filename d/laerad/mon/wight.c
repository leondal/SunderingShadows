//Coded by the one and only master of monsters...BANE//
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"wight","Wight"}));
    set_name("Wight");
    set_short("A nightmarish Wight");
    set_long(
	"This horrid undead creature is a ghastly reflection of its "+
	"former human self, with cruel, burning eyes set in mummified "+
	"flesh over a twisted skeleton with hands that end in sharp "+
	"claws. Long, sickly hair runs from its disfigured head. Its "+
	"teeth are bared, ready to feast on your flesh after it rends "+
	"you limb from limb..."
    );
    set_body_type("human");
    set_race("wight");
    set_gender("male");
    set_alignment(9);
    set_property("alignment adjustment",4);
    set_property("swarm",1);
    set_size(2);
    set_hd(7,21);
    set_hp(77);
    set_exp(1500);
    set_overall_ac(4);
    set("aggressive",19);
    set_attack_limbs(({"right hand"}));
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_damage(1,4);
    set_attack_bonus(1);
    set_hit_funcs( (["right hand":(:TO,"drain":)]) );
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}
void drain(object targ){
    int i, hp_loss;
    string *curclass, *classes;
    if(targ->query_exp() < 3001){
	tell_object(targ,"%^BOLD%^RED%^The Wight has withered your body to dust!");
	tell_room(ETO,"%^BOLD%^RED%^The Wight has withered "+targ->query_cap_name()+"'s body to dust!");
	targ->set_hp(-1);
	} else {
	tell_object(targ,"%^BOLD%^BLUE%^You feel your life force drain away!");
	tell_room(ETO,"%^BOLD%^BLUE%^"+targ->query_cap_name()+"'s stumbles back weakly from the touch of the Wight!",targ);
        targ->add_exp(-3000);
   classes = targ->query_classes();
        for(i=0;i<sizeof(targ->query_classes());i++){
            curclass = classes[i];

while((int)ADVANCE_D->get_exp(targ->query_class_level(curclass),curclass, targ) >
((int)targ->query_exp()/sizeof(classes))){
	    targ->set_mlevel(curclass,(int)targ->query_class_level(curclass) -1 );
	    hp_loss = ADVANCE_D->get_hp_bonus(curclass,targ->query_stats("constitution"),targ->query_class_level(curclass),TO);
            targ->set_max_hp(((int)targ->query_max_hp() - hp_loss));
            targ->reduce_my_skills(curclass);
            targ->reduce_my_skills(curclass);
	    if(interactive(targ)){
	    if(wizardp(targ)) return 1;
	    ADVANCE_D->class_news(targ->query_class(),targ->query_cap_name()+" has lost a level to the touch of a Wight!");
	    }
     	}
    }
  }
}
