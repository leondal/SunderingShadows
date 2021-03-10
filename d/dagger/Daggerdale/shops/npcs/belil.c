
inherit "/std/monster.c";

void create() {
    ::create();
    set_name("belil");
    set_id( ({"belil", "farmer", "gambor"}) );
    set_short("Belil-Gambor, the farmer");
    set("aggressive", 0);
    set_level(15);
    set_long(
      "Belil-Gambor has long blonde straight hair and "
      "is reasonably dressed for a farmer."
    );
    set_languages( ({ "common" }) );
    set_gender("male");
    set_alignment(5);
    set("race", "elf");
    set_hd(15,1);
    set_body_type("human");
    set_property("no bump", 1);
}

