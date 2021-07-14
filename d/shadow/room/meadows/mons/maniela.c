#include <std.h>
#include "../meadow.h"
inherit NPC;

void create()
{
   ::create();
   set_name("maniela");
   set_short("Maniela, a halfling healer");
   set_id(({"healer","maniela","halfling","halfling healer"}));
   set_long(
   "Maniela is a gentle looking halfling who offers her services as a healer"+
   " to those in need. She has dark blue eyes and dark brown hair, but a"+
   " sunny disposition. She is a little overweight and stands almost two and"+
   " a half feet tall, wearing a dark green robe and some sandals."
   );
   set_gender("female");
   set_race("halfling");
   set_body_type("halfling");
   set_alignment(1);
   set_hd(15,5);
   set_class("cleric");
   set_mlevel("cleric",15);
   set_overall_ac(-5);
   set_exp(100);
}

/*void heart_beat() {
    object *attackers;
    ::heart_beat();
    
    attackers = (object *)this_player()->query_attackers();
    if(attackers){
        tell_room(ETP,"%^BOLD%^%^CYAN%^The halfling grabs a small orb, smashing it and creating a huge cloud of smoke! When it clears, the halfling is nowhere to be found.%^RESET%^");
        TO->move("/d/shadowgate/void.c");
        TO->remove();
        return;
    }
}*/

