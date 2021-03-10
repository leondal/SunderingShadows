inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "staff", "bo staff", "Staff", "Bo staff", "Bo Staff", "bo", "Bo" }));
   set_name("bo staff");
   set_short("Bo staff");
   set_long(
        "This is a staff made from bamboo. It stands about 9.5 feet high and is very strong and sturdy."
   );
   set_weight(3);
   set_size(3);
   set("value", 30);
   set_wc(2,5);
   set_large_wc(1,9);
   set_type("bludgeoning");
}
