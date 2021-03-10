#include <std.h>
#include "../seneca.h";

inherit ROOM;

void create() {
    ::create();
    set_name("Esteban's Storage Room");
    set_short("Esteban's Storage Room");
    set_long("Esteban's Storage Room\n"+
       "There is a lot of stuff here - and you shouldn't be.\n");
    set_light(2);
    set_indoors(1);
    set_travel(PAVED_ROAD);
    set_terrain(WOOD_BUILDING);
    set_property("no teleport",1);
    set_exits(([
       "up" : ROOMS"clothes2"
    ]));
}

void reset() {

    ::reset();
    if(!present("seneca coat"))
	new(OBJ"seneca_coat")->move(TO); 
    if(!present("seneca pants"))
	new(OBJ"seneca_pants")->move(TO); 
    if(!present("seneca hat"))
	new(OBJ"seneca_hat")->move(TO); 
    if(!present("seneca gloves"))
	new(OBJ"seneca_gloves")->move(TO); 
    if(!present("seneca belt"))
	new(OBJ"seneca_belt")->move(TO); 
    if(!present("seneca boots"))
	new(OBJ"seneca_boots")->move(TO); 
    if(!present("regular gloves"))
      new(OBJ"e_gloves")->move(TO);
    if(!present("regular gloves 2"))
      new(OBJ"e_gloves")->move(TO);
    if(!present("regular shirt"))
      new(OBJ"e_shirt")->move(TO);
    if(!present("regular shirt 2"))
      new(OBJ"e_shirt")->move(TO);
    if(!present("regular shirt 3"))
      new(OBJ"e_shirt")->move(TO);
    if(!present("regular shirt 4"))
      new(OBJ"e_shirt")->move(TO);
    if(!present("regular shirt 5"))
      new(OBJ"e_shirt")->move(TO);
    if(!present("regular pants"))
      new(OBJ"e_pants")->move(TO);
    if(!present("regular pants 2"))
      new(OBJ"e_pants")->move(TO);
    if(!present("regular pants 3"))
      new(OBJ"e_pants")->move(TO);
    if(!present("regular pants 4"))
      new(OBJ"e_pants")->move(TO);
    if(!present("regular cloak"))
      new(OBJ"e_cloak")->move(TO);
    if(!present("regular cloak 2"))
      new(OBJ"e_cloak")->move(TO);
    if(!present("regular cloak 3"))
      new(OBJ"e_cloak")->move(TO);
    if(!present("regular coat"))
      new(OBJ"e_coat")->move(TO);
    if(!present("regular coat 2"))
      new(OBJ"e_coat")->move(TO);
    if(!present("regular coat 3"))
      new(OBJ"e_coat")->move(TO);
    if(!present("regular coat 4"))
      new(OBJ"e_coat")->move(TO);
    if(!present("regular shoes"))
      new(OBJ"e_shoes")->move(TO);
    if(!present("regular shoes 2"))
      new(OBJ"e_shoes")->move(TO);
    if(!present("regular shoes 3"))
      new(OBJ"e_shoes")->move(TO);
}