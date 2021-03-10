#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("An elven home, bedroom");
set_long ("%^GREEN%^This is obviously an extra room.  A simple <bed> with <covers> and <pillows> takes up most of the room.  A small <table> sits beside the bed with a <bowl> of <flowers>.  A porthole <window> looks out upon the <forest>.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of lavender reaches your nose from small sachets placed in the clothes press.");
set_listen ("default", "You heave only the whisper of the wind through the trees.");
set_exits( ([
"west" : "/d/dagger/Elvanta/forest/roomH4f"
]) );
set_items(([
"clothes press" : "This is a wooden box, five feet long, three feet wide and two and a half feet tall.  It is to hold clothes and extra blankets for those who may visit.",
"bed" : "The bed measures five feet long and three feet wide made of aged oak.",
"covers" : "Covers with floral designs woven into the wool will keep a guest warm at night.",
"pillows" : "Floral decorated pillows are set upon the bed>",
"table" : "A small three legged night table hold a bowl of flowers and a jug of water.",
"bowl" : "The bowl is made of polished grey green granite.",
"flowers" : "Lilies of every hue fill the bowl with vibrant colour.",
"window" : "The round window is covered by curtains with the same pattern as the covers.",
"forest" : "The forest is tall and well filled with creatures of many kinds."
]) );
}
void reset(){
::reset();
if(!present("elf"))
new("/d/dagger/Elvanta/forest/mon/elf")->move(TO);
}
