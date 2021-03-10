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
	set_id(({ "tattoo", " tempus symbol", " huge back tattoo", " flaming sword tattoo", " blood red shield tattoo" }));
	set_short("huge Tempus symbol back tattoo");
	set_long(
@MYLONG
%^RESET%^%^WHITE%^This tattoo covers the whole of Og's back.It's a %^RED%^f%^ORANGE%^l%^RED%^a%^ORANGE%^m%^RED%^e%^ORANGE%^RESET%^%^WHITE%^ shaped shield.The background of the shield is %^BOLD%^%^RED%^blood red.%^RESET%^%^WHITE%^ In the center of the shield is a %^RED%^f%^ORANGE%^l%^RED%^a%^ORANGE%^m%^RED%^i%^ORANGE%^n%^RED%^g%^ORANGE%^RESET%^%^WHITE%^ silver sword.  The sword is incredibly detailed and features a horned skull on its pommel.It's clear that this incredible artwork is a symbol that this person is a true follower of Tempus.%^RESET%^

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

