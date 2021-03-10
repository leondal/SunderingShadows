inherit "/std/weapon";

void create() {
    ::create();
    set_id(({ "claymore", "sword" }));
    set_name("claymore");
    set_short("A polished claymore");
    set_long(
      "This is the standard issue sword of the Seneca guard and infantry corps.  It is a heavy two handed, double bladed long sword with a black mesh wrapped handle and polished blade."
    );
    set_weight(45);
    set_size(3);
    set("value", 10);
    set_wc(1,10);
    set_large_wc(3,6);
    set_type("slash");
}
