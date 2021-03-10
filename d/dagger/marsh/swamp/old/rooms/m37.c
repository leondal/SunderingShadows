#include <std.h>
inherit ROOM;
#define MPATH "/d/dagger/marsh/swamp/mon/"+
#define RPATH "/d/dagger/marsh/swamp/rooms/"+
int xy;
void create() {
    ::create();
   set_terrain(MARSH);
   set_travel(FRESH_BLAZE);
    set_property("light", 0);
    set_short("%^GREEN%^Dagger marsh%^RESET%^");
    set_long( "%^GREEN%^"
        "You are wandering within the depths of the %^CYAN%^Dagger marsh%^GREEN%^. "
	"The %^ORANGE%^bog%^GREEN%^ squishes below your feet and you "
	"are extremely careful not to fall prey to the patches of "
	"%^RED%^quicksand%^GREEN%^ that are surely to be found here. "
	"All around you %^BLUE%^insects%^GREEN%^ buzz madly. Many tales have surfaced "
	"about %^CYAN%^Dagger marsh%^GREEN%^ and the horrors that lie deep within its "
	"darkened pathways. Old rotten %^BOLD%^trees%^RESET%^%^GREEN%^ "
	"lay half-dead beside you covered in %^MAGENTA%^moss%^GREEN%^"
	" and %^MAGENTA%^creeper weeds%^GREEN%^."      
        "%^RESET%^"
    );
    set_listen("default",
 	"You hear the sound of your heart racing."
    );
    set_smell("default",
	"It smells of massive decay here."
    );
    set_items(([
        "bog":"%^GREEN%^The bog is murky and disgusting%^RESET%^",
        "quicksand":"There is bound to be patches of its somewhere.%^RESET%^",
        "paths":"The paths are small and twist through the bog.",
	"insects":"Insects buzz around your head in a frenzy.",
	"trees":"The trees are all half-dead and rotten and provide many odd "
	"shaped shadows to add to the darkened mood.",
	"weeds":"There is certainly an abundance of those here.",
	"moss":"The moss grows everywhere and on everything. It is as though "
	"vegetation is the master of this area.",
    ]));
    set_exits(([
	"east": RPATH "m36",
	"northwest": RPATH "m38",

    ]));
}
void reset() {
    ::reset();
    if(!present("thing") && !present("lizard") && !present("bogger") &&
	!present("mound") && !present("boa")) {
        xy = random(10);
        if(xy == 0) {
	    new( MPATH "thing.c" )->move(TO);
        }
        if(xy == 1) {
	    new( MPATH "lizard.c" )->move(TO);
        }
        if(xy == 2) {
	     new( MPATH "bogger.c" )->move(TO);
        }
        if(xy == 3) {
	    new( MPATH "mound.c" )->move(TO);
	}
        if(xy == 4) {
	    new( MPATH "boa.c" )->move(TO);
        }
        if(xy == 5) {
	    new( MPATH "lizard.c" )->move(TO);
            new( MPATH "boa.c" )->move(TO);
            new( MPATH "bogger.c" )->move(TO);
        }
        if(xy == 6) {
	    new( MPATH "thing.c" )->move(TO);
            new( MPATH "lizard.c" )->move(TO);
            new( MPATH "bogger.c" )->move(TO);
        }
    }
}
