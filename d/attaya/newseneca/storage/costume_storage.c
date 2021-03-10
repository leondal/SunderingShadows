#include <std.h>
#include "../seneca.h";

inherit ROOM;

void create() {
    ::create();
    set_name("Costume Designer's Storage Room");
    set_short("Costume Designer's Storage Room");
    set_long("Costume Designer's Storage Room\n"+
       "There is a lot of stuff here - and you shouldn't be.\n");
    set_light(2);
    set_indoors(1);
    set_travel(PAVED_ROAD);
    set_terrain(WOOD_BUILDING);
    set_property("no teleport",1);
    set_exits(([
       "up" : ROOMS"bard_costume"
    ]));
}

void reset() {
    ::reset();
    if(!present("ninja costume") && !random(3))
	new(OBJ"costume_ninja")->move(TO); 
    if(!present("fairy costume") && !random(3))
	new(OBJ"costume_fairy")->move(TO); 
    if(!present("bunny costume") && !random(3))
	new(OBJ"costume_bunny")->move(TO); 
    if(!present("witch costume") && !random(3))
	new(OBJ"costume_witch")->move(TO);
    if(!present("lion costume") && !random(3))
	new(OBJ"costume_lion")->move(TO);
    if(!present("belly dancer costume") && !random(3))
	new(OBJ"costume_dancer")->move(TO);
    if(!present("devil costume") && !random(3))
	new(OBJ"costume_devil")->move(TO);
    if(!present("ballerina costume") && !random(3))
	new(OBJ"costume_ballerina")->move(TO);
    if(!present("pirate costume") && !random(3))
	new(OBJ"costume_pirate")->move(TO);
    if(!present("bride costume") && !random(3))
	new(OBJ"costume_bride")->move(TO);
    if(!present("mermaid costume") && !random(3))
	new(OBJ"costume_mermaid")->move(TO);
    if(!present("pig costume") && !random(3))
	new(OBJ"costume_pig")->move(TO);
    if(!present("goblin costume") && !random(3))
	new(OBJ"costume_goblin")->move(TO);
    if(!present("jester costume") && !random(3))
	new(OBJ"costume_jester")->move(TO);
    if(!present("angel costume") && !random(3))
	new(OBJ"costume_angel")->move(TO);
    if(!present("guard costume") && !random(3))
	new(OBJ"costume_guard")->move(TO);
    if(!present("zombie costume") && !random(3))
	new(OBJ"costume_zombie")->move(TO);
    if(!present("wizard costume") && !random(3))
	new(OBJ"costume_wizard")->move(TO);
    if(!present("knight costume") && !random(3))
	new(OBJ"costume_knight")->move(TO);
    if(!present("groom costume") && !random(3))
	new(OBJ"costume_groom")->move(TO);
    if(!present("king costume") && !random(3))
	new(OBJ"costume_king")->move(TO);
    if(!present("queen costume") && !random(3))
	new(OBJ"costume_queen")->move(TO);
    if(!present("vampire costume") && !random(3))
	new(OBJ"costume_vampire")->move(TO);
    if(!present("random feathered mask"))
	new(OBJ"feathered_mask")->move(TO);
    if(!present("random feathered mask 2"))
	new(OBJ"feathered_mask")->move(TO);
    if(!present("random feathered mask 3"))
	new(OBJ"feathered_mask")->move(TO);
    if(!present("random feathered mask 4") && !random(3))
	new(OBJ"feathered_mask")->move(TO);
    if(!present("random feathered mask 5") && !random(4))
	new(OBJ"feathered_mask")->move(TO);
    if(!present("celestia mask") && !random(4))
	new(OBJ"mask_celestia")->move(TO);
    if(!present("arborea mask") && !random(4))
	new(OBJ"mask_arborea")->move(TO);
    if(!present("abyss mask") && !random(4))
	new(OBJ"mask_abyss")->move(TO);
    if(!present("baator mask") && !random(4))
	new(OBJ"mask_baator")->move(TO);
    if(!present("snowflake mask") && !random(4))
	new(OBJ"mask_snowflake")->move(TO);
    if(!present("flames mask") && !random(4))
	new(OBJ"mask_flame")->move(TO);
    if(!present("jester mask") && !random(4))
	new(OBJ"mask_jester")->move(TO);
    if(!present("cat costume") && !random(3))
	new(OBJ"costume_cat")->move(TO);
    if(!present("butterfly costume") && !random(3))
	new(OBJ"costume_butterfly")->move(TO);
}