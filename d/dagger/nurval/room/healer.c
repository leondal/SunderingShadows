#include <std.h>
#include "../tomb.h"

inherit HEALER;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(1);
    set_short("%^BOLD%^%^WHITE%^The %^BLUE%^Last%^BLACK%^ Remedy%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^The %^BLUE%^Last%^BLACK%^ Remedy%^RESET%^
%^BOLD%^%^BLACK%^This square chamber is mostly unremarkable. Massive black stone tables stand on the floor, partially decomposed or damaged %^RESET%^%^ORANGE%^bodies%^BOLD%^%^BLACK%^ rest on them, there are several %^WHITE%^s%^BLACK%^k%^WHITE%^e%^BLACK%^l%^WHITE%^e%^BLACK%^t%^WHITE%^o%^BLACK%^n%^WHITE%^s%^RESET%^%^BOLD%^%^BLACK%^ as well. A small group of undead healers are tending to the bodies: applying balsams, cutting out eternal organs, tying up soaked in oils %^RESET%^%^ORANGE%^ban%^WHITE%^ds%^BOLD%^%^BLACK%^ and otherwise preparing and repairing the corpses. By the walls of this chambers stone shelves hold endless collection of %^WHITE%^vials%^BLACK%^ and alchemical preparations. The room is illuminated by %^RESET%^%^CYAN%^gl%^BOLD%^o%^RESET%^%^CYAN%^wing patterns%^BOLD%^%^BLACK%^ on the ceiling, same as in the corridor outside.
");
    set_smell("default", "%^WHITE%^The room has a distinct odor of alcohol and oils.");
    set_listen("default", "%^BLUE%^The room is deadly silent.");
    set_exits((["south" : ROOMS+"/tomb1"] ));
    set_name("Hehet");
    if(!present("hehet"))
    {
        find_object_or_load(MONS+"/hehet")->move(TO);
    }
}

void reset()
{
    ::reset();
    if(!present("hehet"))
    {
        find_object_or_load(MONS+"/hehet")->move(TO);
    }
}
