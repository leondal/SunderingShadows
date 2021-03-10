//cyril.c ~Circe~ 11/2/07 for Seneca
#include <std.h>

inherit NPC;

void create(){
    ::create();
    set_nwp("healing", 20);
    set_id(({"cyril","healer","cyril the healer","Cyril the Healer"}));
    set_name("Cyril");
    set_short("Cyril the Healer");
    set_long(
@CIRCE
%^RESET%^%^CYAN%^Cyril is a young-seeming man in his late thirties who has sleek %^YELLOW%^blond hair %^RESET%^%^CYAN%^kept short and tidy.  His pale %^RESET%^gray eyes %^CYAN%^display intelligence and compassion, and it is his dedication to the welfare of his fellow man that has made him the healer he is.  A pure joy of science and medicine causes him to strive for new remedies, so he pays little attention to more mundane matters.  He wears the simple robes of a %^ORANGE%^monk%^CYAN%^, belted at the waist with a %^ORANGE%^hemp cord%^CYAN%^.%^RESET%^
CIRCE
    );
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_size(2);
    set_hd(30,2);
    set_hp(500);
    set_overall_ac(-10);
    set_exp(100);
    set_alignment(1);
    set("aggressive",0);
//    set_diety("istishia");
//    new("/d/magic/symbols/istishia_symbol")->move(TO);
//    force_me("wear symbol");
    set_class("cleric");
    set_mlevel("cleric",20);
    set_stats("wisdom",18);
    set_spells(({
	"cloudburst",
	"cloudburst",
	"cloudburst",
      "tidal surge",
      "lightning touch",
      "stormwinds"
    }));
    set_spell_chance(75);
}