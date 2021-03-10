inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "nunchaku", "nunchuks", "numchucks", "Nunchaku", "Nunchuks", "chucks", "Chucks" }));
   set_name("nunchaku");
   set_short("Nunchaku");
   set_long(
        "Nunchaku can be used as a paired weapon for striking. One of the main advantages of Nunchaku is for entangle and this can only be done if one weapon is used with two hands."
   );
   set_weight(3);
   set_size(1);
   set("value", 30);
   set_wc(2,4);
   set_large_wc(2,4);
   set_type("bludgeoning");
}
