#include <std.h>

#define STYLES ({"crescent moon",\
"shooting star",\
"star",\
"eagle",\
"owl",\
"harp",\
"wolf"})

inherit DAEMON;

int j, val;
string str, METAL, X, DESC;

void create()
{
   ::create();
}

void create_amulet(object obj)
{
   val = random(800);
   j = random(7);
   str = STYLES[j];
   switch(j) {
      case 0:
         DESC = "%^CYAN%^The %^BOLD%^%^WHITE%^moonstone%^RESET%^%^CYAN%^"+
		" has been carved into the image of a %^BOLD%^%^WHITE%^crescent"+
         " moon%^RESET%^%^CYAN%^, a common enough symbol among Selune followers that is"+
         " fairly simple to make.";
         break;
      case 1:
         DESC = "%^CYAN%^The %^BOLD%^%^WHITE%^moonstone%^RESET%^%^CYAN%^"+
		" has been carved into the image of a %^BOLD%^shooting"+
         	" star%^RESET%^%^CYAN%^, with several slender moonstone slivers trailing behind"+
         	" the star as it arcs upwards.";
         break;
      case 2:
         DESC = "%^CYAN%^The %^BOLD%^%^WHITE%^moonstone%^RESET%^%^CYAN%^"+
		" is incredibly clear and has been carved"+
         	" into the image of a %^BOLD%^%^WHITE%^star%^RESET%^%^CYAN%^"+
		" that seems to be twinkling in the light."; 
         break;
      case 3:
         DESC = "%^CYAN%^The %^BOLD%^%^WHITE%^moonstone%^RESET%^%^CYAN%^"+
		" has been carved into the image of an %^BOLD%^%^BLUE%^eagle"+
         	" %^RESET%^%^CYAN%^with wings spread in flight, ready to explore and find the"+
         " limits of its flight. The detail of the eagle is incredible,"+
         " even the claws and feathers have been carefully marked.";
         break;
      case 4:
         DESC = "%^CYAN%^The %^BOLD%^%^WHITE%^moonstone%^RESET%^%^CYAN%^"+
		" is a milky white and has been carved into"+
         	" the image of a %^BOLD%^%^WHITE%^wise owl%^RESET%^%^CYAN%^"+
		" that is carefully observing the world"+
         	" at hand. The detail of the owl is exquisite, with all the"+
         	" feathers having been finely carved in."; 
         break;
      case 5:
         DESC = "%^CYAN%^The %^BOLD%^%^WHITE%^moonstone%^RESET%^%^CYAN%^"+
		" has been carved into the image of a %^MAGENTA%^harp%^RESET%^%^CYAN%^."+
         " The edges of the harp are a milky white, while the slender"+
         " slivers that make up the strings are almost crystal clear.";
         break;
      case 6:
         DESC = "%^CYAN%^The %^BOLD%^%^WHITE%^moonstone%^RESET%^%^CYAN%^"+
		" has been carved into the image of a %^BOLD%^%^BLUE%^wolf"+
         	" %^RESET%^%^CYAN%^that is carefully watching its prey. The image is full of life"+
         " and movement, and you almost expect the magnificent figure to"+
         " come to life and leap off the amulet.";
         break;
   }
   switch(val) {
      case 0..200:
         METAL = "%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r";
         break;
      case 201..300:
         METAL = "%^BOLD%^%^WHITE%^white gold";
         break;
      case 301..600:
         METAL = "%^BOLD%^%^WHITE%^m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l";
         break;
      case 601..800:
         METAL = "%^BOLD%^%^WHITE%^platinum";
         break;
   }
   if(val < 100) {
      obj->set_value(100);
   }
   else {
      obj->set_value(val);
   }
   obj->set_weight(3);
   obj->set_type("ring");
   obj->set_limbs(({"neck"}));
   obj->set_short("%^RESET%^%^CYAN%^A "+METAL+" %^RESET%^%^CYAN%^moonstone amulet");
   obj->set_name("moonstone amulet");
   obj->set_id(({"dagger_jewelry","amulet","moonstone amulet",""+METAL+" amulet",""+METAL+" moonstone amulet",""+str+" amulet",""+str+" moonstone amulet"}));
   obj->set_long("%^CYAN%^This is a beautiful amulet that has been fashioned from"+
   " "+METAL+"%^RESET%^%^CYAN%^. Many small links create the chain, and in the center sits"+
   " a large oval disc with a carved moonstone set into it. "+DESC+"");
}
