//  tester the test-shopkeeper

inherit "/std/store";

void create()    {
  ::create();
  set_name("shopkeeper");
  set_short("Tester, the Shopkeeper");
  set_id(({"tester","shopkeep","shopkeeper"}));
  set_long("Buy, sell, list... that sort of stuff.");
  set_gender("male");
  set("race","gray elf");
  set_languages(({"elven","common","dwarven"}));
  set_storage("/realms/kayla/workroom");
  set_skill("bargaining",50);
/*
  set_shop_type("armour");
*/
}
