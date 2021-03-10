//Updated description and mechanics - Octothorpe 11/7/09
//Coded by the one and only master of monsters...BANE//

#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"scarecrow","Scarecrow", "laeradmon"}));
    set_name("scarecrow");
    set_short("%^YELLOW%^frightful scarecrow%^RESET%^");
    set_long("%^YELLOW%^The scarecrow's body is made up of cut wood "+
	   "and he sits on a large stake in the ground.  Its limbs are "+
	   "bound together with hemp rope and covered in tattered rags, "
	   "grass and straw.  A hollow gourd with a face carved into "
	   "it serves as its head.  In spite of it seeming to be "
	   "completely inanimate, something about the eyes makes you "
	   "suspect some vile magic at work.");
    set_body_type("human");
    set_race("scarecrow");
    set_gender("male");
    set_size(2);
    set_alignment(9);
    set_hd(15,20);	// was 5,20
    set_max_level(20);  // was 15
    set_hp(160);  	// was 60
    set_attack_bonus(6);
    set_exp(11500);
    set_overall_ac(-5);
    set("aggressive",15);
    set_property("swarm",1);
    set_attack_limbs(({"right hand","left hand"}));
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    set_damage(2,6);
    set_funcs(({"gaze"}));
    set_func_chance(55);
    set_stats("strength",24);
    set_stats("dexterity",12);
    set_stats("intelligence",3);
    set_stats("wisdom",8);
    set_stats("constitution",13);
    set_stats("charisma",15);        
}

void gaze(object targ){
    if("/daemon/saving_throw_d.c"->will_save(targ,-13)){
	   tell_object(targ,"%^BOLD%^GREEN%^The scarecrow gazes into your "+
	      "eyes hypnotizing you!");
	   tell_room(ETO,"%^BOLD%^GREEN%^The scarecrow gazes into "+
	      ""+targ->QCN+"'s eyes!",targ);
	   tell_room(ETO,""+targ->QCN+"'s body goes limp.",targ);
 	   targ->set_paralyzed(8+random(6),"%^RESET%^%^GREEN%^You stare off "+
	      "into space.%^RESET%^");
	   add_attack_bonus(query_attack_bonus()+1);
	return;
    }
    tell_object(targ,"%^BOLD%^GREEN%^The scarecrow gazes into your eyes "+
	   "but you resist its charm!%^RESET%^");
    tell_room(ETO,"%^BOLD%^GREEN%^The scarecrow gazes into "+
	   ""+targ-> QCN+"'s eyes but "+targ->query_subjective()+" resists "+
	   "its charm!%^RESET%^",targ);
    return;
}
