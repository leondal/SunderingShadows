inherit "/std/weapon";

void create() {
    ::create();
    set_id(({ "sabre", "sword" }));
    set_name("sabre");
    set_short("A polished sabre");
    set_long(
      "This is the standard weapon issued to the seneca field infantry.  It is a short sword with a single edged blade and a leather wrapped hilt.  Etched into the blade is the phrase:"
      +"%^RED%^One shall stand..."
      +"One shall fall."
    );
    set_weight(20);
    set_size(1);
    set("value", 320);
    set_wc(1,6);
    set_large_wc(1,6);
    set_property("enchantment",2);
    set_type("slash");
}
