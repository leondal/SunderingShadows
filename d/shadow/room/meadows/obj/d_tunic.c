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

void create_tunic(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "amethyst" || str == "emerald green" || str == "aquamarine" || str == "indigo" || str == "olive green" || str == "ivory" || str == "azure" || str == "ocean blue") {
      VAR = "an";
   }
   val = random(30);
   switch(val) {
      case 0..5:
         FABRIC = "burlap";
         obj->set_long("This burlap tunic is rather rough and uncomfortable."+
         " It has been dyed "+VAR+" "+str+" color. This would be good"+
         " for field work or other strenuous activities for it will"+
         " hold up quite well.");
         break;
      case 6..10:
         FABRIC = "hemp";
         obj->set_long("This tunic is made from sturdy hemp that's been"+
         " dyed "+VAR+" "+str+" color. It tends to make one a bit"+
         " itchy when it gets hot, but it is very durable.");
         break;
      case 11..15:
         FABRIC = "cotton";
         obj->set_long("This is a thick cotton tunic that has been dyed"+
         " "+VAR+" "+str+" shade. It is of good quality and appears"+
         " durable in addition to being fairly comfortable.");
         break;
      case 16..20:
         FABRIC = "woolen";
         obj->set_long("This is a hand-knit woolen tunic that has been"+
         " dyed "+VAR+" "+str+" shade. It is of fine quality and looks"+
         " warm and durable, as well as fairly comfortable. This would"+
         " be good for the winters or colder climates.");
         break;
      case 21..25:
         FABRIC = "suede";
         obj->set_long("This suede tunic has been dyed "+VAR+""+
         " "+str+" color. It is rather fancy, as far as tunics go, and"+
         " is obviously not meant for work and other such demeaning"+
         " activities.");
         break;
      case 26..30:
         FABRIC = "velvet";
         obj->set_long("The velvet tunic is soft and rather pleasant"+
         " to wear. It has been dyed "+VAR+" "+str+" shade. This is"+
         " obviously not for every day wear.");
         break;
   }
   if(val < 5) {
      obj->set_value(5);
   }
   else {
      obj->set_value(val);
   }
   obj->set_name("tunic");
   obj->set_type("clothing");
   obj->set_limbs(({"torso"}));
   obj->set_weight(5);
   obj->set_short(capitalize(VAR)+" "+str+" "+FABRIC+" tunic");
   obj->set_id(({"tunic","clothing",""+str+" tunic",""+FABRIC+" tunic",""+str+" "+FABRIC+" tunic"}));
}
