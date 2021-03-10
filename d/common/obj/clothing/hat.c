inherit "/std/armour";

void create() {
    ::create();
    set_name("hat");
    set_id(({ "hat","simple hat" }));
    set_short("simple hat");
    set_long("This is a simple but serviceable hat, made from soft felt with a narrow band as a decoration around its "
"middle. It would be good for day-to-day activities and travel.");
    set_weight(4);
    set_value(7);
    set_type("clothing");
    set_limbs( ({ "head" }) );
    set_ac(0);
}
