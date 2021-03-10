#include <std.h>

inherit TOWNSMAN;
void create() {
    ::create();
    set_name("Ironklaw");
    set_id( ({ "ironklaw", "healer"}) );
    set_short("Ironklaw the Insane Cleric.");
    set("aggressive", 0);
    set_level(35);
    set_long(
      "Ironklaw was so named for the left hand that has been replaced by a shiny metal clamp.  He changes his facial expressions in unexpected rapid succession, and each one looks more unsettling than the last.  He seems to have tiny electric currents running all over his body."
    );
    set_gender("male");
    set_alignment(3);
    set("race", "human");
    add_money("gold", random(500));
    set_body_type("human");
    set_property("no attack", 1);
    set_hd(19,3);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(500));
    set_max_mp(query_mp());
}


