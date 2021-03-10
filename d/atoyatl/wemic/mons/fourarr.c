#include <std.h>
#include "../wemic.h"

inherit NPC;
void create() {
    ::create();
    set_name("Fourarr");
    set_id( ({ "fourarr", "healer"}) );
    set_short("Fourarr, wemic healer");
    set_long("%^ORANGE%^This older %^BOLD%^wemic %^RESET%^%^ORANGE%^has a rounded face with pouchy cheeks. His gaze is intense but kindly, and the %^RESET%^crinkles%^ORANGE%^ at the corners of his eyes speak of a life filled with compassion and laughter. His %^BOLD%^leonine%^RESET%^%^ORANGE%^ body remains %^RESET%^l%^BOLD%^%^WHITE%^i%^RESET%^the %^ORANGE%^and %^MAGENTA%^muscular%^ORANGE%^, though his %^BOLD%^furry h%^RESET%^%^ORANGE%^i%^BOLD%^de%^RESET%^%^ORANGE%^ has a little %^RESET%^sag%^ORANGE%^ to it these days. His knowledge of the %^GREEN%^medicinal%^ORANGE%^ properties of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^e pl%^RESET%^%^GREEN%^a%^BOLD%^nts %^RESET%^%^ORANGE%^has earned him his role as the %^CYAN%^village healer%^ORANGE%^. Unlike some of the other wemics in the village, he doesn't have much to say for himself.");
    set("aggressive", 0);
    set_level(39);
    set_gender("male");
   set_alignment(2);
   set_race("wemic");
    set_hd(19,4);
    add_money("gold", random(500));
    set_body_type("human");
    set_property("no attack", 1);
    set_hp(800);
    set_max_hp(800);
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(500));
    set_max_mp(query_mp());
    set_exp(10);
    remove_std_db();
    set_nwp("healing",15);
    set_skill("healing", 35);
}
