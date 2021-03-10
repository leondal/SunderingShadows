#include <std.h>

#define GEMS ({"%^BOLD%^%^WHITE%^sno%^BLACK%^w%^WHITE%^flake %^BLACK%^obs%^WHITE%^i%^BLACK%^dian","%^RESET%^%^ORANGE%^tig%^YELLOW%^e%^RESET%^%^ORANGE%^r's eye","%^RESET%^%^RED%^carn%^BOLD%^e%^RESET%^%^RED%^lian","%^BOLD%^%^RED%^red jasper","%^YELLOW%^citrine","%^RESET%^%^ORANGE%^py%^YELLOW%^ri%^RESET%^%^ORANGE%^te","%^GREEN%^aventurine","%^BOLD%^%^MAGENTA%^rose quartz","%^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^thy%^BOLD%^s%^RESET%^%^MAGENTA%^t","%^CYAN%^aquamarine","%^CYAN%^turq%^BOLD%^uo%^RESET%^%^CYAN%^ise","%^BOLD%^%^WHITE%^clear calcite","%^BOLD%^%^MAGENTA%^pink coral","%^BOLD%^%^BLUE%^blue coral","%^GREEN%^jade","%^BOLD%^%^WHITE%^moonstone","%^BOLD%^%^RED%^f%^RESET%^%^ORANGE%^i%^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^e %^RED%^opal","%^BOLD%^%^BLUE%^blue spinel","%^GREEN%^green tourmaline","%^BOLD%^%^WHITE%^dia%^CYAN%^m%^WHITE%^ond"})
#define METALS ({"silver","%^ORANGE%^brass","%^ORANGE%^co%^GREEN%^p%^ORANGE%^p%^GREEN%^e%^ORANGE%^r","%^YELLOW%^gold","%^BOLD%^%^WHITE%^platinum"})


inherit DAEMON;

int i,j,price1,price2;
string str,GEM,METAL;

void create_earrings(object obj)
{
	j = random(sizeof(GEMS));
	GEM = GEMS[j];
	i = random(sizeof(METALS));
	METAL = METALS[i];
      price1 = random(25)+40;
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
	obj->set_name(""+GEM+" petal earrings%^RESET%^");
	obj->set_short(""+GEM+" petal earrings%^RESET%^");
	obj->set_id(({"earrings","petal earrings",""+GEM+" earrings",""+GEM+" petal earrings"}));
	obj->set_long("These earrings are made of thin "+METAL+" "+
         "%^RESET%^hooks that dangle from the wearer's earlobes.  "+
         "Each earring supports a delicate petal-shaped "+GEM+" "+
         "%^RESET%^that shimmers when the light hits it.  They "+
         "are lightweight and would make a wonderful addition "+
         "to any woman's wardrobe.");
	obj->set_weight(1);
	obj->set_type("ring");
	obj->set_limbs(({"head"}));
	obj->set_ac(0);
}
