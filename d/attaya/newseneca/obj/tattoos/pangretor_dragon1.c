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
	set_id(({ "tattoo", "dragon tattoo" }));
	set_short("%^MAGENTA%^A huge %^BOLD%^%^BLACK%^ex%^RESET%^%^MAGENTA%^q%^BOLD%^%^BLACK%^uisite %^RESET%^%^RED%^dragon %^MAGENTA%^tattoo%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^The dragon rests his head on the hand and the tail ends halfway up the upper-arm. His eyes are %^YELLOW%^gold%^RESET%^%^ORANGE%^e%^YELLOW%^n %^BLACK%^and the slits are ja%^RESET%^%^WHITE%^g%^BOLD%^%^BLACK%^ged. His mouth is open, a glow of %^YELLOW%^bright yellow%^BLACK%^ radiates from within the dragons maw and his teeth are %^WHITE%^serrated and countless%^BLACK%^. He has yellow streaks %^GREEN%^c%^BLUE%^h%^BLACK%^a%^CYAN%^o%^RESET%^%^BLUE%^t%^GREEN%^i%^WHITE%^c%^CYAN%^a%^MAGENTA%^l%^BOLD%^%^BLACK%^l%^GREEN%^y %^BLACK%^flowing over his body and they glow with the same light as his mouth. His claws are menacing looking and they dig into the skin of the arm, claiming his territory. The tail of the beast is %^RESET%^%^MAGENTA%^thi%^RED%^c%^MAGENTA%^k %^BOLD%^%^BLACK%^and %^RESET%^%^RED%^l%^MAGENTA%^o%^RED%^ng%^BOLD%^%^BLACK%^, swirling itself along the arm, squeezing it. The yellow streaks continue up the tail and come together at the tip.%^RESET%^

MYLONG
	);
	set_limbs(({"left arm"}));
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

