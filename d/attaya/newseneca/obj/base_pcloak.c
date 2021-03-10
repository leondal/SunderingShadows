#include <std.h>

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

string COLOR, DESIGN, LENGTH;

void create_cloak(object obj){
   COLOR = COLORS[random(sizeof(COLORS))];
   DESIGN = DESIGNS[random(sizeof(DESIGNS))];
   LENGTH = "long";
   if(!random(3)){
      LENGTH = "short";
   }
    obj->set_long("Crafted from exquisite "+COLOR+" waterproof cloth%^RESET%^, "+
       "this cloak has been designed to protect the wearer from the elements "+
       "while enhancing his or her style.  This cloak is "+LENGTH+" "+
       "and features a deep hood that can be worn to further protect "+
       "from inclement weather.  Decorating the cloak and adding a touch of "+
       "flair is a row of "+DESIGN+" %^RESET%^that encircles the entire cloak "+
       "in a complimentary color.  Clearly, this is a cloak made by a "+
       "master tailor.");
   obj->set_value(30+random(21));
   obj->set_name("waterproof cloak");
   obj->set_type("clothing");
   obj->set_limbs(({"neck"}));
   obj->set_weight(1);
   obj->set_short("%^RESET%^"+LENGTH+" "+COLOR+" %^RESET%^waterproof cloak%^RESET%^");
   obj->set_id(({"clothing","cloak",""+COLOR+" cloak","waterproof cloak"}));
}
