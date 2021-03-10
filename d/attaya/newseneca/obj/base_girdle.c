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

inherit DAEMON;

string COLOR,mydesc,myshort;

void create_girdle(object obj){
   COLOR = COLORS[random(sizeof(COLORS))];
   switch(random(3)){
      case 0:  mydesc = "This feminine corset has been created from "+
                  "delicate "+COLOR+" lace%^RESET%^ to accent any "+
                  "lady's figure.  Typically worn under clothing, it "+
                  "is meant as a foundation garment rather than a "+
                  "shirt.  The top of the corset is strapless, "+
                  "and the base is reinforced with silk to help "+
                  "the garment hold its shape.  Tiny "+COLOR+" "+
                  "flowers %^RESET%^can be found throughout the lace - "+
                  "though one would have to be awfully close indeed "+
                  "to see them!";
               myshort = "%^RESET%^delicate "+COLOR+" lace %^RESET%^corset";
               break;
      case 1:  mydesc = "Sewn from "+COLOR+" satin%^RESET%^, this "+
                  "overbust corset features a busk fastening at "+
                  "the front and thin "+COLOR+" satin laces %^RESET%^"+
                  "at the back.  Most often worn under dresses or "+
                  "other clothing, this corset will enhance "+
                  "any lady's figure.  The top of the corset "+
                  "is cut into a heart-shaped neckline, and "+
                  "the bottom extends to the lady's hips.  This "+
                  "garmet comes with a shift, which may be worn "+
                  "beneath it for comfort and cleanliness.";
               myshort = "%^RESET%^exquisite "+COLOR+" satin %^RESET%^corset";
               break;
      default: mydesc = "Crafted of supple "+COLOR+" leather%^RESET%^, "+
                  "this corset features thin straps and %^BOLD%^"+
                  "ivory boning %^RESET%^that make it sturdy "+
                  "in addition to being quite fetching.  Clearly "+
                  "opting for fashion rather than ease of use, this "+
                  "corset features no front busk, but it has "+
                  "matching "+COLOR+" silk laces %^RESET%^in the "+
                  "back.  The corset can be laced to accentuate "+
                  "a lady's figure, drawing the eye if she dares "+
                  "wear it without a shirt.";
               myshort = "%^RESET%^supple "+COLOR+" leather %^RESET%^corset";
               break;
   }
   obj->set_long(""+mydesc+"");
   obj->set_value(100+random(51));
   obj->set_name("girdle");
   obj->set_type("ring");
   obj->set_limbs(({"torso"}));
   obj->set_weight(1);
   obj->set_short(""+myshort+"");
   obj->set_id(({"clothing","girdle",""+COLOR+" girdle","Lace girdle","corset","Corset",""+COLOR+" corset"}));
}
