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

void create_scarf(object obj)
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
         FABRIC = "hemp";
         obj->set_long("This hemp scarf has been dyed "+VAR+" "+str+" shade"+
         " and has been treated to make it softer. It is warm and durable"+
         " but not overly pretty.");
         break;
      case 6..10:
         FABRIC = "cotton";
         obj->set_long("This is a light cotton scarf that has been dyed"+
         " "+VAR+" "+str+" shade. It is soft and fashionably made with"+
         " little tassels at the end.");
         break;
      case 11..15:
         FABRIC = "woolen";
         obj->set_long("This is a hand-knit woolen scarf that's been"+
         " dyed "+VAR+" "+str+" shade. It is very warm and fuzzy.");
         break;
      case 16..20:
         FABRIC = "fleece";
         obj->set_long("This fleece scarf is exquisitely soft and wonderfully"+
         " warm. It has been dyed "+VAR+" "+str+" shade and the ends are"+
         " fashionably designed into a zig-zag pattern.");
         break;
      case 21..25:
         FABRIC = "silk";
         obj->set_long("This silk scarf is light and has a tendency to flow"+
         " in the wind. It is "+VAR+" "+str+" shade and is slightly"+
         " transparent. It is beautiful and designed in the latest of styles.");
         break;
   }
   if(val < 2) {
      obj->set_value(2);
   }
   else {
      obj->set_value(val);
   }
   obj->set_name("scarf");
   obj->set_type("ring");
   obj->set_limbs(({"neck"}));
   obj->set_weight(1);
   obj->set_short(capitalize(VAR)+" "+str+" "+FABRIC+" scarf");
   obj->set_id(({"scarf","clothing",""+str+" scarf",""+FABRIC+" scarf",""+str+" "+FABRIC+" scarf"}));
}
