//edited by Odin to conform to tabletop
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "bastard sword", "a bastard sword", "bastard" }));
     set_name("bastard sword");
   set_short("A bastard sword");
   set_long(
   "This is a long, heavy sword.  Its handle is almost big enough for two hands for a normal sized human, but more effectivly wielded with one.  It's not so much pointed as made for heavy blows with its edge."
   );
   set_weight(10);
   set_size(2);
   set("value", 35);
   set_wc(1,10);
   set_large_wc(1,10);
   set_type("slashing");
   set_weapon_speed(6);
   set_weapon_prof("exotic");

   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
