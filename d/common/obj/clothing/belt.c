inherit "/std/armour";

void create() {
    ::create();
    set_name("belt");
    set_id(({ "belt","simple belt" }));
    set_short("simple belt");
    set_long("This is a simple but serviceable shirt, crafted from leather with a simple brass buckle at the centre. It "
"is not particularly impressive to look upon, but would fare well as an accessory to common garments.");
    set_weight(3);
    set_value(5);
    set_type("clothing");
    set_limbs( ({ "waist" }) );
    set_ac(0);
}
