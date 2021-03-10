// changed add action for search to use set_search, which ALL searches should do
// to fix bug after search was changed for the hide/concealment nwp *Styx*  10/23/02

#include <std.h>
#include "../derrodefs.h"

inherit CROOM;

void create(){
  set_monsters( ({ MON"derro1", MON"derro2" }), ({1, 1}) );
  ::create();
  set_repop(60);
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Torture chamber%^RESET%^"  );
  set_long(
  "%^RED%^Torture chamber%^RESET%^\n"
  "  This room leads to cells to the west and out a steel door to the north."
  "  Scattered about this huge room are various implements of torture."
  "  Racks, braziers, and manacles that all look very sturdy although most of them look only designed to hold those of human sized or larger."
  "  Some of them are scaled for creatures that must be 20 feet tall."
  "  Obviously not the work of these Derro."
  "  A red light emanates from the globes in the ceiling bathing everything in hellish light."
  "\n"
  );
  set_smell("default",
  "You get the occasional whiff of the scent of decaying flesh."
  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",
  "racks":"Devices that use cranks and anchors to pull limbs from their sockets.",
  "braziers":"Cold metal bowls full of coals that would be burned to heat the irons to red hot and sear the flesh of the guests here.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "north":ROOMS"c20",
  "east":ROOMS"c25",
  ]));
/* removing now that its use to the founding wiz is gone and boards are becoming IC
*Styx*  11/28/02
  ob=new("/std/bboard");
  ob->set_name("board");
  ob->set_id(({"board","prison board",}));
  ob->set_board_id("derro_board");
  ob->set_short("Prison board");
  ob->set_long("  This board was once used by the firegiants to leave suggestions to their prisons keeper."
  "  Now it can be used by adventures as they travel through to post their comments about the area.");
  ob->set_max_posts(30);
  ob->set_location("/d/dagger/derro/rooms/c21.c");
*/
  set_search("default", (: TO, "search_here" :) );
}

void reset(){
  ::reset();
  if(!random(4))  flag = 0;
/* changing to use CROOM for control over longer reboots *Styx*  11/29
  if(!present("derro warrior")){
    new(MON"derro1.c")->move(TO);
  new(MON"derro2.c")->move(TO);
  }
*/
}

void init(){
  ::init();
//  add_action("search","search");
}

int search_here(){
  if(flag) {
     write("You find nothing else of interest.");
     return 1;
  }
  tell_room(TO, TPQCN+" pokes around and finds a metal bar.", TP);
  write("You poke around and find a metal bar among the implements.");
  flag=1;
  new(OBJ"prybar.c")->move(TO);
  return 1;
}
