// adapted to Nim'navanon. N, 12/18.
#include <std.h>
inherit "/d/common/obj/armour/studded";

void create(){
	::create();
	set_name("%^RESET%^%^GREEN%^Tro%^RESET%^%^RED%^p%^RESET%^%^GREEN%^hies "+
"of t%^RESET%^%^ORANGE%^h%^RESET%^%^GREEN%^e Hu%^RESET%^%^RED%^n%^RESET%^"+
"%^GREEN%^t A%^RESET%^%^ORANGE%^r%^RESET%^%^RED%^m%^RESET%^%^GREEN%^or%^RESET%^");
	set_id(({ "hide", "mottled hide armor", "armor", "leather", "trophies of the hunt", "Trophies of the Hunt"}));
	set_short("%^RESET%^%^GREEN%^Tro%^RESET%^%^RED%^p%^RESET%^%^GREEN%^hies"+
" of t%^RESET%^%^ORANGE%^h%^RESET%^%^GREEN%^e Hu%^RESET%^%^RED%^n%^RESET%^"+
"%^GREEN%^t A%^RESET%^%^ORANGE%^r%^RESET%^%^RED%^m%^RESET%^%^GREEN%^or%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^M%^RESET%^%^BOLD%^%^BLACK%^o%^RESET%^"+
"%^GREEN%^t%^RESET%^%^ORANGE%^tled hi%^RESET%^%^BOLD%^%^BLACK%^d%^RESET%^"+
"%^GREEN%^e%^RESET%^%^ORANGE%^ ar%^RESET%^%^BOLD%^%^BLACK%^m%^RESET%^%^ORANGE%^or%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This armor, though a haphazard collection "+
"of different hides and skins stitched together, provides an amazing level "+
"of protection. You can identify skins from several beasts, %^RESET%^%^BOLD%^"+
"%^GREEN%^sc%^RESET%^%^GREEN%^a%^RESET%^%^BOLD%^%^GREEN%^les from d%^RESET%^"+
"%^GREEN%^r%^RESET%^%^BOLD%^%^GREEN%^agons%^RESET%^%^ORANGE%^, %^RESET%^%^RED%^"+
"furs %^RESET%^%^ORANGE%^from all manner of %^RESET%^%^RED%^forest creatures"+
"%^RESET%^%^ORANGE%^, even a few bright %^RESET%^%^YELLOW%^feathers"+
"%^RESET%^%^ORANGE%^. The entire armor is stitched with a %^RESET%^%^BOLD%^"+
"%^RED%^bl%^RESET%^%^RED%^oo%^RESET%^%^BOLD%^%^RED%^d red thi%^RESET%^%^RED%^"+
"c%^RESET%^%^BOLD%^%^RED%^k thread%^RESET%^%^ORANGE%^. At the collar is a "+
"crude clasp from a fang of some %^RESET%^%^GREEN%^serpent%^RESET%^%^ORANGE%^.\n%^RESET%^");
	set_weight(20);
	set_value(3000);
	set_lore("%^RED%^%^BOLD%^Hunters of Nim'navanon are known to only wear the skin"+
" of beasts they hunted personally, the armor then becoming a trophy. There "+
"are times though when a hunt master collects all the kills from a great hunt"+
" and creates the Trophy of the Hunt. The armor is blessed in blood and suits "+
"are given to the most daring and vicious of the hunters.%^RESET%^");
	set_property("lore difficulty",15);
	set_size(2);
      set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+"%^BOLD%^%^RED%^ pulls the"+
" "+query_short()+"%^BOLD%^%^RED%^ over their head.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You pull the "+query_short()+"%^BOLD%^"+
"%^RED%^ over your head and feel the thrill of the hunt.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(EETO,"%^BOLD%^%^RED%^As "+ETOQCN+"%^BOLD%^%^RED%^ removes the"+
" "+query_short()+"%^BOLD%^%^RED%^, scanning around.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You remove the "+query_short()+"%^BOLD%^"+
"%^RED%^and feel the blood rush settle.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(EETO,"%^RESET%^%^GREEN%^As "+who->QCN+"%^RESET%^%^GREEN%^ str"+
"ikes "+ETOQCN+"%^RESET%^%^GREEN%^, "+ETOQCN+"%^RESET%^%^GREEN%^ blocks"+
" the blow easily! %^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^GREEN%^As "+who->QCN+"%^RESET%^%^GREEN%^'s "+
"blow is about to strike you, you deflect it with a patch of heavy scale on the armor!%^RESET%^");
	tell_object(who,"%^RESET%^%^GREEN%^As you strike "+ETOQCN+"%^RESET%^"+
"%^GREEN%^ they block easily!%^RESET%^");
return(-1)*(damage);
}
}
