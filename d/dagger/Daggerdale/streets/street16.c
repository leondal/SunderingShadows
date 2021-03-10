#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("A ruined town square");
    set_short("%^BOLD%^%^BLACK%^A ruined town square%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You stand on a ruined street. It was obviously the scene of a %^RESET%^%^RED%^"
"bloody battle%^BOLD%^%^BLACK%^, as the ground is pockmarked with small craters and the fine cobblestones have "
"been mostly ruined. To the east lies a burned out building.%^RESET%^\n\n"

// start of feywild spread from the centre of daggerdale here. This is intended to take potentially decades, given it is fighting against opposing shadow energy in the area.
"%^RESET%^Between the cracks in the cobblestones, tendrils of %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^lia"
"%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^e %^RESET%^have started to sprout, slowly but surely suppressing %^ORANGE%^stone "
"%^RESET%^and %^BOLD%^%^BLACK%^shadow %^RESET%^beneath their verdant grasp. They appear to be spreading from the "
"%^BOLD%^%^GREEN%^young tree %^RESET%^in the centre of the ruins.\n");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits(([
      "north" : STREETS"street22",
      "west" : STREETS"street15",
      "east" : SHOPS"woodwright",
    ]));
}