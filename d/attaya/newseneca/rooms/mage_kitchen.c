//~Circe~ 1/3/07 for new Seneca
//Kitchen for the mage guild - members can 
//request food and drink for free as a perk 
//to opening a cubby here

#include <std.h>
#include <move.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Kitchen of the Esoteric Haven, Seneca");
   set_short("%^BOLD%^%^WHITE%^Kitchen of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Kitchen of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^\n"+
      "Truly a magical wonder, this kitchen is fully stocked with "+
      "all manner of %^BOLD%^utensils%^RESET%^, all of which "+
      "are operating of their own "+
      "accord!  The %^BOLD%^%^BLACK%^gray stone walls %^RESET%^"+
      "are graced with %^BOLD%^hooks %^RESET%^in several places "+
      "that hold necessities, while the %^ORANGE%^darkwood "+
      "cabinets%^RESET%^ have doors that open and close themselves, "+
      "sending implements floating through the air as if directed "+
      "by some unseen will.  A chorus of %^BOLD%^knives %^RESET%^"+
      "work their magic upon %^ORANGE%^cutting boards %^RESET%^"+
      "placed upon the %^CYAN%^marble countertops %^RESET%^while "+
      "%^BOLD%^whisks %^RESET%^stir up delights in %^ORANGE%^"+
      "ceramic bowls%^RESET%^.  The sounds of the kitchen blend "+
      "together to create a domestic symphony, and the fragrances "+
      "produced by the mystical utensils is enough to whet any "+
      "hungry mage's appetite.  Three small round %^ORANGE%^darkwood "+
      "tables %^RESET%^with matching %^ORANGE%^chairs %^RESET%^"+
      "are lined along the curved northern wall, well away from "+
      "the %^BOLD%^%^RED%^f%^YELLOW%^i%^RESET%^%^ORANGE%^e%^RED%^"+
      "r%^BOLD%^y%^RESET%^ ovens and floating knives.  Here, "+
      "a member of the tower may sit, order from the "+
      "%^CYAN%^menu%^RESET%^ provided, and enjoy a relaxing "+
      "meal prepared by the magical wonders.  Orders are taken "+
      "by an enchanted %^MAGENTA%^teapot%^RESET%^, who stands "+
      "ready by the stove when her services are not required.\n");
   set_smell("default","The delicious fragrance of cooking foods lingers here.");
   set_listen("default","The roar of the waterfall is dampened somewhat by the noises of the kitchen.");
   set_items(([
      ({"walls","wall","stone walls","gray stone walls"}) : "%^BOLD%^"+
         "%^BLACK%^The northern wall is curved, echoing the outer "+
         "surface.  In many places, much of the gray stone has "+
         "been covered with scattered hooks holding pots, pans, "+
         "and other dishes.%^RESET%^",
   ]));
   set_exits(([
      "west" : ROOMS"mage_landing5"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/mage_landing5","west",0,0);
   set_door_description("door","The door in the western wall is "+
      "unique in construction.  It seems to have been made not of "+
      "wood but of metal, which is common enough.  The glaring "+
      "difference is that the surface of the metal shifts and "+
      "flows, giving it the appearance of %^BOLD%^m%^RESET%^o"+
      "%^BOLD%^l%^RESET%^t%^BOLD%^e%^RESET%^n %^BOLD%^m%^RESET%^i"+
      "%^BOLD%^t%^RESET%^h%^BOLD%^r%^RESET%^i%^BOLD%^l%^RESET%^.");
}

void init(){
   ::init();
   add_action("read_em","read");
   add_action("order_em","order");
}

void reset() {
  ::reset();
   if(!present("server"))
      find_object_or_load("/d/attaya/newseneca/mon/mage_server")->move(TO);
}

int read_em(string str) {
    object ob;
    int i;

  if(str!="menu")
    return 0;
    ob = present("server", TO); 
    if (!objectp(ob)){  
      write("The enchanted teapot is not here to direct the other animated implements!\n");
      return 1;
    }
    write("Any member of the tower may request the following foods and drinks:");
    write("%^MAGENTA%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~");
    write("\t%^RESET%^%^GREEN%^A platter of %^BOLD%^%^RED%^f"+
      "%^MAGENTA%^r%^RESET%^%^ORANGE%^e%^RED%^s%^BOLD%^%^MAGENTA%^h "+
      "%^RESET%^%^MAGENTA%^f%^ORANGE%^r%^YELLOW%^u%^RED%^i"+
      "%^MAGENTA%^t%^RESET%^");
    write("\t%^RESET%^%^ORANGE%^A golden loaf of bread%^RESET%^");
    write("\t%^RESET%^%^RED%^A bowl of hearty beef stew%^RESET%^");
    write("\t%^RESET%^%^CYAN%^A cup of %^BOLD%^mystical "+
      "%^RESET%^%^ORANGE%^tea%^RESET%^");
    write("\t%^RESET%^%^ORANGE%^A steaming mug of "+
      "%^BOLD%^%^BLACK%^coffee%^RESET%^");
    write("\t%^RESET%^%^CYAN%^A glass of refreshing %^BOLD%^water%^RESET%^");
    write("%^MAGENTA%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~");
    write("%^BOLD%^<order dish_name> will get you the food or drink.%^RESET%^");
    return 1;
}

int order_em(string str){
object server, obj;
   server = present("server",TO);
   if(!str){
      tell_object(TP,"What would you like to order?");
      return 1;
   }
   if(!objectp(server)){
      tell_object(TP,"The enchanted teapot is not here to direct the other animated implements!");
      return 1;
   }
   if(!file_exists("/d/magic/comps/seneca/"+TPQN+".comp.o")){
      tell_room(TO,"%^RESET%^%^MAGENTA%^"+server->QCN+" whistles"+
         "%^RESET%^: %^BOLD%^%^MAGENTA%^I'm sorry, love! I only "+
         "serve those who belong to the tower.  Master's orders!%^RESET%^");
      return 1;
   }
   switch(str){
      case "fruit": case "fresh fruit": case "platter of fruit": case "platter of fresh fruit":
         obj = new(OBJ"fruit"); break;
      case "bread": case "loaf of bread": case "golden bread": case "golden loaf of bread":
         obj = new(OBJ"bread"); break;
      case "stew": case "beef stew": case "bowl of stew": case "bowl of beef stew":
         obj = new(OBJ"stew"); break;
      case "coffee": case "steaming coffee": case "mug of coffee": case "steaming mug of coffee":
         obj = new(OBJ"coffee"); break;
      case "tea": case "mystical tea": case "cup of tea": case "cup of mystical tea":
         obj = new(OBJ"tea"); break;
      case "water": case "glass of water": case "refreshing water": case "glass of refreshing water": 
         obj = new(OBJ"water"); break;
      default: tell_room(TO,"%^RESET%^%^MAGENTA%^"+server->QCN+" "+
         "whistles%^RESET%^: %^BOLD%^%^MAGENTA%^I don't serve "+str+", love!");
         return 1;
   }
   tell_room(TO,"%^RESET%^%^MAGENTA%^"+server->QCN+" whistles%^RESET%^: "+
      "%^BOLD%^%^MAGENTA%^Here is your "+str+", dear.%^RESET%^");
   server->force_me("emoteat "+TPQN+" smiles at $N fondly.");
   if((string)obj->move(TP) == MOVE_OK){
      tell_room(TO,""+server->QCN+" hands "+TPQCN+" "+obj->query_short()+".",TP);
      tell_object(TP,""+server->QCN+" hands you "+obj->query_short()+".");
      return 1;
   }else{
      tell_room(TO,""+server->QCN+" places "+obj->query_short()+" before "+TPQCN+".",TP);
      tell_object(TP,""+server->QCN+" places "+obj->query_short()+" before you.");
      obj->move(ETP);
      return 1;
   }
   tell_room(TO,"Hmm...something seems to be wrong.");
   return 1;
}