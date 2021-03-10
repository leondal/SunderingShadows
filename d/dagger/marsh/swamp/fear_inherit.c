#include <std.h>
#include "marsh.h"

inherit CROOM;

void make_creatures();

object the_uncle;

void create()
{
    make_creatures();
    set_repop(99);

    ::create();

    set_terrain(MARSH);
    set_travel(FRESH_BLAZE);
    set_property("light", -1);
    set_property("no teleport",!random(6));

    set_short("%^BLUE%^Marsh of Fear%^RESET%^");

    set_long( "%^RESET%^%^BLUE%^The marsh now is very dark as the %^GREEN%^rotten vegetation%^BLUE%^ "
      "and %^ORANGE%^trees%^BLUE%^ grow up to form a canopy above you. Blackness fills the area making "
      "movement treacherous and slow. The %^MAGENTA%^bog%^BLUE%^ squishes below your feet and you are "
      "extremely careful not to fall prey to the patches of %^RED%^quicksand%^BLUE%^ that are surely to "
      "be found here.  All around you %^YELLOW%^insects%^RESET%^%^BLUE%^ buzz madly. The vegetation seems "
      "to own this marsh, growing possessed and with an insane frenzy. It is almost as though the land "
      "here seeps evil and is sentient and aware of those which walk upon its surface.\n%^RED%^You feel "
      "as though a great evil lives deeper within the marsh and wants you to wander deeper and closer "
      "to it.%^RESET%^");

    set_listen("default","The marsh of fear seems to whisper its evil insanity into your ears.");
    set_smell("default","It smells of death, rotting vegetation and foul ichor.");

    set_items(([ "bog"          : "%^GREEN%^The bog is murky and disgusting%^RESET%^",
	             "quicksand"    : "There is bound to be patches of its somewhere.%^RESET%^",
	             "paths"        : "The paths are small and twist through the bog.",
	             "insects"      : "Insects buzz around your head in a frenzy.",
	             "trees"        : "The trees are all half-dead and rotten and provide many odd "
	                              "shaped shadows to add to the darkened mood.",
	             "vegetation"   : "There is certainly an abundance of that here.",
	             "moss"         : "The moss grows everywhere and on everything. It is as though "
	                              "vegetation is the master of this area.",]));
}

// some of these can potentially be 0 on purpose
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
            set_monsters(({MON"calf.c",MON"banshee.c"}), ({random(4),random(2)}));
            break;
        case 10..19:
            set_monsters(({MON"reaver.c",MON"banshee.c"}),({random(4),random(2)}));
            break;
        case 20..29:
            set_monsters(({MON"bog.c",MON"calf.c"}),({random(3),random(3)}));
            break;
        case 30..47:
            set_monsters(({MON"reaver.c",MON"bog.c",MON"banshee.c",MON"calf.c"}),
                         ({roll_dice(1,4),roll_dice(1,3),random(2),roll_dice(1,3)}));
            break;
        case 48..49:
            set_monsters(({MON"uncle.c"}),({1}));
            break;
        }
   }
   return;
}
