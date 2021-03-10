#include <std.h>
#include "../kildare.h"

inherit ROOM;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_name("A Secret Hideaway");
   set_short("A Secret Hideaway");
   set_smell("default","You smell the clean air of the mountains.");
   set_listen("default","It is blessedly quiet in here after the roaring wind of the mountainside.");
}
