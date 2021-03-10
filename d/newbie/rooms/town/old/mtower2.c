#include <std.h>
#include "../../newbie.h"

inherit INH"townmove.c";

void create() {
        ::create();
        set_property("indoors",1);
        set_property("no teleport",1);
        set_property("light",3);
        set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
        set_short("%^MAGENTA%^An imposing looking tower");
        set_long(
@STYX
You are in the middle of the imposing mage tower and definitely feel the magical energy of the weave in the air.  The beginning of the spiral staircase to the other two levels is along the southern wall and glass globes hang along the walls to softly light the room.  The walls are covered with tapestries picturing mages studying, casting, and alchemists refining components.
STYX
        );
        set_smell("default","The tower smells of spell components like sulfur and parchment from scrolls.");
        set_listen("default","Little disturbs the quiet here.");
        set_items(([
        ({"wall","walls"}) : "The walls are a thick stone, probably to withstand the practicing of spells that might go awry.",
        ({"globes","globe"}) : "The globes are very delicate etched glass and appear to be filled with phosphorescent moss that has been magically made to glow and provide light.",
        ({"tapestry","tapestries"}) : "One tapestry shows an elderly-looking alchemist working in a shop with jars of various components all around.  Another shows a young mage studying various scrolls with a mentor and pointing to sections with a questioning look.",
        ]));
        set_exits(([
        "east" : MAINTOWN"mtower3",
        "down" : MAINTOWN"mtower1",
        "up" : MAINTOWN"mtower4"
        ]));
}
