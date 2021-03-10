#include <std.h>

#define GEMS ({"%^BOLD%^%^WHITE%^sno%^BLACK%^w%^WHITE%^flake %^BLACK%^obs%^WHITE%^i%^BLACK%^dian","%^RESET%^%^ORANGE%^tig%^YELLOW%^e%^RESET%^%^ORANGE%^r's eye","%^RESET%^%^RED%^carn%^BOLD%^e%^RESET%^%^RED%^lian","%^BOLD%^%^RED%^red jasper","%^YELLOW%^citrine","%^RESET%^%^ORANGE%^py%^YELLOW%^ri%^RESET%^%^ORANGE%^te","%^GREEN%^aventurine","%^BOLD%^%^MAGENTA%^rose quartz","%^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^thy%^BOLD%^s%^RESET%^%^MAGENTA%^t","%^CYAN%^aquamarine","%^CYAN%^turq%^BOLD%^uo%^RESET%^%^CYAN%^ise","%^BOLD%^%^WHITE%^clear calcite"})
#define METALS ({"silver","%^ORANGE%^brass","%^ORANGE%^co%^GREEN%^p%^ORANGE%^p%^GREEN%^e%^ORANGE%^r","%^YELLOW%^gold","%^BOLD%^%^WHITE%^platinum"})

inherit DAEMON;

int i,j,price1,price2;
string str, GEM,METAL;

void create_strand(object obj)
{
	j = random(sizeof(GEMS));
	GEM = GEMS[j];
	i = random(sizeof(METALS));
	METAL = METALS[i];
      price1 = random(10)+25;
      switch(i){
         case 0..2:  price2 = random(15)+5;
                     break;
         case 3:  price2 = random(25)+15;
                  break;
         case 4:  price2 = random(35)+25;
                  break;
      }
	obj->set_value(price1+price2);
	obj->set_name(""+GEM+" strand");
	obj->set_short(""+GEM+" strand%^RESET%^");
	obj->set_id(({"necklace",""+GEM+" necklace","strand",""+METAL+" strand",""+GEM+" strand","crystal strand"}));
	obj->set_long("This necklace is made of a fine strand of "+METAL+" "+
         "%^RESET%^with tiny knots tied at regular intervals.  The knots "+
         "support chips of "+GEM+" crystals%^RESET%^, making this necklace "+
         "sparkle in the light.");
	obj->set_weight(1);
	obj->set_type("ring");
	obj->set_limbs(({"neck"}));
	obj->set_ac(0);
}
