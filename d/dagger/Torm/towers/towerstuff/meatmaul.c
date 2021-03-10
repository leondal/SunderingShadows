inherit "/std/weapon";

create() {
    ::create();
  set_id(({"meat maul","maul",
  }));
  set_name("meat maul");
  set_short("meat maul");
   set_long(
  "  This massive two handed maul looks a fright, with chunks of tissue clinging to its double head, and its oak handle stained with dark blood."
  "  Looking closely you can see the great steel head of the maul has divots carved into its face to increas the amount of force it delives with impacts to meat."
  );
  set_weight(20);
  set_size(3);
  set_value(200);
  set_wc(2,5);
  set_large_wc(3,6);
   set_type("bludgeoning");
  set_prof_type("large hammer");
  set_weapon_speed(10);
  set_property("enchantment",2);
}
