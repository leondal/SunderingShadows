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
	set_id(({ "tattoo", "dragon tattoo", "huge tattoo" }));
	set_short("%^MAGENTA%^A huge %^BOLD%^%^BLACK%^ex%^RESET%^%^MAGENTA%^q%^BOLD%^%^BLACK%^uisite %^RESET%^%^RED%^dragon %^MAGENTA%^tattoo%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^A dark, black%^WHITE%^-%^BLACK%^scaled dragon wraps itself around the forearm. The dragon rests his head on the hand and the tail ends halfway up the upper-arm. His eyes are %^YELLOW%^gold%^RESET%^%^ORANGE%^e%^YELLOW%^n %^BLACK%^and the slits are ja%^RESET%^%^WHITE%^g%^BOLD%^%^BLACK%^ged. His mouth is open, a gl%^YELLOW%^o%^BLACK%^w of %^YELLOW%^bright yellow%^BLACK%^ seems to rad%^YELLOW%^i%^BLACK%^ate from within the dragons maw and his %^WHITE%^teeth %^BLACK%^are %^RED%^s%^BLACK%^e%^RED%^r%^BLACK%^r%^RED%^a%^BLACK%^t%^RED%^e%^BLACK%^d and %^WHITE%^countless%^BLACK%^. You follow the neck from the head and you get to the body which %^CYAN%^dominates %^BLACK%^most of the tattoo. His scales are a deep black that does not refle%^GREEN%^c%^BLACK%^t any light that touches it. He has %^YELLOW%^yellow streaks %^GREEN%^c%^BLUE%^h%^BLACK%^a%^CYAN%^o%^RESET%^%^BLUE%^t%^GREEN%^i%^WHITE%^c%^CYAN%^a%^MAGENTA%^l%^BOLD%^%^BLACK%^l%^GREEN%^y %^BLACK%^flowing over his body and they gl%^YELLOW%^o%^BLACK%^w with the same light as his mouth. His claws are menacing looking and they %^RED%^dig %^BOLD%^%^BLACK%^into the skin of the arm, claiming his territory. His wings are tinged with %^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^er %^BLACK%^along their edges and folded back alongside his body. The tail of the beast is %^RESET%^%^MAGENTA%^thi%^RED%^c%^MAGENTA%^k %^BOLD%^%^BLACK%^and %^RESET%^%^RED%^l%^MAGENTA%^o%^RED%^ng%^BOLD%^%^BLACK%^, swirling itself along the arm, squeez%^CYAN%^i%^BLACK%^ng it. The %^YELLOW%^yellow streaks %^BLACK%^continue up the tail and come together at the %^GREEN%^t%^YELLOW%^i%^GREEN%^p%^BLACK%^. %^WHITE%^This tattoo likely took a very long time to complete, with all of the detail and the shear size of the dragon, it is the pinnacle of body art and should be worn proudly.%^RESET%^

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

