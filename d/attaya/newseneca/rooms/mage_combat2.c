//~Circe~ 1/12/08 for new Seneca
//"Safe" duelling area for the mage guild
//Players here can summon target dummies and battle one 
//another, though death is possible, and they need to 
//submit to each other to avoid alignment hits.  This is 
//really more for roleplay than any sense of a working arena

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
   set_name("Inside the Dome of the Esoteric Haven, Seneca");
   set_short("%^BOLD%^%^WHITE%^Inside the Dome of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Inside the Dome of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^\n"+
      "%^BOLD%^%^CYAN%^A thin dome made of coruscating "+
      "%^RED%^c%^YELLOW%^o%^BLUE%^l%^GREEN%^o%^MAGENTA%^r%^CYAN%^s "+
      "surrounds this recessed area in the floor, giving "+
      "combatants a large, safe place within which to practice "+
      "magic.  The %^BLUE%^void steel floor%^CYAN%^ helps ensure "+
      "that spells do not go awry, while the dome itself is a "+
      "%^YELLOW%^crackling %^CYAN%^field of magical energy that "+
      "contains all airborne spells.  Those outside the dome may "+
      "watch the combat in safety, but what happens within the "+
      "dome is very real, and deaths may sometimes occur.  Proceed "+
      "carefully should you choose to compete here.%^RESET%^\n\n"+
      "%^YELLOW%^When you are finished, you may %^CYAN%^<%^YELLOW%^"+
      "leave dome%^CYAN%^>%^YELLOW%^.%^RESET%^\n");
   set_smell("default","Strangely, the dome is completely free of "+
      "scent, though hair all over your body rises as with static "+
      "electricity.");
   set_listen("default","A faint buzzing noise comes from the dome.");
   set_items(([
      ({"lead","layer of lead","lead layer"}) : "Visible only "+
         "around certain edges, the layer of lead offers "+
         "protection against the types of magic used here "+
         "escaping this protected area.",
      ({"void steel","layer of void steel","void steel coating"}) :
         "%^BOLD%^%^BLUE%^The layer of void steel that covers "+
         "every surface in the room is so deeply black as to "+
         "have an almost bluish appearance.  It is matte and seems "+
         "to absorb light rather than reflect it.  It is smooth "+
         "and somewhat spongy to the touch, though it doesn't "+
         "give at all.%^RESET%^",
      ({"sunken floor","dais","reverse dais","stairs","floor"}) : "%^BOLD%^"+
         "%^BLACK%^Four slender steps that curve flawlessly, leading down "+
         "into a depression, much like a dais in reverse.  A "+
         "mystical %^CYAN%^carving %^BLACK%^lies in the center of "+
         "the floor, giving off a soft glow, and the entire area "+
         "is covered by a magical dome.%^RESET%^",
      ({"dome","magic dome","magical dome"}) : "%^BOLD%^%^CYAN%^"+
         "A transluscent %^WHITE%^dome%^CYAN%^ that shimmers with "+
         "coruscating %^RED%^c%^YELLOW%^o%^BLUE%^l%^GREEN%^o"+
         "%^MAGENTA%^r%^CYAN%^s protects this area.  It looks "+
         "as though you must "+
         "%^WHITE%^<%^BLACK%^leave%^WHITE%^> %^CYAN%^the dome "+
         "when you are finished duelling.  It is extremely "+
         "difficult to see anything outside the dome, and it feels "+
         "as if you are in a world of your own.%^RESET%^",
      ({"symbols","magic symbols","magical symbols","carving","magical carving"}) :
         "The intricate carving of %^BOLD%^%^WHITE%^m%^BLACK%^"+
         "a%^CYAN%^g%^BLACK%^i%^WHITE%^c%^CYAN%^a%^WHITE%^l %^BLACK%^"+
         "s%^CYAN%^y%^BLACK%^m%^WHITE%^b%^CYAN%^o%^WHITE%^l%^BLACK%^s "+
         "%^RESET%^in the center of the room is dizzying to study.  "+
         "Runes of all different types have been arranged in a "+
         "complicated web design, all intended to help generate "+
         "the dome that hovers protectively all around you."
   ]));
}

void init(){
   ::init();
   add_action("leave_em","leave");
}

void reset(){
object scry_object;
   ::reset();
   if(!present("DomeListener")){
      scry_object = new(OBJ"domelistener");
      scry_object->set_caster("/d/attaya/newseneca/rooms/mage_combat.c");
      scry_object->set_target("/d/attaya/newseneca/rooms/mage_combat2.c");
      scry_object->move(TO);
   }
}

int leave_em(string str){
   if(!str) return 0;
   if(str != "dome" && str != "the dome" && str != "here") return 0;
   tell_object(TP,"%^BOLD%^%^BLACK%^You approach the "+
      "coruscating %^RED%^c%^YELLOW%^o%^BLUE%^l%^GREEN%^o"+
      "%^MAGENTA%^r%^CYAN%^s %^BLACK%^of the dome, feeling them "+
      "part with a crackle of %^YELLOW%^electricity %^BLACK%^"+
      "as you pass through easily.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+"%^BOLD%^%^BLACK%^ approaches the "+
      "coruscating %^RED%^c%^YELLOW%^o%^BLUE%^l%^GREEN%^o"+
      "%^MAGENTA%^r%^CYAN%^s %^BLACK%^of the dome, and the dome "+
      "parts with a crackle of %^YELLOW%^electricity %^BLACK%^"+
      "as "+TP->QS+"%^BOLD%^%^BLACK%^ passes through easily.%^RESET%^",TP);
   tell_room(find_object_or_load("/d/attaya/newseneca/rooms/mage_combat.c"),"%^BOLD%^"+
      "%^BLACK%^The shimmering dome parts briefly, and "+
      ""+TPQCN+" walks through.%^RESET%^",TP);
      TP->move_player("/d/attaya/newseneca/rooms/mage_combat");
   return 1;
}