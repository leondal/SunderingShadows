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
	set_id(({ "tattoo", "rib tattoo", "rat tattoo", "medium tattoo", "left side tattoo", "side tattoo" }));
	set_short("%^MAGENTA%^A medium-sized %^BOLD%^rat %^RESET%^%^MAGENTA%^tattoo%^WHITE%^");
	set_long(
@MYLONG
%^RESET%^A little %^BOLD%^%^BLACK%^black rat %^RESET%^is turned leftwards, crouching on her hind legs, with her beady little %^BOLD%^%^BLACK%^black eyes %^RESET%^boring into you. The artistry is very realistic, right down to the little razor %^BOLD%^claws %^RESET%^on her raised forepaws. The rat is perched on a %^BOLD%^%^MAGENTA%^m%^RESET%^%^RED%^a%^BOLD%^%^MAGENTA%^u%^RESET%^%^RED%^v%^BOLD%^%^MAGENTA%^e %^RESET%^background within a classic %^ORANGE%^victorian frame %^WHITE%^which features very ornate and detailed scrollwork. Her %^BOLD%^%^BLACK%^small head %^RESET%^and %^BOLD%^%^BLACK%^wiry tail %^RESET%^lift beyond the frame, appearing closer to you than the rest of her small body. A %^BOLD%^silver crown %^RESET%^sits comfortably on her head. A little %^BOLD%^plaque %^RESET%^set into the bottom of the frame reads, in fancy script: %^BOLD%^Rat Queen%^RESET%^.

MYLONG
	);
	set_limbs(({"torso"}));
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

