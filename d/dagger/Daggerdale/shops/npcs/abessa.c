
inherit "/std/monster";

void create() {
    ::create();
    set_name("abessa");
    set_id( ({"abessa", "maid", "serving maid"}) );
    set_short("Abessa, the serving maid");
    set("aggressive", 0);
    set_level(19);
    set_long(
      "Abessa is a sow faced human with long brown straight hair."
    );
    set_languages( ({ "common" }) );
    set_gender("female");
    set_alignment(5);
    set("race", "human");
    set_hd(19,1);
    set_body_type("human");
    set_property("no bump", 1);
}

