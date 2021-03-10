// changing from type "ring" to type "jewelry", matching limbs with shoes -Ares
// if something is wrong with jewelry, it probably would be best to correct the lib
// rather than assign a strange type to an inherit.
// Changed back to "ring", jewelry is causing glitches with crafting/repairs & I have
// fixed the ring stacking problem with ROPs. N, 11/17.
inherit "/std/armour";

void create() 
{
    ::create();
    set_name("anklet");
    set_id(({ "anklet" }));
    set_short("plain anklet");
    set_long("This is a plain, undecorated anklet.  It's probably not worth much, but it seems well-made.");
    set_weight(2);
    set_value(5);
    set_type("ring");
    set_limbs( ({ "left foot","right foot" }) );
    set_ac(0);
}
