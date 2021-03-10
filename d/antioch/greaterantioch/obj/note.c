#include <std.h>
#include "../gantioch.h"
inherit OBJECT;

create(){
   ::create();
   set_id(({"note"}));
   set_name("note");
   set_obvious_short("A hand-written note");
   set_short("A hand-written note");
   set_long("
            ***************************************************
            Dear Grolin,

            Thank you for your quick acquisition of the woman
            for my...delight. I had thought this would have
            taken more time...which shows your dedication for
            the large sum of coins I paid you. I will be sure
            to look to you for my next purchase. Please be sure
            to give the location of my home to the west of
            the keep to your men to ensure a quick delivery next
            time as well.

            Be well,

            Signed,
            Faris Gorineth
            ****************************************************
   ");
   set_weight(1);
   set_value(0);
}

