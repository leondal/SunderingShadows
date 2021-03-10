/*This room was compiled by Techen's ROOM EDITOR V1.355*/
#include <std.h>
#include "/d/islands/japan/def.h"
inherit ROOM;
void init() {
::init();
}
void create() {
::create();
set_property ("light", 2 );
set_short( "A large field");
set_long(
@TECHEN
  The fields continue.  There are small tuffs of plant life that
seem to be growing well in the sewage ridden ground.  You sigh as
you wonder how you will ever get the smell out of your clothes.
TECHEN
);
add_item ("plant" , "It is a small group of rice plants that have started to grow in the sewage.");
add_item ("field" , "This is a section of field that continues for miles.");
add_item ("fields" , "Looking at the fields makes you wonder.. Who needs all of this stuff.");
set_exits(([
"north" :EXIT "plain-8",
"southwest" :EXIT "plain-12",
"southeast"  :EXIT "plain-10"
]) );
set_smell("default", "You smell sewage.");
set_listen("default", "You hear only the sound of your footsteps.");
}
