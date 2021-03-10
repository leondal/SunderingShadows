#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^The path itself is a vague line winding over the grassy hills and distinguishable only by the occaisional rain-washed ruts and flat, hard patches of earth breaking through the heavy grass.  Ahead of you lies more grassland, the same for west and east, but as you try to look into the distance, a large forest covers the horizon.");
set_smell("default", "%^BOLD%^BLUE%^\nRain soaked grasses sends clouds of pollen into the air making you sneeze.");
set_listen("default", "%^CYAN%^Crickets, mice and small birds make their presence heard.");
set_exits (([
"south" : PROOM+"room45.c",
"southeast" : PROOM+"room42.c"
]));
set_items(([
"path" : "It is a long and winding roadway to something, to somewhere.",
"hills" : "Dust coloured hills appear, somewhat barren, but you can hear sounds of life.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are going.",
"forest" : "It is a forest, has trees, green stuff, but also, well, now that would be giving it away, now wouldn't it?"
]));
if(!present("deer"));
new("/realms/svaha/monsters/deer")->move(TO);
}
