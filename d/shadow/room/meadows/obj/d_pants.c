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

void create_pants(object obj)
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
         obj->set_long("These burlap pants are highly durable but not"+
         " overly comfortable. They're great for working in the field"+
         " or other such chores. They've been dyed "+VAR+" "+str+""+
         " color.");
         break;
      case 6..10:
         FABRIC = "hemp";
         obj->set_long("These pants have been made out of tightly"+
         " woven hemp and appear very durable, if a bit hot. They have"+
         " been dyed "+VAR+" "+str+" color.");
         break;
      case 11..15:
         FABRIC = "cotton";
         obj->set_long("These are a pair of light cotton pants. They"+
         " have been dyed "+VAR+" "+str+" shade. They are made for"+
         " lounging around and staying cool and would not be good"+
         " to use out in the field."); 
         break;
      case 16..20:
         FABRIC = "leather";
         obj->set_long("These are a pair of sturdy leather pants that"+
         " have been dyed "+VAR+" "+str+" color. They are highly"+
         " durable and are good for activities where you want to make"+
         " sure your legs are protected, such as smithing.");
         break;
      case 21..25:
         FABRIC = "suede";
         obj->set_long("These suede pants have been dyed "+VAR+""+
         " "+str+" shade. They're a bit on the fancy side and are"+
         " more commonly worn by the higher born who wish to flaunt"+
         " their wealth.");
         break;
   }
   if(val < 5) {
      obj->set_value(5);
   }
   else {
      obj->set_value(val);
   }
   obj->set_name("pants");
   obj->set_type("clothing");
   obj->set_limbs(({"right leg","left leg"}));
   obj->set_weight(5);
   obj->set_short("A pair of "+str+" "+FABRIC+" pants");
   obj->set_id(({"pants","clothing",""+str+" pants",""+FABRIC+" pants",""+str+" "+FABRIC+" pants"}));
}
