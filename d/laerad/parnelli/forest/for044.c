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
	"that you just don't ever want to leave.  A large mountain range lies "+
	"to the north and west."
    );
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for055",
	"south":"/d/laerad/parnelli/forest/for045",
	"southwest":"/d/laerad/parnelli/forest/for034"
    ]) );
}
