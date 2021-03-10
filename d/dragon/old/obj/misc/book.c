
#include <std.h>

object ob;
int num;

inherit OBJECT;

void create() {
  ::create();
  set_name("book");
  set_id(({"book","reading book"}));
  set_short("A ordinary book");
  set_long("This is an ordinary reading book.  It's old and the pages look loose.");
  set_weight(0);
  set_value(1);
  num = 1;
}

void init() {
  ::init();
  add_action("rip_out","rip");
}

int rip_out(string str) {
  if(!str) return 0;
  if(str != "book") return 0;
  if(num == 0) write("The book has already been ripped apart.\n");
  if(this_player()->query_stats("strength") < 9) {
    write("%^GREEN%^You think you can rip a book apart!");
    return 1;
  }
 tell_room(environment(TP), "%^RED%^"+TPQCN+" manages to rip a book apart.",TP);
  write("You are able to save a piece of parchment.");
  ob = new("/std/Object.c");
  ob->set_name("parchment");
  ob->set_id(({"parchemnt","paper"}));
  ob->set_short("A piece of parchment");
  ob->set_long("This is a piece of parchment from a book.");
  ob->set_weight(0);
  ob->set_value(1);
  ob->move(this_player());
  num = 0;
  remove();
  return 1;
}
