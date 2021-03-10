//~Circe~ 1/6/08 for new Seneca

#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Meeting Room of the Esoteric Haven, Seneca");
   set_short("%^BOLD%^%^WHITE%^Meeting Room of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Meeting Room of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^\n"+
      "This meeting room is set up as an amphitheater to "+
      "allow for large gatherings.  Here, magi from all over "+
      "the realms and of all beliefs gather to argue and learn "+
      "about different forms of magic from advanced theories in "+
      "transmutations to the latest developments in potion-brewing"+
      ".  Curved %^BOLD%^%^BLACK%^"+
      "stone benches %^RESET%^rise all around in stadium seating "+
      "with a demonstration area in the center.  The central "+
      "area of the room is a wide circle partially filled with "+
      "a long laboratory %^BOLD%^tabletop%^RESET%^ set atop "+
      "%^ORANGE%^cabinets%^RESET%^ filled with supplies wizards "+
      "often need.  A large %^BOLD%^%^BLACK%^blackboard %^RESET%^"+
      "on wheels stands along the northern edge of the circle, "+
      "giving demonstrators a place to write down pertinent "+
      "information for observers.  Behind the %^BOLD%^%^BLACK%^"+
      "blackboard%^RESET%^, the stadium seating stops, leaving "+
      "room for the thick %^RED%^mahogany table %^RESET%^and "+
      "%^RED%^chairs %^RESET%^arranged there.  Here, smaller "+
      "meetings can be held, from settling a magical dispute "+
      "to planning an upcoming lesson.  The %^BOLD%^%^BLACK%^"+
      "walls %^RESET%^of the amphitheater have been lined with "+
      "functional %^CYAN%^tapestries %^RESET%^to help control "+
      "the acoustics in the room.  This meeting hall is held "+
      "as a sacred place among the magic-users of the realms, "+
      "and none dares disturb its peace.\n");
   set_smell("default","The crystal clean fragrance of water fills the air.");
   set_listen("default","The murmur of the waterfall can be heard through the thick walls.");
   set_items(([
      ({"walls","wall","stone walls","gray stone walls"}) : "%^BOLD%^"+
         "%^BLACK%^The gray stone walls of the tower seem to blend "+
         "in to the background, covered in most places by the "+
         "functional %^CYAN%^tapestries%^RESET%^.%^RESET%^",
      ({"benches","stone benches","seating","stadium seating"}) : 
         "%^BOLD%^%^BLACK%^No chisel has touched the stone "+
         "benches which rise from the center of the room.  "+
         "%^CYAN%^Magic %^BLACK%^has been used to shape "+
         "the gray stone into wide benches with no backs, and "+
         "stairs have been likewise made at intervals.  The "+
         "benches are somewhat uncomfortable, likely an aid to "+
         "help bored magi stay awake.%^RESET%^",
      ({"tabletop","laboratory table","laboratory tabletop","cabinets","supplies"}) :
         "The tabletop is made of hard stone that seems resistant "+
         "to the various spills and cuts of magical experimentation"+
         ".  Beakers, braziers, a small chemical rack, and other "+
         "useful equipment are kept in the cabinets beneath "+
         "the table, while the tabletop itself is kept perfectly "+
         "clean when not in use.  The table dominates the central "+
         "demonstration area.",
      "blackboard" : "%^BOLD%^%^BLACK%^Outlined with %^RESET%^"+
         "%^ORANGE%^wood%^BOLD%^%^BLACK%^, the large blackboard "+
         "gives demonstrators ample space to display their "+
         "research.  No chalk lies in the tray here, which seems "+
         "strange until you realize that the magi simply create "+
         "illusions or conjure up the writing they need.  The "+
         "blackboard is on wheels so it may be moved out of the "+
         "way to give access to the smaller meeting area behind it.",
      ({"mahogany table","chair","chairs"}) : "Arranged behind "+
         "the blackboard, the thick %^RED%^mahogany table %^RESET%^"+
         "is rather simple in design.  It has thick legs and a "+
         "solid top, and it matches the chairs around it perfectly "+
         "in their spartan design.  Many wizards find it more "+
         "comfortable to discuss matters here before taking them "+
         "up in front of the whole assembly.",
      ({"tapestry","tapestries"}) : "The %^CYAN%^tapestries %^RESET%^"+
         "here are a deep %^CYAN%^azure%^RESET%^ and are perfect "+
         "rectangles.  Strangely, no decoration of any kind "+
         "can be seen on their surface."
   ]));
   set_exits(([
      "west" : ROOMS"mage_landing1"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/mage_landing1","west",0,0);
   set_door_description("door","The door in the western wall is "+
      "unique in construction.  It seems to have been made not of "+
      "wood but of metal, which is common enough.  The glaring "+
      "difference is that the surface of the metal shifts and "+
      "flows, giving it the appearance of %^BOLD%^m%^RESET%^o"+
      "%^BOLD%^l%^RESET%^t%^BOLD%^e%^RESET%^n %^BOLD%^m%^RESET%^i"+
      "%^BOLD%^t%^RESET%^h%^BOLD%^r%^RESET%^i%^BOLD%^l%^RESET%^.");
}