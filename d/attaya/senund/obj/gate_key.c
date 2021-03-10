
inherit  "/std/Object";
void create()
{
  ::create();
  set_name("gate key");
  set_id(({"key","gate key"}));
  set_short("Gate key");
  set_long("This is an old metal key. It is beginning to rust but it "+
             "still appears usable. The word gate is written on the top "+
             "of the key.");
  set_weight(1);
  set("value", 10);
}
