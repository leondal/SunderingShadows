#include <std.h>

#define ANTIOCH "/d/antioch/antioch2/obj/"+

inherit ROOM;

void create() {
    ::create();
    set_property("no teleport",1);
    set_short("Rosinden's Back Room");
    set_long("Supplies and such are stored here and you should NOT be here.\n");
    set_exits( (["up" : "/d/shadow/room/ekibi/room/hut"]) );
}

void reset() {
object obj;
    ::reset();
if(!present("climbing tools"))
  new("/d/common/obj/misc/climb_tool")->move(TO);
if(!present("climbing tools 2"))
  new("/d/common/obj/misc/climb_tool")->move(TO);
if(!present("kit")){
  obj = new("/d/common/obj/potion/healing");
  obj->set_uses(random(4)+3);
  obj->move(TO);
}
if(!present("kit 2")){
  obj = new("/d/common/obj/potion/healing");
  obj->set_uses(random(4)+3);
  obj->move(TO);
}
if(!present("kit 3")){
  obj = new("/d/common/obj/potion/healing");
  obj->set_uses(random(4)+3);
  obj->move(TO);
}
if(!present("rope"))
  new("/d/common/obj/misc/rope")->move(TO);
if(!present("torch"))
  new("/d/common/obj/misc/torch")->move(TO);
if(!present("torch 2"))
  new("/d/common/obj/misc/torch")->move(TO);
if(!present("torch 3"))
  new("/d/common/obj/misc/torch")->move(TO);
if(!present("iron rations") && !random(4))
 new(ANTIOCH"iron_rations")->move(TO);
if(!present("standard rations") && !random(2))
 new(ANTIOCH"standard_rations")->move(TO);
if(!present("dry rations") && !random(3))
 new(ANTIOCH"dry_rations")->move(TO);
}
