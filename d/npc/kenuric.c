//changed to speak wizish so new players wouldn't be lost ~Circe~ 1/3/13
#include <std.h>

inherit NPC;

void create(){
    ::create();

    set_name("Kenuric Offeriot");
    set_short("Kenuric Offeriot, Sexton of the Cathedral of St. Vala");
    set_id(({"kenuric","offeriot","Kenuric","Kenuric Offeriot","kenuric offeriot","sexton"}));
    set_long(
@TABOR
Kenuric Offeriot is the head caretaker of the Cathedral of St. Vala.  As
the cathedral is dedicated not to a god, but rather to a strange
universal saint, the only staff at the Cathedral are a group of
caretakers that make sure that the sanctuary is set up for the services
of whatever clergy wishes to use the building, as long as they
acknowledge St. Vala's divine calling, of course.  Because the King
sees resurrections in the Cathedral as proving the gods' favor of St.
Vala (and thus of his family), Kenuric is under standing orders to help
the recently deceased back to life whenever they may arrive here.
Kenuric is a follower of Kelemvor, and respects St. Vala's contributions
to the Kelemvor faith, whatever they were.
TABOR
    );
    set_race("human");
    set_body_type("human");
    set_class("cleric");
    set_hd(50,1);
    set_hp(10000000);
    set_spells(({"flame strike","cause blindness","hold person","touchsickle"}));
    set_spell_chance(90);
    set_diety("kelemvor");
    new("/d/common/obj/armour/robe")->move(TO);
    command("wear robe");
    command("speak wizish");
    set_unique(1);
    set_alignment(4);
    remove_std_db();
    set_gender("male");

}



void init() {
   ::init();
   if (TP->query_ghost()) {

      call_out("whisper_dead",1,TP);
   }
}

void whisper_dead(object who){
   command("whisper "+who->query_name()+" You may wish to pray, to get a new body. If you need help once you have prayed, we can reequip you with basic items here.");
}
