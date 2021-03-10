#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(30000);
	set_id(({ "tattoo", "dragon tattoo", "blue dragon tattoo", "huge tattoo", "huge dragon tattoo" }));
	set_short("%^BOLD%^%^BLUE%^A huge %^RESET%^%^BLUE%^co%^BOLD%^%^BLUE%^b%^RESET%^%^CYAN%^a%^BLUE%^lt %^BOLD%^%^BLUE%^d%^YELLOW%^r%^BLUE%^a%^RESET%^%^MAGENTA%^g%^BOLD%^%^BLACK%^o%^BLUE%^n ta%^RESET%^%^RED%^t%^CYAN%^t%^BOLD%^%^BLUE%^o%^RESET%^%^BLUE%^o%^RESET%^");
	set_long(
@MYLONG
%^RESET%^%^BLUE%^Curled around this woman's body is the grand image of a fearsome %^BOLD%^%^BLUE%^bl%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^e d%^RESET%^%^RED%^r%^BOLD%^%^BLUE%^a%^BLACK%^g%^BLUE%^on%^RESET%^%^BLUE%^. The beast is frozen in flight across her back, wings spread wide down her arms. Looking upon it, one can almost see the thundercloud outlines behind it swirl with the powerful beat of the mighty creature's wings. %^BOLD%^%^WHITE%^S%^RESET%^p%^BOLD%^i%^RESET%^n%^BOLD%^es %^RESET%^%^BLUE%^adorn its plated back from nape to the end of its kite-tipped tail, which itself coils her abdomen and down the left thigh. The head is at a three-quarter degree upon the top of her chest, its neck curling down from her right shoulder. %^YELLOW%^S%^WHITE%^p%^YELLOW%^a%^RESET%^%^WHITE%^r%^MAGENTA%^k%^YELLOW%^s %^RESET%^%^BLUE%^gather in its wide-open jaws, the vigilant %^ORANGE%^g%^YELLOW%^o%^BLACK%^l%^YELLOW%^d%^RESET%^%^ORANGE%^en e%^YELLOW%^y%^RESET%^%^ORANGE%^es %^BLUE%^staring outward in silent rage.%^RESET%^

MYLONG
	);
	set_limbs(({"torso"}));
	set_wear((:TO,"wear_me":));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "huge"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

