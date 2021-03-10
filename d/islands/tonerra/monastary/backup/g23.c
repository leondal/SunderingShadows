
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^GREEN%^Monastary Garden.
");
set_long(
@SEETH
%^GREEN%^You left the tiled path and travelled into a field of bamboos. The bamboos stand tall well above your head. There is enough room for you to move throughout the bamboo field.
SEETH
);

set_items(([
"bamboos" : "%^BOLD%^%^GREEN%^A field of bamboos. They are very hard and sturdy.",
]));

set_exits(([
"west" : RPATH "g22.c",
"south" : RPATH "g15.c",
"southwest" : RPATH "g14.c",
]));

set_smell("default", "The air is wonderfully clean and refreshing.");

}
