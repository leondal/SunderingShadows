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

void create_dress(object obj)
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
         obj->set_long("This is a rough and rather crude "+LENGTH+" burlap dress that"+
         " has been dyed "+VAR+" "+str+" color. It would be good for washing"+
         " floor or some other menial activity.");
         break;
      case 6..10:
         FABRIC = "hemp";
         obj->set_long("This "+LENGTH+" dress is made out of light hemp that"+
         " has been dyed "+VAR+" "+str+" color. It is fairly light and also"+
         " pretty durable, although not the most stylish of dresses, it is"+
         " practical.");
         break;
      case 11..15:
         FABRIC = "cotton";
         obj->set_long("The "+LENGTH+" cotton dress is light and soft. It's"+
         " been dyed "+VAR+" "+str+" shade. It is perfect for lounging"+
         " around in, picking wildflowers, or other girlish activities.");
         break;
      case 16..20:
         FABRIC = "woolen";
         obj->set_long("This is a hand-knit "+LENGTH+" woolen dress that's"+
         " been dyed "+VAR+" "+str+" shade. It is incredibly warm and quite"+
         " soft, perfect for some of the cooler climates.");
         break;
      case 21..25:
         FABRIC = "suede";
         obj->set_long("The "+LENGTH+" suede dress has been dyed "+VAR+""+
         " "+str+" shade. It is durable and helps protect from the wind,"+
         " in addition to being rather fashionable.");
         break;
      case 26..30:
         FABRIC = "velvet";
         obj->set_long("The "+LENGTH+" velvet dress is quite soft and"+ 
         " pleasant to touch. It's been dyed "+VAR+" "+str+" shade."+
         " Although it's not the most durable of materials it is pretty"+
         " to look at.");
         break;
      case 31..35:
         FABRIC = "silk";
         obj->set_long("The "+LENGTH+" silk dress is beautiful and ever so"+
         " smooth but also quite delicate. It has been dyed "+VAR+" "+str+""+
         " shade. It is of excellent quality and cut in a very fashionable"+
         " style to help emphasize all the right curves.");
         break;
   }
   if(val < 5) {
      obj->set_value(5);
   }
   else {
      obj->set_value(val);
   }
   obj->set_name("dress");
   obj->set_type("clothing");
   obj->set_limbs(({"torso"}));
   obj->set_weight(3);
   obj->set_short("A "+LENGTH+" "+str+" dress");
   obj->set_id(({"dress","clothing",""+str+" dress",""+FABRIC+" dress",""+str+" "+FABRIC+" dress",""+LENGTH+" "+str+" dress",""+LENGTH+" dress",""+LENGTH+" "+FABRIC+" dress",""+LENGTH+" "+str+" "+FABRIC+" dress"}));
}
