#include <std.h>
#include "../../kildare.h"
inherit ROOM;

void create()
{
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_short("Mariel's Clothing Storage");
        set_long("An assortment of cloth, thread, needles, and other things are kept here.");
        set_property("no teleport",1);
        set_exits((["down" : ROOMS"vil6"]));
}

void reset()
{
        ::reset();
if(!present("moccasins"))
 new(OBJ"moccasins")->move(TO);
if(!present("wool coat"))
 new(OBJ"woolcoat")->move(TO);
if(!present("hunting cap"))
 new(OBJ"huntingcap")->move(TO);
if(!present("leathergloves"))
 new(OBJ"gloves")->move(TO);
if(!present("mittens"))
 new(OBJ"mittens")->move(TO);
if(!present("sweater"))
 new(OBJ"c_sweater")->move(TO);
if(!present("leatherpants"))
 new(OBJ"leatherpants")->move(TO);
if(!present("scarf"))
 new(OBJ"c_scarf")->move(TO);
if(!present("kilt"))
 new(OBJ"c_kilt")->move(TO);

}
