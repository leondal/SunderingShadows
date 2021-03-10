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

void create_shirt(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "amethyst" || str == "emerald" || str == "aquamarine" || str == "indigo" || str == "olive green" || str == "ivory" || str == "azure" || str == "ocean blue") {
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
         " burlap shirt that has been dyed "+VAR+" "+str+" color. The"+
         " best thing about this shirt is that it will last for a long"+
         " time.");
         break;
      case 6..10:
         FABRIC = "hemp";
         obj->set_long("This "+LENGTH+" shirt is made out of sturdy"+
         " hemp that's been dyed "+VAR+" "+str+" color. It is slightly"+
         " itchy and rather uncomfortable to wear in the heat, but"+
         " appears very durable.");
         break;
      case 11..15:
         FABRIC = "cotton";
         obj->set_long("This is a soft, "+LENGTH+" cotton shirt that has"+
         " been dyed "+VAR+" "+str+" shade. It is of a very good quality and"+
         " looks durable in addition to being comfortable. The front"+
         " buttons up and there is a collar around the neck.");
         break;
      case 16..20:
         FABRIC = "woolen";
         obj->set_long("This is a hand-knit "+LENGTH+" woolen shirt that has"+
         " been dyed "+VAR+" "+str+" shade. It is of fine quality and looks"+
         " warm and durable, as well as fairly comfortable. This would"+
         " be good for the winters or colder climates.");
         break;
      case 21..25:
         FABRIC = "fleece";
         obj->set_long("This "+LENGTH+" fleece shirt is just about the"+
         " softest thing you've ever touched. It has been excellently"+
         " made and tightly woven to keep out the cold. It is "+VAR+""+
         " "+str+" shade and will keep you warm in the cold.");
         break;
      case 26..30:
         FABRIC = "suede";
         obj->set_long("This "+LENGTH+" suede shirt has been dyed "+VAR+""+
         " "+str+" color. It is fairly sturdy and rather smooth to the"+
         " touch. It buttons up the front with a collar around the neck.");
         break;
      case 31..35:
         FABRIC = "velvet";
         obj->set_long("The velvet shirt is very soft and quite pleasant"+
         " to touch. It is "+LENGTH+" and has been dyed "+VAR+" "+str+""+
         " shade. It is not the most durable of materials but is pretty"+
         " to look at.");
         break;
      case 36..40:
         FABRIC = "silk";
         obj->set_long("This is a delicate "+LENGTH+" silk shirt that has"+
         " been dyed "+VAR+" "+str+" shade. It is of excellent quality and"+
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
   obj->set_short(capitalize(VAR)+" "+str+" "+LENGTH+" "+FABRIC+" shirt");
   obj->set_id(({"shirt","clothing",""+str+" shirt",""+FABRIC+" shirt",""+str+" "+FABRIC+" shirt",""+LENGTH+" shirt",""+LENGTH+" "+FABRIC+" shirt",""+LENGTH+" "+str+" shirt",""+LENGTH+" "+str+" "+FABRIC+" shirt",""+str+" "+LENGTH+" "+FABRIC+" shirt",""+str+" "+LENGTH+" shirt"}));
}
