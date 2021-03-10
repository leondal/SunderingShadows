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
The air here is making you sick.  The plants, although in great
numbers don't cover entirely the view of the flowing liquid in
which they grow.
TECHEN
);
add_item ("sewage" , "This is lumpy water.");

set_exits(([
"east" :EXIT "dock",
"northeast" :EXIT "plain-1",
"north" :EXIT "plain-4"
]) );
set_smell("default", "You smell sewage");
set_listen("default", "You hear the sounds of nature");
}
