//tstatue.c

#include <std.h>
#include <daemons.h>

#define BETAS ({"Praetor","Kaja","Krink","Hunter","Hazard","Moonbow","Tsulu","Hopper","Therex","Darkstar","Knowla","Coyotte","Anna","Trudge","Tuco","Duncan","Menolly","Gareth","Vassago","Clever","Meatha","Captc","Keasha","David","Camden","Lethe","Hotblack","Gabrielle","Imlac","Nadcorp","Robin","Sweetsavage","Sera","Shroomy"})

inherit OBJECT;

void init(){
	::init();
	add_action("read","read");
	}
	
void create(){
	::create();
	
	set_name("Statue");
	set_id(({"statue","monument"}));
    set("short","%^BOLD%^%^YELLOW%^A grand monument carved from the earth itself");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^The monument of eternal adventure %^RESET%^
This massive statue stands before you as a monument to all time. Here 
stands the monument that was dedicated by the creators of the world to
the eternal adventure that life will bring us. The grand figure above
you lacks distinguishing features, You almost see your own face. A large
plaque is imbedded in the base of the statue.
OLI
	);
	set_weight(100000);
	set_value(10000);
	}
	
int read(string str){
	string tmp,tmp2;
	int i;
	if(!str || str != "plaque") return  0;
	
	tell_room(environment(TO),TPQCN+" reads over the plaque!",TP);
	tmp = ({"%^BOLD%^%^CYAN%^We give great thanks to the following Beta testers:\n%^BOLD%^%^YELLOW%^"});
	for(i=0;i<sizeof(BETAS);i+=4){

		if(i < sizeof(BETAS))
			tmp2 = "%^BOLD%^%^YELLOW%^"+arrange_string(BETAS[i],15)+"\t";
		if(i+1 < sizeof(BETAS))
			tmp2 = tmp2+"%^BOLD%^%^YELLOW%^"+arrange_string(BETAS[i+1],15)+"\t";
		if(i+2 < sizeof(BETAS))
			tmp2 = tmp2+"%^BOLD%^%^YELLOW%^"+arrange_string(BETAS[i+2],15)+"\t";
		if(i+3 < sizeof(BETAS))
			tmp2 = tmp2+"%^BOLD%^%^YELLOW%^"+arrange_string(BETAS[i+3],15)+"\t\n";
					tmp += ({tmp2});
	}
	tmp += ({"%^BOLD%^%^GREEN%^\n\nPlease Note that players receiving wizships do not appear on this list"});
	
	TP->more(tmp);
	
	return 1;
	}
	
