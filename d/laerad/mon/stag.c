//Coded by Bane//
#include <std.h>
inherit WEAPONLESS;
void create(){
    object ob;
    ::create();
    set_id(({"stag","black stag","Black Stag", "forestmon"}));
    set_name("Black Stag");
    set_short("A Black Stag");
    set_long(
	"This mystical creature roams these forests in search of lost "+
   "souls that it can steal and drag to Kelemvor's domain.  It stands about 6 "+
   "feet tall and is covered in thick black fur.  Its eyes glow "+
	"a fiendish red and smoke trails from its nostrils."
    );
    set_body_type("quadruped");
    set_race("stag");
   set_gender("male");
    set_size(2);
    set_hd(20,40);
    set_hp(200);
    set_alignment(9);
    set_exp(12000);
    set_overall_ac(-8);
    set("aggressive",0);
    add_limb("antlers","head",0,0,0);
    set_mob_magic_resistance("average");
    set_property("no bump",1);
    set_base_damage_type("piercing");
    set_attack_limbs(({"antlers"}));
    set_attacks_num(1);
    set_damage(5,6);
    set_funcs(({"headbutt"}));
    set_func_chance(30);
    set_moving(1);
    set_speed(100);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}

void headbutt(object targ){
    tell_room(ETO,"%^RED%^The Black Stag lowers its antlers.");
    if(!"daemon/saving_d"->saving_throw(targ,"breath_weapon")){
	tell_object(targ,"%^BOLD%^RED%^The Black Stag slams its antlers into you!");
	tell_room(ETO,"%^BOLD%^RED%^The Black Stag slams its antlers into "+targ->query_cap_name()+"!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(8,8));
	return 1;
    }
    tell_object(targ,"%^BOLD%^RED%^The Black Stag gallops past you barely missing its attack!");
    tell_room(ETO,"%^BOLD%^RED%^The Black Stag gallops past "+targ->query_cap_name()+" barely missing its attack!",targ);
    return 1;
}

void paralyzed(int time,string message){return 1;}
