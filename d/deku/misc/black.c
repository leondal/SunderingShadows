inherit "/std/Object";

void create() {
  ::create();
  set_name("black stone");
  set_id(({"black stone","stone","black"}));
  set("short","Black stone");
  set("long","A soft, twinkling black shadow emanates from the stone.\n"+
             "This stone resembles death.");
  set_value(50);
  set_weight(1);
}
