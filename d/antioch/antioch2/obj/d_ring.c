#include <std.h>
#include "../antioch.h"

#define STONES ({"%^BOLD%^%^WHITE%^diamond%^RESET%^",\
"%^BOLD%^%^GREEN%^emerald%^RESET%^",\
"%^BOLD%^%^RED%^ruby%^RESET%^",\
"%^BOLD%^%^BLUE%^sapphire%^RESET%^",\
"%^BOLD%^%^BLACK%^onyx%^RESET%^",\
"%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l%^RESET%^",\
"%^RESET%^%^MAGENTA%^amethyst%^RESET%^",\
"%^RESET%^%^ORANGE%^topaz%^RESET%^",\
"%^RESET%^%^RED%^garnet%^RESET%^",\
"%^RESET%^%^ORANGE%^tiger's eye%^RESET%^",\
"%^RESET%^%^ORANGE%^amber%^RESET%^",\
"%^BOLD%^%^CYAN%^aquamarine%^RESET%^",\
"%^RESET%^%^GREEN%^agate%^RESET%^",\
"%^BOLD%^%^BLACK%^ma%^GREEN%^l%^BLACK%^ach%^GREEN%^i%^BLACK%^te%^RESET%^",\
"%^BOLD%^%^WHITE%^moonstone%^RESET%^",\
"%^BOLD%^%^BLACK%^beryl%^RESET%^",\
"%^BOLD%^%^WHITE%^pearl%^RESET%^",\
"%^BOLD%^%^BLACK%^hematite%^RESET%^",\
"%^BOLD%^%^MAGENTA%^rose quartz%^RESET%^",\
"%^BOLD%^%^GREEN%^tourmaline%^RESET%^",\
"%^YELLOW%^citrine%^RESET%^",\
"%^BOLD%^%^RED%^carnelian%^RESET%^",\
"%^BOLD%^%^GREEN%^blo%^RED%^o%^GREEN%^dst%^RED%^o%^GREEN%^ne%^RESET%^",\
"%^RESET%^%^CYAN%^azurite%^RESET%^",\
"%^BOLD%^%^GREEN%^per%^YELLOW%^i%^GREEN%^dot%^RESET%^"})

#define METALS ({"silver","electrum","gold","white gold","platinum","titanium"})

inherit DAEMON;

int i, j, val, price1, price2;
string str, STONE, METAL, X, DESC1, DESC2;

void create()
{
	::create();
}

