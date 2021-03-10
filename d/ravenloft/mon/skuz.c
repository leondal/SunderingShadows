//Coded by the one and only master of monsters...BANE//
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"skuz","Skuz"}));
    set_name("Skuz");
    set_short("A slimy Skuz");
    set_long(
	"Perhaps the most feared of undead creatures, this monster "+
	"radiates pure negative energy. The thing appears as a slimy, "+
	"filmy coated pool of water. The beast is able to manipulate "+
	"its body into humaniod form making it easier to %^BOLD%^RED%^ "+
	"DESTROY%^RESET%^ those foolish enough to get near it!"
    );
    set_body_type("undead");
    set_race("skuz");
    set_gender("male");
    set_size(2);
    set_alignment(9);
    set_hd(15,40);
    set_hp(160);
    set_exp(15000);
    set_overall_ac(-1);
    set_mob_magic_resistance("average");
    set_property("alignment adjustment",5);
    set_property("swarm",1);
    add_money("gold",random(2500)+1500);
    set("aggressive",19);
    set_attack_limbs(({"right hand","left hand"}));
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_damage(2,6);
    set_hit_funcs( ([
	"right hand":(:TO,"drain":),
	"left hand":(:TO,"drain":)
    ]) );
}
int drain(object targ){
    int i, hp_loss;
   string curclass,*classes;
    if(targ->query_exp() < 6001){
	tell_object(targ,"%^BOLD%^RED%^The Skuz has withered your body to dust!");
	tell_room(ETO,"%^BOLD%^RED%^The Skuz has withered "+targ->query_cap_name()+"'s body to dust!",targ);
        set_property("magic",1);
        targ->set_hp(-1);
        remove_property("magic");
	} else {
        tell_object(targ,"%^BOLD%^BLUE%^You feel your life force drain away!");
        tell_room(ETO,"%^BOLD%^BLUE%^"+targ->query_cap_name()+" stumbles back weakly from the touch of the Skuz!",targ);
	targ->add_exp(-6000);
   classes = targ->query_classes();
	for(i=0;i<sizeof(targ->query_classes());i++){
	    curclass = classes[i];
          while((int)ADVANCE_D->get_exp(targ->query_class_level(curclass),curclass) > ((int)targ->query_exp()/sizeof(classes))){
            targ->set_mlevel(curclass,(int)targ->query_class_level(curclass) - 1);
	    hp_loss = ADVANCE_D->get_hp_bonus(curclass,targ->query_stats("constitution"),targ->query_class_level(curclass),TO);
	    targ->set_max_hp(((int)targ->query_max_hp() - hp_loss));
	    targ->reduce_my_skills(curclass);
	    targ->reduce_my_skills(curclass);
	    if(interactive(targ)){
	    if(wizardp(targ)) return 1;
	    ADVANCE_D->class_news(curclass,targ->query_cap_name()+" has lost a level to the touch of a Skuz!");
	    }
        }
    }
  }
}
