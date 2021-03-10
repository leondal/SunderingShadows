#include <std.h>
inherit "/d/common/mons/bat";

void create() {
   ::create();
   set_name("penguin");
   set_id(({"penguin","monster","animal"}));
   set_short("A penguin");
   set_long("This is a black and white pinguin. "+
   " They like to hang around on the ice when "+
   "they are not swimming in the sea looking for fish to eat.");
   set_gender(random(2) ? "male" : "female");
   set_race("penguin");
}
void init(){
   ::init();
   if(TP->query_stats("charisma")< 18){
      write("%^CYAN%^The penguin gets spooked by you and jumps in the water.");
      tell_room(ETO,"%^CYAN%^The penguin gets spooked by "+TPQCN+
      " and jumps in the water.");
      TO->move("/d/shadowgate/void");
      TO->remove();
   }
}