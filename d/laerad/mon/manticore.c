//Updated description and mechanics - Octothorpe 11/7/09
//Coded by the one and only master of monsters...BANE//
// updated to use WEAPONLESS by Dinji & Styx 7/2003

#include <std.h>
inherit WEAPONLESS;

void create(){
    ::create();
    set_id(({"manticore","Manticore", "laeradmon", "magical beast"}));
    set_name("manticore");
    set_short("%^RESET%^g%^BOLD%^r%^BOLD%^%^BLACK%^o%^RESET%^t%^BOLD%^"+
	   "%^BLACK%^e%^RESET%^sq%^BOLD%^%^BLACK%^ue %^RESET%^m%^BOLD%^"+
	   "%^BLACK%^a%^RESET%^nt%^BOLD%^%^BLACK%^i%^RESET%^c%^BOLD%^%^o"+
	   "%^RESET%^r%^BOLD%^%^BLACK%^e%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^The manticore is a true monster, with "+
	   "a leonine torso and legs, bat-like wings, a humanoid head, and "+
	   "a tail tipped with %^RESET%^ir%^BOLD%^%^BLACK%^o%^RESET%^n "+
	   "%^ORANGE%^spikes.  It stands six feet tall and its massive "+
	   "wing span measures over twenty-five feet. The creature's t"+
	   "%^BOLD%^a%^RESET%^%^ORANGE%^wny hide is %^RESET%^d%^BOLD%^"+
	   "%^BLACK%^u%^RESET%^sky %^ORANGE%^color and its wings are "+
	   "dark brown.%^RESET%^");
    set_body_type("dragon");
    set_race("manticore");
    set_gender("male");
    set_size(3);  // was 2 for some reason
    set_alignment(9);
    set_hd(17,19);      // was 7,19
    set_max_level(20);  // was 18
    set_hp(175);        // was 75
    set_attack_bonus(2);  // was 1
    set_exp(12000);
    set_overall_ac(-5);   // was 3
    set("aggressive",15);
    set_attack_limbs(({"right foreclaw","left foreclaw","tail"}));
    set_base_damage_type("slashing");
    set_attacks_num(3);
    set_damage(2,12);
    set_funcs(({"spikes"}));
    set_func_chance(102);
    set_stats("strength",20);
    set_stats("dexterity",15);
    set_stats("intelligence",7);
    set_stats("wisdom",12);
    set_stats("constitution",19);
    set_stats("charisma",4);
    set_moving(1);
	set_speed(60);
	set_nogo(({"/d/laerad/wasteland/waste1"}));
}

void spikes(object targ){
/* changing from this to be a dex check along with AC
    int roll, ac;
    roll=random(20);
    ac=targ->query_ac();
    if(roll > 13-ac){
*/

    if( ((int)targ->query_stats("dexterity") - (int)targ->query_ac()) < random(40) ) {
	tell_object(targ,"%^BOLD%^BLACK%^The manticore fires a volley of "+
	   "tail spikes that sink deep into your flesh!%^RESET%^");
	tell_room(ETO,"%^BOLD%^BLACK%^The manticore fires a volley of tail "+
	   "spikes at "+targ->QCN+" %^BOLD%^%^RED%^that sink deep into "+targ->QP+" "+
	   "flesh!%^RESET%^",targ);
	targ->do_damage("torso",roll_dice(6,8));
	set_func_chance(0);
	call_out("reset_spikes",20);
	return;
    }
    tell_object(targ,"%^BOLD%^BLACK%^The manticore fires a volley of "+
	   "tail spikes right past you!%^RESET%^");
    tell_room(ETO,"%^BOLD%^BLACK%^The manticore fires a volley of tail "+
	   "spikes right past "+targ->QCN+"!%^RESET%^",targ);
    set_func_chance(0);
	add_attack_bonus(query_attack_bonus()+1);
    call_out("reset_spikes",20);
    return;
}

void reset_spikes(){
   if(!objectp(TO))
	return;
   set_func_chance(102);
}
