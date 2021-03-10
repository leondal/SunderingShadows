inherit "/std/weapon";

void create()
{
    ::create();
    set_id(({ "whip", "lash", "scourge", "bdsmx" }));
    set_name("whip");
    set_short("A whip");
    set_long("Interwoven strips of leather and steel have been braided together to " +
             "create this flexible whip.  The handle of the whip is crafted from leather, " +
             "creating a comfortable grip.  Unlike a normal whip, this lash ends " +
             "in a dagger several inches long, adding a deadly touch to this " +
             "weapon and making it obvious that it is useful only for combat.");
    set_weight(4);
    set_size(1);
    set_value(15);
    set_wc(1, 6); //waveeblade euivalent from pathfinder
    set_large_wc(1, 6);
    set_type("slashing");
    set_damage_type("slashing");
    set_prof_type("whip");
    set_weapon_speed(8);
    set_weapon_prof("exotic");
    set_critical_threat_range(3);
    set_critical_hit_multiplier(2);
    set_property("repairtype", ({ "leatherwork" }));
}
