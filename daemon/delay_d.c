//ACTIVELY USED - By potion brewing

// I wanted to call this cron_d.c, but I don't think everyone would get it,
// and it's not exactly a cron_d. It's more of a callout handling daemon.
// Garrett 02/15/2002

#include <std.h>
//#define DEBUG

inherit DAEMON ;

int clean_up() {return 0;}




void execute(object ob, string fname, mixed * arguments) {
  function func;

#ifdef DEBUG
  if (objectp(find_player("saide")))
  tell_object(find_player("saide"),identify(ob) + identify(fname) +identify(arguments));

#endif // DEBUG

  seteuid(getuid());

// Build the function into a function pointer.

  func=(: call_other, ob, ({fname}) + arguments :);

// Run the function pointer.
#ifdef DEBUG
  if (objectp(find_player("saide")))
  tell_object(find_living("saide"),identify(func));
#endif // DEBUG
  catch(call_other(ob,"???"));
   (*func)();
   ob->remove();   
  return;

}

void sleep(mixed obmixed, string fname, int delay, mixed * arguments) {
  object obj;

  int delay_factor;

  //if (!objectp(obmixed))
  //  if (!objectp(obj=find_object(obmixed)))
  //     return;

  if(objectp(obmixed)) { obj = new(base_name(obmixed)); }
  else { obj = new(obmixed); }
  obj->set_no_clean(1);

#ifdef DEBUG
  if (objectp(find_player("saide"))) tell_object(find_player("saide"),identify(TO));
  if (objectp(find_player("saide")))
  tell_object(find_player("saide"),identify(obmixed)+ identify(fname)+identify(delay) + identify(arguments));
#endif // DEBUG

  if (!intp(delay))

    delay_factor = -1;
  else
    delay_factor = delay;

  if (delay_factor >= 0) {
      call_out( "execute", delay_factor, obj, fname, arguments );
  } else {
      execute(obj,fname, arguments);
  }
}

void later_run(string fname, mixed * arguments) {

  function func;

  func = (: call_other, TO, ({ fname }) + arguments :);
  (*func)();

  return;
}

void co_later_run(int delay, string fname, mixed *arguments) {
  call_out("later_run", delay, fname, arguments);
  return;
}
