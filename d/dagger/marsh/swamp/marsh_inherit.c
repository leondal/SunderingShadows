#include <std.h>
#include "marsh.h"

inherit CROOM;

void make_creatures();

void create()
{
    make_creatures();
    set_repop(75);

    ::create();

    set_terrain(MARSH);
    set_travel(FRESH_BLAZE);
    set_property("light", 0);

    set_short("%^GREEN%^Dagger marsh%^RESET%^");

    if(base_name(TO) == "/d/dagger/marsh/swamp/marsh_inherit") { TO->set_property("no teleport",1); }

    set_long( "%^GREEN%^You are wandering within the depths of the %^CYAN%^Dagger marsh%^GREEN%^. "
	    "The %^ORANGE%^bog%^GREEN%^ squishes below your feet and you are extremely careful not to fall "
        "prey to the patches of %^RED%^quicksand%^GREEN%^ that are surely to be found here. All around "
        "you %^BLUE%^insects%^GREEN%^ buzz madly. Many tales have surfaced about %^CYAN%^Dagger marsh"
        "%^GREEN%^ and the horrors that lie deep within its darkened pathways. Old rotten %^BOLD%^trees"
        "%^RESET%^%^GREEN%^ lay half-dead beside you covered in %^MAGENTA%^moss%^GREEN%^ and %^MAGENTA%^"
        "creeper weeds%^GREEN%^.%^RESET%^");

    set_listen("default","You hear the sound of insects buzzing and the chitter of small animals.");
    set_smell("default","It smells of massive decay here.");

    set_items(([ "bog"          : "%^GREEN%^The bog is murky and disgusting%^RESET%^",
                 "quicksand"    : "There is bound to be patches of its somewhere.%^RESET%^",
                 "paths"        : "The paths are small and twist through the bog.",
	             "insects"      : "Insects buzz around your head in a frenzy.",
	             "trees"        : "The trees are all half-dead and rotten and provide many odd "
	                              "shaped shadows to add to the darkened mood.",
	             "weeds"        : "There is certainly an abundance of those here.",
	             "moss"         : "The moss grows everywhere and on everything. It is as though "
	                              "vegetation is the master of this area.",]));

}

void make_creatures()
{
   int monsters;
   monsters = has_mobs();
   if(!monsters)
   {
        if(mons) { mons = ([]); }

        switch(random(50))
        {
        case 0..9:
            set_monsters(({MON"thing.c",MON"lizard.c",MON"bogger.c"}),({1,1,1}));
            break;
        case 10..19:
            set_monsters(({MON"boa.c",MON"thing.c",MON"bogger.c",MON"lurker.c"}),({1,1,1,random(3)+1}));
            break;
        case 20..29:
            set_monsters(({MON"boa.c",MON"thing.c",MON"bogger.c",MON"lizard.c"}),
                            ({random(2),random(2),random(2),random(2)}));
            break;
        case 30..45:
            set_monsters(({MON"lizard.c",MON"thing.c",MON"bogger.c",MON"mound.c",MON"boa.c",MON"lurker.c"}),
                         ({roll_dice(1,2),roll_dice(1,2),roll_dice(1,2),roll_dice(1,2),roll_dice(1,2),roll_dice(1,2)}));
            break;
        case 46..49:
            set_monsters(({MON"mound.c"}),({roll_dice(1,3)}));
            break;
        }
   }
   return;
}
