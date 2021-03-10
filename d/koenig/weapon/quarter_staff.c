inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "staff", "quarter", "quarter staff", "quarter_staff" }));
   set_name("quarter_staff");
   set_short("A black staff");
   set_long("This is an elaborately decorated staff, with evil imagery from top.  The "+
   "evil magic can be felt just by touching the staff.");
   set_weight(4);
   set_size(3);
   set("value", 0);
   set_wc(1,6);
   set_large_wc(1,6);
   set_property("enchantment",2);
   set_type("bludgeoning");
   set_prof_type("staff");
}
