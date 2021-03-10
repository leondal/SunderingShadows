#include <std.h>
#include "/d/common/common.h"

const string WHAT= replace_string(TO->file_name(),TO->query("domain"),"common") ;
inherit WHAT;

void create() {
  ::create();
  if (objectp(PO))
    log_file("common","Created: "+file_name()+" on "+ctime(time())+ " Prev_obj was: "+identify(PO)+".\n");
  else
    log_file("common","Created: "+file_name()+" on "+ctime(time())+ ".\n");
  return;
}
