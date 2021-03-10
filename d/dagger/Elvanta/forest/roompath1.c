#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set ("day long", "%^ORANGE%^Insects skitter here and there, bright-coloured birds dart through the canopies above and small, furry-faced animals appear like apparitions and are gone in the blink of an eye.");
set("night long", "%^CYAN%^Insects skitter here and there, the sound of quiet wings fills the air, and small furry-faced animals appear like apparitions in the moonlight and are gone in the blink of an eye.");
set_smell ("default", "%^MAGENTA%^The fragrance of pine needles and freshly dampened earth fills your senses.");
set_listen ("default", "You hear birds, squirrels and the wind whispering through the trees.  Was that laughter you heard, as well?");
set_exits (([
"northeast" : "/d/dagger/Elvanta/forest/roompath2",
"southwest" : "/d/tharis/road/wroad20"
]));
set_items
(([
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"insects" : "Insects of many legs, many eyes, and many ears crawl about",
"birds" : "Birds of every hue and description fill the air"
]));
}
void reset(){
::reset();
if(!present("deer"));
new("/d/dagger/Elvanta/forest/mon/deer")->move(TO);
if(!present("owl"));
new("/d/dagger/Elvanta/forest/mon/owl")->move(TO);
}
