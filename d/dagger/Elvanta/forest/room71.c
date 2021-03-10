#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^You walk ahead silently following the <pathway> created by whom or what you don't know.  Shapes dart and glide wraithlike through the gloom, some with faces that are almost human, some with the look of forest creatures.  Eyes blink and peer out at you, then are gone.%^RESET%^");
set ("night long", "%^CYAN%^The <mist> swirls and stirs withing the great forest <trees>, its trailers twisting about like snakes.  The mist has the look of something alive.  It closes about you and the way back becomes as uncertain as the way forward.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nDamp earth and the musty odour of wet leaves prevails.");
set_listen ("default", "You hear sounds more haunting than comforting, bits and pieces of life that sprinkles the gloom with hints of what lies hidden.");
set_exits (([
"northwest" : "/d/dagger/Elvanta/forest/room70",
"southeast" : "/d/dagger/Elvanta/forest/room72"
]));
set_items
(([
"mist" : "The mist comes from the forest, pale gray and silent, slipping around you like a worn cloak.",
"trees" : "Unlike the trees you have come through, these trees look old, gnarled and eerie.  Almost as if they had a life of their own, they wrap around each other to form pathways and pitfalls.",
"globes" : "These globes are welcome in this forest and light your way.  They are approximately two feet in diameter and give off a warm blue light.  They are hung from intricately braided silver chains.",
"pathway" : "The pathway continues in a southeast direction, but is not as clear as it once was, as mist starts to rise from out of nowhere."
]));
}
void reset(){
::reset();
if(!present("sprite"))
new("/d/dagger/Elvanta/forest/mon/sprite")->move(this_object());
}
