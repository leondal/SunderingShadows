#include "../../undead.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("The City of Graez");
    set_short("%^ORANGE%^A dim back room%^RESET%^");
    set_long("%^ORANGE%^A dim back room%^RESET%^\n"
"Another of the many renovated warehouses and shacks around town, this one "
"is small but %^MAGENTA%^cosy%^RESET%^.  The room is sealed well enough "
"that noise from outside is muted nearly to silence, an uncanny change "
"after the constant din outdoors.  The only %^YELLOW%^light %^RESET%^in the "
"room is shed from a few dim lanterns about the room.  Very little "
"furniture clutters the already cramped room, only a desk with a chair, and "
"a large chest which sits on the floor behind it.\n");
    set_smell("default","The smell of smoke and ale drifts in from the bar.");
    set_listen("default","Muted sound is barely audible from beyond the room.");

    set_exits(([
        "out":TOWN"pub"
    ]));

    set_items(([
      ({"light","lanterns"}): "The only %^YELLOW%^lighting %^RESET%^within "
"the room emanates from a few dim lanterns placed around the area, which "
"seem to add as many %^BOLD%^%^BLACK%^shadows %^RESET%^as they dismiss.",
      ({"furniture","chair","desk","chest"}): "Even the few pieces of "
"furniture in the room serve to %^CYAN%^clutter %^RESET%^its small area.  A "
"desk and chair segregate one half of the room from the other, behind which "
"sits a large storage chest.", 
    ]));
}

void reset() {
    ::reset();
    if(!present("nicoli")) find_object_or_load(MON"nicoli")->move(TO);
}
