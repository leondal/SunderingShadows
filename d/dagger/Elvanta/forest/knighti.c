#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The Knightly Inn, hallway");
set_long ("%^ORANGE%^This is a hallway, there isnt much else to say, it gets you from room to room, thats about it.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou can still smell smoke from the commons room, but also the faint aroma of roses.");
set_listen ("default", "The rumble of noise from the common rooms reaches you, but it is not disturbing.");
set_exits (([
"south" : "/d/dagger/Elvanta/forest/knightj",
"down" : "/d/dagger/Elvanta/forest/knighta",
"west" : "/d/dagger/Elvanta/forest/knightg",
"east" : "/d/dagger/Elvanta/forest/knighte"
]));
set_items
(([
"bed" : "The bed is made of solid oak, with handmade quilts of many colours laid upon it.  A pillow awaits your weary head.",
"table" : "A small bedside table stands about three feet high on three legs.  A jug and bowl for washing is there, as well as a vase of flowers to welcome you.",
"chair" : "A straight backed chair, sits beside the window.",
"press" : "A clothes press, four feet long, two feet wide, and two feet high sits at the end of the bed for your clothes.",
"flowers" : "A beautiful group of rugosa roses are set in the vase upon the night table.  The fragrance is heavenly.",
"jug" : "A plain white jug, made from clay is filled with water, for washing your weary face.",
"bowl" : "The bowl matches the jug, and waits to be filled.",
"window" : "The window looks out into the forest, sounds of wildlife can be heard if you listen hard enough."
]));
}
