//changed to type "ring" to be worn with pants/skirts ~Circe~ 5/31/07
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

inherit ARMOUR;

void create(){
    string COLOR;
    ::create();
    COLOR = COLORS[random(sizeof(COLORS))];
    set_name("hose leggings");
    set_id(({"hose","hose leggings","hosery","leggings","fine hosery"}));
    set_short("%^RESET%^"+COLOR+" fine hosery%^RESET%^");
    set_long("Sewn from a new lightweight fabric, this pair of leggings "+
       "is formed to cling to the wearer's legs.  The material has "+
       "been dyed a perfect shade of "+COLOR+"%^RESET%^, and the hose would "+
       "add some small bit of protection from the ordinary dust of "+
       "travel.  They would likely tear quite easily, though, and "+
       "should be treated with care.");
    set_lore("Crafted by the famed tailors of Seneca, these leggings are "+
       "made of a material they are not yet revealing.  Some hint that perhaps "+
       "Seneca has found a trade route with a yet-unknown nation, though it "+
       "is most likely just the product of the ingenuity of the realm's best "+
       "tailors.  Some fashion-forward ladies have taken to wearing these "+
       "hose under short skirts, revealing far too much of their legs to the "+
       "scandalized older crowd.");
    set_property("lore difficulty",10);
    set_type("ring");
    set_limbs(({"right leg","left leg"}));
    set_weight(1);
    set_value(3);
}
