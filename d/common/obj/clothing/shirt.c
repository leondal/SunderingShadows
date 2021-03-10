inherit "/std/armour";

void create() {
    ::create();
    set_name("shirt");
    set_id(({ "shirt","simple shirt" }));
    set_short("simple shirt");
    set_long("This is a simple but serviceable shirt, stitched of sturdy linen with gathered sleeves and buttons down the "
"front. It would be good for day-to-day activities and travel, if they were not too athletic or strenuous.");
    set_weight(5);
    set_value(8);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
    set_ac(0);
}
