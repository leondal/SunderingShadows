inherit "/std/armour";

void create() {
    ::create();
    set_name("cloak");
    set_id(({ "cloak","simple cloak" }));
    set_short("simple cloak");
    set_long("This is a simple but serviceable cloak, stitched of sturdy linen with a fine silver button at the throat to "
"hold it in place. It would be good for day-to-day activities and travel.");
    set_weight(5);
    set_value(8);
    set_type("clothing");
    set_limbs( ({ "neck" }) );
    set_ac(0);
}
