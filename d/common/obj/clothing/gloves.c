inherit "/std/armour";

void create() {
    ::create();
    set_name("gloves");
    set_id(({ "gloves","simple gloves" }));
    set_short("simple gloves");
    set_long("This is a simple but serviceable pair of gloves, crafted of sturdy linen with reinforced stitches along the "
"seams. They would be good for day-to-day activities and travel.");
    set_weight(4);
    set_value(7);
    set_type("clothing");
    set_limbs( ({ "left arm","right arm" }) );
    set_ac(0);
}
