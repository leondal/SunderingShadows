#include <std.h>
inherit ROOM;

void create(){
:: create();
  set_property("no teleport",1);
set_property("light", 2);
set_property("indoors", 0);
set_short("%^ORANGE%^A pathway");
set_long("%^ORANGE%^Large rocks begin to appear making your trek a difficult one.  The path you are travelling on seems to have been used but not frequently as small bits of scrub grabs at your feet.  You begin to lose sight of the beach as stands of poplars start to spring up around you.  To the east, larger hills begin to take shape, covered in wildflowers and bracken.");
set_smell("default", "%^CYAN%^\nYou can smell damp earth and the faint odour of sea.");
set_listen("default", "%^BLUE%^The sound of sea gives way to bird calls and creature movement.");
set_exits( ([
  "northwest" : "/d/hm_quest/rooms/quest2",
  "west" : "/d/hm_quest/rooms/quest4"
]) );
set_items(([
"pier" : "The pier appears to be several hundred years old, as the pilings are rotten and the planks teeter as you tread upon them",
"beach" : "A nice looking beach of sand and small plants appears to a welcome sight for any vacationer",
"rocks" : "Large rocks, the size of small elephants, and the same colour appear to try and block your way",
"path" : "The path is strewn with pebbles and scrub",
"scrub" : "Small plants struggle to stay alive in this area",
"hills" : "Vague outlines of purple hills, are dotted with bright reds, greens and orange wildflowers",
"wildflowers" : "Purple thistle, wild roses, and buttercups are among the few wildflowers you can identify upon the hills",
"plants" : "Small bits of crabgrass and the occaisional struggling bush try to survive on just sand and sky.",
"bird" : "A bird, with red wings, and a black beak circles above you screeching with joy or hatred, it's hard to tell",
"sand" : "Miles upon miles of golden sand is to the left and right of you."
]) );
if(!present("rock"))
new("/realms/svaha/items/rock")->move(TO);
}
