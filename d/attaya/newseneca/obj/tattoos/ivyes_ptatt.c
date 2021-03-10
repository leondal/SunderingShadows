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
	set_id(({ "tattoo", "neck tattoo" }));
	set_short("%^RESET%^%^MAGENTA%^A small %^RESET%^%^RED%^"%^BOLD%^%^RED%^P%^RESET%^%^RED%^"%^RESET%^%^MAGENTA%^ tattoo%^RESET%^");
	set_long(
@MYLONG
 %^MAGENTA%^,ggggggggggg,  
%^MAGENTA%^dP%^RED%^"""%^MAGENTA%^88%^RED%^""""""%^MAGENTA%^Y8,%^WHITE%^
%^MAGENTA%^Yb,  88      `8b%^WHITE%^
 %^MAGENTA%^`%^RED%^"  %^MAGENTA%^88      ,8P%^WHITE%^
     %^MAGENTA%^88aaaad8P%^RED%^" 
     %^MAGENTA%^88%^RED%^"""""    
     %^MAGENTA%^88         
     %^MAGENTA%^88         
     %^MAGENTA%^88         
     %^MAGENTA%^88%^RESET%^

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

