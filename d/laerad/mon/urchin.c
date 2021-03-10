//Coded by Bane//
#include <std.h>
inherit "/d/laerad/mon/wander/pwander.c";
void create(){
    ::create();
    set_id(({"urchin","boy","human"}));
    set_name("urchin boy");
    set_short("A small urchin boy");
    set_long(
	"This small young boy is dressed in tattered clothing.  He wanders "+
	"the back alleys of Asgard looking for food and shelter, trying to "+
	"stay alive.  He looks very poor and hungry."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(7,10);
    set_hp(66);
    set_overall_ac(6);
    add_search_path("/cmds/thief");
    set_thief_skill("move silently",80);
    set_thief_skill("hide in shadows",80);
    set_thief_skill("pick pockets",75);
    toggle_steal();
    set_exp(500);
    set_alignment(9);
    set_emotes(10,({"The urchin smiles happily.","The urchin wipes his nose with his sleeve."}),0);
    new("/d/common/obj/weapon/dagger")->move(TO);
    command("wield dagger");
}
