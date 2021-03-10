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
	set_short("%^RESET%^%^MAGENTA%^A small neck tattoo%^RESET%^");
	set_long(
@MYLONG
%^MAGENTA%^Inked into the back of her neck is a single letter %^RED%^"%^BOLD%^P%^RESET%^%^RED%^" %^MAGENTA%^- about two inches in height. It is boldly scripted in %^BOLD%^purple ink %^RESET%^%^MAGENTA%^and shadowed with %^RED%^red%^MAGENTA%^. Although simple in design, the %^WHITE%^stylish %^MAGENTA%^font adds some flair and femininity.%^WHITE%^

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

