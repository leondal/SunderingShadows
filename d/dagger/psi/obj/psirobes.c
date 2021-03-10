
#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";



void create(){
    ::create();
    set_name("robes");
    set_obvious_short("%^BOLD%^%^BLUE%^A set of royal blue robes%^RESET%^");
    set_short("%^BOLD%^%^BLUE%^Robes of the %^RESET%^%^ORANGE%^Me%^BOLD%^%^BLACK%^nt%^RESET%^a%^BOLD%^%^BLACK%^li%^RESET%^%^ORANGE%^st%^RESET%^");
    set_id(({"robes","robes of the mentalist","Robes of the Mentalist","psion robes","psionic robes","robe"}));
    set_long("%^BOLD%^%^BLUE%^Reaching the floor, these long robes are flowing and light,"
" like nothing you've ever seen before.  A large, spindled collar fans out upright around"
" the wearers head, framing it with dramatic effect.  Within the %^RESET%^%^BLUE%^strange"
" fabric%^BOLD%^, the %^CYAN%^forms %^BLUE%^of your %^CYAN%^imagination %^BLUE%^seem to"
" be constantly shifting into view before they float back into %^BLACK%^obscurity%^BLUE%^,"
" blending in with the robes' essence once again.  It's long, wide sleeves nearly manage"
" to cover the wearers hands, and the robe is trimmed with a thin lining of"
" %^BLACK%^black silk%^BLUE%^.  Around the waist, a simple %^RESET%^%^ORANGE%^bronze"
" cord %^BOLD%^%^BLUE%^can be used to fasten them shut.%^RESET%^");

    set_lore("%^RESET%^%^BLUE%^The name Zarizth, in fact, was often used in childrens scary tales"
" to one another, and these robes look oddly like the ones she was always described as wearing. "
" According to the tales, the darkest beings all sought to have access to the realm that Zarizth"
" was locked in, and each had already managed to find one of four pieces needed to open the"
" the portal to her.  The stories always ended that one managed to get to her, and that together"
" they were coming for you!  But surely, nothing like her really existed, did it?"); 
    set_weight(5);
    set_type("clothing");   
    while((int)TO->query_property("enchantment") != 4){
        TO->remove_property("enchantment");
        TO->set_property("enchantment",4);
    }
    set_limbs(({"torso"}));
    set_max_internal_encumbrance(21);
    set_item_bonus("charisma",2);
    set_item_bonus("intelligence",2);
    set_item_bonus("spell slots",1);
    set_value(35000);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme(){

   // if(member_array("%^BOLD%^%^BLUE%^Defeated Zarizth!%^RESET%^",ETO->query_mini_quests())== -1) //{
   //     tell_object(ETO,"You must first defeat %^BOLD%^%^CYAN%^%^FLASH%^Zarizth %^RESET%^to use //this item.");
  //      return 0;
  //  }

    if((int)ETO->query_class_level("psion") < 35){
        tell_object(ETO,"%^RESET%^%^CYAN%^The powers of your mind cannot overcome the will of the robes and they refuse you!%^BOLD%^");
        return 0;
    }
    tell_object(ETO,"%^BOLD%^%^CYAN%^A rush of %^RESET%^%^ORANGE%^confidence %^BOLD%^%^BLUE%^fills you as you slip on the robes.");
    tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+""+
                " smirks with an air of confidence after slipping on "+ETO->query_possessive()+" robes.",ETO);
    return 1;
}

int removeme(){
    tell_object(ETO,"%^RESET%^%^ORANGE%^The wave of confidence fades and you suddenly feel more vulnerable.");
	return 1;
}

void init()
{
	::init();
	add_action("check_put","put");
}

int check_put(string str)
{
	if(!query_worn()) 
    {
	    notify_fail("You must be wearing the robes to place something in their"+
		    " pockets.\n");
		return 0;
	}

	if(query_worn()) return ::put_into();
}
