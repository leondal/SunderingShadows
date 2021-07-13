// Chernobog (3/6/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
#include <move.h>

#define SCRY_D "/daemon/ic_scry_locate_d"
inherit VAULT;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("Shadow Coliseum");
    set_short("%^BOLD%^C%^ORANGE%^olis%^RESET%^%^ORANGE%^eum %^BOLD%^%^WHITE%^A%^ORANGE%^re%^RESET%^%^ORANGE%^na%^WHITE%^");
    set_long("%^BOLD%^%^BLACK%^This is the main arena, the focal point and heart of the coliseum. %^RESET%^%^ORANGE%^Stone walls %^BOLD%^%^BLACK%^surround a field of %^RESET%^%^ORANGE%^sand %^BOLD%^%^BLACK%^at your feet while a %^GREEN%^s%^CYAN%^h%^GREEN%^i%^CYAN%^m%^GREEN%^m%^CYAN%^e%^GREEN%^r%^CYAN%^i%^GREEN%^n%^CYAN%^g %^GREEN%^a%^CYAN%^u%^GREEN%^r%^CYAN%^a %^BLACK%^caps the battlefield grounds. The audience seating rises up in concentric rings above the walls while a singular %^RESET%^%^MAGENTA%^v%^BOLD%^i%^RESET%^%^MAGENTA%^ew%^BOLD%^i%^WHITE%^n%^RESET%^%^MAGENTA%^g b%^BOLD%^o%^RESET%^%^MAGENTA%^x %^BOLD%^%^BLACK%^garbed in %^RESET%^%^MAGENTA%^p%^BOLD%^u%^RESET%^%^MAGENTA%^r%^BOLD%^p%^WHITE%^l%^RESET%^%^MAGENTA%^e %^BOLD%^%^BLACK%^stands alone to the northeast. A slatted %^RESET%^iron gate %^BOLD%^%^BLACK%^has been imbedded in the stone wall, the only obvious entrance or exit from the realm of the arena.%^RESET%^");
    set_smell("default","It smells of blood and sweat and dirt.");
    set_listen("default","The distant pennants snap in the wind.");
    set_items(([
        ({"box","magistrate box"}) : "%^BOLD%^%^BLACK%^These box seats are isolated from the common seats surrounding the %^RESET%^%^ORANGE%^coliseum%^BOLD%^%^BLACK%^. It is draped in %^RESET%^%^MAGENTA%^sil%^BOLD%^%^WHITE%^k%^MAGENTA%^e%^RESET%^%^MAGENTA%^n cl%^BOLD%^%^WHITE%^o%^MAGENTA%^t%^RESET%^%^MAGENTA%^h %^BOLD%^%^BLACK%^and marked by the symbol of Shadow, three interconnected rings of %^ORANGE%^g%^WHITE%^o%^ORANGE%^ld%^BLACK%^, s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r, and %^RESET%^%^ORANGE%^copper%^BOLD%^%^BLACK%^. It is an intimate location, with room for only the magistrate and a couple guests.%^RESET%^",
        ({"sand","ground"}) : "%^BOLD%^%^BLACK%^The ground is covered in a thin layer of %^RESET%^%^ORANGE%^sand%^BOLD%^%^BLACK%^, enough to offer solid footing for anyone battling within the arena.%^RESET%^",
        ({"walls","stands"}) : "%^ORANGE%^Solid stone walls %^BOLD%^%^BLACK%^rise up, encircling the perimeter of the arena. A thin %^GREEN%^t%^CYAN%^r%^GREEN%^a%^CYAN%^n%^GREEN%^s%^CYAN%^l%^GREEN%^u%^CYAN%^c%^GREEN%^e%^CYAN%^n%^GREEN%^t a%^CYAN%^u%^GREEN%^r%^CYAN%^a %^BLACK%^stretches overhead, and the audience stands begin past it, trailing up in stepped layers until meeting the %^RESET%^%^CYAN%^sky%^BOLD%^%^BLACK%^. A ring of cloth %^GREEN%^pe%^MAGENTA%^nn%^RED%^an%^ORANGE%^ts %^BLACK%^on flag poles crown the %^RESET%^%^ORANGE%^coliseum%^BOLD%^%^BLACK%^.%^RESET%^",
        "aura" : "%^BOLD%^%^BLACK%^A vague %^CYAN%^b%^GREEN%^o%^CYAN%^r%^GREEN%^d%^CYAN%^e%^GREEN%^r %^BLACK%^is apparent over the arena, evidence of some %^GREEN%^m%^CYAN%^a%^GREEN%^g%^CYAN%^i%^GREEN%^c %^BLACK%^at play, present to prevent interference to and from the combatants within.%^RESET%^",
        ]));
    set_exits(([
        "northeast" : ROOMS"concourse5",
        ]));
    set_door("iron gate", ROOMS"concourse5", "northeast", 0);
    set_door_description("iron gate","%^BOLD%^%^BLACK%^The massive gate is formed of woven bands of %^RESET%^iron %^BOLD%^%^BLACK%^in vertical and horizontal intersections, creating an %^RESET%^%^RED%^imposing %^BOLD%^%^BLACK%^and impressive barrier to the arena.%^RESET%^");
}

void reset()
{
    object scry_object;
    ::reset();
    if (!present("arena_listenerA")) {
        scry_object = new(OBJ "arena_listenerA");
        scry_object->set_caster("/d/shadow/coliseum/room/arena.c");
        scry_object->set_target("/d/shadow/coliseum/room/stands1.c");
        scry_object->move(TO);
    }
    if (!present("arena_listenerB")) {
        scry_object = new(OBJ "arena_listenerB");
        scry_object->set_caster("/d/shadow/coliseum/room/arena.c");
        scry_object->set_target("/d/shadow/coliseum/room/stands2.c");
        scry_object->move(TO);
    }
    if (!present("arena_listenerC")) {
        scry_object = new(OBJ "arena_listenerC");
        scry_object->set_caster("/d/shadow/coliseum/room/arena.c");
        scry_object->set_target("/d/shadow/coliseum/room/stands3.c");
        scry_object->move(TO);
    }
    if (!present("arena_listenerD")) {
        scry_object = new(OBJ "arena_listenerD");
        scry_object->set_caster("/d/shadow/coliseum/room/arena.c");
        scry_object->set_target("/d/shadow/coliseum/room/stands4.c");
        scry_object->move(TO);
    }
    if (!present("arena_listenerD")) {
        scry_object = new(OBJ "arena_listenerE");
        scry_object->set_caster("/d/shadow/coliseum/room/arena.c");
        scry_object->set_target("/d/shadow/coliseum/room/viewing_box.c");
        scry_object->move(TO);
    }
}

