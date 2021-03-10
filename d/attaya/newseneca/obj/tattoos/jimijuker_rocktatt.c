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
	set_id(({ "tat", "tattoo", "chest tat", " rocktat", "ink" }));
	set_short("a medium RED tat on his broad little chest!");
	set_long(
@MYLONG
This is a bold tattoo. Its done in BOLD RED LETTERS! across his strong chest . It says...?I SOLD MY SOUL FOR ROCK GNOME -N- ROLL!? It is written in gnomish, but by the gift of magic, all can understand it.
yes


MYLONG
	);
	set_limbs(({"torso"}));
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

