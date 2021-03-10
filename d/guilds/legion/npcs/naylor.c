#include <std.h>

inherit MONSTER;

void create(){
    ::create();
    set_name("Naylor");
    set_short("Naylor, the Legion's healer");
    set_long(
      "Naylor is a middle aged man, just past his prime.  Still very strong, physically and in the arts of healing, he is here in the hall of the Legion to bolster his own power with the power of others, supplying his healing for the powerful substance, gold."
    );
    set_hd(3,1);
    set_hp(20);
    set_max_hp(20);
    set_exp(10);
    set_race("human");
    set_gender("male");
    set_body_type("human");
    set_alignment(5);
    set("aggressive", 0);
}
