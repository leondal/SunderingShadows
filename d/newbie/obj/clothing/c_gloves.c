#include <std.h>
inherit ARMOUR;

#include <std.h>

#define COLORS ({"%^BOLD%^%^BLACK%^black%^RESET%^",\
"%^RESET%^%^ORANGE%^brown%^RESET%^",\
"%^BOLD%^%^WHITE%^white%^RESET%^",\
"%^BOLD%^%^WHITE%^cream%^RESET%^",\
"%^YELLOW%^tan%^RESET%^",\
"%^BOLD%^%^RED%^red%^RESET%^",\
"%^BOLD%^%^GREEN%^green%^RESET%^",\
"%^BOLD%^%^BLUE%^blue%^RESET%^",\
"%^RESET%^%^MAGENTA%^purple%^RESET%^",\
"%^RESET%^%^CYAN%^blue-green%^RESET%^",\
"%^BOLD%^%^BLACK%^charcoal gray%^RESET%^"})

int j, val;
string str, FABRIC;

void create_gloves()
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   val = random(18);
   switch(val) {
      case 0..3:
         FABRIC = "cotton";
         set_long("This is a pair of light cotton gloves that have"+
         " been dyed a "+str+" shade. They are soft and light, probably"+
         " made for a lady.");
         set_wear("The cotton gloves are light and cool against"+
         " your hands.");
         break;
      case 4..8:
         FABRIC = "leather";
         set_long("These leather gloves are in excellent shape."+
         " They have been lined with cotton padding for comfort and"+
         " the exterior has been dyed a "+str+" shade. They would be"+
         " excellent for riding or any activity where you might wish"+
         " to protect your hands a little.");
         set_wear("You slip the leather gloves over your hands.");
         break;
      case 9..12:
         FABRIC = "woolen";
         set_long("These woolen gloves are very soft and fuzzy,"+
         " they will at least keep your hands warm in colder weather."+
         " They have been dyed a rich "+str+" shade.");
         set_wear("Your hands feel warmer as you place them in"+
         " the woolen gloves.");
         break;
      case 13..15:
         FABRIC = "fleece";
         set_long("The fleece gloves are incredibly warm and"+
         " soft against your skin. They have been carefully knit"+
         " and keep the wind and cold out rather well. They are a"+
         " "+str+" shade.");
         set_wear("The fleece gloves are soft and warm your hands.");
         break;
      case 16..17:
         FABRIC = "silk";
         set_long("The silk gloves are divinely smooth and soft"+
         " against your skin. They reach all the way up to the elbows"+
         " and have been dyed a "+str+" shade. They are obviously for"+
         " a woman of wealth and influence.");
         set_wear("The silk gloves slip smoothly up to your elbows.");
         set_remove("You slowly take the beautiful silk gloves off.");
         break;
   }
   if(val < 2) {
      set_value(2);
   }
   else {
      set_value(val);
   }
   set_cointype("silver");
   set_name("gloves");
   set_type("clothing");
   set_limbs(({"left arm","right arm"}));
   set_weight(2);
   set_short("A pair of "+str+" "+FABRIC+" gloves");
   set_id(({"gloves","clothing",""+str+" gloves",""+FABRIC+" gloves",""+str+" "+FABRIC+" gloves","pair of gloves","pair of "+str+" "+FABRIC+" gloves","pair of "+str+" gloves","pair of "+FABRIC+" gloves"}));
}

void create()
{
   	::create();
	create_gloves();
	set_size(random(3)+1);
}
