//mystery_cone.c - random ice cream cone for the adventurous
//sorts on Seneca beach
//~Circe~ 6/18/08

#include <std.h>

inherit "/std/food.c";

#define FLAVORS ({"%^RESET%^%^MAGENTA%^boysenberry",\
"%^YELLOW%^banana",\
"%^BOLD%^%^BLACK%^blackcurrant",\
"%^BOLD%^%^RED%^cherry",\
"%^BOLD%^%^WHITE%^coconut",\
"%^BOLD%^%^BLACK%^coffee",\
"%^BOLD%^%^GREEN%^honeydew",\
"%^RESET%^%^ORANGE%^mango",\
"%^BOLD%^%^WHITE%^pina colada",\
"%^RESET%^%^RED%^raspberry",\
"%^BOLD%^%^RED%^strawberry",\
"%^YELLOW%^cheesecake",\
"%^BOLD%^%^WHITE%^vanilla",\
"%^BOLD%^%^GREEN%^mint %^BLACK%^chocolate"})

#define WEIRDS ({"%^RESET%^%^RED%^cinnamon","%^BOLD%^%^GREEN%^cucumber","%^RESET%^%^ORANGE%^honey","%^YELLOW%^lemon","%^RESET%^%^ORANGE%^orange","%^BOLD%^%^RED%^p%^WHITE%^e%^RED%^p%^WHITE%^p%^RED%^e%^WHITE%^r%^RED%^m%^WHITE%^i%^RED%^n%^WHITE%^t","%^RESET%^%^MAGENTA%^prune","%^RESET%^%^ORANGE%^rum"})

#define YUCKS ({"%^GREEN%^brussel sprout","%^RESET%^%^ORANGE%^carrot","%^RESET%^%^GREEN%^dill","%^RESET%^%^RED%^paprika","%^RESET%^%^ORANGE%^cheese","%^BOLD%^%^WHITE%^sardine","%^BOLD%^%^GREEN%^spinach","%^YELLOW%^tripe","%^BOLD%^%^WHITE%^vinegar","%^BOLD%^%^GREEN%^zucchini"})

void create(){
   int i;
   string FLAVOR;
   ::create();
   set_name("mystery ice cream");
   set_id(({"cone","ice cream","ice cream cone","mystery cone","mystery ice cream cone","food"}));
   set_strength(15);
   set_weight(1);
   set_destroy();
   set_short("%^BOLD%^%^BLACK%^A %^CYAN%^M%^MAGENTA%^y%^GREEN%^s"+
      "%^YELLOW%^t%^RED%^e%^RESET%^%^CYAN%^r%^GREEN%^i%^BOLD%^"+
      "%^WHITE%^o%^BLUE%^u%^RESET%^%^ORANGE%^s %^BOLD%^%^MAGENTA%^"+
      "I%^RED%^c%^YELLOW%^e %^CYAN%^C%^BLACK%^r%^WHITE%^e%^RED%^a"+
      "%^BOLD%^%^GREEN%^m %^YELLOW%^C%^CYAN%^o%^MAGENTA%^n%^BOLD%^"+
      "%^GREEN%^e%^RESET%^");
   switch(random(10)){
      case 0..5:  FLAVOR = FLAVORS[random(sizeof(FLAVORS))];
                  set_long("Judging from the color and the light "+
                     "fragrance rising from it, this seems to be a "+
                     ""+FLAVOR+"-flavored %^RESET%^ice cream cone.  "+
                     "Two scoops have been piled high atop the "+
                     "delicate %^ORANGE%^waffle cone%^RESET%^, making "+
                     "this a delightful treat on a hot day.");
                  set_my_mess("You enjoy the delightful flavor of the ice cream.");
                  set_your_mess("seems to enjoy an unusual ice cream cone.");
                  break;
      case 6..8:  FLAVOR = WEIRDS[random(sizeof(WEIRDS))];
                  set_long("Judging from the color and light "+
                     "fragrance rising from it, this seems to be a "+
                     ""+FLAVOR+"-flavored %^RESET%^ice cream cone.  "+
                     "Two heaping scoops have been piled high atop "+
                     "the delicate %^ORANGE%^waffle cone%^RESET%^, "+
                     "providing ample opportunity for you to..."+
                     "enjoy...the flavor of this unusual concoction.");
                  set_my_mess("You cautiously eat the ice cream.  How...interesting.");
                  set_your_mess("cautiously eats an unusual ice cream cone.");
                  break;
      default:    FLAVOR = YUCKS[random(sizeof(YUCKS))];
                  set_long("Judgine from the color and light "+
                     "fragrance rising from it, this seems to be a "+
                     ""+FLAVOR+"-flavored%^RESET%^ ice cream cone.  "+
                     "You can't help but wonder who in their right "+
                     "mind would want to create such a thing, but "+
                     "here it stands before you - two scoops of "+
                     "the...treat...piled high atop a %^ORANGE%^"+
                     "waffle cone%^RESET%^ for you to savor.");
                  set_my_mess("The disgusting flavor of the ice cream is a little hard to stomach.");
                  set_your_mess("eats an unusual ice cream cone and looks sick.");
                  break;

   }
}
