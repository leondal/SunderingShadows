#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
	::create();
	set_property("light",2);
	set_terrain(GARDEN);
	set_travel(FOOT_PATH);
	set_short("A path through the park");
	set_long(
	"The path through the park turns here, running to the north and cutting to the east."+
	" A couple of benches made of polished granite have been positioned on the west and"+
	" south sides of the path. There is a large white marble fountain on the east that"+
	" shows a fairy pouring water from a jug onto a couple of large flowers. There are"+
	" also three exquisite statues made of polished limestone, one on either ends of"+
	" the benches, and one between them. The first statue is one of a young lady with"+
	" a basketfull of flowers. She is leaning over to pick a few more flowers, several"+
	" silver cups and blue wings have been planted around this statue. The second statue"+
	" is of a young doe that is grazing in the meadow, genitian sage has been planted"+
	" around the figure. The third statue is of two young children who are laughing"+
	" at something funny, brightly colored painted tongues have been planted all about"+
	" them." 
	);
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
	set_smell("default","An odd light scent drifts in from the east.");
	set_listen("default","You hear the water splashing into the fountain.");
	set_items(([
	"grass" : "%^GREEN%^%^BOLD%^The grass beneath your feet is lush and green, it is"+
	" almost like a carpet it is so thick and well cared for.",
	"silver cups" : "%^BOLD%^%^MAGENTA%^Although these small, cup-shaped flowers are"+
	" called silver cups, there is nothing silver about them. They are a pretty raspberry"+
	" pink, with darker pink veins that run through them for a pretty effect.",
	"blue wings" : "%^BOLD%^%^BLUE%^These royal blue flowers are fan-shaped with small"+
	" %^WHITE%^white eyes%^BLUE%^ in the very center. They seem to be constantly in"+
	" bloom, with lush %^GREEN%^green%^BLUE%^ leaves surrounding the plants.",
	"painted tongues" : "These trumpet-shaped flowers are growing in a variety of bright"+
	" colors. You can see jewel toned shades of blue, brick, yellow, violet, purple, and"+
	" rose, all with contrasting veins running through them. The petals look velvety"+
	" but quite delicate.",
	"gentian sage" : "%^CYAN%^This little wildflower is a deep marine-blue color. There"+
	" are few of them in bloom and they all look rather delicate. They have long, slender"+
	" blooms with deeper blue veins running through them.",
	({"young lady","lady","first statue","statue 1","statue"}) : "The first statue is that of a"+
	" young woman who is apparently picking flowers. She has a basket that is almost"+
	" full of flowers looped around one arm. You can see roses, daisies, and a few"+
	" daffodils in the basket already. She has her hair pulled back with a clip in the"+
	" shape of a butterfly and she is wearing a long dress. She has a peaceful look on"+ 	" her face. She is in the process of leaning over to pick more flowers. Silver cups"+
	" and blue wings have been planted in the area around the statue.",
	({"second statue","statue 2","doe","young doe"}) : "This is the statue of a young"+
	" doe that is serenly grazing on some grass. You can see the darker spots on her"+
	" back with a different shade of limestone. The doe looks so young and delicate,"+
	" her legs are tiny, daintily balancing on her hooves. Her little tail is perked"+
	" up in happiness. Genitian sage has been planted all about the statue.",
	({"third statue","statue 3","children","kids"}) : "There are really two statues here,"+
	" but they portray one scene. There is a young boy and a young girl, both around the"+
	" age of five. They are both smiling and laughing about something. Brightly colored"+
	" painted tongues have been planted all around the two statues, making it seem as"+
	" though they are in a meadow.",
	({"fountain","marble fountain"}) : "%^BOLD%^On the east is a large fountain made"+
	" of white marble. At the top is a dainty fairy who is carefully pouring water from"+
	" a jug down onto her flower garden. The water spills from the jug, over the flowers,"+
	" and into the base of the fountain, which is in the shape of a large cup-shaped"+
	" flower. The wings of the fairy are delicately etched out, and there is a smile"+
	" on her pretty face. It is a lovely scene.",
	({"bench","benches","granite benches","gray benches"}) : "Two polished granite"+
	" benches have been placed here, one on the south and one on the west. They have"+
	" high backs that have been etched with scenes of flowers, birds, and butterflies.",
	]));
	set_exits(([
	"east" : MAINTOWN"park6",
	"north" : MAINTOWN"park8",
	]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
