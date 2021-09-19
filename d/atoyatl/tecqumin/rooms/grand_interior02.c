#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit CROOM;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_name("A ruined apothecary");
  set_short( "%^CYAN%^A %^ORANGE%^ruined %^CYAN%^apothecary" );
  set_long( "%^BLUE%^Dusty %^ORANGE%^shelves%^BLUE%^ groaning with"
    +" %^RESET%^stone%^BLUE%^ and %^RED%^earthenware%^BLUE%^ pots line"
    +" the walls of the interior of this large circular building. A large"
    +" %^ORANGE%^workbench%^BLUE%^ in the centre of the space carries"
    +" mixing bowls, cutting tools and pestle and mortar sets."
    +" %^BOLD%^%^GREEN%^V%^RESET%^%^GREEN%^eg%^BOLD%^%^GREEN%^e"
    +"%^RESET%^%^GREEN%^t%^ORANGE%^at%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^"
    +"on%^BLUE%^ has crept in through the cracks and gaps in the walls,"
    +" but the %^BOLD%^%^BLACK%^lack of l%^RESET%^i%^BOLD%^%^BLACK%^ght"
    +" %^RESET%^%^BLUE%^has stopped it growing far. A few"
    +" %^BOLD%^%^WHITE%^m%^RESET%^us%^BOLD%^%^WHITE%^hr%^RESET%^oo"
    +"%^BOLD%^%^WHITE%^ms%^RESET%^BLUE%^ have sprouted under the"
    +" shelves here and there. At the back of the room, the staircase has"
    +" collapsed into ruin." );
  set_items(([  ({"pots", "earthenware pots", "stone pots"}) : "The"
    +" stone and earthenware pots are in various shapes and sizes. Most"
    +" are cracked, broken and empty, but a few retain cork stoppers or"
    +" wax sealant." ,
                ({"workbench"}) : "The workbench is stained from long"
    +" use, and has been left in some disarray, as though abandoned"
    +" mid-apothecarying" ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.\n");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.\n");}

