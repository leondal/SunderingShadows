inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "lion head sword", "Lion Head Sword", "Lion Head sword", "Lion head sword", "lion sword", "Lion sword", "lion" }));
   set_name("lion head sword");
   set_short("%^YELLOW%^Lion Head Sword");
   set_long(
        "%^YELLOW%^The most popular Chinese sword. The %^BOLD%^%^YELLOW%^Tai Chi %^YELLOW%^sword has a 28in blade, a 10in handle, and a cord at the pommel."
   );
   set_weight(15);
   set_size(3);
   set("value", 50);
   set_wc(3,6);
   set_large_wc(3,6);
   set_type("slash");
}
