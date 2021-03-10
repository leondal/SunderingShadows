inherit "/std/weapon";

create() {
    ::create();

  set_id(({"duster","feather duster"}));
  set_name("feather duster");
  set_short("A feather duster");
   set_long(
  "  It's a short rather clean looking feather duster."
   "  From the look of the feathers, this duster has never even touched a speck of dust."
  );
  set_weight(2);
   set_size( 1 );
  set_large_wc(1,2);
  set_wc(1,2);
   set_value(5);
set_type("bludgeoning");
   set_prof_type("tool");
}
