#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(
	"Green grass reaches up past your ankles and"+
	" stretches for as far as the eye can see. There"+
	" are several tall trees scattered throughout"+
	" the valley and the wind blows through their"+
	" branches, making them sway. Rabbits and other"+
	" small animals scamper about in the grass and you"+
	" can even see deer grazing in the distance. Bright"+
	" colored butterflies float around in the wind and"+
	" some birds are perched in the trees, singing"+
	" happily. To the south you see a fairy ring."
	);
	set("night long",
	"Starlight is spread over the valley, bathing it"+
	" in silver. The trees look mystical, their leaves"+
	" reflect the moonlight and seem almost to glow."+
	" As the wind blows them they almost seem to be"+
	" following some sacred, ancient dance. Even the"+
	" grass at your feet reflects some of the silver."+
	" You can see fireflies in the distance as bright"+
	" pinpoints of yellow light. Some nightingales"+
	" are singing a beautiful melody in the distance."+
	" All the other animals seem to have gone to"+
	" sleep. To the south you see a fairy ring."
	);
	set_exits( ([
	"west" : ROOMS+"g80",
	"east" : ROOMS+"g78",
	"north" : ROOMS+"v47",
	]) );
}
