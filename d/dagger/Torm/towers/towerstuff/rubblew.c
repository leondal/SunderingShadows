#include <std.h>
#include "/d/dagger/Torm/tormdefs.h";
inherit OBJECT;
object ob;
void create(){
  ::create();
  set_name("rubble");
  set_id(({"rubble","debris","rubblex",
  "broken brass statue","statue",
  "broken warrior",
  }));
  set_short("A broken brass statue");
  set_long(
  "  This is the remains of a tall brass statue."
  "  A terrible rent has been torn into its side and you can see springs and broken gears inside it."
  "  A gleaming brass sword still rests in its hands but seems to be fused to the arm."
  );
  set_weight(100);
  set("value",200);
  set_property("no animate",1);
}
int do_fix(){
  if(TO->query_property("done")) return 1;
tell_room(ETO,"%^YELLOW%^The gnome trundles over to the pile of wreakage and starts tinkering with it.");
  TO->set_property("done",1);
  call_out("do_it",20,TO,1);
  }
void do_it(){
  tell_room(ETO,"%^BOLD%^%^YELLOW%^Mended, the brass warrior stands slowly up and readies his swordarm again.");
  ob=new(TOWS+"clockworkw.c");
  ob->set_exp(500);
  ob->move(ETO);
  ob->set_property("DoNe",1);
  TO->remove();
  }
