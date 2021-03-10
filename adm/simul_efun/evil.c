#include <std.h>

/**
 * @file
 */

/**
 * Returns online users with evil alignment
 */
object * evil(){
//
    object * us;
       object * tmp;
    int i,j;
     tmp = ({});

    us = users();
    j = sizeof(us);
    for(i=0;i<j;i++){
      if(!objectp(us[i])) continue;
       if(ALIGN->is_evil(us[i]))
	tmp += ({us[i]});
   }
   return tmp;
}
