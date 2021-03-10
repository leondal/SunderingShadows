#include <std.h>

#define GEMS ({"%^BOLD%^%^WHITE%^sno%^BLACK%^w%^WHITE%^flake %^BLACK%^obs%^WHITE%^i%^BLACK%^dian","%^RESET%^%^ORANGE%^tig%^YELLOW%^e%^RESET%^%^ORANGE%^r's eye","%^RESET%^%^RED%^carn%^BOLD%^e%^RESET%^%^RED%^lian","%^BOLD%^%^RED%^red jasper","%^YELLOW%^citrine","%^RESET%^%^ORANGE%^py%^YELLOW%^ri%^RESET%^%^ORANGE%^te","%^GREEN%^aventurine","%^BOLD%^%^MAGENTA%^rose quartz","%^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^thy%^BOLD%^s%^RESET%^%^MAGENTA%^t","%^CYAN%^aquamarine","%^CYAN%^turq%^BOLD%^uo%^RESET%^%^CYAN%^ise","%^BOLD%^%^WHITE%^clear calcite"})
#define METALS ({"silver","%^ORANGE%^brass","%^ORANGE%^co%^GREEN%^p%^ORANGE%^p%^GREEN%^e%^ORANGE%^r","%^YELLOW%^gold","%^BOLD%^%^WHITE%^platinum"})

inherit DAEMON;

int i,j,price1,price2;
string str, GEM,METAL;

void create_clasp(object obj)
{
	j = random(sizeof(GEMS));
	GEM = GEMS[j];
	i = random(sizeof(METALS));
	METAL = METALS[i];
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
	obj->set_name(""+str+" "+GEM+" clasp%^RESET%^");
	obj->set_short(""+str+" "+GEM+" clasp%^RESET%^");
	obj->set_id(({"clasp",""+GEM+" clasp"}));
	obj->set_long("This clasp is made to hold an article of clothing "+
         "closed.  It has been made so that it tapers at each end, "+
         "allowing it to be slipped into buttonholes, or it may "+
         "be attached by utilizing the cleverly hidden pin on the "+
         "back side.  This particular clasp is oval-shaped and set "+
         "with a highly-polished "+GEM+"%^RESET%^.  The clasp itself "+
         "is made of "+METAL+" %^RESET%^and is rather fashionable.");
	obj->set_weight(2);
	obj->set_type("ring");
	obj->set_limbs(({"neck"}));
	obj->set_ac(0);
}
