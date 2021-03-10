//Circe is awesome, and did this.. i just stole it.  Cy
#include <std.h>
#define TYPES ({"leggings","hose","pants","shorts"})

#define THREADS ({"%^BOLD%^%^YELLOW%^gold%^RESET%^",\
"%^BOLD%^%^WHITE%^pl%^CYAN%^a%^WHITE%^tin%^CYAN%^u%^WHITE%^m%^RESET%^",\
"%^BOLD%^%^WHITE%^silver%^RESET%^",\
"%^RESET%^%^CYAN%^adamantite%^RESET%^",\
"%^RESET%^%^ORANGE%^bronze%^RESET%^",\
"%^BOLD%^%^WHITE%^m%^BLUE%^i%^WHITE%^thr%^BLUE%^i%^WHITE%^l%^RESET%^"})

#define COLORS ({"%^BOLD%^%^CYAN%^aquamarine",\
"%^GREEN%^olive green",\
"%^BOLD%^%^CYAN%^azure",\
"%^BLUE%^indigo",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^MAGENTA%^amethyst",\
"%^BOLD%^%^WHITE%^ivory",\
"%^BOLD%^%^BLUE%^ocean blue",\
"%^BOLD%^%^GREEN%^leaf green",\
"%^GREEN%^pine green",\
"%^BOLD%^%^BLUE%^cobalt blue",\
"%^BLUE%^navy blue",\
"%^GREEN%^forest green",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^BOLD%^%^BLUE%^sapphire blue",\
"%^CYAN%^blue-green",\
"%^GREEN%^gray-green",\
"%^BOLD%^%^BLACK%^black",\
"%^ORANGE%^rich brown",\
"%^ORANGE%^dark brown",\
"%^ORANGE%^walnut brown",\
"%^RED%^brick red",\
"%^ORANGE%^peach",\
"%^BOLD%^%^GREEN%^lime green",\
"%^BOLD%^%^RED%^ruby red",\
"%^MAGENTA%^royal purple",\
"%^RED%^blood red",\
"%^MAGENTA%^violet",\
"%^ORANGE%^rusty orange",\
"%^BOLD%^%^RED%^rusty red",\
"%^BOLD%^%^RED%^reddish orange",\
"%^BOLD%^%^RED%^fiery red",\
"%^BOLD%^%^BLUE%^cornflower blue",\
"%^MAGENTA%^lavender",\
"%^BOLD%^%^MAGENTA%^carnation pink",\
"%^ORANGE%^light brown",\
"%^CYAN%^turquoise",\
"%^BOLD%^%^BLACK%^charcoal gray",\
"%^CYAN%^cyan blue",\
"%^BOLD%^%^WHITE%^rich cream",\
"%^BOLD%^%^WHITE%^cream",\
"%^BOLD%^%^WHITE%^white",\
"%^YELLOW%^saffron",\
"%^YELLOW%^lemon yellow",\
"%^ORANGE%^tangerine",\
"%^BOLD%^%^MAGENTA%^mauve",\
"%^RED%^crimson",\
"%^BOLD%^%^MAGENTA%^lilac",\
"%^YELLOW%^daffodil",\
"%^ORANGE%^beige",\
"%^ORANGE%^taupe",\
"%^BOLD%^%^BLACK%^sable",\
"%^ORANGE%^fawn",\
"%^BOLD%^%^BLACK%^pale gray",\
"%^BOLD%^%^BLACK%^stormy gray",\
"%^ORANGE%^dusty brown",\
"%^BOLD%^%^BLACK%^dark gray"\
})

