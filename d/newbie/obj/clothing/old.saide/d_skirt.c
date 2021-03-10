#include <std.h>

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

inherit DAEMON;

int j, val;
string str, FABRIC, VAR, LENGTH;
void create_skirt(object obj)
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
   val = random(40);
   switch(val) {
      case 0..5:
         FABRIC = "burlap";
         obj->set_long("This is a rough and rather crude "+LENGTH+" "+
         "burlap skirt that has been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^color%^RESET%^. It "+
         "would probably be good for washing the floor or some other "+
         "menial activity though it is not very flattering.");
         break;
      case 6..10:
         FABRIC = "hemp";
         obj->set_long("This "+LENGTH+" skirt is made out of light "+
         "hemp that has been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^color%^RESET%^. It is fairly "+
         "light and also pretty durable.  Although not the most stylish "+
         "of skirts, it is practical.");
         break;
      case 11..15:
         FABRIC = "cotton";
         obj->set_long("The "+LENGTH+" cotton skirt is light and soft. It's"+
         " been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^ shade%^RESET%^. It is rather thin, and would "+
         "probably not be the most durable, though it is certainly better "+
         "than silk or chiffon.");
         break;
      case 16..20:
         FABRIC = "linen";
         obj->set_long("This is a "+LENGTH+" linen skirt that's"+
         " been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^shade%^RESET%^. It is incredibly light and "+
         "flexible, perfect for warmer climates.");
         break;
      case 21..25:
         FABRIC = "suede";
         obj->set_long("The "+LENGTH+" suede skirt has been dyed "+VAR+""+
         " %^RESET%^ "+str+" %^RESET%^shade%^RESET%^. It is durable and helps protect from the wind,"+
         " in addition to being rather fashionable.");
         break;
      case 26..30:
         FABRIC = "velvet";
         obj->set_long("The "+LENGTH+" velvet skirt is quite soft and"+ 
         " pleasant to touch. It's been dyed "+VAR+" %^RESET%^"+str+" shade%^RESET%^."+
         " Although it's not the most durable of materials it is pretty"+
         " to look at and very flattering.");
         break;
      case 31..34:
         FABRIC = "silk";
         obj->set_long("The "+LENGTH+" silk skirt is beautiful and ever so"+
         " smooth but also quite delicate. It has been dyed "+VAR+" "+str+""+
         " shade%^RESET%^. It is of excellent quality and cut in a very fashionable"+
         " style to help emphasize all the right curves.");
         break;
      case 35..39:
         FABRIC = "chiffon";
         obj->set_long("This extraordinary "+LENGTH+" skirt is made of "+
         "soft, sheer chiffon dyed "+VAR+" "+str+" %^RESET%^shade.  It is layered over "+
         "slightly darker silk, creating a stunning effect.  While not "+
         "practical for anything other than gathering wildflowers or "+
         "lounging about doing other girlish activities, it is the most "+
         "beautiful of skirts and flatters all the right curves.");
         break;
   }
   if(val < 5) {
      obj->set_value(5);
   }
   else {
      obj->set_value(val);
   }
   obj->set_name("dress");
   obj->set_type("ring"); //changed to ring to allow them to be worn 
//with pouches.  ~Circe~ 4/29/05
   obj->set_limbs(({"waist"}));
   obj->set_weight(3);
   obj->set_short("%^RESET%^A "+LENGTH+" %^RESET%^"+str+"%^RESET%^ "+FABRIC+" skirt");
   obj->set_id(({"skirt","clothing",""+str+" skirt%^RESET%^",""+FABRIC+" skirt",""+str+" "+FABRIC+" skirt%^RESET%^",""+LENGTH+" "+str+" skirt%^RESET%^",""+LENGTH+" skirt",""+LENGTH+" "+FABRIC+" skirt",""+LENGTH+" "+str+" "+FABRIC+" skirt%^RESET%^"}));
}
