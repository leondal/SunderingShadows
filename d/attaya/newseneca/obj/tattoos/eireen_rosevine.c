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
	set_value(15000);
	set_id(({ "tattoo", "rose", "vine", "rosevine", "tat", "small tattoo", "small tat" }));
	set_short("%^BOLD%^%^WHITE%^small %^RED%^r%^RESET%^%^RED%^os%^BOLD%^e %^RESET%^%^GREEN%^vine %^BOLD%^%^WHITE%^tattoo%^RESET%^");
	set_long(
@MYLONG
%^RESET%^%^CYAN%^this is a %^BOLD%^%^WHITE%^de%^MAGENTA%^l%^WHITE%^icate%^RESET%^%^CYAN%^ design of a %^RESET%^%^GREEN%^vine%^RESET%^%^CYAN%^ of %^RED%^w%^BOLD%^i%^RESET%^%^RED%^ld %^BOLD%^r%^RESET%^%^RED%^os%^BOLD%^e%^RESET%^%^RED%^s %^CYAN%^winding it's way around Eireen's right ankle, the %^RESET%^%^GREEN%^vines%^RESET%^%^CYAN%^ are %^BOLD%^%^WHITE%^tiny %^RESET%^%^CYAN%^yet %^BOLD%^%^WHITE%^fi%^CYAN%^n%^WHITE%^ely de%^YELLOW%^t%^WHITE%^ai%^MAGENTA%^l%^WHITE%^ed%^RESET%^%^CYAN%^ with the %^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^eave%^BOLD%^%^GREEN%^s %^RESET%^%^CYAN%^and even tiny %^BOLD%^%^BLACK%^thorns %^RESET%^%^CYAN%^visible, the %^BOLD%^%^RED%^v%^WHITE%^a%^MAGENTA%^r%^WHITE%^i%^RED%^o%^RESET%^%^RED%^u%^BOLD%^%^RED%^s %^RESET%^%^RED%^r%^BOLD%^%^WHITE%^o%^MAGENTA%^s%^RESET%^%^RED%^e%^BOLD%^s %^RESET%^%^CYAN%^are in shades from %^BOLD%^%^MAGENTA%^p%^WHITE%^al%^MAGENTA%^e p%^WHITE%^in%^MAGENTA%^k %^RESET%^%^CYAN%^to a %^RESET%^%^RED%^d%^BOLD%^e%^RESET%^%^RED%^ep c%^BOLD%^r%^RESET%^%^RED%^im%^BOLD%^s%^RESET%^%^RED%^on%^RESET%^%^CYAN%^, each different than any other%^RESET%^

MYLONG
	);
	set_limbs(({"right leg"}));
	set_wear((:TO,"wear_me":));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "small"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

