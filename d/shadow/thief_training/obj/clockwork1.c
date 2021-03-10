// Chernobog (10/27/20)

#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_id(({"puppet","clockwork_puppet"}));
	set_name("clockwork puppet");
	set_short("%^BOLD%^%^BLACK%^A c%^RESET%^l%^BOLD%^o%^RESET%^c%^BOLD%^%^BLACK%^k%^RESET%^%^ORANGE%^w%^BOLD%^o%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^k puppet%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^The puppet is humanoid in shape and mostly %^RESET%^%^ORANGE%^wooden%^BOLD%^%^BLACK%^, though the gleam of m%^RESET%^e%^BOLD%^t%^RESET%^a%^BOLD%^%^BLACK%^l %^RESET%^c%^BOLD%^o%^RESET%^g%^ORANGE%^s %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^g%^BOLD%^e%^WHITE%^a%^ORANGE%^r%^RESET%^%^ORANGE%^s %^BOLD%^%^BLACK%^flash in the gaps between its limbs. Someone has taken the briefest of time to crudely paint a %^ORANGE%^s%^WHITE%^m%^ORANGE%^il%^WHITE%^e%^ORANGE%^y f%^WHITE%^a%^ORANGE%^ce %^BLACK%^on the head, but the puppet is otherwise unadorned. An occasional twitch rustles through it, accompanied by a short blast of %^RESET%^s%^BOLD%^t%^RESET%^e%^BOLD%^a%^RESET%^m%^BOLD%^%^BLACK%^.%^RESET%^");
	set_weight(1000000);
	set_value(0);
	set_property("no animate",1);
}

