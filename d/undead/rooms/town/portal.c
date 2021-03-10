#include "../../undead.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Within the Castle de Boquillas");
    set_short("%^BOLD%^%^WHITE%^Within the Castle de Boquillas%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^You stand within the Castle de Boquillas.\n"
"%^RESET%^%^ORANGE%^This chamber leads off from the side of the main cathedral, "
"where you can see its arches reaching up towards the heavens.  Here, the "
"building is somewhat more %^CYAN%^subdued%^ORANGE%^, lacking the vibrant "
"stained glass windows that brighten the main chamber.  Instead, your eyes are "
"drawn to the only item of interest in this relatively austere chamber, a "
"%^BOLD%^%^WHITE%^high archway %^RESET%^%^ORANGE%^set within the wall that "
"seems to lead... outside?\n%^RESET%^");
    set_smell("default","The faint smell of incense hangs in the air.");
    set_listen("default","Only the quiet murmur of prayer breaks the silence "
"here.");
    set_exits(([
      "east":TOWN"church1",
      "enter":"/d/dagger/road/tempusportal",
    ]));
    set_invis_exits(({"enter"}));
    set_pre_exit_functions(({"enter"}),({"go_portal"}));

    set_items(([
      ({"church","cathedral","walls","castle","arches"}): "%^ORANGE%^The pale "
"%^BOLD%^%^WHITE%^alabaster-hued %^RESET%^%^ORANGE%^arches of the %^YELLOW%^"
"Castle de Boquillas %^RESET%^%^ORANGE%^rise up towards the heavens in the main "
"chamber beyond this subdued side-room.  Here, only one item draws the eye, a "
"%^BOLD%^%^WHITE%^high archway %^RESET%^%^ORANGE%^within the wall that seems to "
"lead outside.%^RESET%^",
      ({"arch","archway","outside"}): "%^ORANGE%^The only item of interest in "
"this room is a %^BOLD%^%^WHITE%^high archway%^RESET%^%^ORANGE%^ of the same "
"white stone as the rest of this building.  Through this opening, you can see "
"the %^BOLD%^%^CYAN%^open air %^RESET%^%^ORANGE%^outside, and a pathway leading "
"to a building of %^RED%^red stone%^ORANGE%^.  It is oddly peaceful outside, "
"unexpected on this isle of war.  You could likely %^BOLD%^%^WHITE%^<enter>"
"%^RESET%^%^ORANGE%^ the archway if you wished to proceed out.%^RESET%^", 
    ]));
}

int go_portal() {
    tell_object(TP,"%^BOLD%^%^CYAN%^There is a sudden flash as you step "
"through the archway, and you find yourself elsewhere!%^RESET%^");
    tell_room(TO,"%^BOLD%^%^CYAN%^There is a bright flash as "+TP->QCN+
" steps through the archway and disappears!%^RESET%^",TP);
    return 1;
}