#define DESIGNS ({"%^RESET%^%^ORANGE%^seahorses",\
"%^BOLD%^%^WHITE%^antlers",\
"%^RESET%^%^GREEN%^scarab beetles",\
"%^BOLD%^%^BLUE%^bluebirds",\
"%^BOLD%^%^BLACK%^sparrows in flight",\
"%^BOLD%^%^RED%^stoic bulls",\
"%^RESET%^%^ORANGE%^were-rabbits",\
"%^BOLD%^%^MAGENTA%^piglets",\
"%^BOLD%^%^RED%^tumbling roses",\
"%^BOLD%^%^GREEN%^ivy",\
"%^YELLOW%^arrows",\
"%^BOLD%^%^BLACK%^black roses",\
"%^BOLD%^%^CYAN%^intricate g%^RESET%^%^CYAN%^e%^BOLD%^o%^RESET%^%^CYAN%^m%^BOLD%^e%^RESET%^%^CYAN%^t%^BOLD%^r%^RESET%^%^CYAN%^i%^BOLD%^c patterns",\
"%^MAGENTA%^musical n%^BOLD%^%^BLACK%^o%^WHITE%^t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s%^RESET%^",\
"%^BOLD%^%^MAGENTA%^delicate sweetpea blossoms",\
"%^BOLD%^%^BLACK%^baying wolves",\
"%^RESET%^%^BLUE%^prowling wolves",\
"%^RESET%^%^ORANGE%^bear paws",\
"%^BOLD%^%^RED%^beastial claws",\
"%^ORANGE%^tankards of foamy ale",\
"%^BOLD%^%^GREEN%^hopping frogs",\
"%^YELLOW%^herringbone designs",\
"%^BOLD%^%^WHITE%^crossed swords",\
"%^BOLD%^%^RED%^tumbling axes",\
"%^RESET%^%^MAGENTA%^open tomes",\
"%^RESET%^%^MAGENTA%^countless crystals",\
"%^RESET%^%^ORANGE%^does and fawns",\
"%^RESET%^%^GREEN%^cunning snakes",\
"%^RESET%^%^CYAN%^freeform waves",\
"%^BOLD%^%^MAGENTA%^hearts",\
"%^BOLD%^%^WHITE%^doves",\
"%^RESET%^%^GREEN%^oak leaves",\
"%^RESET%^%^ORANGE%^playful squirrels",\
"%^YELLOW%^stars",\
"%^BOLD%^%^WHITE%^stylized eyes",\
"%^BOLD%^%^CYAN%^intertwining starflowers",\
"%^BOLD%^%^MAGENTA%^tulips",\
"%^RESET%^%^ORANGE%^galloping horses",\
"%^BOLD%^%^CYAN%^delicate snowflakes",\
"%^BOLD%^%^BLUE%^playful dolphins",\
"%^BOLD%^%^MAGENTA%^b%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLUE%^t%^CYAN%^t%^RESET%^%^CYAN%^e%^GREEN%^r%^BOLD%^f%^YELLOW%^l%^BOLD%^%^RED%^i%^MAGENTA%^e%^RESET%^%^MAGENTA%^s",\
"%^BOLD%^%^GREEN%^oak leaves",\
"%^BOLD%^%^WHITE%^eagles in flight",\
"%^RESET%^%^RED%^wheeling hawks",\
"%^BOLD%^%^MAGENTA%^paisley designs",\
"%^BOLD%^%^WHITE%^spring lilies",\
"%^BOLD%^%^MAGENTA%^asters",\
"%^RESET%^%^GREEN%^lizards",\
"%^BOLD%^%^RED%^devils",\
"%^BOLD%^%^BLACK%^demons",\
"%^BOLD%^%^WHITE%^unicorns",\
"%^BOLD%^%^YELLOW%^lions",\
"%^RESET%^%^MAGENTA%^skeletons",\
"%^BOLD%^%^RED%^dragons",\
"%^BOLD%^%^%^WHITE%^stylized crescent moons",\
"%^BOLD%^%^YELLOW%^stylized sunbursts",\
"%^BOLD%^%^MAGENTA%^pixies"})

inherit DAEMON;

