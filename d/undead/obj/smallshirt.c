#include <std.h>
inherit ARMOUR;

int dyed;
void dye_me(string str);

void create(){
    ::create();
    set_name("cotton shirt");
    set_id(({"shirt","white shirt","cotton shirt","white cotton shirt"}));
    set_short("%^BOLD%^%^WHITE%^white cotton shirt%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Made from lightweight, thick-knit cotton, this "
"shirt is designed for wearing by almost %^CYAN%^anyone %^WHITE%^and features a "
"high collar that can be left open and loose or closed with a pair of nearly "
"%^RESET%^invisible ties%^BOLD%^%^WHITE%^.  Likewise at the wrists of the "
"somewhat puffy sleeves, the cuffs can be tied tight or left open to allow the "
"sleeves to be rolled up.  Though the garment is a simple white color, the "
"material is soft and designed to %^CYAN%^breathe%^WHITE%^, retaining warmth "
"during cold weather and staying cool in warm weather.  A useful, all around, "
"garment that could be %^CYAN%^dyed %^WHITE%^to suit one's particular tastes or "
"needs.%^RESET%^\n");
    set_lore("These shirts were made popular by sailors and traders who needed "
"a versatile, breathable shirt to get them through the day, regardless of "
"weather conditions.  Designed by weavers throughout the world, most are fairly "
"plain and unadorned, coming in white or a light natural shade.  Though many "
"people have them dyed to their favorite color.  This became so popular that "
"many of the shirts were enchanted to change with the will of the wearer.  "
"Although these enchanted versions were rare, those who had them coveted their "
"added versatility.");
    set_property("lore difficulty",18);
    set_type("clothing");
    set_limbs(({ "torso" }));
    set_weight(5);
    set_value(500);
    set_size(1);
    set_property("enchantment",4);
    while (query_property("enchantment") != 4) {
      remove_property("enchantment");
      set_property("enchantment",4);
    }
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    dyed = 0;
}

int wear_func(){
    tell_object(ETO,"%^BOLD%^%^CYAN%^You slide the shirt over your head and tug "
"it down into place, admiring the comfort the soft cotton yields.%^RESET%^");
    return 1;
}

int remove_func(){
    tell_object(ETO,"%^BOLD%^%^CYAN%^With a soft sigh, you take your shirt "
"off.%^RESET%^");
    return 1;
}

void init() {
    ::init();
    add_action("dye_me","dye");
}

int dye_me(string str) {
    string thecolor, mycolor1, mycolor2;
    if(!str) return notify_fail("What do you want to dye?\n");
    if((sscanf(str,"shirt %s", thecolor) != 1))
      return notify_fail("You should try to <dye shirt color>.\n");
    if(dyed)
      return notify_fail("The shirt has already been dyed, you would just spoil it if you did so again.\n");
    if(thecolor == "white") return notify_fail("The shirt is already white.\n");
    if(thecolor != "red" && thecolor != "blue" && thecolor != "green" && thecolor != "yellow" && thecolor != "brown" && thecolor != "black" && thecolor != "purple" && thecolor != "pink")
      return notify_fail("You can't dye the shirt "+thecolor+", try another.\n");

    switch(thecolor) {
      case "red":
        mycolor1 = "%^RESET%^%^RED%^";
        mycolor2 = "%^BOLD%^%^RED%^";
      break;
      case "blue":
        mycolor1 = "%^RESET%^%^BLUE%^";
        mycolor2 = "%^BOLD%^%^BLUE%^";
      break;
      case "green":
        mycolor1 = "%^RESET%^%^GREEN%^";
        mycolor2 = "%^BOLD%^%^GREEN%^";
      break;
      case "yellow":
        mycolor1 = "%^RESET%^%^ORANGE%^";
        mycolor2 = "%^YELLOW%^";
      break;
      case "brown":
        mycolor1 = "%^RESET%^%^RED%^";
        mycolor2 = "%^RESET%^%^ORANGE%^";
      break;
      case "black":
        mycolor1 = "%^BOLD%^%^WHITE%^";
        mycolor2 = "%^BOLD%^%^BLACK%^";
      break;
      case "purple":
        mycolor1 = "%^RESET%^%^CYAN%^";
        mycolor2 = "%^RESET%^%^MAGENTA%^";
      break;
      case "pink":
        mycolor1 = "%^RESET%^%^MAGENTA%^";
        mycolor2 = "%^BOLD%^%^MAGENTA%^";
      break;
    }

    set_short(mycolor2+thecolor+" cotton shirt%^RESET%^");
    set_long(mycolor1+"Made from lightweight, thick-knit cotton, this shirt is "
"designed for wearing by almost "+mycolor2+"anyone "+mycolor1+"and features a "
"high collar that can be left open and loose or closed with a pair of nearly "
"%^RESET%^invisible ties"+mycolor1+".  Likewise at the wrists of the somewhat "
"puffy sleeves, the cuffs can be tied tight or left open to allow the sleeves "
"to be rolled up.  Though the garment is a simple "+thecolor+" color, the "
"material is soft and designed to "+mycolor2+"breathe"+mycolor1+", retaining "
"warmth during cold weather and staying cool in warm weather.  A useful, all "
"around garment that would suit most tastes or needs.%^RESET%^\n");
    set_id(({"shirt",thecolor+" shirt","cotton shirt",thecolor+" cotton shirt"}));
    tell_object(TP,"You carefully dye the shirt to a "+thecolor+" shade.");
    dyed = 1;
    return 1;
}
