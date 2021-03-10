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

void create_jacket(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "amethyst" || str == "emerald" || str == "aquamarine" || str == "indigo" || str == "olive green" || str == "ivory" || str == "azure" || str == "ocean blue") {
      VAR = "an";
   }
   val = random(35);
   switch(val) {
      case 0..5:
         FABRIC = "burlap";
         obj->set_long("This burlap jacket is rather rough and uncomfortable,"+
         " but it is somewhat warm and does a good job of keeping the wind"+
         " out. It has been dyed "+VAR+" "+str+" color.");
         break;
      case 6..10:
         FABRIC = "hemp";
         obj->set_long("This hemp tunic is thick and heavy, but has been"+
         " tightly woven to resist the wind. It has been dyed "+VAR+" "+str+""+
         " color.");
         break;
      case 11..15:
         FABRIC = "cotton";
         obj->set_long("This is a light cotton jacket that is fairly"+
         " fashionable but not really servicable against the wind or cold."+
         " It has been dyed "+VAR+" "+str+" shade.");
         break;
      case 16..20:
         FABRIC = "woolen";
         obj->set_long("This is tightly knit woolen jacket that has been"+
         " dyed "+VAR+" "+str+" shade. It is of fine quality and looks"+
         " warm and comfortable. This would be good for the winters or colder"+
         " climates.");
         break;
      case 21..25:
         FABRIC = "suede";
         obj->set_long("This suede jacket has been dyed "+VAR+""+
         " "+str+" color and cut in the latest of fashions. It is light"+
         " but durable and protects you from the wind.");
         break;
      case 26..30:
         FABRIC = "fleece";
         obj->set_long("This fleece jacket is undoubtedly one of the softest"+
         " things you have ever touched. It has been dyed "+VAR+" "+str+""+
         " shade and will keep you warm in cool climates while not making"+
         " you overly hot elsewhere. The only thing it doesn't do is"+
         " protect against the wind.");
         break;
      case 31..35:
         FABRIC = "velvet";
         obj->set_long("The velvet jacket is soft, lovely, and would be"+
         " completely unpractical in cold climates. It is cut in the latest"+
         " of styles and while it might provide a bit of protection against"+
         " the wind, it probably wouldn't last long if frequently used. It"+
         " has been dyed "+VAR+" "+str+" shade.");
         break;
   }
   if(val < 5) {
      obj->set_value(5);
   }
   else {
      obj->set_value(val);
   }
   obj->set_name("jacket");
   obj->set_type("clothing");
   obj->set_limbs(({"torso"}));
   obj->set_weight(5);
   obj->set_short(capitalize(VAR)+" "+str+" "+FABRIC+" jacket");
   obj->set_id(({"jacket","clothing",""+str+" jacket",""+FABRIC+" jacket",""+str+" "+FABRIC+" jacket"}));
}
