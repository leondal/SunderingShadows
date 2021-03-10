#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property ("indoors", 1);
set_short ("The Wrath of Grapes Inn, upstairs");
set_long ("%^CYAN%^Upstairs you find a long hallway with twelve <doors> leading off to bedrooms.  All the <bedrooms> are the same, a single <bed>, <blankets>, <pillows>, a <clothes press>, a couple of hooks for clothes and a small <fireplace>.  The room is neat and clean and looks to be a good place to spend a night.");
set_smell ("default", "%^MAGENTA%^\nThe smell of fresh air and flowers fills the room.");
set_listen ("default", "You can still hear faint echoes of voices and song.");
set_exits (([
"down" : "/d/dagger/Elvanta/forest/Inn1"
]));
set_items
(([
"doors" : "The doors ar solid redwood.  Strong and hand carved .  The latches assure you of security.",
"bed" : "The bed is six feet long and four feet wide, covered by a mattress stuffed with horsehair.",
"blankets" : "Several blankets, pale yellow with green vines embroidered upon them rest upon the bed.",
"pillows" : "Your head would love these pillows.  Stuffed with down they are soft and warm.",
"clothes press" : "A wooden box three feet long, two feet high and wide, carved with vine designs upon the lid is where clothes are to be stored.",
"fireplace" : "The fireplace is made of grey white granite and by the amount of soot, has been used often.  Tinder and wood lay waiting for flint to strike.",
"bedrooms" : "Each room is twelve feet long by ten feet wide, clean, warm and bug free."
]));
}
