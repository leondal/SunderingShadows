#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
	::create();
	set_name("bracers");
	set_id(({ "bracers", "bracers of the serpent" }));
	set_short("%^YELLOW%^Bracers of the Serpent%^RESET%^");
	set_obvious_short("A pair of gold bracers");
	set_long(
@AVATAR
%^YELLOW%^These bracers are crafted out of pure gold and formed into the shape of spiraling serpents, that wrap around ones forearms.  The serpents are carved with great detail, each scale has been etched into the metal, giving it a lifelike apperance.  %^RESET%^%^ORANGE%^Topaz%^YELLOW%^ and %^RED%^garnet%^YELLOW%^ flakes are further used to bring to life the diamond pattern on the serpent's body.  The head of the serpent faces downward, towards ones wrist.  %^RED%^Garnet%^YELLOW%^ gems are set into the serpent's eyes.  The tip of each snake's tale is fashioned out of %^RESET%^%^ORANGE%^topaz%^YELLOW%^.

AVATAR
	);
	set_value(1200);
	set_lore(
@AVATAR
The Bracers of the Serpents are rumored to have been made by a mage with a fondness for snakes name Xelthestliana.  The magess took the serpent up as her totem symbol, even to the point of always having at least one with her were ever she traveled.  There are reports even that Xelthestliana was able to alter and shape her spells so they took on serpent like qualities. 

AVATAR
	);
	set_property("lore",13);
	set_size(2);
	set_property("enchantment",3+random(2));
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^A pair of golden serpents slighter around "+ETOQCN+" 's forearms, locking themselves in place.",ETO);
	tell_object(ETO,"%^YELLOW%^The bracers slither around your forearms as they set themselves in place.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^A pair of golden serpents slither off of "+ETOQCN+" 's forearms.",ETO);
	tell_object(ETO,"%^YELLOW%^The serpents heed your wishes and begin to slither off of your forearms.");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^YELLOW%^One of the golden serpents on "+ETOQCN+" 's forearms appears to suddenly come to life and strike "+who->QCN+"",({ETO,who}));
	tell_object(ETO,"%^YELLOW%^One of the serpents hisses softly as it raises it's head to strike "+who->QCN+"");
	tell_object(who,"%^YELLOW%^One of the golden serpents on "+ETOQCN+" 's forearms appears to suddenly come to life and strike you.");
		who->do_damage("torso",random(4));
return damage;	}
}