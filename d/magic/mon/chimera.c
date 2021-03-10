//Coded by the one and only master of monsters...BANE//
// updated to use WEAPONLESS by Dinji & Styx 7/2003
// removed scroll & made a little tougher *Styx*  12/14/03

#include "summoned_monster.h"
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"chimera","Chimera"}));
    set_name("Chimera");
    set_short("A monstrous Chimera");
    set_long(
	"The Chimera is a large beast with the hindquarters "+
	"of a large black goat and the forequarters of a huge "+
	"tawny lion. The monster has three heads, those of "+
	"a goat, a lion, and a fierce dragon. Two large wings "+
	"erupt from its back. Its cold red eyes stare at you "+
	"as he prepares to make you his next meal."
    );
    set_race("chimera");
    set_body_type("dragon");
    set_gender("male");
    set_alignment(9);
    remove_limb("head");
    add_limb("head1", "FATAL", 0, 0, 0);
    add_limb("head2", "FATAL", 0, 0, 0);
    add_limb("head3", "FATAL", 0, 0, 0);
    add_limb("horn", "head1", 0, 0, 0);
    add_limb("mouth2", "head2", 0, 0, 0);
    add_limb("mouth3", "head3", 0, 0, 0);
    add_limb("teeth", "mouth2", 0, 0, 0);
    set_size(2);
    set_hd(12,18);   // was 9,18 , then was 15/18 *Styx*  12/25/04
   set_hp(190);
    set_attack_bonus(6);
    set_exp(3500);
    set_max_level(25);  // was 15
   set_overall_ac(-10);  // was -5
    set("aggressive",19);
   set_attack_limbs(({"right foreclaw","left foreclaw","horn", "teeth"}));
   set_attacks_num(3);
   set_base_damage_type("slashing");
   set_damage(1,6);
    set_funcs(({"breath"}));
    set_func_chance(40);
    set_speed(60);
    set_stats("strength",19);
    set_stats("dexterity",19);
    set_stats("intelligence",16);
    set_stats("wisdom",16);
    set_stats("constitution",16);
    set_stats("charisma",8);
}

void breath(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"breath_weapon")){
        tell_object(targ,"%^BOLD%^RED%^The Chimera breathes a cone of flame at you burning you horribly!");
  	tell_room(ETO,"%^BOLD%^RED%^The Chimera breathes a cone of flame at "+targ->query_cap_name()+", burning "+targ->query_objective()+" horribly!",targ);
        targ->do_damage("torso",roll_dice(10,8));
	return 1;
    }
    tell_object(targ,"%^BOLD%^RED%^The Chimera breathes a cone of flame at you burning you lightly!");
    tell_room(ETO,"%^BOLD%^RED%^The Chimera breathes a cone of flame at "+targ->query_cap_name()+", burning "+targ->query_objective()+" lightly!",targ);
    targ->do_damage("torso",(roll_dice(3,8))/2);
    return 1;
}

/* removing the scrolls to stop ooc info. abuse *Styx* 12/14/03
void reset(){
    object ob;
    ::reset();
    if(!present("scroll")){
	ob=new("/d/magic/scroll");
        ob->set_spell(6);
	ob->move(this_object());
    }
}
*/
