#include <std.h>
inherit VAULT;

object ob, ob1;
int being_pulled, sword_pulled, pulled;

void original() {
    set_long("This eerie, gigantic hall has fallen into decay.  Many tall "+
	"columns rise to a lofty ceiling, others have fallen over and "+
	"litter the center of the room like the trees in Shadowlord "+ 
	"forest. A "+
	"huge granite throne sits against the left wall. A rotting corpse sits upon the throne, "+
	"a %^BOLD%^silver dagger%^RESET%^ struck right through its heart.");
  
    set_items(([
    "throne": "A huge granite throne sits against the left wall. A rotting corpse sits upon the throne, "+
	"a silver dagger struck right through its heart.%^RESET%^",
    "dagger" : "%^RESET%^The dagger is very shiny. You feel tempted to %^BOLD%^<pull>%^RESET%^ it free.",
    ({"corpse","rotting corpse"}) : "The features of a once handsome and proud human "+
           "can still be seen on its face. Now his long silver hair takes on a tarnished color. He is "+
		   "dressed in noble finery, down to the elegant blade and "+
           "armor he loved in life.\n",
    ] ));
    being_pulled = 0;
    sword_pulled = 0;
}

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Hall of the Ancients");
    original();
    set_property("no sticks",1);
    set_property("no teleport", 1);
    set_smell("default","The smell of rot and decay is overwhelming.");
    set_exits(([
    "south" : "/d/deku/fortress/hallN7.c"
    ] ));
}

void reset() {
   ::reset();
   pulled = 1 ;
}

void init(){
  ::init();
  add_action("pull","pull");
}

int pull(string str){
   if(!str) notify_fail("What are you trying to pull?");
   if(str == "dagger"||str == "the dagger"){
      if(pulled == 1) {
         tell_object(TP,"%^BOLD%^%^WHITE%^As you grab onto the cold silver metal of the dagger and yank it free, the corpse rises to its feet, %^BLUE%^blue fire%^WHITE%^ burning in its eyes! A loud snarl escapes his throat as his gaze falls upon you!");
         tell_room(TO,"%^BOLD%^%^WHITE%^As "+TPQCN+" yanks the dagger free, the corpse rises to its feet, %^BLUE%^blue fire%^WHITE%^ burning in its eyes! A loud snarl escapes his throat as his gaze falls upon you!", TP);
         new("/d/deku/weapons/silveredge.c")->move(TP);
		 new("/d/deku/fortress/monster/dknight1")->move(TO);
		 if(ob=present("alphonso jalimpar", TO)) {
         ob->rush();
         pulled = 0;
    set_long("This eerie, gigantic hall has fallen into decay.  Many tall "+
	"columns rise to a lofty ceiling, others have fallen over and "+
	"litter the center of the room like the trees in Shadowlord "+ 
	"forest. A "+
	"huge granite throne sits against the left wall. The throne sits cold and empty.");         
	return 1;
      }
      if(pulled = 0) {
         tell_object(TP,"%^RESET%^%^CYAN%^The dagger has already been pulled.%^RESET%^");

      return 1;
      }
   }
   else{
      tell_object(TP,"%^RESET%^%^CYAN%^Are you trying to pull the dagger free?");
      return 1;
   }
}
}