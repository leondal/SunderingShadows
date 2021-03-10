#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("dark fabric");
	set_id(({ "cloth", "fabric", "fabric of darkness", "dark fabric", "cloth of the void", "dark cloth" }));
	set_short("%^RESET%^%^BLUE%^C%^BOLD%^l%^BLACK%^o%^RESET%^%^BLUE%^th %^BOLD%^o%^RESET%^%^BLUE%^f t%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^e V%^BOLD%^o%^BLACK%^i%^RESET%^%^BLUE%^d%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^a piece of fabric made of d%^BOLD%^a%^BLACK%^r%^RESET%^%^BLUE%^kn%^BOLD%^e%^RESET%^%^BLUE%^ss%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^The soft touch of this fabric would be even richer if it were not for %^BLACK%^vacant %^BLUE%^feeling that settles over "
"you at its touch.  Liquid like, the material swirls with a %^RESET%^%^BLUE%^void of energy %^BOLD%^that draws all light and life down into the nothingness "
"that it is made from.  Despite this, there is a strange pattern that swirls to the surface now and again, like a delicate%^RESET%^%^ORANGE%^ hand "
"%^BOLD%^%^BLUE%^or %^RESET%^%^MAGENTA%^woman's face %^BOLD%^%^BLUE%^pushing outward from the dark liquid, that all too soon vanishes back down into the "
"depths of nothingness.%^RESET%^");
	set_weight(3);
   set_value(0);
	set_lore("%^RED%^Remembered from an ancient journal:%^RESET%^ Only one of the Dresttel escaped the earth's summoning.  The Seer Drutok'tre whose "
"flight to escape the reaching vines cast her into the deep void from which she had summoned the Immare.  But the void could not contain the essence of "
"life and rejected what remained of her as soon as she entered.  Casting out the fabric of essence, bound with the living darkness of the void.  The "
"fabric drifted far from the sight of the battle, escaping the Inomor's uplifted weapons that stabbed and cut at the being made other.  And so Drutok'tre "
"fled and continues to flee, the descendants of the Inomor still seeking to destroy the last of her essence.");
   set_overallStatus(220);
	set_property("lore difficulty",23);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
    set_item_bonus("will",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
   set_overallStatus(220);
}

int wear_func(){
	tell_object(ETO,"%^BOLD%^%^BLUE%^Distant whispers spill over your senses, their words fluttering in your mind as delicate as the wings of some tiny bird's wings.  Wings tipped in razors that slice and cut at your mind, opening pathways for the void to enter.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_object(ETO,"%^BOLD%^%^BLUE%^Trembling, you remove the fabric from your shoulders and breath in a sigh of relief as your senses slowly return.  But will they return the next time?%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLUE%^A sheet of pure darkness billows about "+ETOQCN+" deflecting "+who->QCN+"'s attack.%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^Cloth crafted from the %^RESET%^%^BLUE%^essence of darkness %^BOLD%^flutters about you, concealing you for a moment from "+who->QCN+"'s view.  The protection lasts but a moment, but within that moment the image of a %^RESET%^%^MAGENTA%^woman %^BOLD%^%^BLUE%^surges into your vision.  Her pale, perfect hands extended toward you, reaching toward you for her freedom, or to draw you into the %^BLACK%^void %^BLUE%^forever.%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLUE%^A sheet of pure darkness billows about "+ETOQCN+" deflecting your attack.%^RESET%^");
return (damage*-100)/100;	}
}