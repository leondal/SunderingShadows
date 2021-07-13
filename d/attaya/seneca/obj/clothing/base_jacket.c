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

#define THREADS ({"%^BOLD%^%^YELLOW%^thread of gold",\
"%^BOLD%^%^WHITE%^thread of pl%^CYAN%^a%^WHITE%^tin%^CYAN%^u%^WHITE%^m",\
"%^BOLD%^%^WHITE%^thread of silver",\
"%^BOLD%^%^CYAN%^thread of adamantite",\
"%^RESET%^%^ORANGE%^thread of bronze",\
"%^BOLD%^%^WHITE%^thread of m%^BLUE%^i%^WHITE%^thr%^BLUE%^i%^WHITE%^l"})

inherit DAEMON;

string COLOR, THREAD;

void create_doublet(object obj){
   COLOR = COLORS[random(sizeof(COLORS))];
   THREAD = THREADS[random(sizeof(THREADS))];
   obj->set_long("This sleeveless doublet is fashioned from "+COLOR+" silk "+
      "%^RESET%^with a rich brocade done in "+THREAD+"%^RESET%^.  "+
      "The doublet features a short, rounded collar upon which "+
      "pins are sometimes worn to signify rank or house.  The "+
      "exquisite "+COLOR+" silk %^RESET%^tapers to a man's waist, "+
      "ending in a narrow skirt just over the hips.  The "+
      ""+THREAD+" brocade %^RESET%^is carefully done, creating "+
      "swirling patterns centering around larger fleur-de-lis.  "+
      "The doublet may be worn either alone or over a shirt.");
   obj->set_value(50+random(51));
   obj->set_name("doublet");
   obj->set_type("ring");
   obj->set_limbs(({"torso"}));
   obj->set_weight(3);
   obj->set_short("%^RESET%^"+COLOR+" silk brocade doublet%^RESET%^");
   obj->set_id(({"clothing","doublet","silk doublet",""+COLOR+" silk doublet","brocade doublet"}));
}
