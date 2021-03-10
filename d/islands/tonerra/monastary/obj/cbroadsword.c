inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "broadsword", "chinese broadsword" }));
    set_name("broadsword");
   set_short("%^YELLOW%^Chinese broadsword");
   set_long(
        "This broadsword is curved and a bit heavier then regular broadswords."
   );
  set_weight(10);
   set_size(2);
  set("value", 30);
  set_wc(2,6);
  set_large_wc(2,5);
  set_type("slashing");
}
