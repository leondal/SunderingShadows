#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
	::create();
	set_property("light",2);
	set_terrain(GARDEN);
	set_travel(FOOT_PATH);
	set_short("A beautiful park");
	set_long(
	"You are standing in a garden of a variety of flowers. There are pretty daffodils,"+
	" daisies, and black-eyed susan's, marigolds, poppies, purple and white irises, and a"+
	" large variety of begonias, primroses, pansies, asters, violas, and snapdragons. You"+
	" can see honeysuckle vines growing along the ground, and a few hydrangea and lilac"+
	" bushes that have been kept well trimmed in the back. There are just so many flowers"+
	" here, it is amazing how they have all been carefully positioned to look good next"+
	" to eachother. At the very back of the garden is a stone fountain filled with water"+
	" for the birds. In the center of the fountain is a statue of a morning glory flower"+
	" that has just bloomed. The vines of the morning glory wrap around the inside of"+
	" the water basin, and around the base of the statue."
	);
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
	set_smell("default","The honeysuckle smells wonderful!");
	set_listen("default","You can hear birds chirping in the park.");
	set_items(([
	"grass" : "%^GREEN%^%^BOLD%^The grass beneath your feet is lush and green, it is"+
	" almost like a carpet it is so thick and well cared for.",
	({"statue","fountain"}) : "At the far end of the garden is a large bird bath. The"+
	" basin of the statue is large and rather shallow and kept filled with clear water."+
	" In the very center is the image of a large morning glory flower. The morning glory"+
	" vines have been etched out in the stone, wrapping around the basin and all the way"+
	" down the base of the fountain.",
	"honeysuckle" : "%^YELLOW%^Several honeysuckle vines are growing at the edges of"+
	" the gardens, enticing the birds to come here as well as smelling absolutely divine.",
	"daffodils" : "%^YELLOW%^Large daffodils are off to your right, they are a bright"+
	" yellow shade and bring a cheery life to the garden.",
	"daisies" : "%^BOLD%^Mixed between the daffodils are daisies and black-eyed susan's."+
	" The daisies all have bright white petals with yellow centers, complimenting the"+
	" daffodils.",
	"black-eyed susan's" : "%^YELLOW%^The black-eyed susan's are mixed in the daisies around the"+
	" daffodils. They have bright yellow petals with a %^BLACK%^dark black%^YELLOW%^ center,"+
	" they contrast well with the daisies.",
	"primroses" : "Primroses, sometimes called chrysanthemums, are scattered about the"+
	" garden in almost every color. There are yellow ones planted near the daffodils,"+
	" white and pink ones near the irises, and bright red ones mixed with the violas,"+
	" begonias, and poppies.",
	"violas" : "%^BOLD%^%^MAGENTA%^Sweet smelling violas are planted mostly near the"+
	" far end of the garden and are mixed with the red primroses. They are seen mostly"+
	" in red and pink shades, and compliment the primroses and begonias well.",
	"poppies" : "%^ORANGE%^The poppies are a lovely orange-red shade. They have cup-shaped"+
	" petals that fold inwards and are %^RED%^dark red%^ORANGE%^ in the center.",
	"marigolds" : "%^YELLOW%^Yellow-orange marigolds are planted about the garden, they"+
	" help to keep the bugs away. Their bright colors can be spotted towards the back of"+
	" all the rows of flowers.",
	"irises" : "%^BOLD%^White and %^RESET%^%^MAGENTA%^purple%^BOLD%^%^WHITE%^ irises"+
	" are planted on the left side of the garden, in front of the lilac bushes. Asters,"+
	" white begonias, and snapdragons are all planted near the irises.",
	"begonias" : "%^BOLD%^There are three colors of begonias. The white ones have been"+
	" planted in rows around the irises. The %^MAGENTA%^pink%^WHITE%^ and %^RED%^red%^BOLD%^%^WHITE%^"+
	" ones have been planted at the far end of the garden, mixing with the primroses and"+
	" violas.",
	"pansies" : "Multi-hued pansies have been planted in sections between the other flowers."+
	" Yellow, orange, and white ones separate the daffodils from the violas and begonias"+
	" on the right side of the garden. On the left side, white, purple, and blue ones"+
	" are planted in rows by the begonias next to the irises.",
	"asters" : "A large mixture of asters have been planted inbetween the pansies and"+
	" the violas on the far left side of the garden. They are pretty little flowers"+
	" with delicate star-shaped petals that come in a wide variety of colors.",
	"snapdragons" : "A few rows of snapdragons have been planted in back of the violas"+
	" at the far side of the garden. They are taller than the violas, so easily stick"+
	" up above to be seen. They can be seen in yellow, purple, pink, orange, and red."+
	" They got their name because their petals look like the maw of a dragon, and can"+
	" be easily snapped together.",
	"hydrangea" : "Hydrangea bushes are planted in the very back of the garden and are"+
	" kept in neatly trimmed hedges. It starts on the right with %^BOLD%^white%^RESET%^"+
	" flowers, then turns to %^BOLD%^%^MAGENTA%^pink%^RESET%^ and then %^BOLD%^%^RED%^red%^RESET%^"+
	" before going back to %^BOLD%^%^MAGENTA%^pink%^RESET%^ and then %^BOLD%^white%^RESET%^"+
	" again. Next to the hydrangea on the left side are lilac bushes.",
	"lilac" : "%^MAGENTA%^Lavender lilac bushes are kept well trimmed in the back left"+
	" side of the garden, just behind the irises. They give off a sweet light fragarance"+
	" that is over-powered by the more prominent honeysuckle vines.",
	]));
	set_exits(([
	"south" : MAINTOWN"park2",
	]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
