/*This room was compiled by Techen's ROOM EDITOR V1.355*/
#include <std.h>
#include "/d/islands/japan/def.h"
inherit ROOM;
void init() {
::init();
}
void create() {
::create();
set_property ("light", 1 );
set_short( "A large field");
set_long(
@TECHEN
  This field seems to be growing a differnt crop than the rest.  It
is the home of many larger plants..          Perhapes the best thing
of all is the lack of sewage in this area.
TECHEN
);
add_item ("plant" , "These plants seems to be corn.");
add_item ("plants" , "These plants seem to be corn.");
add_item ("field" , "This field contains different plants then the others.");
set_exits(([
"northwest" :EXIT "plain-9",
"west" :EXIT "plain-11"
]) );
set_smell("default", "The smell here is less powerful");
set_listen("default", "You hear only the sloshing of your feet");
}

