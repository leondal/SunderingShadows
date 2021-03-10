inherit "/std/weapon";

create() {
    ::create();

  set_id(({"rod","rod of rule"}));
  set_name("rod of rule");
  set_short("Rod of rule");
   set_long(
  "  This 3 foot long metal rod is the symbol of the magistrate of the City of Torm."
    "  It's a fairly simple looking rod and as you look closely you notice its poor workmanship, almost like it was copied when the original disapeared."
    "  Even the gold leaf seems poorly attached and is comming off in places, so there's no doubt why the Magistrate keeps it close at hand always to prevent anyone from seeing it."
  );
  set_weight(10);
  set_size(2);
  set_large_wc(1,8);
  set_wc(1,8);
  set_value(25);
set_type("bludgeoning");
}
