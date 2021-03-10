#include <std.h>

#define GEMS ({"%^BOLD%^%^WHITE%^sno%^BLACK%^w%^WHITE%^flake %^BLACK%^obs%^WHITE%^i%^BLACK%^dian","%^RESET%^%^ORANGE%^tig%^YELLOW%^e%^RESET%^%^ORANGE%^r's eye","%^RESET%^%^RED%^carn%^BOLD%^e%^RESET%^%^RED%^lian","%^BOLD%^%^RED%^red jasper","%^YELLOW%^citrine","%^RESET%^%^ORANGE%^py%^YELLOW%^ri%^RESET%^%^ORANGE%^te","%^GREEN%^aventurine","%^BOLD%^%^MAGENTA%^rose quartz","%^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^thy%^BOLD%^s%^RESET%^%^MAGENTA%^t","%^CYAN%^aquamarine","%^CYAN%^turq%^BOLD%^uo%^RESET%^%^CYAN%^ise","%^BOLD%^%^WHITE%^clear calcite"})
#define STONES ({"%^BOLD%^%^MAGENTA%^pink coral","%^BOLD%^%^BLUE%^blue coral","%^GREEN%^jade","%^BOLD%^%^WHITE%^moonstone","%^BOLD%^%^RED%^f%^RESET%^%^ORANGE%^i%^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^e %^RED%^opal","%^BOLD%^%^BLUE%^blue spinel","%^GREEN%^green tourmaline","%^BOLD%^%^WHITE%^dia%^CYAN%^m%^WHITE%^ond"})

inherit DAEMON;

int i,j,price1,price2;
string str,GEM,STONE;

void create_bracelet(object obj)
{
	j = random(sizeof(GEMS));
	GEM = GEMS[j];
	i = random(sizeof(STONES));
	STONE = STONES[i];
      price1 = random(30)+30;
      switch(i){
         case 0..2:  price2 = random(15)+50;
                     break;
         case 3:  price2 = random(25)+75;
                  break;
         case 4:  price2 = random(35)+100;
                  break;
      }
      if(GEM == "%^GREEN%^aventurine" || GEM == "%^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^thy%^BOLD%^s%^RESET%^%^MAGENTA%^t" || GEM == "%^CYAN%^aquamarine"){
         str = "an";
      }else{
         str = "a";
      }
	obj->set_value(price1+price2);
	obj->set_name("crushed "+GEM+" bracelet%^RESET%^");
	obj->set_short("crushed "+GEM+" bracelet%^RESET%^");
	obj->set_id(({"bracelet",""+GEM+" bracelet","crushed bracelet","crushed "+GEM+" bracelet"}));
	obj->set_long("A stunning creation, this bracelet looks to be "+
         "made entirely of s%^BOLD%^p%^RESET%^a%^BOLD%^r%^RESET%^k"+
         "%^BOLD%^l%^RESET%^i%^BOLD%^n%^RESET%^g gems!  Upon closer "+
         "inspection, you see that the bracelet itself is a piece "+
         "of supple black leather fitted with a unique clasp made of "+
         "platinum.  The clasp is mostly hidden within the leather, but "+
         "what you can see of it is an 'S' shape that slips snuggly "+
         "into the other part of the leather, closing the bracelet "+
         "seamlessly.  The surface of the bracelet has been covered "+
         "in crushed "+GEM+" %^RESET%^sprinkled with larger pieces "+
         "of "+STONE+"%^RESET%^!  Much time and care clearly went "+
         "into the crafting of this beautiful bracelet.");
	obj->set_weight(2);
	obj->set_type("ring");
	obj->set_limbs(({"right arm"}));
	obj->set_ac(0);
}
