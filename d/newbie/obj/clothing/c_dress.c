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
string str, FABRIC, VAR, LENGTH;
void create_dress()
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "%^MAGENTA%^amethyst" || str == "%^BOLD%^%^GREEN%^emerald" || str == "%^BOLD%^%^CYAN%^aquamarine" || str == "%^BLUE%^indigo" || str == "%^GREEN%^olive green" || str == "%^BOLD%^%^WHITE%^ivory" || str == "%^BOLD%^%^CYAN%^azure" || str == "%^BOLD%^%^BLUE%^ocean blue") {
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
         set_long("This is a rough and rather crude "+LENGTH+" burlap dress that"+
         " has been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^color. It would be good for washing"+
         " floor or some other menial activity.");
         break;
      case 6..10:
         FABRIC = "hemp";
         set_long("This "+LENGTH+" dress is made out of light hemp that"+
         " has been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^color. It is fairly light and also"+
         " pretty durable, although not the most stylish of dresses, it is"+
         " practical.");
         break;
      case 11..15:
         FABRIC = "cotton";
         set_long("The "+LENGTH+" cotton dress is light and soft. It's"+
         " been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^shade. It is perfect for lounging"+
         " around in, picking wildflowers, or other girlish activities.");
         break;
      case 16..20:
         FABRIC = "woolen";
         set_long("This is a hand-knit "+LENGTH+" woolen dress that's"+
         " been dyed "+VAR+" %^RESET%^"+str+"%^RESET%^ shade. It is incredibly warm and quite"+
         " soft, perfect for some of the cooler climates.");
         break;
      case 21..25:
         FABRIC = "suede";
         set_long("The "+LENGTH+" suede dress has been dyed "+VAR+""+
         " %^RESET%^"+str+"%^RESET%^ shade. It is durable and helps protect from the wind,"+
         " in addition to being rather fashionable.");
         break;
      case 26..30:
         FABRIC = "velvet";
         set_long("The "+LENGTH+" velvet dress is quite soft and"+ 
         " pleasant to touch. It's been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^shade."+
         " Although it's not the most durable of materials it is pretty"+
         " to look at.");
         break;
      case 31..34:
         FABRIC = "silk";
         set_long("The "+LENGTH+" silk dress is beautiful and ever so"+
         " smooth but also quite delicate. It has been dyed "+VAR+" %^RESET%^"+
         ""+str+" %^RESET%^"+
         " shade. It is of excellent quality and cut in a very fashionable"+
         " style to help emphasize all the right curves.");
         break;
   }
   if(val < 5) {
      set_value(5);
   }
   else {
      set_value(val);
   }
   set_name("dress");
   set_type("clothing");
   set_limbs(({"torso"}));
   set_weight(3);
   set_short("%^RESET%^A "+LENGTH+" %^RESET%^"+str+" %^RESET%^dress");
   set_id(({"dress","clothing",""+str+" dress",""+FABRIC+" dress",""+str+" "+FABRIC+" dress",""+LENGTH+" "+str+" dress",""+LENGTH+" dress",""+LENGTH+" "+FABRIC+" dress",""+LENGTH+" "+str+" "+FABRIC+" dress"}));
}


void create()
{
   ::create();
   create_dress();   
   set_size(random(3)+1);
   set_cointype("silver");
}

