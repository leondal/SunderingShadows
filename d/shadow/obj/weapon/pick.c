inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "pick","tool","weapon"}));
   set_name("pick");
   set_short("A pick");
   set_long(
   "This pick looks like a strengthened and shortened version of the mining tool."
   "  The punctures this thing could inflict would be gruesome indeed and you doubt even the heaviest armor would be able to deflect its blows."
   );
   set_weight(6);
   set_size(2);
   set("value", 8);
   set_wc(1,6);
   set_large_wc(2,4);
    set_type("pierce");
   set_prof_type("tool");
   set_weapon_speed(5);
}
