
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^BLACK%^Blacksmithing.
");
set_long(
@SEETH
%^CYAN%^You leave the tiled path and come upon a place where the monks make their weapons. There is a large anvil and hammer infront of you. Many pieces of metal lay on the ground near a barrel of water. There is no ready made weapons here.
SEETH
);

set_items(([
"anvil" : "%^BLUE%^An old large anvil that has been used for ages.",
"hammer" : "%^BLUE%^An old hammer used to temper steel and other assorted metals.",
"barrel" : "%^BOLD%^%^CYAN%^A barrel full of water, meant to cool heated metal.",
"metals" : "%^CYAN%^Many pieces of metal that are laying on the ground till they are forged into something.",
]));

set_exits(([
"east" : RPATH "g2.c",
]));

set_smell("default", "%^BLUE%^The air smells of metal and sweat.");

}
