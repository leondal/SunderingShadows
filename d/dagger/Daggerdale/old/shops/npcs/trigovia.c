// taken out because was set to comp_vendor and didn't have a menu *Styx* 4/7/02
inherit "/std/barkeep";

void create() {
    ::create();
    set_name("trigovia");
    set_id( ({"trigovia", "maid", "serving maid"}) );
    set_short("Trigovia, the serving maid");
    set("aggressive", 0);
    set_level(15);
    set_long(
      "Trigovia smiles warmly and brushes her red wavy hair from "
      "her pretty face."
    );
    set_languages( ({ "common" }) );
    set_gender("female");
    set_alignment(5);
    set("race", "human");
    set_hd(15,1);
    set_body_type("human");
    set_property("no bump", 1);
}

