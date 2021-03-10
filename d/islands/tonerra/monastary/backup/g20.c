
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^BOLD%^%^GREEN%^A large clearing.
");
set_long(
@SEETH
%^GREEN%^Before you is a large clearing. It looks like many of the monks practice here. You can see the many footprints on the ground. To the east of here, you see this large stone platform with four pillars around it. 
SEETH
);

set_items(([
"road" : "A dirt path leading to a well or clearing.",
"path" : "A dirt path leading to a well or clearing.",
"clearing" : "%^BOLD%^%^GREEN%^A large clearing of dirt where the monks practice.",
]));

set_exits(([
"west" : RPATH "g19.c",
"east" : RPATH "g21.c",
]));

set_smell("default", "%^BOLD%^%^CYAN%^The air is refreshing and comfortable.");

}
