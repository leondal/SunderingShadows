#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
   object ob;
   ::create();
    set_short("Archery range");
    set_long("This is one of the rooms housing archery "+
      "targets used by the trainer.  You realize this is a "+
      "VERY bad place to be, and you should probably "+
      "leave the quickest way you can!");
    set_exits( ([
      "north" : "/d/newbie/rooms/special/arch4",
      "south" : "/d/newbie/rooms/special/arch2",
    ]) );
      ob = new("/std/obj/target");
      ob->set_difficulty(30);
      ob->move(TO);
}
