inherit "/std/bag_logic";

void create() {

    ::create();
    set_id( ({"chest", "large chest", "donation chest" }));
set_name("Iron Fist Donation chest");
set_short("Iron Fist Donation chest");
    set_long(
"%^BLUE%^This is the donation chest of the %^RED%^Iron Fist%^BLUE%^ members may place items here so that other members my benefit from them."
    );
    set_no_clean(1);
    set_weight(99999);
    set_value(2);
    set_max_internal_encumbrance(99999);
    set_possible_to_close(1);
}

int cleanup(){
  return 1;
}