void create_ring(object obj)
{
	val = price1 + price2;
   j = random(sizeof(STONES));
	STONE = STONES[j];
   i = random(sizeof(METALS));
	METAL = METALS[i];
	 if(STONE == "%^BOLD%^%^GREEN%^emerald%^RESET%^" || STONE == "%^RESET%^%^MAGENTA%^amethyst%^RESET%^" || STONE == "%^BOLD%^%^BLACK%^onyx%^RESET%^" || STONE == "%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l%^RESET%^" || STONE == "%^RESET%^%^ORANGE%^amber%^RESET%^" || STONE == "%^BOLD%^%^CYAN%^aquamarine%^RESET%^" || STONE == "%^RESET%^%^GREEN%^agate%^RESET%^" || STONE == "%^RESET%^%^CYAN%^azurite%^RESET%^") {
		X = "An";
	}
	else {
		X = "A";
	}
	switch(j) {
		case 0:
			price1 = random(100)+900;
			DESC1 = " The %^BOLD%^diamond%^RESET%^ is of fine quality and"+
			" glitters attractively in the light.";
			break;
		case 1:
			price1 = random(100)+700;
			DESC1 = " The %^GREEN%^%^BOLD%^emerald%^RESET%^ has been cut into"+
			" a rectangular design and sparkles attractively in the center of"+
			" the ring.";
                   break;
		case 2:
			price1 = random(100)+650;
			DESC1 = " The %^RED%^ruby%^RESET%^ set in the center of the ring is"+
			" a very dark shade, of high quality. It has been carefully worked"+
			" int a round cut and almost seems to absorb the light.";
			break;
		case 3:
			price1 = random(50)+650;
			DESC1 = " The %^BLUE%^sapphire%^RESET%^ is a lovely blue color, of"+
			" very high quality. It has been cut in oval fashion and seems"+
			" rather depthless.";
			break;
		case 4:
			price1 = random(200)+50;
			DESC1 = " The piece of %^BOLD%^%^BLACK%^onyx%^RESET%^ has been"+
			" polished into a perfectly round sphere. It sits in the center of"+
			" the ring, reflecting all light.";
			break;
		case 5:
			price1 = random(200)+50;
			DESC1 = " The %^BOLD%^%^WHITE%^opal%^RESET%^ is oval in shape and"+
			" glimmers with a multitude of colors. It is quite lovely.";
			break;
		case 6:
			price1 = random(200)+50;
			DESC1 = " The %^MAGENTA%^amethyst%^RESET%^ has been cut into a"+
			" triangular shape, pointing downwards. Its many facets sparkle"+
			" in the light.";
			break;
		case 7:
			price1 = random(200)+50;
			DESC1 = " The topaz is a vibrant shade of %^ORANGE%^orange%^RESET%^"+
			" that is quite pretty. It has been crafted into a teardrop cut and"+
			" has tiny zirconians set on either side of it.";
			break;
		case 8:
			price1 = random(200)+50;
			DESC1 = " The %^RED%^garnet%^RESET%^ is a very deep red, which marks"+
			" it as high quality. It has been crafted into a round design and"+
			" seems to be almost black in the center it is so dark.";
			break;
		case 9:
			price1 = random(200)+50;
			DESC1 = " This piece of tiger's eye has been carefully polished"+
			" into an oval shape, similar to that of an eye, with one black"+
			" slit running down the center of the stone, widening slightly in"+
			" the middle like a cat's pupil.";
			break;
		case 10:
			price1 = random(200)+50;
			DESC1 = " This piece of %^ORANGE%^amber%^RESET%^ has been carefully polished and"+
			" crafted into an oval cut. It has almost a hundred facets and has"+
			" been carefully set into the very center of the ring."; 
			break;
		case 11:
			price1 = random(200)+50;
			DESC1 = " The %^BOLD%^%^CYAN%^aquamarine%^RESET%^ gem is a very"+
			" pale shade of blue and has been crafted into a teardrop cut.";
			break;
		case 12:
			price1 = random(200)+50;
			DESC1 = " The %^BOLD%^%^GREEN%^moss agate%^RESET%^ stone is a mottled shade of green. It has"+
			" been polished into a perfect circle and is set on a stand in the"+
			" center of the ring.";
			break;
		case 13:
			price1 = random(200)+50;
			DESC1 = " This piece of %^GREEN%^malachite%^RESET%^ has been"+
			" polished and cut into a very thin piece in the shape of a star."+
			" Darker green veins run through the stone, meeting in the center"+
			" in a random pattern.";
			break;
		case 14:
			price1 = random(200)+50;
			DESC1 = " The %^BOLD%^moonstone%^RESET%^ has been carefully polished"+
			" into a round sphere, and then cut in half and mounted onto the"+
			" ring. Moonstones are often favored by Selunites, some believe that"+
			" it helps to induce visions, dreams, and prophecies."; 
			break;
		case 15:
			price1 = random(200)+50;
			DESC1 = " This is a gray beryl that has been polished and given a"+
			" rectangular cut. Swirls of darker and lighter gray mix throughout"+
			" the stone. Some believe that mages can store their power into"+
			" beryl stones, and a flawless one is highly sought after.";
			break;
		case 16:
			price1 = random(200)+50;
			DESC1 = " A large %^BOLD%^pearl%^RESET%^ has been set on a stand"+
			" in the center of the ring, with two smaller pearls on either side"+
			" of it.";
			break;
		case 17:
			price1 = random(200)+50;
			DESC1 = " The piece of hematite set in the ring has been polished"+
			" until it shines and cut into the shape of a Y with an extra line"+
			" extending out from the center of the fork. The symbol is that"+
			" of a rune of protection, appropriate since hematite has mythical"+
			" protective powers.";
			break;
		case 18:
			price1 = random(200)+50;
			DESC1 = " This is a lovely %^BOLD%^%^MAGENTA%^rose quartz%^RESET%^"+
			" gem that has been polished and crafted into the shape of a heart.";
			break;
		case 19:
			price1 = random(200)+50;
			DESC1 = " This piece of %^BOLD%^%^GREEN%^tourmaline%^RESET%^ is a"+
			" yellow-green shade. It is quite pretty, and has been crafted into"+
			" a round cut with many facets.";
			break;
		case 20:
			price1 = random(200)+50;
			DESC1 = " The piece of %^YELLOW%^citrine%^RESET%^ is a bright shade"+
			" of yellow. It has been crafted into a diamond cut. Citrine is"+
			" commonly worn by warriors, it is thought to add courage and"+
			" strength.";
			break;
		case 21:
			price1 = random(200)+50;
			DESC1 = " This piece of %^BOLD%^%^RED%^carnelian%^RESET%^ is a"+
			" reddish orange shade. It has been polished and crafted into the"+
			" shape of a heart. It is said to help with matters of love and"+
			" make the wearer more desireable.";
			break;
		case 22:
			price1 = random(200)+50;
			DESC1 = " The %^GREEN%^bloodstone%^RESET%^ is a dark green shade"+
			" with flecks of %^RED%^red%^RESET%^ throughout it. It has been"+
			" highly polished and carved into the shape of a flat triangle."+
			" It is said to have healing properties and help stop wounds from"+
			" bleeding.";
			break;
		case 23:
			price1 = random(200)+250;
			DESC1 = " The %^CYAN%^azurite%^RESET%^ gem is a bluish color with"+
			" hints of green. It has been carefully crafted into a teardrop"+
			" cut, and two tiny diamonds are on either side of it.";
			break;
		case 24:
			price1 = random(200)+50;
			DESC1 = " The %^BOLD%^%^GREEN%^peridot%^RESET%^ is a pale green"+
			" shade. It has been polished and then crafted into an oval cut.";
			break;
	}
	switch(i) {
		case 0:
			price2 = random(50)+50;
			DESC2 = " The ring is made from pure %^BOLD%^%^WHITE%^silver%^RESET%^"+
				" and is quite sturdy.";
			break;
		case 1:
			price2 = random(50)+200;
			DESC2 = " The ring is made of %^BOLD%^%^WHITE%^el"+
			"%^BLUE%^e%^WHITE%^ctr%^BLUE%^u%^WHITE%^m%^RESET%^ that is mostly silvery,"+
			" with hints of blue to it.";
			break;
		case 2:
			price2 = random(25)+500;
			DESC2 = " The ring is made of pure %^YELLOW%^gold%^RESET%^"+
			", you have to be careful"+
			" with it, or the band could get bent or broken.";
			break;
		case 3:
			price2 = random(50)+700;
			DESC2 = " The ring is made out of %^BOLD%^%^WHITE%^white gold"+
			"%^RESET%^, something that is"+
			" rarely used except in jewelry. It is almost the same as gold, but"+
			" has a bright silvery color instead of the normal yellow hue.";
			break;
		case 4:
			price2 = random(125)+1400;
			DESC2 = " The ring is made out of highly polished "+
			"%^BOLD%^%^WHITE%^platinum%^RESET%^. It is"+
			" a very light brown shade, almost cream, and is rather rare.";
			break;
		case 5:
			price2 = random(50)+1200;
			DESC2 = " The ring is made out of %^BOLD%^%^WHITE%^titanium%^RESET%^"+
			", which is very strong"+
			" and incredibly hard to break. It is a silvery color and has been"+
			" highly polished so that it shines.";
			break;
	}
	obj->set_name(""+STONE+" ring");
	obj->set_short(""+X+" "+STONE+" ring");
	obj->set_id(({"ring","jewelry",""+STONE+" ring",""+METAL+" ring",""+METAL+" "+STONE+" ring","antioch_jewelry"}));
	obj->set_long("The ring has been set with a "+STONE+"."+DESC1+""+DESC2+"");
	obj->set_value(val);
	obj->set_type("ring");
	obj->set_limbs(({"left hand","right hand"}));
	obj->set_weight(1);
	obj->set_ac(0);
}
