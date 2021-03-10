#include <std.h>

#define COLORS ({"%^BOLD%^%^CYAN%^aquamarine%^RESET%^",\
"%^RESET%^%^GREEN%^olive green%^RESET%^",\
"%^RESET%^%^CYAN%^azure%^RESET%^",\
"%^RESET%^%^BLUE%^indigo%^RESET%^",\
"%^BOLD%^%^GREEN%^emerald green%^RESET%^",\
"%^RESET%^%^MAGENTA%^amethyst%^RESET%^",\
"%^BOLD%^%^WHITE%^ivory%^RESET%^",\
"%^BOLD%^%^BLUE%^ocean blue%^RESET%^",\
"%^BOLD%^%^GREEN%^leaf green%^RESET%^",\
"%^RESET%^%^BLUE%^navy blue%^RESET%^",\
"%^BOLD%^%^CYAN%^sky blue%^RESET%^",\
"%^BOLD%^%^BLUE%^sapphire blue%^RESET%^",\
"%^BOLD%^%^BLACK%^gray-%^RESET%^%^GREEN%^green%^RESET%^",\
"%^BOLD%^%^BLACK%^ raven black%^RESET%^",\
"%^RESET%^%^ORANGE%^rich brown%^RESET%^",\
"%^RESET%^%^ORANGE%^dark brown%^RESET%^",\
"%^RESET%^%^RED%^brick red%^RESET%^",\
"%^BOLD%^%^RED%^ruby red%^RESET%^",\
"%^RESET%^%^MAGENTA%^royal purple%^RESET%^",\
"%^BOLD%^%^RED%^blood red%^RESET%^",\
"%^RESET%^%^MAGENTA%^violet%^RESET%^",\
"%^RESET%^%^ORANGE%^rusty orange%^RESET%^",\
"%^RESET%^%^ORANGE%^reddish orange%^RESET%^",\
"%^BOLD%^%^RED%^fiery red%^RESET%^",\
"%^BOLD%^%^CYAN%^cornflower blue%^RESET%^",\
"%^RESET%^%^MAGENTA%^lavander%^RESET%^",\
"%^BOLD%^%^MAGENTA%^carnation pink%^RESET%^",\
"%^BOLD%^%^BLACK%^charcoal gray%^RESET%^",\
"%^BOLD%^%^WHITE%^rich cream%^RESET%^",\
"%^YELLOW%^saphron%^RESET%^",\
"%^RESET%^%^ORANGE%^peach%^RESET%^",\
"%^YELLOW%^lemon yellow%^RESET%^",\
"%^BOLD%^%^MAGENTA%^brilliant pink%^RESET%^",\
"%^BOLD%^%^WHITE%^brilliant white%^RESET%^",\
"%^RESET%^light gray",\
"%^BOLD%^%^BLACK%^dark gray%^RESET%^",\
"%^BOLD%^%^BLACK%^stormy gray%^RESET%^",\
"%^RED%^crimson%^RESET%^",\
"%^YELLOW%^daffodil%^RESET%^",\
"%^RESET%^%^MAGENTA%^amethyst%^RESET%^",\
"%^RESET%^%^ORANGE%^beige%^RESET%^",\
"%^RESET%^%^ORANGE%^fawn%^RESET%^"\
})

inherit DAEMON;

int j, val;
string str, FABRIC, VAR;

void create()
{
   ::create();
}

void create_leggings(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "amethyst" || str == "emerald" || str == "aquamarine" || str == "indigo" || str == "olive green" || str == "ivory" || str == "azure" || str == "ocean blue") {
      VAR = "an";
   }
   val = random(25);
   switch(val) {
      case 0..5:
         FABRIC = "burlap";
         obj->set_long("These burlap leggings are a bit on the heavy"+
         " side and not the most comfortable. They've been dyed "+VAR+""+
         " "+str+" color.");
         break;
      case 6..10:
         FABRIC = "hemp";
         obj->set_long("These leggings have been made from lighter and"+
         " more loosely woven hemp, making them a bit cooler and"+
         " more comfortable. They've been dyed "+VAR+" "+str+" color.");
         break;
      case 11..15:
         FABRIC = "cotton";
         obj->set_long("These cotton leggings are very cool and"+
         " comfortable. They've been dyed "+VAR+" "+str+" shade. They"+
         " are not highly durable but would be good for skipping"+
         " through a meadow, fishing, or other non-strenuous activities.");
         break;
      case 16..20:
         FABRIC = "woolen";
         obj->set_long("These woolen leggings are very soft and warm."+
         " They've been dyed "+VAR+" "+str+" shade. They are perfect"+
         " for keeping you warm in colder climates and have been"+
         " tightly knit to help keep the wind out.");
         break;
      case 21..25:
         FABRIC = "suede";
         obj->set_long("These suede leggings have been dyed "+VAR+""+
         " "+str+" shade. They're a bit on the fancy side and are"+
         " more commonly worn by the higher born who wish to flaunt"+
         " their wealth.");
         break;
   }
   if(val < 2) {
      obj->set_value(2);
   }
   else {
      obj->set_value(val);
   }
   obj->set_name("leggings");
   obj->set_type("clothing");
   obj->set_limbs(({"right leg","left leg"}));
   obj->set_weight(3);
   obj->set_short("A pair of "+str+" "+FABRIC+" leggings");
   obj->set_id(({"leggings","clothing",""+str+" leggings",""+FABRIC+" leggings",""+str+" "+FABRIC+" leggings"}));
}
