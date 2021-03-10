// I wanted to call this cron_d.c, but I don't think everyone would get it,
// and it's not exactly a cron_d. It's more of a callout handling daemon.
// Garrett 02/15/2002

#include <std.h>

inherit DAEMON ;

int clean_up() {return 0;}




void execute(object ob, string fname, mixed * arguments) {
  function func;

  if (objectp(find_player("garrett")))
  tell_object(find_player("garrett"),identify(ob) + identify(fname) +identify(arguments));
  call_other(ob, fname, arguments);

//  if ((functionp(func) == 1) && pointerp(arguments))
    (*func)();
//  else 

//  {
//  func;
  if (objectp(find_player("garrett")))
  tell_object(find_living("garrett"),identify(func));
//  }
  return;

}

void sleep(mixed obmixed, string fname, int delay, mixed * arguments) {
  object obj;

  int delay_factor , hasargs;

  if (!objectp(obmixed))
    if (!objectp(obj=find_object(obmixed)))
       return;

  if (objectp(find_player("garrett")))
  tell_object(find_player("garrett"),identify(obmixed)+ identify(fname)+identify(delay) + identify(arguments));

  if (!intp(delay))

    delay_factor = -1;
  else
    delay_factor = delay;
  
  if (delay_factor >= 0) {
//    if (hasargs == 2) {
//      call_out( "execute_user_call_out", obj, fname, delay_factor );
//    } else  {
      call_out( "execute", delay_factor, obj, fname, arguments );
//    }
  } else {
//    if (hasargs == 2) {
//      TO->execute_user_call_out(obj,fname);
//    } else {
      TO->execute(obj,fname, arguments);
//    }
  }
}

void later_run(string fname, mixed * arguments) {

  function func;
  call_other(TO, fname, arguments);
  //func = (: TO, ({ fname }) + arguments :);
  //(*func)();

  return;
}

void co_later_run(int delay, string fname, mixed *arguments) {
  call_out("later_run", delay, fname, arguments);
  return;
}
