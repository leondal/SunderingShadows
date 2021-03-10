#include <std.h>
#include <money.h>
#include <move.h>
#include "../../tecqumin.h"

inherit HEALER;

void create() {
    ::create();
    set_light(3);
    set_property("training",1);
    set_indoors(1);
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_short("Ixchel's apothecary");
    set_long("This smallish hut has a few cots where sick or injured tabaxi and their guests can be cared for. Ixchel tends to the patients using a range of herbal remedies and hedge magic. There are rows of shelves of herbs and apothecarian accoutrements");
    set_smell("default", "The strong odor of herbs and balms turns your stomach.");
    set_listen("default", "The sound of simmering liquids emmanates from a glass potion bottle that bubbles away over a small flame.");
    set_exits( ([
        "out" : TABAXROOM + "centre"
    ] ));
    set_name("Ixchel");
}

void reset(){
    ::reset();
    if(!present("Ixchel", TO)){ 
        find_object_or_load(MOB + "ixchel")->move(TO);
    }
}
