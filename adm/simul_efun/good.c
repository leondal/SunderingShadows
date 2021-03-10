#include <std.h>

/**
 * @file
 */


/**
 * Returns online users with good alignment
 */
object * good(){
//
    object * us;
       object * tmp;
    int i,j;
     tmp = ({});

    us = users();
    j = sizeof(us);
    for(i=0;i<j;i++){
      if(!objectp(us[i])) continue;
       if(ALIGN->is_good(us[i]))
	tmp += ({us[i]});
   }
   return tmp;
}
