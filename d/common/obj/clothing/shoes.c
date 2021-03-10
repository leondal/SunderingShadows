inherit "/std/armour";

void create() {
    ::create();
    set_name("shoes");
    set_id(({ "shoes","simple shoes" }));
    set_short("simple shoes");
    set_long("This is a simple but serviceable pair of shoes, made of leather with thickened soles to extend their life. "
"They would be good for day-to-day activities and travel.");
    set_weight(4);
    set_value(5);
    set_property("repairtype",({"tailor","armorsmith","leatherwork"}));
    set_type("clothing");
    set_limbs( ({ "left foot","right foot" }) );
    set_ac(0);
}
