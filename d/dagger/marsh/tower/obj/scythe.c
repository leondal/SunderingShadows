#include <std.h>
inherit "/std/weapon";
object owner;
void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TPQN;
}
create() {
    ::create();
    set_name("scythe");
    set_id(({"scythe","scythe of death"}));
    set_short("%^RESET%^%^BLUE%^Scythe of death%^RESET%^");
     set_obvious_short("A black scythe");
    set_long("%^BLUE%^"
      "This blackened weapon, permenantly stained with blood, is a long "
      "reaper like scythe. Its handle is carved to resemble various "
      "skulls all with opened mouths, shaped in a manner to resemble "
      "screams of agony. The blade is extremly cold to the touch and "
      "appears to have been forged and sharpened by a supernatural force."
      "%^RESET%^"
    );
    set_weight(25);
    set_value(400);
    set_wc(2,4);
    set_large_wc(3,4);
    set_type("slashing");
    set_size(2);
    set_prof_type("death scythe");
    set_wield((: TO,"extra_wield" :));
   set_unwield((:TO,"removeme":));
    // set_unwield((: TO,"extra_unwield" :));
    set_hit((: TO,"extra_hit" :));
}
int extra_wield() {
    if((int)ETO->query_level() < 25) {    
	tell_object(ETO,"The inner death of the scythe hates you!\n");
	ETO->do_damage("torso",50);
   ETO->add_attacker(TO);
   ETO->continue_attack();
   ETO->remove_attacker(TO);
	TO->remove();
	return 0;
    }
    if(interactive(TP) && (string)TP->query_name() != owner){
	tell_object(ETO,"The scythe fails to bond with you and vanishes!\n");
	TO->remove();
	return 0;
    }
    if((int)ETO->query_alignment() != 9) {
	tell_object(ETO,"The scythe refuses your hand!\n");
	return 0;
    }
    write("%^BLUE%^"
      "Visions of death and undeath fill your mind!"
      "%^RESET%^"
    );
    say("%^BLUE%^"
      +ETO->query_cap_name()+
      "'s face transforms into the visage of a grinning skull!"
      "%^RESET%^"
      ,ETO);
   ETO->set_property("evil item",1);
    return 1;
}

int removeme() {
   ETO->set_property("evil item",-1);
   return 1;
}
/*
int extra_unwield() {
    if((int)TO->query_wc() < 10){
	write("%^BLUE%^"
      "The grim reaper returns to claim its weapon of death!"
	  "%^RESET%^"
	);
	TO->remove(); 
	return 0;
    }
    return 1;
}
*/

int extra_hit(object ob) {
    object vic;
    int dam, st;
    dam = 6+roll_dice(2,3);
    vic = ETO->query_current_attacker();
    if(!objectp(vic)) return random(8);
    if(random(8) > 5) return dam;
    if(random(8) < 2) {
    message("my_action","%^BLUE%^"
      "The scythe takes on the visage of the %^BOLD%^Grim Reaper%^RESET%^"
      "%^BLUE%^ as you slice into "
      +vic->query_cap_name()+
      "'s flesh!%^RESET%^"
      ,ETO);
    message("other_action","%^BLUE%^"
      +ETO->query_cap_name()+
      " cackles like a being possessed while slashing deep into "
      +vic->query_cap_name()+
      "'s flesh!"
      "%^RESET%^"
      ,environment(vic),(({ETO, vic})));
    message("my_action","%^BLUE%^"
      "The %^BOLD%^Grim Reaper%^RESET%^%^BLUE%^ appears and steals "
      "a piece of your soul as "+ETO->query_cap_name()+" slices "
      +ETO->query_possessive()+
      " scythe deep into your flesh!%^RESET%^"
      ,vic);
    st = (int)ETO->query_stats("strength");
    dam += random(st)/2;
    return dam;
    }
    return 0;
}
