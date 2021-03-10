#include <std.h>
#include "/d/dagger/Torm/tormdefs.h";
inherit OBJECT;
object ob;
void create(){
  ::create();
  set_name("rubble");
  set_id(({"rubble","debris","rubblex",
  }));
  set_short("A pile of rubble");
  set_long(
  "  This is a small pile of smashed mechanical parts."  
  "  A gear slowly dances on the end of a twisted spring that juts from the greasy pile of parts."
  "  A pair of pieces of metal so thin as to be hammered foil are crushed under it and you wonder what it could of been before it was destroyed."
  );
  set_weight(100);
  set("value",200);
  set_property("no animate",1);
}
int do_fix(){
  if(TO->query_property("done")) return 1;
  TO->set_property("done",1);
tell_room(ETO,"%^YELLOW%^The gnome trundles over to the pile of wreakage and starts tinkering with it.");
  call_out("do_it",20,TO,1);
}
void do_it(){
  tell_room(ETO,"%^YELLOW%^Mended, the insect suddenly takes to the air again!.");
  ob=new(TOWS+"clockworki.c");
  ob->set_exp(500);
  ob->move(ETO);
  ob->set_property("DoNe",1);
  TO->remove();
  }
