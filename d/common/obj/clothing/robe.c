inherit "/std/armour";

void create() {
    ::create();
    set_name("robe");
    set_id(({ "robe","simple robe" }));
    set_short("simple robe");
    set_long("This is a simple but serviceable robe, stitched of sturdy linen with long sleeves and a near ground-length "
"hemline. It would be good for day-to-day activities and travel, if they were not too athletic or strenuous.");
    set_weight(8);
    set_value(10);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
    set_ac(0);
}
