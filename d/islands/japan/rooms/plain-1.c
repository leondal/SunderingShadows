/*This room was compiled by Techen's ROOM EDITOR V1.355*/
#include <std.h>
#include "/d/islands/japan/def.h"
inherit ROOM;
void init() {
::init();

       do_random_encounters(({"/d/tharis/monsters/ehater"}),40,5);

}
void create() {
::create();
set_property ("light", 2 );
set_short( "A large field");
set_long(
@TECHEN
  You are wading in over a metre of raw sewage.  Small plants are 
growing happily.  The dock to the south looks is starting to look pretty
damb good right now.
TECHEN
);
add_item ("plants" , "These plants appear to be rice plants.");
add_item ("dock" , "The dock to the south is beginning to look like a nice place to be.");
add_item ("sewage" , "It is brown water that is flowing in from various pipes around the field.");
set_exits(([
"northwest" :EXIT "plain-5",
"west" :EXIT "plain-4",
"southwest" :EXIT "plain-2",
"south" :EXIT "dock",
"southeast" :EXIT "plain-3"
]) );
set_smell("default", "You smell raw sewage");
set_listen("default", "You hear water flooding into the fields.");
}

