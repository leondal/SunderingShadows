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
	set_id(({ "tattoo", "axe tattoo", "battleaxe tattoo", "calf tattoo" }));
	set_short("%^RED%^A huge battleaxe calf tattoo%^RESET%^");
	set_long(
@MYLONG
                                /       \
                              //         \\
                          ////             \\\\  
                %^RED%^       /%^RESET%^///                \\\\  
               %^RED%^      //%^RESET%^/////////////\\\\\\\\\\\\\\\
              %^RED%^     <||||%^RESET%^||||||||||||||||||||||||||||>
                 %^RED%^   \\\\\\%^RESET%^\\\\\\\\\\////////////////
                  %^RED%^O    \\\%^RESET%^\        []         ////
                   %^RED%^       \\%^RESET%^\\     []      //// 
                     %^RED%^         \\%^RESET%^   []    //
                %^RED%^  O             \%^RESET%^  []   /
                                   []
                 %^RED%^ o%^RESET%^                []
                                   []
                 %^RED%^ o%^RESET%^                []
                                   []
                 %^RED%^ :%^RESET%^                []
                                   []
                 %^RED%^ .%^RESET%^                []

MYLONG
	);
	set_limbs(({"right leg"}));
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

