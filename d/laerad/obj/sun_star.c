//updated by Circe with new desc, lore, etc 6/13/04
//Coded by Bane//
#include <std.h>
inherit "/d/common/obj/weapon/morningstar";
void create(){
    ::create();
    set_id(({"star","morning star","morning star of the sun","sun star","sunstar","Sun Star"}));
    set_name("morning star");
    set_short("%^YELLOW%^Sun Star%^RESET%^");
    set_obvious_short("%^BOLD%^%^ORANGE%^A golden morning star");
    set_long(
       "%^BOLD%^This beautiful morning star has been crafted from "+
       "a strong %^RESET%^steel alloy %^RESET%^and covered with a "+
       "thin layer of %^YELLOW%^gold plating%^RESET%^, making it "+
       "s%^RESET%^h%^BOLD%^i%^RESET%^m%^BOLD%^m%^RESET%^e%^BOLD%^r "+
       "in the %^YELLOW%^sunlight%^WHITE%^.  The top half of the "+
       "star is encrusted with rings of %^CYAN%^gems%^WHITE%^, "+
       "alternating in color from %^RESET%^%^MAGENTA%^deep violet"+
       "%^BOLD%^%^WHITE%^, %^RED%^red%^WHITE%^, %^RESET%^%^ORANGE%^"+
       "orange%^BOLD%^%^WHITE%^, %^YELLOW%^brilliant yellow%^WHITE%^, "+
       "and finally to a clear, %^CYAN%^crystalline azure %^WHITE%^"+
       "at the top.  The bottom half of the star has been %^BLACK%^"+
       "darkened %^WHITE%^to mimic the horizon with the %^YELLOW%^"+
       "rising sun %^WHITE%^represented by the %^CYAN%^gems %^WHITE%^"+
       "at the top.  The handle of the morning star is covered in "+
       "crisscrossing strips of white leather with the loose ends tied "+
       "and left hanging below the hilt.%^RESET%^"
    );
    set_lore("The Sun Star is a weapon originally crafted "+
       "to combat the dark hordlings who had run amuk on the "+
       "Gods Plains on the island of Laerad.  Not actually a "+
       "weapon of Lathander, the first Sun Star was indeed "+
       "crafted by a cleric of Lathander.  He was partial to "+
       "the sunrise and saw it as a fitting symbol to combat "+
       "the dark night taking over Laerad.  Even the criss-"+
       "crossed leather upon the hilt has meaning - it is "+
       "supposed to be the bonds of friendship that tie the "+
       "churches of the Light together when combatting "+
       "evil.  One of these morning stars was given to the "+
       "head clerics of each of the churches of the Light.");
    set_weight(2);
    set_value(5000);
    set_size(2);
    set_wc(2,4);
    set_large_wc(1,8);
    set_property("enchantment",2);
    set_type("bludgeoning");
    set_prof_type("mace");
    set_hit( (:TO,"extra_hit":) );
    set_wield( (:TO,"align_check":) );
   set_unwield((:TO,"removeme":));
}
int align_check(){
    int align;
    align=TP->query_alignment();
    if(align == 3 || align == 6 || align == 9){
	tell_object(TP,"%^BOLD%^RED%^This is a weapon of Good!");
	tell_room(ETP,"%^BOLD%^The morning star explodes!");
	TP->do_damage(TP->return_target_limb(),roll_dice(5,6));
    TP->add_attacker(TO);
    TP->continue_attack();
    TP->remove_attacker(TO);
	TO->remove();
	return 0;
	} else {
	tell_object(TP,"%^BOLD%^RED%^The power of the morning star flows into you.");
   ETO->set_property("good item",1);
	return 1;
    }
}

int removeme()
{
   ETO->set_property("good item",-1);
   return 1;
}

int extra_hit(object ob){
    int roll, roll2, align;
   if(!objectp(ob)) return roll_dice(2,4);
    align=ob->query_alignment();
    roll=random(100)+1;
    roll2=random(20)+1;
    if(roll > 60){
    if(!objectp(ob)) return roll_dice(2,4);
	if(align == 3 || align == 6 || align == 9){
	    tell_object(ob,"%^BOLD%^RED%^The morning star singes your evil skin!");
	    tell_room(environment(query_wielded()),"%^BOLD%^RED%^The morning star singes "+ob->query_cap_name()+"'s evil skin!",ob);
	    ob->do_damge(ob->return_target_limb(),roll_dice(2,6));
	    if(!"daemon/saving_d"->saving_throw(ob,"spell")){
		ob->set_paralyzed(10,"You are reeling in pain.");
		return roll_dice(1,4);
	    }
	    return roll_dice(2,4);
	}
	if(roll > 60 && roll < 80){
	    tell_object(ob,"%^BOLD%^YELLOW%^The morning star flashes and sparks as it smashes into you!");
	    tell_room(environment(query_wielded()),"%^BOLD%^YELLOW%^The morning star flashes and sparks as it smashes into "+ob->query_cap_name()+"!",ob);
	    ob->do_damage(ob->return_target_limb(),roll_dice(2,4));
	    return roll_dice(1,4);
	}
    	if(roll > 79){
	    if(roll2 > 15){
	    tell_object(ob,"%^BOLD%^The morning star slams into you knocking the wind out of you!");
	    tell_room(environment(query_wielded()),"%^BOLD%^The morning star slams into "+ob->query_cap_name()+" knocking the wind out of "+ob->query_objective()+"!",ob);
	    ob->set_paralyzed(10,"You are recovering from that last hit.");
	    return roll_dice(1,4);
	    }
	return roll_dice(2,4);
    	}
    }
}
