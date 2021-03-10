inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "Steel Whip", "Steel whip", "steel whip", "whip", "Whip" }));
   set_name("steel whip");
   set_short("Steel Whip");
   set_long(
        "A chinese-type weapon. It's actually 9 linked. metal rods with a weighted blade on one end."
   );
   set_weight(4);
   set_size(3);
   set("value", 30);
   set_wc(2,6);
   set_large_wc(2,6);
   set_type("slashing");
}
