#include <std.h>

inherit OBJECT;

create() {
    ::create();
set_id(({"ruby","huge ruby"}));
   set_name("huge ruby");
set_short("A Huge Red Ruby");
set_long(
@GILG
%^RED%^It's a Huge Dark Red Ruby Gemstone.
Underneath it is a small hidden water compartment.
Hmmm...theres also a small stud on the side.
I wonder what would happen if you pressed it?
Theres also some tiny writing on the bottom.
GILG
);
set_value(0);
   set_weight(5);
}

int init(){
object tp;
  ::init();
  tp = this_player();
add_action("squirt","squirt");
add_action("read_writing","read");
}
int squirt(string arg){
string name, gender, person;
object ob;
  if(!arg) {
      notify_fail("Squirt whom?\n");
      return 0;
  }
  else ob = present(arg, environment(this_player()));
  if(!ob) ob = parse_objects(environment(this_player()), arg);
   if(!ob || !living(ob)) {
       notify_fail("No "+arg+" here.\n");
       return 0;
  }

  name = ob->query_cap_name();
  gender = ob->query_possessive();
  person = ob->query_objective();

message("my_action","%^BOLD%^%^BOLD%^You show the Ruby to "+name+" and when they bend over to view it, you press the stud!",          this_player());
tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" shows "+name+" a Huge Red Ruby and when they bend over to see it... Water SQUIRTS them right in the Face!!",this_object());
return 1;
}
int read_writing(string str)
{
if ((str=="writing") || (str=="the writing") || (str=="the tiny writing"))
{
write("%^BOLD%^To wet thy friends fancy...Type squirt <name>.");
return 1;
}
return 0;
}
