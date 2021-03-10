//pin to inherit for torso worn stuff
inherit "/std/armour";

void create() 
{
    ::create();
    set_name("pin");
    set_id(({ "pin" }));
    set_short("plain pin");
    set_long("This is a plain, undecorated pin.  It's probably not worth
much, but it seems well-made.");
    set_weight(2);
    set_value(5);
    set_type("ring");
    set_limbs( ({ "torso" }) );
    set_ac(0);
}