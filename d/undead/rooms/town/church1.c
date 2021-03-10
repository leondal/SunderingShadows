#include "../../undead.h"
inherit "/std/church";

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Within the Castle de Boquillas");
    set_short("%^BOLD%^%^WHITE%^Within the Castle de Boquillas%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^You stand within the Castle de Boquillas.\n"
"%^RESET%^%^ORANGE%^Around you rise the stone-sculpted walls of the %^YELLOW%^"
"Castle de Boquillas%^RESET%^%^ORANGE%^, tall and magnificent.  In fact, it "
"appears only to be a castle by name, and truly more of a grand cathedral at "
"heart.  Fine %^BOLD%^%^WHITE%^alabaster-hued %^RESET%^%^ORANGE%^arches rise "
"overhead, segregated by windows of stained glass that depict great and "
"triumphant %^RED%^battles%^ORANGE%^.  A central altar of %^BOLD%^%^WHITE%^"
"white marble %^RESET%^%^ORANGE%^stands at the head of the room, set about with "
"glimmering candles.  Corridors wind away between the arches to either side, "
"leading further into the cathedral.  Despite the war raging outside, it is "
"relatively %^CYAN%^peaceful %^ORANGE%^here, as though it were cut off from the "
"rest of the island.%^RESET%^");
    set_smell("default","The faint smell of incense hangs in the air.");
    set_listen("default","Only the quiet murmur of prayer breaks the silence "
"here.");
    set_exits(([
      "north":TOWN"church2",
      "east":TOWN"healer",
      "west":TOWN"portal",
      "south":TOWN"street3",
    ]));

    set_items(([
      ({"church","cathedral","walls","castle","arches"}): "%^ORANGE%^The pale "
"%^BOLD%^%^WHITE%^alabaster-hued %^RESET%^%^ORANGE%^arches of the %^YELLOW%^"
"Castle de Boquillas %^RESET%^%^ORANGE%^rise around you, more like a grand "
"cathedral than a castle.",
      ({"windows","battles","stained-glass","glass"}): "%^ORANGE%^Between the "
"sweeping arches are windows of stained glass, depicting %^RED%^glorious "
"battlescenes %^ORANGE%^in vivid backlit colors.%^RESET%^",
      ({"altar","candles"}): "%^ORANGE%^At the head of the room lies a "
"severely-cut altar of %^BOLD%^%^WHITE%^white marble%^RESET%^%^ORANGE%^.  "
"Burning candles shed flickering %^YELLOW%^light %^RESET%^%^ORANGE%^across its "
"stone surface.%^RESET%^", 
    ]));
}

void reset() {
    ::reset();
    if(!present("ximes priest"))
        find_object_or_load(MON"priest")->move(TO);
}
