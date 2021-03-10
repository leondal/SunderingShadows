inherit "/std/armour";

void create() {
    ::create();
    set_name("breeches");
    set_id(({ "breeches","simple breeches" }));
    set_short("simple breeches");
    set_long("This is a simple but serviceable pair of breeches, crafted of sturdy linen with reinforced stitches along "
"the seams. They would be good for day-to-day activities and travel.");
    set_weight(6);
    set_value(9);
    set_type("clothing");
    set_limbs( ({ "left leg","right leg" }) );
    set_ac(0);
}
