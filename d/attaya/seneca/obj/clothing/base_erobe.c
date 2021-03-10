#include <std.h>

#define THREADS ({"%^BOLD%^%^YELLOW%^thread of gold",\
"%^BOLD%^%^WHITE%^thread of pl%^CYAN%^a%^WHITE%^tin%^CYAN%^u%^WHITE%^m",\
"%^BOLD%^%^WHITE%^thread of silver",\
"%^BOLD%^%^CYAN%^thread of adamantite",\
"%^RESET%^%^ORANGE%^thread of bronze",\
"%^BOLD%^%^WHITE%^thread of m%^BLUE%^i%^WHITE%^thr%^BLUE%^i%^WHITE%^l"})

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
"%^YELLOW%^saphron",\
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
"%^RESET%^%^GREEN%^bamboo shoots",\
"%^BOLD%^%^BLUE%^bluebirds",\
"%^BOLD%^%^BLACK%^sparrows in flight",\
"%^BOLD%^%^RED%^red robins",\
"%^RESET%^%^ORANGE%^bunny rabbits",\
"%^BOLD%^%^MAGENTA%^piglets",\
"%^BOLD%^%^RED%^tumbling roses",\
"%^BOLD%^%^GREEN%^ivy",\
"%^YELLOW%^sunny daisies",\
"%^BOLD%^%^BLACK%^black roses",\
"%^BOLD%^%^CYAN%^intricate g%^RESET%^%^CYAN%^e%^BOLD%^o%^RESET%^%^CYAN%^m%^BOLD%^e%^RESET%^%^CYAN%^t%^BOLD%^r%^RESET%^%^CYAN%^i%^BOLD%^c patterns",\
"%^BOLD%^%^MAGENTA%^delicate sweetpea blossoms",\
"%^BOLD%^%^BLACK%^baying wolves",\
"%^RESET%^%^BLUE%^prowling wolves",\
"%^RESET%^%^ORANGE%^bear paws",\
"%^BOLD%^%^RED%^beastial claws",\
"%^BOLD%^%^GREEN%^grasshoppers",\
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
"%^BOLD%^%^GREEN%^palm trees",\
"%^BOLD%^%^WHITE%^eagles in flight",\
"%^RESET%^%^RED%^wheeling hawks",\
"%^BOLD%^%^MAGENTA%^paisley designs",\
"%^BOLD%^%^WHITE%^spring lilies",\
"%^BOLD%^%^MAGENTA%^asters",\
"%^RESET%^%^MAGENTA%^pansies",\
"%^BOLD%^%^RED%^dragons",\
"%^BOLD%^%^MAGENTA%^pixies"})

inherit DAEMON;

string COLOR, DESIGN, THREAD;

void create_robe(object obj){
    ::create();
    COLOR = COLORS[random(sizeof(COLORS))];
    DESIGN = DESIGNS[random(sizeof(DESIGNS))];
    THREAD = THREADS[random(sizeof(THREADS))];
    obj->set_name("embroidered robe");
    obj->set_id(({"embroidered robe","robe","elegant robe",""+DESIGN+" robe"}));
    obj->set_short("elegant "+COLOR+" robe %^RESET%^embroidered with "+DESIGN+"%^RESET%^");
    obj->set_long("This robe is made of the softest "+COLOR+" wool %^RESET%^imaginable.  "+
       "It wraps the wearer in exquisite warmth and comfort.  In addition, "+
       "it is quite stylish, falling in smooth folds nearly to the floor.  "+
       "A thick band of "+DESIGN+" %^RESET%^has been embroidered along the "+
       "neckline, down the row of "+COLOR+" buttons %^RESET%^and around "+
       "the base of the robe, as well as matching smaller bands along the "+
       "cuffs.  Details of the beautifully embroidered "+DESIGN+" %^RESET%^"+
       "have been accented in "+THREAD+"%^RESET%^.  Not leaving any "+
       "detail undone, the robe has been lined with matching "+COLOR+" "+
       "silk%^RESET%^.");
    obj->set_lore("There is no finer craftsmanship to be found than with the "+
       "tailors of Seneca.  This robe shows off some of their skill and "+
       "their willingness to create fantastic works of art to be worn.");
    obj->set_property("lore difficulty",10);
    obj->set_weight(2);
    obj->set_type("clothing");
    obj->set_limbs(({"torso"}));
    obj->set_value(150+random(51));
}
