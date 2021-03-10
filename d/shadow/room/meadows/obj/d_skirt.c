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
string str, FABRIC, VAR, LENGTH;

void create()
{
   ::create();
}

void create_skirt(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "amethyst" || str == "emerald" || str == "aquamarine" || str == "indigo" || str == "olive green" || str == "ivory" || str == "azure" || str == "ocean blue") {
      VAR = "an";
   }
	switch(random(2)) {
      case 0:
         LENGTH = "short";
         break;
      case 1:
         LENGTH = "long";
         break;
	}
   val = random(35);
   switch(val) {
      case 0..5:
         FABRIC = "burlap";
         obj->set_long("This "+LENGTH+" burlap skirt was obviously made for"+
         " work such as scrubbing floors or other tasks that servants have."+
         " It has been dyed "+VAR+" "+str+" color in an attempt to make it"+
         " a bit less ugly, but it still feels rather harsh and abrasive.");
         break;
      case 6..10:
         FABRIC = "hemp";
         obj->set_long("This "+LENGTH+" skirt is made out of light hemp that"+
         " has been dyed "+VAR+" "+str+" shade. It is more on the practical"+
         " side but it does have some sense of style.");
         break;
      case 11..15:
         FABRIC = "cotton";
         obj->set_long("The "+LENGTH+" cotton skirt is soft and airy. It's"+
         " been dyed "+VAR+" "+str+" shade and allows for freedom of"+
         " movement.");
         break;
      case 16..20:
         FABRIC = "woolen";
         obj->set_long("This is a hand-knit "+LENGTH+" woolen skirt that's"+
         " been dyed "+VAR+" "+str+" shade. It is fuzzy and soft and quite"+
         " warm, you just have to be careful not to stretch the material out.");
         break;
      case 21..25:
         FABRIC = "suede";
         obj->set_long("The "+LENGTH+" suede skirt has been dyed "+VAR+""+
         " "+str+" shade. It is durable and helps protect from the wind,"+
         " in addition to being rather fashionable, although it does tend"+
         " to restrict movement some.");
         break;
      case 26..30:
         FABRIC = "velvet";
         obj->set_long("The "+LENGTH+" velvet skirt is soft and pleasant to"+ 
         " touch. It's been dyed "+VAR+" "+str+" shade and is fashionably"+
         " cut, althuogh it does tend to restrict movement a bit it shows"+
         " off all the right curves.");
         break;
      case 31..35:
         FABRIC = "silk";
         obj->set_long("The "+LENGTH+" silk skirt is wonderfully graceful,"+
         " gently flowing, and incredibly smooth. It has been dyed "+VAR+""+
         " "+str+" shade and is absolutely gorgeous.");
         break;
   }
   if(val < 5) {
      obj->set_value(5);
   }
   else {
      obj->set_value(val);
   }
   obj->set_name("skirt");
   obj->set_type("ring");
   obj->set_limbs(({"waist"}));
   obj->set_weight(2);
   obj->set_short("A "+LENGTH+" "+str+" "+FABRIC+" skirt");
   obj->set_id(({"skirt","clothing",""+str+" skirt",""+FABRIC+" skirt",""+str+" "+FABRIC+" skirt",""+LENGTH+" skirt",""+LENGTH+" "+str+" skirt",""+LENGTH+" "+str+" "+FABRIC+" skirt",""+LENGTH+" "+FABRIC+" skirt"}));
}
