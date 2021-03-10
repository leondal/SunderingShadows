
inherit  "/std/Object";
void create()
{
  ::create();
  set_name("old key");
  set_id(({"key","old key"}));
  set_short("Old key");
  set_long("This is an old steel key. It is beginning to rust but it "+
             "still appears usable.");
  set_weight(1);
  set("value", 10);
}
