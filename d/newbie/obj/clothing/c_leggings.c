#include <std.h>
inherit ARMOUR;

#define COLORS ({"%^BOLD%^%^CYAN%^aquamarine%^RESET%^",\
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

int j, val;
string str, FABRIC, VAR;
void create_leggings()
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "%^MAGENTA%^amethyst" || str == "%^BOLD%^%^GREEN%^emerald" || str == "%^BOLD%^%^CYAN%^aquamarine" || str == "%^BLUE%^indigo" || str == "%^GREEN%^olive green" || str == "%^BOLD%^%^WHITE%^ivory" || str == "%^BOLD%^%^CYAN%^azure" || str == "%^BOLD%^%^BLUE%^ocean blue") {
      VAR = "an";
   }
   val = random(25);
   switch(val) {
      case 0..5:
         FABRIC = "burlap";
         set_long("These burlap leggings are a bit on the heavy"+
         " side and not the most comfortable. They've been dyed "+VAR+""+
         " %^RESET%^"+str+"%^RESET%^ color.");
         break;
      case 6..10:
         FABRIC = "hemp";
         set_long("These leggings have been made from lighter and"+
         " more loosely woven hemp, making them a bit cooler and"+
         " more comfortable. They've been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^color.");
         break;
      case 11..15:
         FABRIC = "cotton";
         set_long("These cotton leggings are very cool and"+
         " comfortable. They've been dyed "+VAR+" %^RESET%^"+str+"%^RESET%^ shade. They"+
         " are not highly durable but would be good for skipping"+
         " through a meadow, fishing, or other non-strenuous activities.");
         break;
      case 16..20:
         FABRIC = "woolen";
         set_long("These woolen leggings are very soft and warm."+
         " They've been dyed "+VAR+" %^RESET%^"+str+"%^RESET%^ shade. They are perfect"+
         " for keeping you warm in colder climates and have been"+
         " tightly knit to help keep the wind out.");
         break;
      case 21..24:
         FABRIC = "suede";
         set_long("These suede leggings have been dyed "+VAR+""+
         " %^RESET%^"+str+"%^RESET%^ shade. They're a bit on the fancy side and are"+
         " more commonly worn by the higher born who wish to flaunt"+
         " their wealth.");
         break;
   }
   if(val < 2) {
      set_value(2);
   }
   else {
      set_value(val);
   }
   set_name("leggings");
   set_type("clothing");
   set_limbs(({"right leg","left leg"}));
   set_weight(3);
   set_short("%^RESET%^A pair of %^RESET%^"+str+"%^RESET%^ "+FABRIC+" leggings");
   set_id(({"leggings","clothing",""+str+" leggings",""+FABRIC+" leggings",""+str+" "+FABRIC+" leggings"}));
}

void create()
{
   ::create();
   create_leggings(); 
   set_size(random(3)+1);
   set_cointype("silver");
}
