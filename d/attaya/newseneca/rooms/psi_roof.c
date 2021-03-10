//~Circe~ 12/3/07 for new Seneca

#include <std.h>
#include "../seneca.h"

inherit VAULT;

int send_living_name(object targ);
int long_look_room(object dest);

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(0);
   set_name("Rooftop of the Spire of Serenity, Seneca");
   set_short("%^BOLD%^%^WHITE%^Rooftop of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Rooftop of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^\n"+
      "The trapdoor opens up into this balcony that encircles the "+
      "base of the %^RED%^steeple %^RESET%^rising up through its "+
      "center.  A %^RED%^stone railing %^RESET%^borders the "+
      "entire circle, reaching about chest high to most humans.  "+
      "The %^RED%^stone%^RESET%^ of the railing is perfectly matched "+
      "to the steeple, making it virtually invisible from the ground.  "+
      "Several %^CYAN%^blankets %^RESET%^are folded and placed under "+
      "a narrow overhang, likely kept there for some protection from "+
      "the weather.  The rooftop is a somewhat narrow band forming a "+
      "perfect circle, but there is enough room to lie down and look "+
      "at the sky directly overhead.  An amazing construction of "+
      "%^ORANGE%^brass %^RESET%^and %^CYAN%^lenses %^RESET%^is mounted "+
      "upon a %^ORANGE%^brass stand %^RESET%^along the southeastern "+
      "portion, and the %^CYAN%^spyglass %^RESET%^may be rotated "+
      "to view various portions of the city.  This seems like a "+
      "quiet place to relax from the pressures of city life, and many "+
      "people like to visit to get a view of the bustling city from "+
      "above, giving them a new perspective.\n");
   set_smell("default","The clean scent of the ocean mingles with a light fragrance of ozone.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      "steeple" : "%^RED%^The steeple is perfectly round, a cone "+
         "meticulously created out of stone that rises to a sharp "+
         "point high overhead.  Its base takes up the central portion "+
         "of the rooftop.%^RESET%^",
      ({"railing","stone railing"}) : "The railing is formed from "+
         "%^RED%^red stone%^RESET%^ like the rest of the roof and "+
         "is crafted into a complicated decorative design filled with "+
         "open space.  It rises to about chest high on most humans, "+
         "giving some security here about a hundred feet off the ground.",
      ({"blanket","blankets","overhang"}) : "A narrow overhang has "+
         "been crafted near the base of the steeple, about a foot off "+
         "the rooftop.  Several soft woolen blankets have been folded "+
         "and left there for anyone to use.  After awhile in the "+
         "elements, they have a slightly moldy smell though.",
      "spyglass" : "The %^CYAN%^spyglass %^RESET%^is formed from a "+
         "%^ORANGE%^brass tube %^RESET%^fitted with curved %^CYAN%^"+
         "glass lenses %^RESET%^at either end.  It is mounted upon a "+
         "matching %^ORANGE%^brass stand%^RESET%^ and may be swiveled "+
         "to <view> different parts of the city.",
      ({"city","seneca","Seneca"}) : "From this high up, the city seems "+
         "small and crowded down below.  You see a sea of rooftops in "+
         "different colors and finishes, and the people look quite "+
         "small indeed."
   ]));
   set_exits(([
      "down" : ROOMS"psi_landing6"
   ]));
   set_door("trapdoor","/d/attaya/newseneca/rooms/psi_landing6","down",0,0);
   set_door_description("trapdoor","This small wooden trapdoor has "+
      "been varnished and set into the stone floor of the roof, allowing "+
      "access to the tower.");
}

void init(){
   ::init();
   add_action("view_em","view");
}

int view_em(string str){
object myplace;
int mynum;
   if(!str){
      tell_object(TP,"You may view either the east, west, south, north, "+
         "or square of the city.");
      return 1;
   }
   if(str != "east" && str != "west" && str != "south" && str != "north" && str != "square"){
      tell_object(TP,"You may view either the east, west, south, north, "+
         "or square of the city.");
      return 1;
   }
   switch(str){
      case "west": mynum = 33+random(8);  
                   myplace = "/d/attaya/newseneca/rooms/wstreet"+mynum+".c";  
                   break;
      case "east": mynum = 13+random(10);
                   myplace = "/d/attaya/newseneca/rooms/estreet"+mynum+".c";  
                   break;
      case "north": mynum = 2+random(11);  
                   myplace = "/d/attaya/newseneca/rooms/street"+mynum+".c";  
                   break;
      case "south": mynum = 23+random(10);  
                   myplace = "/d/attaya/newseneca/rooms/sstreet"+mynum+".c";  
                   break;
      case "square": myplace = "/d/attaya/newseneca/rooms/square.c";  
                   break;
      default: tell_object(TP,"Ack, you seem to have broken something!");
               return 1;
               break;
   }
   tell_object(TP,"%^ORANGE%^You swing the %^CYAN%^spyglass %^ORANGE%^"+
      "around and focus your gaze to the "+str+".%^RESET%^");
   tell_room(TO,"%^ORANGE%^"+TPQCN+" swings the %^CYAN%^spyglass around "+
      "and focuses toward the "+str+".%^RESET%^",TP);
   myplace = find_object_or_load(myplace);
   long_look_room(myplace);
   return 1;
}

int long_look_room(object dest){
    object *inv;
    int i,j;
//    message("room_description","\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_short()+"\n", TP);
    message("room_description","\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_long()+"", TP);
    inv = all_inventory(dest);
    if(sizeof(inv)< 1) return 1;
    for(i=0;i<sizeof(inv);i++){
     	if(!objectp(inv[i])) continue;
     	if(inv[i]->query_invis()) continue;
    	if(!inv[i]->is_detectable()) continue;
    	TO->send_living_name(inv[i]);
    }
    return 1;
}

int send_living_name(object targ){
	string known, str;
	int i,j;
	
    if(targ->is_monster()){
	    str = targ->query_short();
	    message("living_item", "%^CYAN%^BOLD%^[S] %^RED%^"+str,TP);
        return 1;
    }
    if(objectp(TP) && TP->knownAs(targ->query_true_name())){
	    known = TP->knownAs(targ->query_true_name());
    }
    str = targ->getWholeDescriptivePhrase();
    if(known){
        str = capitalize(known)+", "+str;
    }
    if(str){
       message("living_item", "%^CYAN%^BOLD%^[S] %^RED%^"+str, TP);
    }
    known = 0;
    return 1;
}
