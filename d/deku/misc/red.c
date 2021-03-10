inherit "/std/Object";

void create() {
  ::create();
  set_name("red stone");
  set_id(({"red stone","stone","red"}));
  set("short","Red stone");
  set("long","A soft, twinkling red light emanates from the stone.\n"+
             "This stone resembles hatred.");
  set_value(50);
  set_weight(1);
}
