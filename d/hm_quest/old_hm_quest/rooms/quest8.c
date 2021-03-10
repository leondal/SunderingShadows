#include <std.h>
inherit ROOM;

void create(){
:: create();
  set_property("no teleport",1);
set_property("light", 2);
set_property("indoors", 0);
set_short("%^ORANGE%^A pathway");
set_long("%^GREEN%^You look around the tree and see it has been made into a treehouse dwelling.  The branches weave to create walls, and the boughs overhead make a ceiling.  A bed made of carved wood rests in one corner with blankets tossed aside.  A small chest rests against the end of the bed.  On one wall a window is formed, looking out into the tree.  Against the furthest wall sits a table and a solitary chair.");
set_smell("default", "%^CYAN%^\nThe heady smell of leaves and sunlight fills your senses.");
set_listen("default", "%^BLUE%^The sound of the breeze through the trees whispers gently.");
set_exits( ([
  "down" : "/d/hm_quest/rooms/quest7"
]) );
set_items(([
"walls" : "The walls are woven branches, keeping out the wind and rain",
"roof" : "The boughs create a green canopy over your head",
"blankets" : "At one time, these blankets were finely woven and brightly patterned, however, time has taken its toll on the fabric, but signs of beauty still show through.",
"bed" : "A beautifully carved bed, with designs of flowers, and wild animals.",
"window" : "As you look out the window you can see the sea, sand and sky",
"ceiling" : "The boughs create a green canopy over your head.",
"boughs" : "Great leafy boughs create a canopy of life above your head",
"trees" : "Great stands of poplar, interwoven with the occaisional birch tree form this small forest",
"sand" : "Miles upon miles of golden sand is to the left and right of you."
]) );
if(!present("chair"))
new("/realms/svaha/items/qchair")->move(TO);
if(!present("table"))
new("/realms/svaha/items/qtable")->move(TO);
if(!present("chest"))
new("/realms/svaha/items/qchest")->move(TO);
}
