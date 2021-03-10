//updated by Circe 5/31/04 with color, etc.
// Level 3 Landing in the Tower of the Arcane, Tabor
// Thorn@ShadowGate
// 010206
// Tabor
// tfloor3.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create()
{
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_name("Floor 3");
    set_short("Level 3 Landing in the Tower of the Arcane, Tabor");
    set_long(
@TOWER
%^BOLD%^Level 3 Landing in the Tower of the %^CYAN%^A%^YELLOW%^r%^CYAN%^c%^YELLOW%^a%^CYAN%^n%^YELLOW%^e%^WHITE%^, Tabor%^RESET%^
%^BOLD%^%^BLACK%^This is the third level of the Tower of the Arcane.  From here 
you can look down a fine %^RESET%^bl%^BOLD%^%^BLACK%^ac%^RESET%^k ma%^BOLD%^%^BLACK%^rb%^RESET%^le%^BOLD%^%^BLACK%^ staircase to the 
second level.  This staircase also leads up to the next level.

%^RESET%^To the north, you can see a huge amphitheater with raised seating.
TOWER
    );
    set_property("light",2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    set_property("indoors",1);
    set_smell("default","A slight scent of ozone hangs in the air.");
    set_listen("default","Voices from throughout the tower reach your ears.");
    set_items(([
       ({"steps","stairs","staircase"}) : "This grand staircase has been worn "+
          "by countless feet.  It is made of deep black marble, and "+
          "it still glitters like new.",
       ({"hall","assembly hall","amphitheater"}) : "The large assembly "+
          "hall to the north takes up the entire floor.  It is filled "+
          "with benches on raised platforms, each one higher than the "+
          "one before it to allow all magi view of the central area, "+
          "which looks to be some sort of speaker's platform.  On that "+
          "dais, there are five padded chairs and a tall podium."
    ]));
    set_exits( ([
        "north" : ROOMDIR+"tconf",
        "down"  : ROOMDIR+"tfloor2",
        "up"    : ROOMDIR+"tfloor4"
    ]) );
}
