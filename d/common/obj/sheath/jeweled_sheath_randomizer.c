#include <std.h>
#include "/d/common/common.h"

inherit OBJECT ;

void create() {
  ::create();
  //set_value(10000000000000);
  set_name("A random sheath");
  set_id(({"random sheath"}));
  set_short("A random sheath");
  call_out("choose_sheath",0);

  return ;
}

void choose_sheath() { 
  if (!objectp(TO) || !objectp(ETO) ) {
    TO->remove(); 
    return;
  }
  switch(random(22)) {
  case 0..3: new(CSHEATH"jeweled_lsheath")->move(ETO);
               break;
  case 4..6: new(CSHEATH"jeweled_mstaff")->move(ETO);
               break;
  case 7..9: new(CSHEATH"jeweled_msheath")->move(ETO);
               break;
  case 10..12: new(CSHEATH"jeweled_lstaff")->move(ETO);
               break;
  case 13..15: new(CSHEATH"jeweled_mholster")->move(ETO);
               break;
  case 16..18: new(CSHEATH"jeweled_ssheath")->move(ETO);
               break;
  case 19..21: new(CSHEATH"pearled_msheath")->move(ETO);
               break;
  }
  TO->remove();
}
