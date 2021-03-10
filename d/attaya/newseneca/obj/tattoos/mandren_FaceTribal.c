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
	set_id(({ "tattoo", "tribal tattoo", "tribal", "bloody tribal" }));
	set_short("%^BOLD%^%^BLACK%^huge %^RESET%^%^RED%^T%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^b%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^l %^RESET%^%^RED%^T%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^o%^RESET%^");
	set_long(
@MYLONG
%^RED%^              / /\ \
             / /  \ \      
   /  /     / /    \ \     \  \
  /  /     / /      \ \     \  \ 
  \  \     \ \      / /     /  /
   \  \    / /      \ \    /  /

    ___                    ___
   /  /                    \  \
  /  /      ___    ___      \  \
 /  /      /    VV    \      \  \
 |  |     /  /      \  \     |  |
 |   \   /  /        \  \   /   |
  \   \_/  /          \  \_/   /
%^RESET%^

MYLONG
	);
	set_limbs(({"head"}));
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

