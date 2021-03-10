//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_long(
	"%^BOLD%^GREEN%^The Parnelli Forest%^RESET%^\n"+
	"You have walked into a magical forest.  The trees sway back and forth "+
	"as if hypnotized.  Leaves dance around happily in the wind.  The brush "+
	"looks as if it is glowing with pure energy.  You notice the occasional "+
	"firefly or pixie flitter through the air.  The sky above is the most "+
	"beautiful blue you have ever seen.  You feel such a serene peace here "+
	"that you just don't ever want to leave.  There is a beautiful river "+
	"off to the east.  There is a large stone bridge built here so people "+
	"can cross the water to the city of Asgard.  The gates to the infamous "+
	"city are right to the east."
    );
    set_exits( ([
	"bridge":"/d/laerad/parnelli/asgard/as01",
	"west":"/d/laerad/parnelli/forest/for038",
	"north":"/d/laerad/parnelli/forest/for048",
	"south":"/d/laerad/parnelli/forest/for050"
    ]) );
   set_pre_exit_functions( ({"bridge"}),({"no_forestmons"}) );
}

int no_forestmons() {
   if(member_array("forestmon",TP->query_id()) != -1)   return 0;
   return 1;
}