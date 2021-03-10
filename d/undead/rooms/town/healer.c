#include "../../undead.h"
inherit HEALER;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Sabrina");
    set_short("%^BOLD%^%^WHITE%^Within the Castle de Boquillas");
    set_long("%^BOLD%^%^WHITE%^You stand within the Castle de Boquillas.\n"
"%^RESET%^%^ORANGE%^This side-chamber is strung with %^GREEN%^herbs %^ORANGE%^"
"hanging from the ceiling to dry, and all kinds of bottles and jars of various "
"substances upon shelves around the room.  A small %^RED%^fire %^ORANGE%^burns "
"in a fireplace in the corner of the room, warming it and adding a pleasant "
"%^YELLOW%^light %^RESET%^%^ORANGE%^to the area.  A pile of cushions to the "
"side of the fireplace looks to serve as a comfortable and cosy resting place "
"for the apothecary when she is not at work.%^RESET%^");
    set_smell("default","The faint smell of incense hangs in the air.");
    set_listen("default","It is very quiet here.");
    set_exits(([
      "west":TOWN"church1",
    ]));

    set_items(([
      ({"church","cathedral","walls","castle"}): "%^ORANGE%^The pale "
"%^BOLD%^%^WHITE%^alabaster-hued %^RESET%^%^ORANGE%^walls of the Castle de "
"Boquillas are covered in many places here by %^GREEN%^herbs %^ORANGE%^and "
"shelves.%^RESET%^",
      ({"herbs","jars","shelves","bottles"}): "%^ORANGE%^Drying %^GREEN%^herbs "
"%^ORANGE%^hang from the ceiling, while jars and bottles of various alchemical "
"substances lie on shelves around the room.%^RESET%^", 
      ({"fire","fireplace"}): "%^ORANGE%^A %^RED%^cosy fireplace %^ORANGE%^"
"serves to warm the area and shed light around the room.%^RESET%^",
      ({"cushions","pile"}): "%^ORANGE%^A pile of cushions sits by the fire, "
"serving as a comfortable resting place for the apothecary.%^RESET%^",
    ]));
}

void reset() {
    ::reset();
    if(!present("healer"))
        find_object_or_load(MON"sabrina")->move(TO);
}