string TYPE,COLOR,DESIGN,THREAD,brief,desc;
int i,j,k,l,m,val;
void create_pants(object obj){
    ::create();
	i = random(sizeof(TYPES));
   		TYPE = TYPES[i];
   	j = random(sizeof(COLORS));
   		COLOR = COLORS[j];
  	k = random(sizeof(DESIGNS));
   		DESIGN = DESIGNS[k];
   	l = random(sizeof(THREADS));
   		THREAD = THREADS[l];
   val = (random(100)+random(100)+100);
   if(TYPE == "leggings"){
    obj->set_id(({"leggings","pants","suede leggings"}));
      brief = "%^RESET%^A pair of "+COLOR+"%^RESET%^ suede leggings%^RESET%^";
      desc = "Crafted from "+COLOR+"%^RESET%^ suede, these leggings look soft "+
		"and comfortable.  The suede, though soft, still retains "+
		"some of its strength, making these leggings quite durable."+
		"  Embossed onto the suede is a pattern of "+DESIGN+"%^RESET%^.  The "+
		"leggings are accentuated with "+THREAD+" threads, giving a"+
		" subtle richness to them.  The inside of the leggings are "+
		"lined with cotton, creating even more comfort.";
   }
	if(TYPE == "hose"){
    obj->set_id(({"hose","pants","silk hose"}));
      brief = "%^RESET%^A pair of "+COLOR+"%^RESET%^ silk hose%^RESET%^";
      desc = "Crafted from silk, these form fitting hose look extremely"+
		" comfortable.  The "+COLOR+" %^RESET%^silken threads of the hose create an opaque"+
		" effect, proving plenty of modesty for even the more bashful "+
		"types.  Woven into the silk is a pattern of "+DESIGN+"%^RESET%^.  The design"+
		" is further accentuated with shimmering threads of "+THREAD+".  "+
		"The hose are made to fit snug, showing off one's legs.";
   }
	if(TYPE == "pants"){
    obj->set_id(({"pants","leather pants"}));
      brief = "%^RESET%^A pair of "+COLOR+"%^RESET%^ leather pants%^RESET%^";
      desc = "Crafted from buttery soft leather, these pants have a daring"+
		" look to them.  The snug fitting pants look almost brazen in "+
		"their design.  The leather has been dyed "+COLOR+"%^RESET%^, making them"+
		" even more striking.  Embossed down each leg of the pants is pattern "+
		"of "+DESIGN+"%^RESET%^, giving them a flamboyant edge.  Laces in the"+
		" front of the pants allow them to be secured tight.";
   }
	if(TYPE == "shorts"){
    obj->set_id(({"shorts","pants","leather shorts"}));
      brief = "%^RESET%^A pair of "+COLOR+"%^RESET%^ leather shorts%^RESET%^";
      desc = "Crafted from leather, these shorts have been dyed "+COLOR+"%^RESET%^."+
		"  The loose fitting shorts fall below one's knees, giving ample"+
		" protection to the legs.  The shorts are cut full and loose "+
		"through the leg, giving them plenty of room.  Two leather buckles"+
		" at the waist allow the shorts to be cinched in for a tighter fit."+
		"  The shorts have a utilitarian look to them.  Running down each "+
		"leg, a pattern of "+DESIGN+"%^RESET%^ has been embossed into "+
		"the leather, giving them a sophisticated touch.";
   }
	obj->set_lore("Rumored to have been first crafted on the troubled island "+
		"of Attaya, these pants were once the height of fashion several "+
		"years ago.  People from all walks of light craved the elegant and"+
		" fashionable designs that ranges from stylish shorts, brazen pants,"+
		" opaque hose, and suede leggings.  The garments became so popular "+
		"that mages even starts to enchant them, to preserve them.  The pants"+
		" have fallen out of fashion as of lately, though who can say what the"+
		" future will bring.");
    obj->set_property("lore difficulty",10);
    obj->set_weight(4);
    obj->set_type("clothing");
    obj->set_short(""+brief+"");
    obj->set_long(""+desc+"");
    obj->set_limbs(({"right leg","left leg"}));
   obj->set_value(val);
   obj->set_name("pants");
}
