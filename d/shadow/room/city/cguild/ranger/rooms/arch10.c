#include <std.h>

inherit ROOM;

void create() {
   object ob;
   ::create();
   set_short("Archery range");
   set_property("no teleport", 1);
   set_long("You are here.");
   set_exits( ([
               "south":"/d/shadow/room/city/cguild/ranger/rooms/arch9",
               "north":"/d/shadow/room/city/cguild/ranger/rooms/arch11",
               ]) );
   ob = new("/std/obj/target");
   ob->set_difficulty(110);
   ob->move(TO);
   
   ob = new("/std/obj/target");
   ob->set_id(({"moving target", "forest","challenge", "master's","master's challenge","master's challenge target"}));
   ob->set_name("Forest Master's challenge target");
   ob->set_short("Forest Master's challenge target");
   ob->set_ac(-10);
   ob->set_difficulty(200);
   ob->move(TO);
}

