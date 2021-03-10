//Coded by the one and only master of monsters...BANE//
// updated to use WEAPONLESS by Dinji & Styx 7/2003

#include "summoned_monster.h"
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"manticore","Manticore", "laeradmon"}));
    set_name("Manticore");
    set_short("A huge Manticore");
    set_long(
	"%^BOLD%^%^BLACK%^The Manticore is a true monster, with a leonine torso and legs, "+
	"batlike wings, a man's head, and a tail tipped with iron spikes. "+
	"The Manticore stands 6 feet tall and its massive wing span is "+
	"over 25 feet. The creature's tawny hide is black-brown in color "+
	"and its wings are dark brown."
    );
    set_body_type("dragon");
    set_race("manticore");
    set_gender("male");
    set_size(3);  // was 2 for some reason
    set_alignment(9);
    set_hd(17,19);      // was 7,19
    set_max_level(25);  // was 18
    set_hp(175);        // was 75
    set_attack_bonus(2);  // was 1
    set_exp(1850);
    set_overall_ac(-5);   // was 3
    set("aggressive",15);
   set_attack_limbs(({"right foreclaw","left foreclaw","tail"}));
   set_base_damage_type("slashing");
   set_attacks_num(3);
   set_damage(1,12);
    set_funcs(({"spikes"}));
    set_func_chance(102);
    set_stats("strength",18);
    set_stats("dexterity",12);
    set_stats("intelligence",6);
    set_stats("wisdom",6);
    set_stats("constitution",5);
    set_stats("charisma",5);
}

void spikes(object targ){
/* changing from this to be a dex check along with AC
    int roll, ac;
    roll=random(20);
    ac=targ->query_ac();
    if(roll > 13-ac){ 
*/

    if( ((int)targ->query_stats("dexterity") - (int)targ->query_ac()) < random(40) ) {
	tell_object(targ,"%^BOLD%^RED%^The Manticore fires a volley of tail spikes that sink deep into your flesh!");
	tell_room(ETO,"%^BOLD%^RED%^The Manticore fires a volley of tail spikes at "+targ->query_cap_name()+" %^BOLD%^%^RED%^that sink deep into "+targ->QP+" flesh!",targ);
	targ->do_damage("torso",roll_dice(6,6));
	set_func_chance(0);
	call_out("reset_spikes",20);
	return;
    }
    tell_object(targ,"%^BOLD%^RED%^The manticore fires a volley of tail spikes right past you!");
    tell_room(ETO,"%^BOLD%^RED%^The Manticore fires a volley of tail spikes right past "+targ->query_cap_name()+"!",targ);
    set_func_chance(0);
    call_out("reset_spikes",20);
    return;
}

void reset_spikes(){
   if(!objectp(TO))  
	return;
   set_func_chance(102);
}