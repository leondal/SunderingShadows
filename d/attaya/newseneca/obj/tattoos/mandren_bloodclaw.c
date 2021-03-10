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
	set_id(({ "tattoo", "claw tattoo" }));
	set_short("%^RED%^medium Claw Tattoo%^RESET%^");
	set_long(
@MYLONG
%^RED%^		__  __	__  __
	       / /*/ /*/ /*/ / # 
              / / / / / / / /   # 
              ()  ()  ()  ()    #
             | | | | | | | |   \# 
             | | | | | | | |**\ \
              V   V   V   V   | |
                 ~~~~~~~      | |                            
                     ~~~~~   / /
                             V 

MYLONG
	);
	set_limbs(({"neck"}));
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

