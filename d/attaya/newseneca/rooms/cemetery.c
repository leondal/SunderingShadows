//cemetery.c - the cemetery where the affluent people of 
//Seneca have historically been buried.  Another, larger 
//cemetery outside the city walls houses the commoners.
//~Circe~ 1/13/08
#include <std.h>
#include <daemons.h>
#include "../seneca.h"

inherit VAULT;

void create(){
string myseason,mytree,myleaves,myground;
   ::create();
   myseason = season(time());
   set_terrain(CEMETERY);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",3);
   set_name("A Well-tended Cemetery, Seneca");
   set_short("%^BOLD%^%^WHITE%^A Well-tended Cemetery, Seneca%^RESET%^");
   switch(myseason){
      case "spring" : mytree = "%^BOLD%^%^GREEN%^Attaya oak"; 
                      myleaves = "%^BOLD%^%^GREEN%^vibrant green";
                      myground = "a collection of fresh new blades "+
                      "of %^BOLD%^%^GREEN%^grass";
                      break;
      case "summer" : mytree = "%^RESET%^%^GREEN%^Attaya oak";
                      myleaves = "%^RESET%^%^GREEN%^weathered green";
                      myground = "a scattering of %^YELLOW%^g%^WHITE%^"+
                      "o%^RESET%^l%^YELLOW%^d%^WHITE%^e%^RESET%^n sand"+
                      " through some %^RESET%^wi%^ORANGE%^t"+
                      "%^RESET%^her%^ORANGE%^"+
                      "i%^RESET%^ng grass";
                      break;
      case "fall" : case "autumn" :   mytree = "%^YELLOW%^A%^RED%^t%^RESET%^%^RED%^"+
                      "t%^ORANGE%^a%^GREEN%^y%^YELLOW%^a %^RED%^o"+
                      "%^RESET%^%^RED%^a%^ORANGE%^k";
                      myleaves = "%^ORANGE%^c%^GREEN%^h%^YELLOW%^a"+
                      "%^RED%^n%^RESET%^%^RED%^g%^ORANGE%^i"+
                      "%^YELLOW%^n%^RESET%^%^GREEN%^g";
                      myground = "a layer of %^ORANGE%^f%^RED%^a"+
                      "%^BOLD%^l%^YELLOW%^l%^RESET%^%^GREEN%^e"+
                      "%^ORANGE%^n %^GREEN%^l%^YELLOW%^e%^RED%^a"+
                      "%^RESET%^%^ORANGE%^v%^RED%^e%^YELLOW%^s";
                      break;
      case "winter" : mytree = "%^BOLD%^%^WHITE%^A%^RESET%^t%^BOLD%^t"+
                      "%^RESET%^a%^BOLD%^y%^RESET%^a %^BOLD%^o"+
                      "%^RESET%^a%^BOLD%^k";
                      myleaves = "scattered %^ORANGE%^chestnut brown";
                      myground = "a light dusting of %^BOLD%^g%^RESET%^l"+
                      "%^BOLD%^i%^RESET%^s%^BOLD%^t%^RESET%^e%^BOLD%^n"+
                      "%^RESET%^i%^BOLD%^^n%^RESET%^g %^BOLD%^snow";
                      break;
      default: mytree = "Attaya oak";
               myleaves = "%^GREEN%^green";
               break;
   }
   set_long("%^BOLD%^%^WHITE%^A Well-tended Cemetery, Seneca%^RESET%^\n"+
      "This aging cemetery is well-kept, featuring lush %^BOLD%^"+
      "%^GREEN%^grass %^RESET%^kept short year-round.  The "+
      "cemetery seems to have sprung up around a breathtaking "+
      ""+mytree+" %^RESET%^growing in its center with the "+
      "many %^BOLD%^headstones %^RESET%^spiralling out around "+
      "it.  The stoic oak spreads wide, far-reaching branches with "+
      ""+myleaves+" leaves %^RESET%^protectively over the "+
      "final resting place of many of Seneca's elite citizens.  "+
      "Here in "+myseason+", "+myground+" %^RESET%^colors the "+
      "ground, creating a backdrop for the small %^BOLD%^statues "+
      "%^RESET%^spread throughout to commemorate some of the "+
      "fallen and guide them into the realms beyond.  %^YELLOW%^"+
      "F%^RED%^l%^CYAN%^o%^WHITE%^w%^GREEN%^e%^BLUE%^r%^MAGENTA%^"+
      "s %^RESET%^and other small tokens have been left upon some "+
      "of the graves, a testament to the love and admiration "+
      "still felt by those living in Seneca.  Standing just "+
      "to the east is the impressive %^BOLD%^sa%^RESET%^n%^BOLD%^d"+
      "st%^YELLOW%^o%^BOLD%^%^WHITE%^ne %^RESET%^w%^BOLD%^al"+
      "%^YELLOW%^l%^RESET%^ of the %^BOLD%^cathedral %^RESET%^"+
      "while the other three sides are enclosed with a "+
      "%^BOLD%^%^BLACK%^wrought iron fence%^RESET%^ that "+
      "separates the cemetery from the rest of the city.\n");
   set_smell("default","The bountiful aroma of flowers masks the "+
      "clean scent of the ocean.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_exits(([
      "north" : ROOMS"garden1",
      "south" : ROOMS"sstreet30"
   ]));
   set_items(([
      ({"grass","ground"}) : "The grass here is rather "+
         "soft and kept short.  During the "+myseason+" it is "+
         "decorated with "+myground+"%^RESET%^.",
      ({"oak","Attaya oak","attaya oak","tree","oak tree"}) : 
         "The serene cemetery is centered around this magnificent "+
         "tree that must be hundreds of years old.  The bark is "+
         "rough and deeply ridged, and the root system has upset "+
         "some of the graves that were clearly dug when the tree "+
         "was much younger.  The spreading branches reach almost "+
         "to the fence on all sides, casting a deep shade over "+
         "the whole area.",
      ({"headstone","headstones"}) : "The headstones are made of "+
         "marble or other stones, most of them white.  Each has "+
         "been carved with remembrances of the deceased, though "+
         "some have faded and become illegible with time.",
      ({"grave","graves"}) : "No new graves seem to have been dug "+
         "for quite some time.  Each grave is marked with a small "+
         "statue or headstone - or, in the cases of the most "+
         "affluent, both.",
      ({"statue","statues"}) : "Each of the statues is small, none "+
         "rising more than a few feet.  A few of them are angels, "+
         "and others seem to have a connection to the deceased.  "+
         "You see a stone sword with the tip in the ground and "+
         "the pommel up, a statue of a roaring lion, and a few "+
         "of hawks or eagles in flight.",
      ({"flower","flowers","token","tokens"}) : "As signs of "+
         "love and remembrance, several of the graves have been "+
         "decorated with tropical flowers, shells, small pieces "+
         "of jewelry, and other such items.",
      ({"wall","sandstone wall","cathedral","cathedral wall"}) : 
         "Rising to the east, the cathedral wall is made of "+
         "smooth sandstone blocks, fitted so well that there are "+
         "no cracks or seams to be seen.  Along the corners of the "+
         "wall and in other appropriate places, %^YELLOW%^gold "+
         "%^RESET%^or %^BOLD%^silver %^RESET%^has been set to add detail "+
         "to the cathedral.",
      ({"fence","iron fence","wrought iron fence"}) : "%^BOLD%^"+
         "%^BLACK%^The iron picket fence has fleur-de-lis caps "+
         "and is set with %^RESET%^stone columns %^BOLD%^"+
         "%^BLACK%^at intervals.  An ornamental gate in the northern side "+
         "of the fence offers entry to the park.%^RESET%^"
   ]));
   set_door("narrow gate","/d/attaya/newseneca/rooms/garden1","north",0);
   set_door_description("narrow gate","%^BOLD%^%^BLACK%^The gate is made of "+
      "iron bars much like the rest of the fence.  It features "+
      "decorative caps in the shape of fleurs-de-lis and has a "+
      "simple handle.%^RESET%^");
   set_door("gate","/d/attaya/newseneca/rooms/sstreet30","south",0);
   set_door_description("gate","%^BOLD%^%^BLACK%^The gate is made of "+
      "iron bars much like the rest of the fence.  It features "+
      "decorative caps in the shape of fleurs-de-lis and has a "+
      "simple handle.%^RESET%^");
}