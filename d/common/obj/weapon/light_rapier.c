// adapted from the pirate weapon per suggestion by Shar - *Styx*  4/8/02
//updated damage since it has its own prof - Circe 4/29/04
//Based on a discussion with circe - rapier is size 2 now - cythera 5/07

inherit "/std/weapon";

create(){
    ::create();
    set_id(({"light rapier","rapier","sword","foil"}));
    set_name("light rapier");
    set_short("light rapier");
    set_long("This is a fairly light and thin-bladed weapon, sometimes "
"referred to as a foil.  It is used more for thrusting jabs than sweeping "
"arcs and often used by nimble, swashbuckling types or those who prefer to "
"employ finesse rather than brute force in sparring or battle.  It looks "
"durable, light, and easy to maintain.  The blade of this rapier is "+
"shorter than it's more famous cousin.");
//    set_large_wc(1,6);
    set_wc(1,4);
    set_large_wc(1,4);
    set_weight(4);
    set_size(1);
    set("value",10);
    set_type("piercing");
    set_prof_type("rapier");
   set_weapon_speed(3);
   set_weapon_prof("martial");
   set_critical_threat_range(3);
   set_critical_hit_multiplier(2);
   set_damage_type("piercing");
   set_property("repairtype",({"weaponsmith"}));
}
