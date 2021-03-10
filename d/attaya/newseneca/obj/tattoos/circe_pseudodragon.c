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
	set_id(({ "tattoo", "dragon tattoo", "faerie dragon tattoo", "pseudodragon tattoo" }));
	set_short("%^RESET%^%^MAGENTA%^a small tattoo of a delicate %^BOLD%^faerie dragon%^RESET%^");
	set_long(
@MYLONG
%^RESET%^%^MAGENTA%^This playful little %^BOLD%^faerie dragon%^RESET%^%^MAGENTA%^ is peeking out from behind a pristine %^BOLD%^%^WHITE%^fluffy white cloud%^RESET%^%^MAGENTA%^ lined in %^RESET%^silver%^MAGENTA%^.  The delicate %^CYAN%^gos%^BOLD%^s%^RESET%^%^CYAN%^am%^BOLD%^e%^RESET%^%^CYAN%^r %^BOLD%^wings %^RESET%^%^MAGENTA%^float on an unfelt breeze, sparkling with %^BOLD%^i%^CYAN%^r%^RED%^i%^YELLOW%^d%^GREEN%^e%^BLUE%^s%^CYAN%^c%^WHITE%^e%^MAGENTA%^n%^YELLOW%^c%^GREEN%^e%^RESET%^%^MAGENTA%^.  The %^YELLOW%^golden tint %^RESET%^%^MAGENTA%^of the dragon's skin is most visible in the curling %^YELLOW%^tail%^RESET%^%^MAGENTA%^ that just brushes the bottom of the %^BOLD%^%^WHITE%^cloud%^RESET%^%^MAGENTA%^.  A %^BOLD%^mischievous gl%^WHITE%^e%^MAGENTA%^am %^RESET%^%^MAGENTA%^sparkles in the %^BOLD%^%^BLUE%^faerie dragon's eyes%^RESET%^%^MAGENTA%^ as it points a slender %^BOLD%^pink wand %^RESET%^%^MAGENTA%^at some poor, unsuspecting target.%^RESET%^

MYLONG
	);
	set_limbs(({"left leg"}));
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

