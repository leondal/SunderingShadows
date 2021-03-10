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
string str, FABRIC, VAR, STYLE;

void create()
{
   ::create();
}

void create_sweater(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "amethyst" || str == "emerald" || str == "aquamarine" || str == "indigo" || str == "olive green" || str == "ivory" || str == "azure" || str == "ocean blue") {
      VAR = "an";
   }
	switch(random(2)) {
      case 0:
         STYLE = "light";
         break;
      case 1:
         STYLE = "heavy";
         break;
	}
   val = random(15);
   switch(val) {
      case 0..5:
         FABRIC = "cotton";
         obj->set_long("This is a soft, "+STYLE+" cotton sweater that has"+
         " been dyed "+VAR+" "+str+" shade. It has been tightly woven to"+
         " help add a bit of protection against the wind, but it doesn't"+
         " help all that much.");
         break;
      case 6..10:
         FABRIC = "woolen";
         obj->set_long("This is a hand-knit "+STYLE+" woolen sweater that's"+
         " been dyed "+VAR+" "+str+" shade. It is of fine quality and looks"+
         " soft and warm.");
         break;
      case 11..15:
         FABRIC = "fleece";
         obj->set_long("This "+STYLE+" fleece sweater is so very soft you"+
         " don't really want to let it go. It has been dyed "+VAR+" "+str+""+
         " shade and will keep you warm in the cold.");
         break;
   }
   if(val < 2) {
      obj->set_value(2);
   }
   else {
      obj->set_value(val);
   }
   obj->set_name("sweater");
   obj->set_type("clothing");
   obj->set_limbs(({"torso"}));
   obj->set_weight(3);
   obj->set_short("A "+STYLE+" "+str+" "+FABRIC+" sweater");
   obj->set_id(({"sweater","clothing",""+str+" sweater",""+FABRIC+" sweater",""+str+" "+FABRIC+" sweater",""+STYLE+" sweater",""+STYLE+" "+str+" sweater",""+STYLE+" "+FABRIC+" sweater",""+STYLE+" "+str+" "+FABRIC+" sweater"}));
}
