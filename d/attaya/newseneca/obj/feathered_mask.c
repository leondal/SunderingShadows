//feathered_mask.c - randomly colored feathered half-masks
//for new Seneca ~Circe~ 12/21/07
#include <std.h>
#include "../seneca.h"

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
"%^CYAN%^b%^GREEN%^l%^CYAN%^u%^GREEN%^e%^CYAN%^-%^GREEN%^g%^CYAN%^r%^GREEN%^e%^CYAN%^e%^GREEN%^n",\
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
"%^BOLD%^%^CYAN%^turquoise",\
"%^BOLD%^%^BLACK%^charcoal gray",\
"%^BOLD%^%^CYAN%^cyan blue",\
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

inherit COSTUME;

string COLOR;

void create(){
   ::create();
   COLOR = COLORS[random(sizeof(COLORS))];
   set_name("feathered mask");
   set_short("%^RESET%^%^CYAN%^a half-mask with "+COLOR+" feathers%^RESET%^");
   set_id(({"mask","half-mask","feathered mask","feathered half-mask",""+COLOR+" mask",""+COLOR+" feathered mask",""+COLOR+" half-mask",""+COLOR+" feathered half-mask","random feathered mask"}));
   set_long("%^RESET%^%^CYAN%^A sculpted piece of leather with "+
      "carved eye holes forms the base of this half-mask.  The "+
      "mask is made to cover the upper portion of the face from "+
      "the hairline to the cheeks, and it is alight with countless "+
      ""+COLOR+" feathers%^RESET%^%^CYAN%^ that dance into the air "+
      "and down over the cheeks.  Matching "+COLOR+" silk ribbons "+
      "%^RESET%^%^CYAN%^flow from either side, allowing the mask to be "+
      "tied into place.%^RESET%^");
   set_costume_type(""+COLOR+" feathered%^RESET%^");
   set_costume("mask");
   set_value(100);
   set_limbs(({"head"}));
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}