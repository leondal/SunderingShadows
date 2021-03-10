#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
	::create();
	set_property("light",2);
	set_terrain(GARDEN);
	set_travel(FOOT_PATH);
	set_short("A garden of hanging baskets");
	set_long(
	"You have come to a little section of the park that is filled with lovely hanging"+
	" baskets. You can see they're filled with petunias, geraniums, impatients, cosmos,"+
	" purple robes, fairy bouquets, pheasant eyes, and alyssum. The baskets are hanging"+
	" from metal wires hung from a few slender poles that have been positioned strategically"+
	" around the garden. The ground beneath the hanging baskets is covered by a delicate"+
	" flower known as meadow foam. This is a very pleasant place with a tranquil atmosphere."
	);
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
	set_smell("default","The sweet fragarance of the meadow foam drifts to your nostrils.");
	set_listen("default","You can hear birds chirping in the park.");
	set_items(([
	"grass" : "%^GREEN%^%^BOLD%^The grass beneath your feet is lush and green, it is"+
	" almost like a carpet it is so thick and well cared for.",
	"petunias" : "A basket of %^BOLD%^%^MAGENTA%^pink%^RESET%^ and %^BOLD%^%^RED%^red%^RESET%^"+
	" petunias is hanging in the back left. The petunias have full, slick looking petals"+
	" and are rather large. They're obviously well watered.",
	"geraniums" : "A large basket of %^BOLD%^%^WHITE%^white%^RESET%^ and %^BOLD%^%^RED%^red%^RESET%^"+
	" geraniums is hanging on the right side. Assylum flowers line the edges of the"+
	" basket, giving it a daintier look.",
	"impatients" : "There are several hanging baskets of impatients that are a variety"+
	" of colors. There are pink, red, purple, and white ones. They seem to be doing"+
	" very well, and are apparently easy to grow in baskets since there are so many of"+
	" them.",
	"cosmos" : "%^BOLD%^%^MAGENTA%^There is a basket of cosmos hanging on the back right. These have a"+
	" semi-double flower with a row of sinle petals surrounded by a shorter inner row"+
	" of petals, giving it a very full look. There are a mix of pink, deep magenta, and"+
	" bluish pink flowers. The have lush green foliage surrounding them, giving the"+
	" basket a full, pretty look.",
	"purple robes" : "%^MAGENTA%^The purple robes are also known as cupflowers, for their"+
	" cup-like shapes. They are a deep shade of purple with a miniature %^YELLOW%^yellow%^RESET%^%^MAGENTA%^"+
	" star in the very center. There is a pretty basket of them hanging close to the"+
	" front.",
	"fairy bouquets" : "These small flowers look remarkably like baby snapdragons. They"+
	" seem rather delicate, and you can see them blooming in lavender, pale yellow, pink,"+
	" white, magenta, violet, and sometimes a combination of those colors. The fairies"+
	" supposedly love these tiny flowers, which are just the right size for them. There"+
	" are two baskets of them, one on the left and one on the right.",
	"meadow foam" : "%^BOLD%^These tiny, cup-shaped flowers cover the entire ground! They are"+
	" mostly yellow and pink flowers with white rims. The foliage around them is a"+
	" bright yellow-green shade that helps add to their charm. They give off a light,"+
	" sweet fragarance that drifts through the air.",
	"pheasant eyes" : "%^BOLD%^%^MAGENTA%^These tiny flowers smell like cloves. They"+
	" appear here in a variety of shades, from rose to lavender to white. They all have"+
	" rings of deep pink in the center, creating an eye. The tips of the petals are"+
	" also a darker pink, and their foliage is a steel blue shade. They are most definitely"+
	" different, and it almost does look like the eye of a pheasant hiding in the grass."+
	" There is only one basket of these, hanging in the back left.",
	"alyssum" : "%^BOLD%^These are lacy white flowers that give off a pleasant honey"+
	" scent. They are found at the edges of some of the baskets, like a graceful outline"+
	" of lace.",
	]));
	set_exits(([
	"south" : MAINTOWN"park8",
	]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
