#include <std.h>

inherit MONSTER;

void create(){
   object ob;
   ::create();
   set_property("Gflagprop",1);
    set_name("Kalarg");
    set_short("Kalarg the Mongrelman healer");
    set_id( ({"healer", "kalarg", "kalarg", "mongrelman", "mong", "kalarag the healer"}) );
    set_long(
   "Kalarg is one of the race of Mongrelmen that inhabit this island, created magically from men combined with the body parts of several animals.  Kalarg is an old mongrelman, and has learned the skills of the healer since he escaped his master.  He now wanders the island, trying to remain hidden from the dinosaurs, and from his master, who wishes him returned."
    );
    set_hd(19,10);
    set_exp(10);
   set_gender("male");
   set_race("mongrelman");
   set_body_type("human");
   ob = new("/d/islands/dinosaur/obj/noscry_amulet.c");
   ob->move(TO);
   command("wear amulet");
}
