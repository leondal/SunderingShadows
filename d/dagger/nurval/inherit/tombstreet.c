#include <std.h>
#include "../tomb.h"

inherit ROOM;

string * randevents = ({
        "%^BLUE%^A platoon of heavily armed %^WHITE%^skeletons%^BLUE%^ marches through the place.%^RESET%^",
            "%^WHITE%^Ghost riders ride through on their phantasmal steeds.%^RESET%^",
            "%^BLUE%^Swarm of bats flies through, human figure inside of it.%^RESET%^",
            "%^BLUE%^A small group of humans in black robes passes through.%^RESET%^",
            "%^BLUE%^A lich passes through, followed by his mortal apprentice. Everyone bows before them.%^RESET%^",
    });

void create(){
    ::create();
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Necropolis");
    set_short("%^BOLD%^%^BLACK%^Inner streets of %^CYAN%^Tomb of Nurval%^RESET%^");
    set_long(
"%^BOLD%^%^BLACK%^Inner streets of %^CYAN%^Tomb of Nurval%^RESET%^
%^BOLD%^%^BLACK%^This wide tunnel is made of obsidian bricks. There are numerous doors embedded into its sides, but no windows. Some of the doors have plain signs of craft shops above them, most are in some way related to magic. The walls are plain black, with no decorations. The tunnel is divided into two paved lines, each wide enough for a platoon of troops to pass through. Twenty feet above the road the ceiling %^RESET%^%^CYAN%^il%^BOLD%^lumi%^RESET%^%^CYAN%^nates%^BOLD%^%^BLACK%^ the area with elaborate %^RESET%^%^CYAN%^g%^BOLD%^low%^RESET%^%^CYAN%^ing pa%^BOLD%^tte%^RESET%^%^CYAN%^rns%^BOLD%^%^BLACK%^. The 'life' seems busy here, and local inhabitants are busy with their activities.
"
        );
    set_smell("default","%^CYAN%^A smell of balsams and oils dominates the area.");
    set_listen("default","%^WHITE%^You hear the faint humming of a busy night in the necropolis.");
}

void reset()
{
    ::reset();
    tell_room(TO,randevents[random(sizeof(randevents))]);
}
