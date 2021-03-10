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
	set_id(({ "neck tattoo", "tattoo" }));
	set_short("%^RESET%^%^MAGENTA%^A small %^RED%^"%^BOLD%^P%^RESET%^%^RED%^" %^MAGENTA%^tattoo%^WHITE%^");
	set_long(
@MYLONG
%^RESET%^%^MAGENTA%^This is a simple letter %^RED%^"%^BOLD%^P%^RESET%^%^RED%^" %^MAGENTA%^- about two inches in height. It is boldly scripted in %^BOLD%^purple ink %^RESET%^%^MAGENTA%^and shadowed with %^RED%^red%^MAGENTA%^. Although simple in design, the %^WHITE%^stylish %^MAGENTA%^font adds some flair and femininity.%^WHITE%^

MYLONG
	);
	set_limbs(({"neck"}));
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

