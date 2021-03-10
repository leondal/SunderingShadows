#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The Knightly Inn, a room");
set_long ("%^ORANGE%^All the rooms are the same, very utilitarion in style.  A <bed>, <table>, <chair> and clothes <press> form the furniture.  There are some <flowers> on the table, as well as a <jug> and <bowl> for washing.  A <window> looks out into the <forest>.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou can still smell the smoke from the commons room, but the flowers also have a delicate aroma.");
set_listen ("default", "The rumble of noise from the common rooms reaches you, but it is not disturbing.");
set_exits (([
"east" : "/d/dagger/Elvanta/forest/knightj"
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
