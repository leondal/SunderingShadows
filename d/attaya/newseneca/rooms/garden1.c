//garden1 - Circe 1/13/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"garden_inherit";

void create(){
   ::create();
   set_long(::query_long()+"\n%^RESET%^%^GREEN%^A narrow "+
      "%^BOLD%^%^WHITE%^pathway %^RESET%^%^GREEN%^"+
      "created from the %^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d"+
      "%^WHITE%^e%^RESET%^n sand %^GREEN%^that liberally dusts "+
      "%^BOLD%^%^WHITE%^Seneca%^RESET%^%^GREEN%^ winds through the "+
      "%^BOLD%^gardens %^RESET%^%^GREEN%^here.  It curves from the "+
      "%^BOLD%^%^WHITE%^sa%^RESET%^n%^BOLD%^dst%^YELLOW%^o%^BOLD%^"+
      "%^WHITE%^ne cathedral %^RESET%^%^GREEN%^to the east up to "+
      "the %^ORANGE%^gazebo %^RESET%^%^GREEN%^north of here.  "+
      "A narrow branch of the pathway also leads south through a "+
      "%^BOLD%^%^BLACK%^wrought iron fence %^RESET%^%^GREEN%^into "+
      "the %^RESET%^cemetery%^GREEN%^.%^RESET%^\n");
   set_exits(([
      "north" : ROOMS"gazebo",
      "south" : ROOMS"cemetery",
      "west" : ROOMS"garden2",
      "east" : ROOMS"cath_foyer"
   ]));
   add_item("gazebo","%^ORANGE%^The gazebo to the north is a "+
      "beautiful construction of wooden trellises and lattice "+
      "work left a beautiful %^YELLOW%^g%^RESET%^%^ORANGE%^o"+
      "%^YELLOW%^l%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^"+
      "%^ORANGE%^n brown.  Climbing %^GREEN%^vines "+
      "%^ORANGE%^wind their way along the trellises, painting a "+
      "pretty scene.%^RESET%^");
   add_item("cemetery","The small cemetery to the south is the "+
      "final resting place of Seneca's elite.  Weathered "+
      "tombstones and statues dot the grassy landscape, marking "+
      "the graves of the wealthy.  Another, larger cemetery lies "+
      "outside the city for those who do not have the social "+
      "standing to be buried here.");
   add_item("cathedral","The huge cathedral to the east is "+
      "graced on this side by twin %^BOLD%^archways %^RESET%^"+
      "divided by a slender %^BOLD%^silver column%^RESET%^.  "+
      "No door bars access to the cathedral so that any who seek "+
      "solace may find it day or night.");
   add_item("pathway","The pathway here is carved out of the "+
      "grass and strewn with %^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d"+
      "%^WHITE%^e%^RESET%^n sand.  Small %^BOLD%^white stones "+
      "%^RESET%^line the pathway, giving it definition as it "+
      "meanders in the cardinal directions.");
   add_item("fence","%^BOLD%^%^BLACK%^The iron picket fence has "+
      "fleur-de-lis caps and is set with %^RESET%^stone columns "+
      "%^BOLD%^%^BLACK%^at intervals.  An ornamental gate in the "+
      "southern side of the fence offers entry to the cemetery.%^RESET%^");
   set_door("narrow gate","/d/attaya/newseneca/rooms/cemetery","south",0);
   set_door_description("narrow gate","%^BOLD%^%^BLACK%^The gate is made of "+
      "iron bars much like the rest of the fence.  It features "+
      "decorative caps in the shape of fleurs-de-lis and has a "+
      "simple handle.%^RESET%^");
}