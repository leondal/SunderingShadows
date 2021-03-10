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
string str, FABRIC, VAR;

void create_tunic()
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "%^MAGENTA%^amethyst" || str == "%^BOLD%^%^GREEN%^emerald" || str == "%^BOLD%^%^CYAN%^aquamarine" || str == "%^BLUE%^indigo" || str == "%^GREEN%^olive green" || str == "%^BOLD%^%^WHITE%^ivory" || str == "%^BOLD%^%^CYAN%^azure" || str == "%^BOLD%^%^BLUE%^ocean blue") {
      VAR = "an";
   }
   val = random(30);
   switch(val) {
      case 0..5:
         FABRIC = "burlap";
         set_long("This burlap tunic is rather rough and uncomfortable."+
         " It has been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^color. This would be good"+
         " for field work or other strenuous activities for it will"+
         " hold up quite well.");
         break;
      case 6..10:
         FABRIC = "hemp";
         set_long("This tunic is made from sturdy hemp that's been"+
         " dyed "+VAR+" %^RESET%^"+str+" %^RESET%^color. It tends to make one a bit"+
         " itchy when it gets hot, but it is very durable.");
         break;
      case 11..15:
         FABRIC = "cotton";
         set_long("This is a thick cotton tunic that has been dyed"+
         " "+VAR+" %^RESET%^"+str+" %^RESET%^shade. It is of good quality and appears"+
         " durable in addition to being fairly comfortable.");
         break;
      case 16..20:
         FABRIC = "woolen";
         set_long("This is a hand-knit woolen tunic that has been"+
         " dyed "+VAR+" %^RESET%^"+str+" %^RESET%^shade. It is of fine quality and looks"+
         " warm and durable, as well as fairly comfortable. This would"+
         " be good for the winters or colder climates.");
         break;
      case 21..25:
         FABRIC = "suede";
         set_long("This suede tunic has been dyed "+VAR+""+
         " %^RESET%^"+str+" %^RESET%^color. It is rather fancy, as far as tunics go, and"+
         " is obviously not meant for work and other such demeaning"+
         " activities.");
         break;
      case 26..29:
         FABRIC = "velvet";
         set_long("The velvet tunic is soft and rather pleasant"+
         " to wear. It has been dyed "+VAR+" %^RESET%^"+str+" %^RESET%^shade. This is"+
         " obviously not for every day wear.");
         break;
   }
   if(val < 5) {
      set_value(5);
   }
   else {
      set_value(val);
   }
   set_name("tunic");
   set_type("clothing");
   set_limbs(({"torso"}));
   set_weight(5);
   set_short(capitalize(VAR)+" %^RESET%^"+str+"%^RESET%^ "+FABRIC+" tunic%^RESET%^");
   set_id(({"tunic","clothing",""+str+" tunic",""+FABRIC+" tunic",""+str+" "+FABRIC+" tunic"}));
}


void create()
{
   ::create();
   create_tunic();
   set_size(random(3)+1);
   set_cointype("silver");
}
