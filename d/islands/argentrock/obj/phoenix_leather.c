//removed references to old gods ~Circe~ 7/30/19
#include <std.h>
inherit "/d/common/obj/armour/leather_plate.c";

void create(){
	::create();
	set_name("%^RED%^red leather armor%^RESET%^");
	set_id(({"leather armor","red armor","leather","leathers","red leather","breastplate of the phoenix","phoenix armor","red leather armor","breastplate","leather breastplate","red breastplate"}));
	set_short("%^RESET%^%^RED%^Breastplate of the P%^BOLD%^h%^RESET%^%^ORANGE%^o%^MAGENTA%^e%^ORANGE%^n%^BOLD%^%^RED%^i%^RESET%^%^RED%^x%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^A red leather breastplate%^RESET%^");
	set_long("%^RESET%^This is a suit of %^RED%^r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d%^RESET%^ leather breastplate. On the breastplate an image of a %^RED%^p%^BOLD%^h%^RESET%^%^ORANGE%^o%^MAGENTA%^e%^ORANGE%^n%^BOLD%^%^RED%^i%^RESET%^%^RED%^x%^RESET%^ in flight. It is a very large and life like picture that takes up most of the front.  Wisps of flames lick off the feathers of the %^RED%^p%^BOLD%^h%^RESET%^%^ORANGE%^o%^MAGENTA%^e%^ORANGE%^n%^BOLD%^%^RED%^i%^RESET%^%^RED%^x%^RESET%^ as its tail flows down past the waistline of the armor.  The %^RED%^p%^BOLD%^h%^RESET%^%^ORANGE%^o%^MAGENTA%^e%^ORANGE%^n%^BOLD%^%^RED%^i%^RESET%^%^RED%^x%^RESET%^ seems to be calling out its victory. %^YELLOW%^Golden%^RESET%^ buckles allow the armor to be tightened and fitted to any body type.%^RESET%^");
	set_lore("The Phoenix has long been a simple of rebirth and of purification, which naturally makes it a perfect symbol for the church of Jarmila.  The followers of Lysara also deeply revere the phoenix for how it rises again from its own flames.  The phoenix has become a icon that many who fight to protect people and for the good of all races.  The Breastplate of the Phoenix is no different.  Fashioned by sun elves centuries ago, this leather armor outfitted a small army who fought against countless number of orcs, goblins, and drow - fighting to protect their forest homes.  This armor is one of the few remains of the Selu'havessthor's golden age.");
	set_property("lore",12);
	set_value(2400);
	set_size(-1);
	set_property("enchantment",4);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme(){
     if((int)ETO->query_highest_level() < 30) {
        tell_object(ETO,"The armor doesn't fit you!");
        return 0;
     }
	if(ALIGN->is_evil(ETO)) {
		tell_object(ETO,"%^RED%^The red leather becomes incredibly"+
		" hot and you cannot stand to wear it.");
		return 0;
	}
	if(ALIGN->is_good(ETO)) {
		tell_object(ETO,"%^ORANGE%^The image of the phoenix"+
		" seems to glow for a brief moment.");
		return 1;
	}else {
		tell_object(ETO,"%^BOLD%^%^RED%^You hear the cry of a phoenix"+
		" as you wear the leather and prepare for battle.");
		return 1;
	}
}

int removeme(){
	tell_object(ETO,"%^RED%^You can barely bring yourself to"+
	" remove the soft leather of the phoenix armor.");
	return 1;
}
