#include <std.h>

#define COLORS ({"gray","black","white","lavender","peach","golden","blue","green","rose"})

#define METALS ({"silver","electrum","gold","white gold","rose gold","platinum"})

inherit DAEMON;

int i, j, val, price1, price2;
string str, METAL, DESC1, COLOR;

void create()
{
   ::create();
}

void create_pearls(object obj)
{
   j = random(9);
   str = COLORS[j];
   i = random(6);
   METAL = METALS[i];
   switch(j) {
      case 0:
         price1 = random(100)+800;
         COLOR = "%^BOLD%^%^BLACK%^";
         DESC1 = "The pearl has a slight gray tint to it, they are semi-rare"+
         " but are found easier than the black pearls, although they are"+
         " still quite pretty.";
         break;
      case 1:
         price1 = random(100)+600;
         COLOR = "%^RESET%^";
         DESC1 = "Black pearls are incredibly rare and hard to come by,"+
         " to find one so large is unusual and very special.";
         break;
      case 2:
         price1 = random(150)+200;
         COLOR = "%^BOLD%^%^WHITE%^";
         DESC1 = "The pearl is a glistening white and absolutely flawless.";
         break;
      case 3:
         price1 = random(50)+350;
         COLOR = "%^MAGENTA%^%^BOLD%^";
         DESC1 =  "This pearl has a slight lavender hue to it which is"+
         " highly prized, some say it brings luck but no one is sure.";
         break;
      case 4:
         price1 = random(50)+350;
         COLOR = "%^RESET%^%^ORANGE%^";
         DESC1 = "The peach pearl is a very soft and pale color and is"+
         " supposed to be a sign of further health and happiness.";
         break;
      case 5:
         price1 = random(50)+350;
         COLOR = "%^YELLOW%^";
         DESC1 = "The golden pearls are slightly uncommon and have a nice"+
         " luster to them, a rather pleasant warm glow.";
         break;
      case 6:
         price1 = random(100)+400;
         COLOR = "%^BOLD%^%^CYAN%^";
         DESC1 = "The pearl has a faint blue hue to it, almost as though"+
         " it never quite left the depths of the ocean. Some people think"+
         " blue pearls help one acquire wisdom, but others say that is just"+
         " an old wives tale.";
         break;
      case 7:
         price1 = random(100)+400;
         COLOR = "%^BOLD%^%^GREEN%^";
         DESC1 = "The pearl is a soft shade of sea foam green and is quite"+
         " lovely. Sea elves often tend to prefer the rare green pearls and"+
         " some people think they help to encourage adventure.";
         break;
      case 8:
         price1 = random(50)+350;
         COLOR = "%^BOLD%^%^RED%^";
         DESC1 = "This pearl has a deep rose hue to it that is very catching."+
         " The rose pearl is supposed to help one find true love, or to"+
         " encourage love to grow deeper.";
         break;
   }
   switch(i) {
      case 0:
         price2 = random(25)+50;
         break;
      case 1:
         price2 = random(50)+100;
         break;
      case 2..4:
         price2 = random(75)+200;
         break;
      case 5:
         price2 = random(100)+500;
         break;
   }
	val = price1 + price2;
   obj->set_name("pearl necklace");
   obj->set_short(""+COLOR+"A "+str+" pearl necklace%^RESET%^");
   obj->set_id(({"necklace","pearl necklace",""+str+" necklace",""+str+" pearl necklace","neacklace of pearls",""+METAL+" necklace",""+METAL+" pearl necklace",""+METAL+" "+str+" pearl necklace","r_pearls"}));
   obj->set_long("The necklace consists of a dainty "+METAL+" chain that"+
   " has a large "+str+" pearl set in the center of the "+METAL+" heart"+
   " that is strung on the chain. "+DESC1+"");
   obj->set_value(val);
   obj->set_weight(1);
   obj->set_type("ring");
   obj->set_limbs(({"neck"}));
   obj->set_wear("You slip the "+str+" pearl necklace around your neck.");
   obj->set_remove("You remove the "+str+" pearl necklace wistfully.");
   obj->set_size(random(3)+1);
}
