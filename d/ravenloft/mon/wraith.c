//Coded by the one and only master of monsters...BANE//
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"wraith","Wraith"}));
    set_name("Wraith");
    set_short("A horrible Wraith");
    set_long(
	"This creature of the undead is pure evil...seeking only to "+
	"absorb human life energy. The monster appears as a black, "+
	"vaguely man-shaped cloud. It eyes glow a deadly red showing "+
	"its shear hatred of all that is living..."
    );
    set_body_type("undead");
    set_race("wraith");
    set_gender("male");
    set_size(2);
    set_alignment(9);
    set_property("weapon resistance",1);
    set_property("swarm",1);
    set_hd(10,20);
    set_hp(100);
    set_exp(4500);
    set_overall_ac(3);
    set("aggressive",19);
    set_attack_limbs(({"right hand"}));
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_damage(1,6);
    set_attack_bonus(5);
    set_hit_funcs( (["right hand":(:TO,"drain":)]) );
}
void drain(object targ){
    int i, hp_loss;
    string *curclass, *classes;
    if(targ->query_exp() < 3001){
    	tell_object(targ,"%^BOLD%^RED%^The Wraith has withered your body to dust!");
    	tell_room(ETO,"%^BOLD%^RED%^The Wraith has withered "+targ->query_cap_name()+"'s body to dust!",targ);
    	targ->set_hp(-1);
	} else {
	tell_object(targ,"%^BOLD%^BLUE%^You feel your life force drain away!");
	tell_room(ETO,"%^BOLD%^RED%^"+targ->query_cap_name()+" stumbles back weakly from the touch of the Wraith!",targ);
    	targ->add_exp(-3000);
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
	    ADVANCE_D->class_news(targ->query_class(),targ->query_cap_name()+" has lost a level to the touch of a Wraith!");
	    }
        }
    }
  }
}
