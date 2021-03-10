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
	set_id(({ "tattoo", "tat", "small tattoo", "notes", "nusical notes" }));
	set_short("A medium black-ink tattoo of musical notes");
	set_long(
@MYLONG
This tattoo is of three musical-notes. Its a simple, but skillfully inked tat. Its done in BOLD BLACK. What do the three notes mean...you will have to ask the gnome!

MYLONG
	);
	set_limbs(({"right hand"}));
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

