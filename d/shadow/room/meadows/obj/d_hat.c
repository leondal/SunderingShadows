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

void create_hat(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "amethyst" || str == "emerald" || str == "aquamarine" || str == "indigo" || str == "olive green" || str == "ivory" || str == "azure" || str == "ocean blue") {
      VAR = "an";
   }
   val = random(40);
   switch(val) {
      case 0..2:
         FABRIC = "straw";
         obj->set_long("This is a light, wide-brimmed straw hat that has"+
         " been dyed "+VAR+" "+str+" shade. It is great for helping to keep"+
         " the sun out of your eyes, but tends to try and blow away if the"+
         " wind picks up.");
         break;
      case 3..5:
         FABRIC = "hemp";
         obj->set_long("This is a pretty hemp hat that has been dyed "+VAR+""+
         " "+str+" color. It has a bit of a brim to protect your eyes from"+
         " the sun.");
         break;
      case 6..8:
         FABRIC = "leather";
         obj->set_long("This is a stylishly sleek leather hat that has been"+
         " dyed "+VAR+" "+str+" shade. It will look good on just about anyone.");
         break;
      case 9..11:
         FABRIC = "wool";
         obj->set_long("This is warm wool hat that fits snuggly on your head"+
         " and can even be pulled down to cover your ears. It has been dyed"+
         " "+VAR+" "+str+" color and will undoubtedly help to keep you warm"+
         " in colder climates.");
         break;
      case 12..14:
         FABRIC = "felt";
         obj->set_long("This felt hat has been dyed "+VAR+" "+str+" shade"+
         " and is rather fashionable.");
         break;
      case 15..17:
         FABRIC = "suede";
         obj->set_long("This suede hat is quite nice and is designed in the"+
         " latest of styles and has been dyed "+VAR+" "+str+" shade.");
         break;
      case 18..20:
         FABRIC = "velvet";
         obj->set_long("The velvet hat is very pretty indeed, having been"+
         " dyed "+VAR+" "+str+" shade. It is not terribly practical if the"+
         " weather were bad, but it looks great.");
         break;
      case 21..40:
         FABRIC = "fur";
         obj->set_long("This fur hat is warm and fuzzy, fitting snuggly on"+
         " your head it will keep you very toasty. It has been dyed "+VAR+""+
         " "+str+" shade.");
         break;
   }
   obj->set_value(val);
   if(val < 2) {
      obj->set_value(2);
   }
   obj->set_name("hat");
   obj->set_type("clothing");
   obj->set_limbs(({"head"}));
   obj->set_weight(2);
   obj->set_short(capitalize(VAR)+" "+str+" "+FABRIC+" hat");
   obj->set_id(({"hat","clothing",""+str+" hat",""+FABRIC+" hat",""+str+" "+FABRIC+" hat"}));
}
