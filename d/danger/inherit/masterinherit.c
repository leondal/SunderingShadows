// Master inherit for all of Danger. 
// Every room on Danger continent should inherit this room.

#include <std.h>
inherit ROOM;
void create() {
   ::create();
   set_short("Master Inherit");
   set_long("Every room on Danger should inherit this room.");
}
