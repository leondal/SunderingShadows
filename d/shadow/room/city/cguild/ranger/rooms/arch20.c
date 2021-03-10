
#include <std.h>

inherit ROOM;

void create() {
   object ob;
   ::create();
   set_short("Archery range");
   set_property("no teleport", 1);
   set_long("You are here.");
   set_exits( ([
               "south":"/d/shadow/room/city/cguild/ranger/rooms/arch19",
               //"north" : "/d/shadow/room/city/cguild/ranger/rooms/arch21",
               ]) );
   ob = new("/std/obj/target");
   ob->set_difficulty(125);
   ob->move(TO);
   
   ob = new("/std/obj/target");
   ob->set_id(({"challenge","ranger's"}));
   ob->set_name("Master ranger's challenge target");

   ob->set_short("Master ranger's challenge target");
   ob->set_ac(-10);
   ob->set_difficulty(250);
   ob->move(TO);
}
