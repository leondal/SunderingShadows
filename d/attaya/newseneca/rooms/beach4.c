//beach4.c - ~Circe~ 6/13/08 for new Seneca
//Minniwyn, who serves ice cream and snowcones, is technically behind 
//an open window.  She's in the room simply for code's sake, and will 
//knock out the prop and close the window if attacked.
#include <std.h>
#include "../seneca.h"

inherit STORAGE"beach";

void create(){
   ::create();
   set_long(::query_long()+"The %^ORANGE%^hut%^RESET%^ stands just "+
      "to the east here, though there is no doorway on this side.  "+
      "There is, however, an open %^CYAN%^window%^RESET%^ with a "+
      "narrow %^ORANGE%^counter%^RESET%^ and a %^BOLD%^sign%^RESET%^ "+
      "posted on the wall.\n");
   set_exits(([
      "west" : ROOMS"beach3",
      "southwest" : ROOMS"beach8",
      "south" : ROOMS"beach9",
      "southeast" : ROOMS"beach10"
   ]));
   add_item("hut","The hut is crafted from weathered wood left in "+
      "its natural hue.  The roof is made from woven leaves, which "+
      "have aged to be the same color as the building now.  An "+
      "open, glassless window with a small counter for a ledge "+
      "allows the occupants inside to conduct business with those "+
      "outside, while a %^BOLD%^sign %^RESET%^posted on the wall "+
      "explains what sort of business that might be.");
   add_item(({"sign","menu"}),"The sign seems to be a menu of "+
      "of sorts.  Perhaps you should <read menu>.");
}

void reset(){
   ::reset();
   if(!present("minniwyn")) find_object_or_load(MON"minniwyn")->move(TO);
}

void init(){
   ::init();
   add_action("read","read");
}

int read(string str){
   object ob;
   int i;

   if(str!="menu")
      return 0;
   ob = present("barkeep", TO);
   if(!objectp(ob)){  
      tell_object(TP,"The ice cream shop seems to be closed!");
      return 1;
   }
    write("The following great treats are served here:");
   
    write("%^YELLOW%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~");
    write("\t%^BOLD%^Vanilla Ice Cream                    %^RESET%^"+
	      ""+(int)ob->get_price("vanilla ice cream") + " silver");
    write("\t%^BOLD%^%^BLACK%^Chocolate Ice Cream                  %^RESET%^"+
	      ""+(int)ob->get_price("chocolate ice cream") + " silver");
    write("\t%^BOLD%^%^RED%^Strawberry Ice Cream                 %^RESET%^"+
	      ""+(int)ob->get_price("strawberry ice cream") + " silver");
    write("\t%^ORANGE%^Peach Ice Cream                      %^RESET%^"+
	      ""+(int)ob->get_price("peach ice cream") + " silver");
    write("\t%^BOLD%^%^RED%^Red Snowcone                         %^RESET%^"+
	      ""+(int)ob->get_price("red snowcone") + " silver");
    write("\t%^BOLD%^%^MAGENTA%^Pink Snowcone                        %^RESET%^"+
	      ""+(int)ob->get_price("pink snowcone") + " silver");
    write("\t%^BOLD%^%^BLUE%^Blue Snowcone                        %^RESET%^"+
	      ""+(int)ob->get_price("blue snowcone") + " silver");
    write("\t%^YELLOW%^Yellow Snowcone                      %^RESET%^"+
	      ""+(int)ob->get_price("yellow snowcone") + " silver");
    write("\t%^BOLD%^%^GREEN%^Green Snowcone                       %^RESET%^"+
	      ""+(int)ob->get_price("green snowcone") + " silver");
    write("\t%^ORANGE%^Orange Snowcone                      %^RESET%^"+
	      ""+(int)ob->get_price("orange snowcone") + " silver");
    write("\t%^MAGENTA%^Purple Snowcone                      %^RESET%^"+
	      ""+(int)ob->get_price("purple snowcone") + " silver");
    write("\t%^BOLD%^%^RED%^R%^RESET%^%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^o%^RESET%^%^MAGENTA%^w%^RESET%^ %^BOLD%^%^RED%^S%^RESET%^%^ORANGE%^n%^YELLOW%^o%^GREEN%^w%^CYAN%^c%^BLUE%^o%^RESET%^%^MAGENTA%^n%^BOLD%^%^RED%^e                     %^RESET%^"+
	      ""+(int)ob->get_price("rainbow snowcone") + " silver");
    write("\t%^YELLOW%^Frozen Lemonade                      %^RESET%^"+
	      ""+(int)ob->get_price("frozen lemonade") + " silver");
    write("\t%^BOLD%^%^CYAN%^Ice Water                            %^RESET%^"+
	      ""+(int)ob->get_price("ice water") + " silver");
    write("%^YELLOW%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~");
    write("%^BOLD%^<buy dish_name> will get you the food or drink.%^RESET%^");
    return 1;
}