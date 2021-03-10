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
set_short( "A small path");
set_long(
@TECHEN
You have come across a large stretch of land that seems to push you
towards the south.  A large forest lay down the road, it beckons
you to approch it.
TECHEN
);
add_item ("forest" , "It is a large.. well lit forest.  It has a large road cut threw it.");
add_item ("road" , "You see a road that seem to be lined with human bones.");
set_exits(([
"south" :EXIT "plain-7",
"northwest" :EXIT "plain-1",
"west" :EXIT "dock"
]) );
set_smell("default", "You smell a cocktail of odors from flowers to sewage.");
set_listen("default", "You can hear birds chirping.");
}
