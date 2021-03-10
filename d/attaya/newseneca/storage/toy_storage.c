#include <std.h>
#include "../seneca.h";

inherit ROOM;

void create() {
    ::create();
    set_name("Toymaker's Storage Room");
    set_short("Toymaker's Storage Room");
    set_long("Toymaker's Storage Room\n"+
       "There is a lot of stuff here - and you shouldn't be.\n");
    set_light(2);
    set_indoors(1);
    set_travel(PAVED_ROAD);
    set_terrain(WOOD_BUILDING);
    set_property("no teleport",1);
    set_exits(([
       "up" : ROOMS"toystore"
    ]));
}

void reset() {

    ::reset();
    if(!present("deity stuffed animal"))
	new(OBJ"deity_stuffed")->move(TO); 
    if(!present("deity stuffed animal 2"))
	new(OBJ"deity_stuffed")->move(TO); 
    if(!present("deity stuffed animal 3"))
	new(OBJ"deity_stuffed")->move(TO); 
    if(!present("deity stuffed animal 4"))
	new(OBJ"deity_stuffed")->move(TO); 
    if(!present("deity stuffed animal 5"))
	new(OBJ"deity_stuffed")->move(TO); 
    if(!present("stuffed animalz 6") && random(3))
       new(OBJ"TOY_bear")->move(TO);
    if(!present("stuffed animalz 6") && random(3))
       new(OBJ"TOY_piggy")->move(TO);
    if(!present("stuffed animalz 6") && random(3))
       new(OBJ"TOY_purpledragon")->move(TO);
    if(!present("stuffed animalz 6") && random(3))
       new(OBJ"TOY_browndog")->move(TO);
    if(!present("stuffed animalz 6") && random(3))
       new(OBJ"TOY_kitten")->move(TO);
    if(!present("stuffed animalz 6") && random(3))
       new(OBJ"TOY_monster")->move(TO);
    if(!present("stuffed animalz 6") && random(3))
       new(OBJ"TOY_wolf")->move(TO);
    if(!present("wooden music box") && !random(4))
       new(OBJ"music_box1")->move(TO);
    if(!present("carousel music box") && !random(4))
       new(OBJ"music_box2")->move(TO);
    if(!present("shell music box") && !random(4))
       new(OBJ"music_box3")->move(TO);
}