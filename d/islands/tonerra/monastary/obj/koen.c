inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sa tjat koen", "Sa Tjat Koen", "koen", "Koen", "Sa", "sa", "Tjat", "tjat" }));
   set_name("sa tjat koen");
   set_short("Sa Tjat Koen");
   set_long(
        "This weapon looks like Nunchaku with a second chain and third handle attached. Can be used to entangle like nunchaku."
   );
   set_weight(3);
   set_size(3);
   set("value", 30);
   set_wc(1,9);
   set_large_wc(2,5);
   set_type("bludgeoning");
}
