// Coded by Bane
// spectre.c
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"spectre","frightening","frightening spectre"}));
    set_name("spectre");
    set_short("A frightening Spectre");
    set_long(
	"This powerful undead haunts the most desolate and "+
	"deserted of places.  They hate all life and light.  "+
	"The spectre is semitransparent and retains a semblance "+
	"of its former life."
    );
    set_body_type("undead");
    set_race("spectre");
    set_gender("male");
    set_size(2);
    set_alignment(9);
    set_property("weapon resistance",1);
    set_property("swarm",1);
    set_hd(10,5);
    set_hp(125);
    set_exp(5500);
    set_overall_ac(2);
    set("aggressive",19);
    set_attack_limbs(({"right hand"}));
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_damage(1,8);
    set_attack_bonus(5);
    set_hit_funcs( (["right hand":(:TO,"drain":)]) );
}
void drain(object targ){
    int i, hp_loss;
    string *curclass, *classes;
    if(targ->query_exp() < 4001){
	tell_object(targ,"%^BOLD%^RED%^The Spectre has withered your body to dust!");
	tell_room(ETO,"%^BOLD%^RED%^The Spectre has withered "+targ->query_cap_name()+"'s body to dust!",targ);
    	targ->set_hp(-1);
	} else {
	tell_object(targ,"%^BOLD%^BLUE%^You feel your life force drain away!");
	tell_room(ETO,"%^BOLD%^BLUE%^"+targ->query_cap_name()+" stumbles back weakly from the touch of the Spectre!",targ);
	targ->add_exp(-4000);
   classes = targ->query_classes();
        for(i=0;i<sizeof(targ->query_classes());i++){
            curclass = classes[i];

while((int)ADVANCE_D->get_exp(targ->query_class_level(curclass),curclass) >
((int)targ->query_exp()/sizeof(classes))){
            targ->set_mlevel(curclass,(int)targ->query_class_level(curclass) -
1);
	    hp_loss = ADVANCE_D->get_hp_bonus(curclass,targ->query_stats("constitution"),targ->query_class_level(curclass),TO);
            targ->set_max_hp(((int)targ->query_max_hp() - hp_loss));
            targ->reduce_my_skills(curclass);
            targ->reduce_my_skills(curclass);
	    if(interactive(targ)){
	    if(wizardp(targ)) return 1;
	    ADVANCE_D->class_news(targ->query_class(),targ->query_cap_name()+" has lost a level to the touch of a Spectre!");
	    }
        }
    }
  }
}
