#include <std.h>

#define GEMS ({"%^BOLD%^%^WHITE%^sno%^BLACK%^w%^WHITE%^flake %^BLACK%^obs%^WHITE%^i%^BLACK%^dian","%^RESET%^%^ORANGE%^tig%^YELLOW%^e%^RESET%^%^ORANGE%^r's eye","%^RESET%^%^RED%^carn%^BOLD%^e%^RESET%^%^RED%^lian","%^BOLD%^%^RED%^red jasper","%^YELLOW%^citrine","%^RESET%^%^ORANGE%^py%^YELLOW%^ri%^RESET%^%^ORANGE%^te","%^GREEN%^aventurine","%^BOLD%^%^MAGENTA%^rose quartz","%^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^thy%^BOLD%^s%^RESET%^%^MAGENTA%^t","%^CYAN%^aquamarine","%^CYAN%^turq%^BOLD%^uo%^RESET%^%^CYAN%^ise","%^BOLD%^%^WHITE%^clear calcite"})
#define METALS ({"silver","%^ORANGE%^brass","%^ORANGE%^co%^GREEN%^p%^ORANGE%^p%^GREEN%^e%^ORANGE%^r","%^YELLOW%^gold","%^BOLD%^%^WHITE%^platinum"})
#define SHAPES ({"%^YELLOW%^sunrise","%^CYAN%^falcon","%^GREEN%^serpent","%^BOLD%^%^BLACK%^raven","%^ORANGE%^wolf","%^BOLD%^%^BLACK%^panther","%^RED%^hawk","%^ORANGE%^bear","%^BOLD%^%^CYAN%^crescent moon"})

inherit DAEMON;

int i,j,k,price1,price2;
string str, GEM,METAL,SHAPE;

void create_cufflinks(object obj)
{
	j = random(sizeof(GEMS));
	GEM = GEMS[j];
	i = random(sizeof(METALS));
	METAL = METALS[i];
      k = random(sizeof(SHAPES));
      SHAPE = SHAPES[k];
      price1 = random(10)+25;
      switch(i){
         case 0..2:  price2 = random(15)+15;
                     break;
         case 3:  price2 = random(25)+25;
                  break;
         case 4:  price2 = random(35)+35;
                  break;
      }
      if(GEM == "%^GREEN%^aventurine" || GEM == "%^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^thy%^BOLD%^s%^RESET%^%^MAGENTA%^t" || GEM == "%^CYAN%^aquamarine"){
         str = "an";
      }else{
         str = "a";
      }
	obj->set_value(price1+price2);
	obj->set_name("a pair of "+GEM+" cufflinks%^RESET%^");
	obj->set_short("a pair of "+GEM+" cufflinks%^RESET%^");
	obj->set_id(({"cufflinks","cuff links","pair of cufflinks","paif of "+GEM+" cufflinks"}));
	obj->set_long("These cufflinks are made of "+METAL+" posts "+
         "%^RESET%^that each hold a cabochon-cut "+GEM+"%^RESET%^.  "+
         "The "+GEM+" %^RESET%^has a "+SHAPE+" intaglio %^RESET%^beneath the "+
         "surface, and the carving is flawless!  Cufflinks are often "+
         "worn as a decoration upon the sleeves of the higher classes "+
         "of the lands.");
	obj->set_weight(2);
	obj->set_type("ring");
	obj->set_limbs(({"right arm","left arm"}));
	obj->set_ac(0);
}
