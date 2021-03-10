#include "../../newbie.h"
inherit ROOM;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("An imposing stone tower");
    set_short("%^MAGENTA%^An imposing stone tower");
    set_long("%^MAGENTA%^An imposing stone tower%^RESET%^\n"+
"You stand within the imposing wizard's tower of Offestry.  Its tall stone %^ORANGE%^walls %^RESET%^seem a little "
"crooked, whether from poor crafting or from some later incident.  The base of a spiral staircase lies against the "
"northern wall, leading to a room at the top of the tower, while glass %^CYAN%^globes %^RESET%^are spaced around the "
"walls to softly light the room.  Between them hang several %^GREEN%^tapestries%^RESET%^, depicting mages and some "
"spectacular spells.\n");
    set_smell("default","The tower smells of dry parchment, mingled with faint hints of sulfur.");
    set_listen("default","Little disturbs the quiet here.");
    set_items(([
        ({"wall","walls"}) : "%^ORANGE%^The walls are made of thick stone, probably to withstand the practicing of spells "
"that might go awry.  A few seem a little mis-aligned, though whether this is due to poor crafting or later impact "
"remains a mystery.  Regardless, the tower still seems quite sturdy.%^RESET%^",
        ({"globes","globe"}) : "%^CYAN%^The globes appear to be very delicate, etched from fine glass.  They have been "
"filled with phosphorescent moss that sheds a soft magical glow around the tower.%^RESET%^",
        ({"tapestry","tapestries"}) : "%^GREEN%^One especially impressive tapestry shows a mage standing to the side of a "
"battle with a bolt of lightning streaking from her hand.  Another shows a robed wizard in battle with swarms of meteors "
"blasting into the dragon that his allies are fighting.%^RESET%^",
    ]));
    set_exits(([
        "south" : MAINTOWN"wstreet3",
        "north" : MAINTOWN"magic",
        "west" : MAINTOWN"mtower5",
        "up" : MAINTOWN"mtower3",
    ]));
}