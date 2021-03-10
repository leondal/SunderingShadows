#include <std.h>
#include "../../kildare.h"
inherit ROOM;

void create()
{
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_short("David's Storage Room");
        set_long("Hanging meats and curing leathers are around the room.");
        set_property("no teleport",1);
        set_exits((["down" : ROOMS"vil4"]));
}

void reset()
{
        ::reset();
if(!present("cured meat"))
 new("/d/antioch/antioch2/obj/dried_meat")->move(TO);
if(!present("pine nuts"))
 new(OBJ"pine_nuts")->move(TO);
if(!present("strips of jerky"))
 new("/d/antioch/antioch2/obj/rawhide")->move(TO);
if(!present("waterskin"))
 new("/d/shadow/room/kildare/obj/kildare_skin")->move(TO);
if(!present("sausage links"))
 new(OBJ"sheep_sausage")->move(TO);
if(!present("crowdie"))
 new(OBJ"cheese")->move(TO);
if(!present("haggis"))
 new(OBJ"haggis")->move(TO);
if(!present("tools") && !random(2))
 new("/d/common/obj/misc/climb_tool")->move(TO);
if(!present("rope") && !random(2))
 new("/d/common/obj/misc/rope")->move(TO);
if(!present("soap") && !random(2))
 new("/d/common/obj/misc/soap")->move(TO);
if(!present("large pouch") && !random(2))
 new("/d/common/obj/misc/pouch")->move(TO);
if(!present("small pouch") && !random(2))
 new("/d/common/obj/misc/spouch")->move(TO);
if(!present("lantern") && !random(2))
 new("/d/common/obj/misc/beacon")->move(TO);
if(!present("oil") && !random(2))
 new("/d/common/obj/misc/oil")->move(TO);
if(!present("sack") && !random(2))
 new("/d/common/obj/misc/sack")->move(TO);
if(!present("bandage") && !random(2))
 new("/d/common/obj/misc/bandage")->move(TO);
}
