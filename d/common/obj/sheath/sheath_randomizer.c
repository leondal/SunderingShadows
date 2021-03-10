#include <std.h>
#include "/d/common/common.h"

inherit OBJECT ;

void create() {
  ::create();
  set_value(10000000000000);
  call_out("choose_sheath",0);
  return ;
}

void choose_sheath() { 
  if (!objectp(TO) || !objectp(ETO) ) {
    TO->remove(); 
    return;
  }
  switch(random(24)) {
  case 0..3: new(CSHEATH"sheath_mbludgeon")->move(ETO);
               break;
  case 4..6: new(CSHEATH"sheath_mstaff")->move(ETO);
               break;
  case 7..9: new(CSHEATH"sheath_medium")->move(ETO);
               break;
  case 10..12: new(CSHEATH"sheath_small")->move(ETO);
               break;
  case 13..15: new(CSHEATH"sheath_lgbludgeon")->move(ETO);
               break;
  case 16..18: new(CSHEATH"sheath_lgstaff")->move(ETO);
               break;
  case 19..21: new(CSHEATH"sheath_large")->move(ETO);
               break;
  case 22:  new(CSHEATH"sheath_great")->move(ETO);
               break;
  case 23:  new(CSHEATH"sheath_giantbludgeon")->move(ETO);
               break;
  }
  TO->remove();
}
