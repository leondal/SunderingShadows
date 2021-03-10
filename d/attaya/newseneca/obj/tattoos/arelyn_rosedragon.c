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
	set_value(20000);
	set_id(({ "tattoo", "dragon tattoo", "small tattoo", "rose tattoo" }));
	set_short("%^CYAN%^%^BOLD%^A medium %^RESET%^%^GREEN%^sized %^RESET%^%^BOLD%^dragon %^RESET%^%^GREEN%^and %^RED%^%^BOLD%^rose %^RESET%^%^BOLD%^tattoo%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^Occupying the spot at the small of the back is a small tattoo of a silver dragon entwined with a %^RED%^rose of fire.  %^RESET%^%^BOLD%^The dragon itself is exquisite in its detail, complete with sparkling individual scales that shimmer in the light.  The %^RESET%^%^GREEN%^stem of the rose is colored a dark green %^RESET%^%^BOLD%^and the thorns taper to points so sharp it looks as if you might be able to prick your finger on them. The dragon's wings are wrapped protectively about the %^RESET%^%^GREEN%^stem %^RESET%^%^BOLD%^of the rose, claws gripping two of the thorns. %^ORANGE%^The petals themselves are made of gushing %^RED%^o%^RESET%^%^ORANGE%^r%^BOLD%^RED%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^RED%^g%^RESET%^%^ORANGE%^e and %^BOLD%^y%^RESET%^%^BOLD%^e%^ORANGE%^%^BOLD%^l%^RESET%^%^BOLD%^l%^ORANGE%^o%^RESET%^%^BOLD%^w flames, the dragon's serpentine neck twisting around to face the flower with a partially open maw.

MYLONG
	);
	set_limbs(({"waist"}));
	set_wear((:TO,"wear_me":));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "medium"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

