inherit "/d/common/obj/weapon/claw.c";

void create() {
    ::create();
    set_id(({ "blades", "retractable blades" }));
    set_name("retractable blades");
    set_short("A set of nine inch retractable blades");
    set_long(
      "This set of three blades is mounted against a forearm plate and forms a shield over the forearm.  The blades retract into slits in the front of the raised shield.  This is a very bloody weapon designed by the Kinnesaruda."
    );
    set_weight(25);
    set_size(1);
    set("value", 1500);
    set_wc(1,6);
    set_large_wc(1,8);
    set_type("slashing");
}
