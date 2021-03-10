#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_terrain(STONE_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_name("An abandoned temple");
    set_short("%^RESET%^%^BLUE%^An abandoned temple%^RESET%^");
    set_long("%^RESET%^%^BLUE%^An abandoned temple%^RESET%^\n"
"%^RESET%^You are standing within the stone building itself, its solid walls sweeping up on either side towards the heavens.  It must have been %^CYAN%^ma%^BOLD%^%^CYAN%^g%^RESET%^%^CYAN%^nif"
"%^BOLD%^%^CYAN%^ic%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^nt %^RESET%^when first built, the perfectly-interlocked stones still holding in most places despite obvious ages of abandonment.  Delicate "
"iconography can still be seen etched upon the walls, where they haven't crumbled or fallen away, or been overgrown by %^GREEN%^moss%^RESET%^ and %^BOLD%^%^GREEN%^v%^YELLOW%^i%^BOLD%^%^GREEN%^"
"nes%^RESET%^.  Rubble lies across the floor in several places, leaving holes where the roof has fallen in and letting in a few %^ORANGE%^r%^YELLOW%^a%^BOLD%^%^WHITE%^y%^RESET%^%^ORANGE%^s "
"%^RESET%^of natural light to the otherwise dark interior.  Broad %^ORANGE%^vessels %^RESET%^sit within niches of the walls, empty of whatever oil or other substance might once have lit the "
"chamber.  A massive table of %^BLUE%^stone %^RESET%^stands in the very centre of the room, seemingly yet untouched by the slow decay of the building.  The quiet serenity of the rest of the "
"island has given way to a solemn and reverent %^BLUE%^silence %^RESET%^here, so that even your own breathing seems loud in your ears.  With the heavy stone doors firmly closed, the only way "
"you can see out of here is a set of %^ORANGE%^cr%^RESET%^u%^ORANGE%^mb%^BOLD%^%^BLACK%^l%^RESET%^e%^ORANGE%^d %^RESET%^stairs leading from the far end of the building, down the dangerously "
"steep cliffside beyond.\n");

    set_smell("default","The air is completely still and dry.");
    set_listen("default","It is perfectly silent here.");
    set_exits( ([
        "out" : "/d/shadow/virtual/sea/hmquest.dock",
    ]) );
    set_items(([
      ({ "walls", "stones" }) : "%^RESET%^Despite its age and state of %^BLUE%^decay%^RESET%^, it's more than apparent that this building was once a creation of magnificence, its walls sweeping "
"skyward with stonework that still remains smooth and perfectly settled.  Intricate %^ORANGE%^et%^RESET%^c%^ORANGE%^hings %^RESET%^still mark the walls where they haven't been damaged by "
"weather, plant overgrowth, or the sheer weight of the ages.",
      ({ "iconography", "etchings" }) : "%^RESET%^Intricate markings pattern the walls, telling tales long lost that you can only guess at the meaning of now.  Drawings of wild beasts, peoples of every kind, shape or form, and countless trees and plants cover the walls.",
      ({ "moss", "vines", "overgrowth", "plants", "plant overgrowth" }) : "%^RESET%^%^GREEN%^V%^YELLOW%^i%^BOLD%^%^WHITE%^b%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^n%^RESET%^"
"%^GREEN%^t %^RESET%^leaves sprout from vines that crawl their way across the walls, while patches of %^GREEN%^mo%^CYAN%^s%^GREEN%^s %^RESET%^creep around the damp corners.",
      "vessels" : "%^RESET%^Beaten %^ORANGE%^co%^BOLD%^%^MAGENTA%^p%^RESET%^%^ORANGE%^per %^RESET%^vessels, in the shape of oval dishes, line most of the niches in the walls.  They seem "
"designed to hold oil or some similar fuel for %^BOLD%^%^RED%^b%^WHITE%^u%^YELLOW%^r%^BOLD%^%^MAGENTA%^n%^BOLD%^%^RED%^i%^YELLOW%^n%^BOLD%^%^RED%^g%^RESET%^, but at present they are empty.",
      "stairs" : "%^RESET%^A set of %^ORANGE%^cr%^RESET%^u%^ORANGE%^mb%^BOLD%^%^BLACK%^l%^RESET%^e%^ORANGE%^d %^RESET%^stairs lead out of the only open portal from this place, right at the far "
"side of the room.  They lead down the steep cliff beyond, and look to be in such disrepair as to be quite dangerous to descend.",
    ]));
    add_pre_exit_function("out","GoThroughDoor");
}

void init() {
    ::init();
    if(!present("stone table")) new("/d/hm_quest/obj/table")->move(TO);
}

void reset() {
    ::reset();
    if(!present("stone table")) new("/d/hm_quest/obj/table")->move(TO);
}

int GoThroughDoor() {
    tell_object(TP,"%^BOLD%^%^GREEN%^You depart the temple, treading carefully down the ruined stairs, though the world grows strangely hazy and your senses blur.");
    tell_object(TP,"%^BOLD%^You suddenly find yourself already safely down the broken stairs and dangerous cliffside.  How did you manage that?  You look around, slightly dazed.");
    return 1;
}