//hall6
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit CROOM;

void create(){
::create();
   set_property("indoors",1);
   set_property("light",-3);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^Within a small shaft");
   set_short("%^RESET%^The inside of a pyramid%^RESET%^");
   set_listen("default","Whispers and soft hisses seem to float upon the stale air.");
   set_long((:TO,"ldesc":));
   set_items(([
   "walls":"The walls here are smooth to the touch.  A few pieces of rich fabric still cling to the walls in a few places.",
   ({"carpet","floor"}):"There are a few pieces of fabric lining the floor.  It looks as though perhaps they once were part of an old carpet.",
   "fabric":"Small pieces of fabric still cling to the walls in bits and pieces.  They are old and decayed and it is impossible to tell what color they once were.",
]));
   set_exits((["north":INRMS+"doorroom","south":INRMS+"hall4"]));
}
string ldesc(string str){
   return("%^BOLD%^%^BLACK%^This is a dark north-south hallway that is quite large and easy to walk through."
"  No slime covers the walls here, instead, they actually look like they might have been covered with rich"
" tapestries at one point.  Small pieces of fabric still hang down from near the top of the walls, and bits of"
" old carpet line the floor.%^RESET%^");
} 
