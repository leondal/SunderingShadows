inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "bastard sword", "2-handed bastard sword", "bastard", "bastard_two", "2-handed sword" }));
    set_name("2-handed bastard sword");
   set_short("A 2-handed bastard sword");
   set_long(
   "This is a longer, heavier version of the regular bastard sword and is just perfect for a the leverage needed to deliver powerful slashes.  Like the normal size version, it's not as pointed on the end as a normal sword and more made for heavy blows with its edge."
   );
   set_weight(10);
   set_size(3);
   set("value", 20);
   set_wc(2,6);
   set_large_wc(2,6);
   set_type("slashing");
   set_weapon_speed(8);
   set_weapon_prof("martial");

   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
