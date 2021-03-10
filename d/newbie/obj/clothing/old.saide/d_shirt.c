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
void create_shirt(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "%^MAGENTA%^amethyst" || str == "%^BOLD%^%^GREEN%^emerald" || str == "%^BOLD%^%^CYAN%^aquamarine" || str == "%^BLUE%^indigo" || str == "%^GREEN%^olive green" || str == "%^BOLD%^%^WHITE%^ivory" || str == "%^BOLD%^%^CYAN%^azure" || str == "%^BOLD%^%^BLUE%^ocean blue") {
      VAR = "an";
   }
	switch(random(2)) {
      case 0:
         LENGTH = "short sleeved";
         break;
      case 1:
         LENGTH = "long sleeved";
         break;
	}
   val = random(40);
   switch(val) {
      case 0..5:
         FABRIC = "burlap";
         obj->set_long("This is a rather rough and uncomfortable "+LENGTH+""+
         " burlap shirt that has been dyed "+VAR+" %^RESET%^"+str+"%^RESET%^ color. The"+
         " best thing about this shirt is that it will last for a long"+
         " time.");
         break;
      case 6..10:
         FABRIC = "hemp";
         obj->set_long("This "+LENGTH+" shirt is made out of sturdy"+
         " hemp that's been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^ color. It is slightly"+
         " itchy and rather uncomfortable to wear in the heat, but"+
         " appears very durable.");
         break;
      case 11..15:
         FABRIC = "cotton";
         obj->set_long("This is a soft, "+LENGTH+" cotton shirt that has"+
         " been dyed "+VAR+" %^RESET%^ "+str+" %^RESET%^shade. It is of a very good quality and"+
         " looks durable in addition to being comfortable. The front"+
         " buttons up and there is a collar around the neck.");
         break;
      case 16..20:
         FABRIC = "woolen";
         obj->set_long("This is a hand-knit "+LENGTH+" woolen shirt that has"+
         " been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^shade. It is of fine quality and looks"+
         " warm and durable, as well as fairly comfortable. This would"+
         " be good for the winters or colder climates.");
         break;
      case 21..25:
         FABRIC = "fleece";
         obj->set_long("This "+LENGTH+" fleece shirt is just about the"+
         " softest thing you've ever touched. It has been excellently"+
         " made and tightly woven to keep out the cold. It is "+VAR+""+
         " %^RESET%^"+str+" %^RESET%^shade and will keep you warm in the cold.");
         break;
      case 26..30:
         FABRIC = "suede";
         obj->set_long("This "+LENGTH+" suede shirt has been dyed "+VAR+""+
         " %^RESET%^"+str+" %^RESET%^color. It is fairly sturdy and rather smooth to the"+
         " touch. It buttons up the front with a collar around the neck.");
         break;
      case 31..35:
         FABRIC = "velvet";
         obj->set_long("The velvet shirt is very soft and quite pleasant"+
         " to touch. It is "+LENGTH+" and has been dyed "+VAR+" %^RESET%^"+str+""+
         " %^RESET%^shade. It is not the most durable of materials but is pretty"+
         " to look at.");
         break;
      case 36..39:
         FABRIC = "silk";
         obj->set_long("This is a delicate "+LENGTH+" silk shirt that has"+
         " been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^shade. It is of excellent quality and"+
         " incredibly soft to the touch. A shirt like this is not for"+
         " every day wear, and would probably not last long unless"+
         " carefully treated.");
         break;
   }
   if(val < 5) {
      obj->set_value(5);
   }
   else {
      obj->set_value(val);
   }
   obj->set_name("shirt");
   obj->set_type("clothing");
   obj->set_limbs(({"torso"}));
   obj->set_weight(3);
 obj->set_short(capitalize(VAR)+" "+str+"%^RESET%^ "+LENGTH+" "+FABRIC+" shirt%^RESET%^");
   obj->set_id(({"shirt","clothing",""+str+" shirt",""+FABRIC+" shirt",""+str+" "+FABRIC+" shirt",""+LENGTH+" shirt",""+LENGTH+" "+FABRIC+" shirt",""+LENGTH+" "+str+" shirt",""+LENGTH+" "+str+" "+FABRIC+" shirt",""+str+" "+LENGTH+" "+FABRIC+" shirt",""+str+" "+LENGTH+" shirt"}));
}
