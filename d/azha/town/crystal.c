#include <std.h>

inherit "/std/psi_lab";

object obj;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
   set_indoors(1);
   set_name("Striated Cognizance Sanitarium");
   set_short("Striated Cognizance Sanitarium");
   set_long(
      "%^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^t%^BOLD%^r%^RESET%^%^CYAN%^i"+
      "%^BOLD%^a%^RESET%^%^CYAN%^t%^BOLD%^e%^RESET%^%^CYAN%^d "+
      "Cognizance Sanitarium%^RESET%^\n"+
      "This round room features %^BOLD%^vaulted ceilings %^RESET%^"+
      "of smooth marble lightly veined in %^BOLD%^%^CYAN%^azure%^RESET%^.  "+
      "Dedicated to the preservation of mental health, the spa "+
      "is ringed with wide stairs rising toward the ceiling.  "+
      "Despite being underground, the room offers a soft "+
      "%^YELLOW%^light%^RESET%^ to brighten the clearly "+
      "mystical details.  "+
      "In irregular intervals, streams of %^BOLD%^%^BLUE%^"+
      "crystalline water %^RESET%^meander along the steps towards "+
      "a %^BOLD%^%^CYAN%^pool %^RESET%^filling the center of the "+
      "floor.  Dancing lightly on the surface of the pool are "+
      "pristine %^BOLD%^water lilies %^RESET%^atop bold "+
      "%^BOLD%^%^GREEN%^green lily pads%^RESET%^.  Rotating slowly "+
      "several feet above the pond is a flawless %^BOLD%^%^CYAN%^"+
      "crystal ball%^RESET%^.  Scattered images whirl slowly within "+
      "its depths, the resonance of the many minds which frequent "+
      "this place.  Echoing "+
      "the delicate music of the streams is the faint music "+
      "of several %^BOLD%^wind chimes %^RESET%^made of cut "+
      "%^BOLD%^%^MAGENTA%^c%^RED%^r%^YELLOW%^y%^GREEN%^s%^CYAN%^t"+
      "%^BLUE%^a%^RESET%^%^MAGENTA%^l%^BOLD%^s %^RESET%^that "+
      "are hung at varying heights from the ceiling.  The top "+
      "stair circling the room provides a safe place for psions "+
      "to open a rift to store excess crystals.\n\n"+
      "The command <help workroom> will instruct you in its use.\n"
   );
   set_smell("default","The cool, refreshing fragrance of a crisp stream fills the air.");
   set_listen("default","The melody of the twinkling crystals sounds lightly above the running water.");
   set_items(([
       ({"wall","walls","stair","stairs"}) : "The walls of this circular "+
          "room are dominated by wide stairs made of azure-veined white "+
          "marble.  Each step is more than wide enough for one to recline "+
          "upon leisurely, and they are being worn smooth with the gentle "+
          "lapping of the water.",
       ({"pool","lilies","lily pads"}) : "The surface of the serene "+
          "pool in the center of the room is ruffled only by the "+
          "streams that cause the lilies to lightly dance.  The "+
          "flowers are exquisite, providing a light perfume in "+
          "addition to their calming beauty.",
       ({"chimes","wind chimes","crystals"}) : "The wind chimes "+
          "are made from crystals in all shapes, sizes, and colors.  "+
          "Strangely, they seem totally unsupported by any visible means, "+
          "and they appear almost enchanted to sound even without the "+
          "necessary wind."
    ]));
    set_exits(([
        "up" : "/d/azha/town/azha_psi_comps"
    ]));
   setOwner("none");
   setLabId("azha");
}

void reset(){
   ::reset();
   if(!present("crystal ball")){
      obj = new("/d/magic/obj/crystal_ball");
      obj->set_long("%^RESET%^%^CYAN%^This sphere is made from a "+
         "polished piece of crystal about ten inches in diameter.  "+
         "The surface is flawless, free from scratches or cracks.  The "+
         "center of the ball seems almost opaque, as though it is "+
         "hiding some manner of secret.  The crystal ball hovers "+
         "feet above the surface of the pond, unsupported by any "+
         "visible means.%^RESET%^");
      obj->move(TO);
   }
}
